/* @file: file_discovery.c
 *
 */
#include "../include/file_discovery.h"

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
