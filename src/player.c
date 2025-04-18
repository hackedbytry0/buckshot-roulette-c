#include "../include/player.h"

/**
 *  Creates and initializes a new player with the given name.
 *  Allocates memory on the heap.
 *
 *  @param name The name of the player (must be NAME_SIZE or smaller).
 *  @return A pointer to the newly created Player, or NULL on failure.
 */
Player* createPlayer(char name[NAME_SIZE]) {
    Player* player = malloc(sizeof(Player));
    if (player == NULL) {
        fprintf(stderr, "ERROR: Failed to allocate memory for player.\n");
        return NULL;
    }

    strcpy(player->name, name);
    player->health = 0;
    player->turnsWaiting = 0;
    player->itemCount = 0;
    player->maxItems = 0;
    player->items = NULL;

    return player;
}

/**
 *  Adds an item to the player's inventory.
 *
 *  If this is the first item being added (i.e., new level), it allocates memory 
 *  for the item array based on `player->maxItems`. If the inventory is full,
 *  the function prints and error message and does nothing.
 *
 *  @param player Pointer to the Player whose inventory will be updated.
 *  @param item Pointer to the Item to be added (copied into the inventory).
 */
void addPlayerItem(Player* player, Item* item) {
    // New level
    if (player->items == NULL) {
        player->items = malloc(player->maxItems * sizeof(Item));
        if (player->items == NULL) {
            fprintf(stderr, "ERROR: Failed to allocate memory for player items.\n");
            return;
        }
    }

    // Inventory full
    if (player->itemCount >= player->maxItems) {
        printf("Looks like you don't have room for more items...\n");
        return;
    }

    player->items[player->itemCount++] = *item;
    printf("Item added!\n");
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
void usePlayerItem(Player* player, Item* item) {
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

/**
 *  Frees the memory used by the player's item inventory and resets related counters.
 *
 *  This function should be called when a level ends.
 *
 *  @param player Pointer to the Player whose inventory will be cleared.
 */
void cleanPlayerItems(Player* player) {
    free(player->items);
    player->items = NULL;
    player->itemCount = 0;
    player->maxItems = 0;
}
