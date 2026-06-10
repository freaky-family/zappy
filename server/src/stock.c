#include "stock.h"

static void stock_init(stock_t *stock)
{
    stock->food = 0;
    stock->linemate = 0;
    stock->deraumere = 0;
    stock->sibur = 0;
    stock->mendiane = 0;
    stock->phiras = 0;
    stock->thystame = 0;
}

void stock_initialize_client(stock_t *stock)
{
    stock_init(stock);
    stock->food = 10;
}

void stock_initialize_world(stock_t *stock)
{
    stock_init(stock);
}
