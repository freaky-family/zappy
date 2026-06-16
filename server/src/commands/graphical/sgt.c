#include "server.h"
#include "messages.h"
#include <stdio.h>

void command_graphic_sgt(server_t *server)
{
    dprintf(*CLIENT->fd, "sgt %d" ZMSG_END_SEQ, server->freq);
}
