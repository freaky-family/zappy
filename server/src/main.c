#include "args.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    args_t *args = parse_args(argc, argv);

    if (args == NULL || args->valid == false) {
        args_free(args);
        return 84;
    }
    printf("Valid arguments!\n");
    args_free(args);
    return 0;
}
