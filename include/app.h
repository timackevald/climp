/* @Brief: app header file
 *
 */

#ifndef APP_H
#define APP_h

#include <stdint.h>
#include <stddef.h>
#include "data_storage.h"

typedef enum
{
    FMT_UNKNOWN,
    FMT_JPEG,
    FMT_PNG,
    FMT_TIFF
} app_filetype_t;

typedef enum
{
    ORDER_LITTLE,
    ORDER_BIG
} app_byteorder_t;


typedef struct app_context
{
    /* App data */
    app_filetype_t filetype;
    app_byteorder_t byteorder;
    data_node_t *exif_data;

    /* System resources */
    uint32_t fd;
    void *mmap_ptr;
    size_t file_size;
} app_context_t;

/* @Brief: Init app layer and parser
 * @Param: self pointer
 * @Param: int argc, char **argv
 * @Return: 0 on success
 */
uint8_t app_init(app_context_t *self, int argc, char **argv);

/* @Brief: Run parser
 * @Param: self pointer
 * @Return: 0 on success
 */
uint8_t app_run(app_context_t *self);

/* @Brief: Deinit app
 * @Param: pointer to self pointer
 * @Return: 0 on success
 */
uint8_t app_deinit(app_context_t **self_ptr);

#endif /* APP_H */
