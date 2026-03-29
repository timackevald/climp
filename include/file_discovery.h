/* @Brief: file discovery h file
 * Tasked with determining:
 * - Size
 * - Type
 * - Endianess
 */

#include <stddef.h>
#include <stdint.h>

typedef enum
{
    FMT_UNKNOWN,
    FMT_JPEG,
    FMT_PNG,
    FMT_TIFF
} file_type_t;

typedef enum
{
    ORDER_LITTLE,
    ORDER_BIG
} file_byteorder_t;

typedef struct file_discovery
{
    /* File data */
    file_type_t type;
    file_byteorder_t byteorder;
    size_t file_size;

    /* System resources */
    uint32_t fd;
    void *mmap_ptr;
} file_discovery_t;

/* @brief: Initializes the file discovery structure
 * @param self: Pointer to the file discovery structure
 * @return: 0 on success, non-zero on failure
 */
uint8_t file_discovery_init(file_discovery_t *self);

/* @brief: Performs the file discovery work
 * @param self: Pointer to the file discovery structure
 * @param ctx: Pointer to the application context
 * @return: 0 on success, non-zero on failure
 */
uint8_t file_discovery_work(file_discovery_t *self, struct app_context *ctx);

/* @brief: Deinitializes the file discovery structure
 * @param self: Pointer to the file discovery structure
 * @return: 0 on success, non-zero on failure
 */
uint8_t file_discovery_deinit(file_discovery_t *self);
