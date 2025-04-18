#include "../include/item.h"
#include "../include/player.h"

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
const struct Item* createItem(ItemType type, int8_t damage, uint8_t turnsWaiting) {
    struct Item* item = malloc(sizeof(struct Item));
    if (item == NULL) {
        fprintf(stderr, "ERROR: Failed to allocate memory for item.\n");
        return NULL;
    }

    item->type = type;
    item->damage = damage;
    item->turnsWaiting = turnsWaiting;

    return item;
}

/**
 *  Uses a specific item from the player's inventory.
 *
 *  This function performs the item's action (e.g., dealing damage, applying effects)
 *  and may modify the player's state accordingly. The behavior depends on the item's type.
 *
 *  @param player Pointer to the Player who is using the item.
 *  @param item Pointer to the Item to be used.
 */
void useItem(struct Player* player, struct Item* item) {
    switch (item->type) {
        case CIGARETTES:
            break;
        case BEER:
            break;
        case KNIFE:
            break;
        case GLASS:
            break;
        case HANDCUFFS:
            break;
    }
}
