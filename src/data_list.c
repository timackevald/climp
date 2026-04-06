/* @Brief: data_list c file
 *
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/data_list.h"

/* @Brief: creates list
 * @Return: new list or null
 */
data_list_t *data_list_create(void)
{
    /* Allocation freed in data_list_free */
    data_list_t *new_list = (data_list_t*)calloc(1, sizeof(data_list_t));
    if (!new_list)
    {
        perror("malloc");
        return NULL;
    }

    return new_list;
}

/* @Brief: allocates and returns new node
 * @Param: tag_id, value and type
 * @Return: new node on success and null on failure
 */
data_node_t *data_node_create(uint16_t tag_id, data_value_t value, data_type_t type)
{
    /* Allocation freed in data_list_free */
    data_node_t *new_node = (data_node_t*)malloc(sizeof(data_node_t));
    if (!new_node)
    {
        return NULL;
    }
    new_node->tag_id = tag_id;
    new_node->value = value;
    new_node->type = type;
    new_node->next = NULL;
    new_node->list = NULL;

    return new_node;
}

/* @Brief: appends node to list
 * @Param: list and node
 */
void data_list_append(data_list_t *self, data_node_t *node)
{
    if (self == NULL || node == NULL) return;
    if (self->head == NULL)
    {
        self->head = node;
        self->tail = node;
    }
    else
    {
        self->tail->next = node;
        self->tail = node;
    }

    self->count++;
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
