#ifndef ZAPPY_SERVER_STOCK_H_
    #define ZAPPY_SERVER_STOCK_H_

typedef struct {
    unsigned int food;
    unsigned int linemate;
    unsigned int deraumere;
    unsigned int sibur;
    unsigned int mendiane;
    unsigned int phiras;
    unsigned int thystame;
} stock_t;

void stock_initialize_client(stock_t *stock);
void stock_initialize_world(stock_t *stock);

#endif
