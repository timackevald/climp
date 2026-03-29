/* @Brief: app header file
 *
 */

#ifndef APP_H
#define APP_H

#include <stdint.h>
#include <stddef.h>
#include "data_list.h"
#include "file_discovery.h"

typedef struct app_context
{
    /* File data */
    file_discovery_t file_information;

    /* Parsed data */
    data_list_t parsed_data;

} app_context_t;

/* @Brief: Init all parts of app
 * @Param: self pointer
 * @Param: argc and argv
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
