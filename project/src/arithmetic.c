#include<stdio.h>
#include "../include/arithmetic.h"
#include<string.h>

int perform_arithmetic(int x, char *op, int y)
{
    if (strcmp(op, "+") == 0)
    {
        return x + y;
    }
    else if (strcmp(op, "-") == 0)
    {
        return x - y;
    }
    else if (strcmp(op, "*") == 0)
    {
        return x * y;
    }
    else if (strcmp(op, "/") == 0)
    {
        return x / y;
    }
    else
    {
        printf("Invalid operator: %s\n", op);
        return 0;
    }
}