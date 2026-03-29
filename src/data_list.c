/* @Brief: data_list c file
 *
 */

#include <stdint.h>
#include "../include/data_list.h"

/* @Brief: creates list
 * @Return: new list
 */
data_list_t *data_list_create(void)
{
    // TO DO implement

}

/* @Brief: creates a new node
 * @Param: tag_id, value and type
 * @Return: new node
 */
data_node_t *data_node_create(uint32_t tag_id, data_value_t value,
                              data_type_t type)
{
    // TO DO implement

}

/* @Brief: appends node to list
 * @Param: list and node
 */
void data_list_append(data_list_t *list, data_node_t *node)
{
    // TO DO implement
}

/* @Brief: prints content of linked list
 * @Param: list
 */
void data_list_print(const data_list_t *list)
{
    // TO DO implement

}

/* @Brief: frees list
 * @Param: pointer to list
 * @Return: 0 on success
 */
uint8_t data_list_free(data_list_t **list_ptr)
{
    // TO DO implement
    return 0;
}
