#ifndef PLAYER_H
#define PLAYER_H

#define NAME_SIZE 7   // 6 characters + null character

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/** 
 *  Struct representing an item in the game.
 *
 *  This struct contains the properties of a game item, including its type,
 *  damage, and the number of turns it takes before it can be used again.
 */
struct Item;  // Forward declaration

/**
 *  Represents a player in the game.
 *
 *  This structure stores basic information about a player, including their name,
 *  current health, the number of turns they must wait before acting, and their inventory.
 */
struct Player {
    char          name[NAME_SIZE];    /**< The player's name */
    uint8_t       health;             /**< The player's current health */
    uint8_t       turnsWaiting;       /**< Number of turns the player must wait before acting */
    uint8_t       itemCount;          /**< Number of items the player has in the inventory */
    uint8_t       maxItems;           /**< Maximum number of items the player can store */
    struct Item*  items;              /**< Dynamically allocated array of items (i.e., inventory) */
};
typedef struct Player Player;

/**
 *  Creates and initializes a new player with the given name.
 *
 *  @param name The name of the player (must be NAME_SIZE or smaller).
 *  @return A pointer to the newly created Player, or NULL on failure.
 */
struct Player* createPlayer(char name[NAME_SIZE]);

/**
 *  Adds an item to the player's inventory.
 *
 *  @param player Pointer to the Player whose inventory will be updated.
 *  @param item Pointer to the Item to be added (copied into the inventory).
 */
void addPlayerItem(struct Player* player, struct Item* item);

/**
 *  Uses a specific item from the player's inventory.
 *
 *  This function performs the item's action (e.g., dealing damage, applying effects)
 *  and may modify the player's state accordingly. The behavior depends on the item's type.
 *
 *  @param player Pointer to the Player who is using the item.
 *  @param item Pointer to the Item to be used.
 */
void usePlayerItem(struct Player* player, struct Item* item);

/**
 *  Frees the memory used by the player's item inventory and resets related counters.
 *
 *  This function should be called when a level ends.
 *
 *  @param player Pointer to the Player whose inventory will be cleared.
 */
void cleanPlayerItems(struct Player* player);

#endif
