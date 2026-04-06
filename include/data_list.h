/* Brief: data storage header file
 *
 */

#ifndef DATA_LIST_H
#define DATA_LIST_H

#include <stdint.h>

typedef enum
{
    EXIF_TYPE_BYTE = 1,
    EXIF_TYPE_ASCII,
    EXIF_TYPE_SHORT,
    EXIF_TYPE_LONG,
    EXIF_TYPE_RATIONAL
} data_type_t;

typedef union
{
    uint32_t num;
    char *str;
    struct {
        uint32_t num;
        uint32_t den;
    } rational;
} data_value_t;

typedef struct data_list
{
    struct data_node *head;
    struct data_node *tail;
    uint32_t count;
} data_list_t;

typedef struct data_node
{
    uint16_t tag_id;
    data_type_t type;
    data_value_t value;

    data_list_t *list;
    struct data_node *next;
} data_node_t;

/* @Brief: creates list
 * @Return: new list or null
 */
data_list_t *data_list_create(void);

/* @Brief: creates a new node
 * @Param: tag_id, value and type
 * @Return: new node
 */
data_node_t *data_node_create(uint16_t tag_id, data_value_t value, data_type_t type);

/* @Brief: appends node to list
 * @Param: list and node
 */
void data_list_append(data_list_t *self, data_node_t *node);
/* @Brief: prints content of linked list
 * @Param: list
 */
void data_list_print(const data_list_t *list);

/* @Brief: frees list
 * @Param: pointer to list
 * @Return: 0 on success
 */
uint8_t data_list_free(data_list_t **list_ptr);

#endif /* DATA_LIST_H */
