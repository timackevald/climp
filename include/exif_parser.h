/* @Brief: exif parser header file
 * Parses TIFF (Tagged Image File Format) for IDF (Image File Directory) blocks
 */

#ifndef EXIF_PARSER_H
#define EXIF_PARSER_H

#include <stdint.h>
#include "data_storage.h"
#include "app.h"

/* @Brief: Parses tiff for ifd blocks and adds these to list
 * @Param: tiff_start - pointer to endianess byte
 * @Param: file_end_ptr - pointer to last memory address of file
 * @Param: byteorder
 * @param: list
 * @retur: 0 on success
 */
uint8_t exif_parser_run(const uint8_t *tiff_start, const uint8_t *file_end_ptr,
                        app_byteorder_t byteorder, data_list_t *list);

#endif /* EXIFx_PARSER_H */
