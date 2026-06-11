#include "clients.h"
#include "commands.h"
#include "server.h"
#include <stdio.h>
#include <time.h>

static float time_since_start(clock_t start)
{
    clock_t current_clock = clock();
    return (double)(current_clock - start) / CLOCKS_PER_SEC;
}

static void verify_frequency(server_t *server, client_data_t *data)
{   
    double time_elapsed = time_since_start(data->command_start);

    // TODO remove, this is for future debug (no command are implemented so it cannot be tested)
    printf("fd: %d, command current duration: %f (in seconds)\n", *data->fd, time_elapsed);
    if (time_elapsed >= (double)data->command->time_limit / (double)server->freq) {
        data->command->function(server);
        data->is_command_running = false;
        // TODO maybe change this
        data->command = NULL;
    }
}

void frequency_handling(server_t *server)
{
    for (size_t i = 0; i < server->clients->amount; i++) {
        if (server->clients->elems[i]->is_command_running == true) {
            verify_frequency(server, server->clients->elems[i]);
        }
    }
}

void calculate_timeout(server_t *server)
{
    bool has_timeout = false;

    for (size_t i = 0; i < server->clients->amount; i++) {
        if (server->clients->elems[i]->is_command_running == true) {
            double time_elapsed = time_since_start(server->clients->elems[i]->command_start);
            double time_until_end = ((double)server->clients->elems[i]->command->time_limit / (double)server->freq) - time_elapsed;

            // Remove a quarter of the poll timeout to make sure it works
            int poll_timeout = (int)(time_until_end * 1000);
            poll_timeout = poll_timeout - poll_timeout / 4;

            if (has_timeout == false) {
                server->poll_timeout = poll_timeout;
                has_timeout = true;
            } else if (poll_timeout < server->poll_timeout) {
                server->poll_timeout = poll_timeout;
            }
        }
    }
    if (has_timeout == false) {
        server->poll_timeout = DEFAULT_POLL_TIMEOUT;
    }

}
