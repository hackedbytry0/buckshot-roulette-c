#include "../include/item.h"

/**
 *  Creates a new item with the given properties.
 *
 *  Allocates memory on the heap for the item.
 *
 *  @param type The type of the item (e.g., weapon, shield).
 *  @param damage The amount of damage the item inflicts.
 *  @param turnsWaiting The number of turns required before the item can be used again.
 *  @return A pointer to the newly created Item, or NULL if allocation fails.
 */
const Item* createItem(ItemType type, int8_t damage, uint8_t turnsWaiting) {
    Item* item = malloc(sizeof(Item));
    if (item == NULL) {
        fprintf(stderr, "ERROR: Failed to allocate memory for item.\n");
        return NULL;
    }

    item->type = type;
    item->damage = damage;
    item->turnsWaiting = turnsWaiting;

    return item;
}
