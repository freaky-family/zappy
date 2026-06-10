#include "world.h"
#include <stdlib.h>

world_t *world_init(unsigned int x, unsigned int y)
{
    world_t *world = calloc(1, sizeof(world_t));

    if (world == NULL)
        return NULL;
    world->x = x;
    world->y = y;
    world->tiles = calloc(x * y, sizeof(tile_t));
    if (world->tiles == NULL)
        return NULL;
    return world;
}

tile_t *world_generate_egg(world_t *world)
{
    tile_t *tile = NULL;
    int x = rand() % world->x;
    int y = rand() % world->y;

    while (world->tiles[x * (y + 1)].egg == true) {
        x = rand() % world->x;
        y = rand() % world->y;
    }
    tile = &world->tiles[x * (y + 1)];
    tile->egg = true;
    return tile;
}

void world_free(world_t *world)
{
    if (world->tiles)
        free(world->tiles);
    free(world);
}
