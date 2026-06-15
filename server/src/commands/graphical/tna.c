#include "server.h"
#include "messages.h"
#include <stdio.h>

void command_graphic_tna(server_t *server)
{
    for (size_t i = 0; i < server->teams->amount; i++) {
        dprintf(*CLIENT->fd, "tna %s" ZMSG_END_SEQ, server->teams->elems[i]->name);
    }
}
