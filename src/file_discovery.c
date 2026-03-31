/* @file: file_discovery.c
 * @brief: Handles discovering file properties
 */

#include "../include/file_discovery.h"
#include <endian.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

uint8_t file_discovery_init(file_discovery_t *self, char *file_name)
{
    if (!self || !file_name)
    {
        fprintf(stderr, "Passed invalid arguments to function: file_discovery_init\n");
        return 1;
    }

    /* Try to open file */
    memset(self, 0, sizeof(*self));
    self->file_name = file_name;
    if ((self->fd = open(self->file_name, O_RDONLY) == -1))
    {
        perror("open");
        return 1;
    }

    /* Get filesize */
    struct stat st;
    if (fstat(self->fd, &st) == -1)
    {
        perror("fstat");
        return 1;
    }
    self->file_size = st.st_size;

    /* Try to memory map file */
    self->mmap_ptr = mmap(NULL, self->file_size, PROT_READ, MAP_PRIVATE, self->fd, 0);
    if (self->mmap_ptr == MAP_FAILED)
    {
        perror("mmap");
        close(self->fd);
        return 1;
    }

    return 0;
}

uint8_t file_discovery_work(file_discovery_t *self)
{
    if (!self)
    {
        fprintf(stderr, "Passed invalid arguments to function: file_discovery_work\n");
        return 1;
    }

    /* Discover file type */
    const uint8_t *byte_ptr = (const uint8_t *)self->mmap_ptr;
    if (byte_ptr[0] == 0x89 && byte_ptr[1] == 0x50 && byte_ptr[2] == 0x4E && byte_ptr[3] == 0x47)
    {
        self->type = FMT_PNG;
        self->byteorder = ORDER_UNKNOWN;
    }
    else if (byte_ptr[0] == 0xFF && byte_ptr[1] == 0xD8 && byte_ptr[2] == 0xFF)
    {
        self->type = FMT_JPEG;
        self->byteorder = ORDER_UNKNOWN;
    }
    /* For TIFF the first two bytes are endianess */
    else if (byte_ptr[0] == 0x49 && byte_ptr[1] == 0x49 && byte_ptr[2] == 0x2A && byte_ptr[3] == 0x00)
    {
        self->type = FMT_TIFF;
        /* 0x49, Ox 49 means little-endian/ II */
        self->byteorder = ORDER_LITTLE;
    }
    else if (byte_ptr[0] == 0x4D && byte_ptr[1] == 0x4D && byte_ptr[2] == 0x00 && byte_ptr[3] == 0x2A)
    {
        self->type = FMT_TIFF;
        /* 0x4D, 0x4D means big-endian/ MM */
        self->byteorder = ORDER_BIG;
    }
    else
    {
        self->type = FMT_UNKNOWN;
        self->byteorder = ORDER_UNKNOWN;
    }

    return 0;
}

uint8_t file_discovery_deinit(file_discovery_t *self)
{
    if (self == NULL) return 1;

    /* Unmap file */
    if (self->mmap_ptr != NULL && self->mmap_ptr != MAP_FAILED)
    {
        munmap(self->mmap_ptr, self->file_size);
        self->mmap_ptr = NULL;
    }

    /* Close FD */
    if (self->fd >= 0)
    {
        close(self->fd);
        self->fd = -1;
    }

    self->type = FMT_UNKNOWN;
    self->byteorder = ORDER_UNKNOWN;
    self->file_size = 0;

    return 0;
}
