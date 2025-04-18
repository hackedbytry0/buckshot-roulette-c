#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>
#include <stdint.h>

/** 
 *  Enum representing different types of items in the game.
 *
 *  Each item type corresponds to a specific object that a player can possess.
 */
typedef enum {
    CIGARETTES,   /**< A package of cigarettes */
    BEER,         /**< A beer can */
    KNIFE,        /**< A knive */
    GLASS,        /**< A magnifying glass */
    HANDCUFFS      /**< A pair of handcuffs */
} ItemType;

/** 
 *  Struct representing an item in the game.
 *
 *  This struct contains the properties of a game item, including its type,
 *  damage, and the number of turns it takes before it can be used again.
 */
typedef struct {
    ItemType  type;           /**< Type of the item */
    int8_t    damage;         /**< Amount of damage the item inflicts, if applicable */
    uint8_t   turnsWaiting;   /**< The number of turns it makes the user wait */
} Item;

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
const Item* createItem(ItemType type, int8_t damage, uint8_t turnsWaiting);

#endif
