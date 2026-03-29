/* @file: file_discovery.c
 *
 */

#include "../include/file_discovery.h"
#include <string.h>
#include <fcntl.h>

uint8_t file_discovery_init(file_discovery_t *self, char *file_path)
{
    memset(self, 0, sizeof(*self));
    self->file_path = file_path;
    if ((self->fd = open(self->file_path, O_RDONLY) == -1))
    {

    }

    return 0;
}

uint8_t file_discovery_work(file_discovery_t *self)
{

    return 0;
}

uint8_t file_discovery_deinit(file_discovery_t *self)
{

    return 0;
}
