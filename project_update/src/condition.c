#include <stdio.h>
#include <string.h>
#include "../include/condition.h"
#include <stdbool.h>

bool evaluate_condition(int x, char *op, int y) {
    if (strcmp(op, "==") == 0) { 
        return x == y;
    } else if (strcmp(op, "!=") == 0) {
        return x != y;
    } else if (strcmp(op, ">") == 0) {
        return x > y;
    } else if (strcmp(op, "<") == 0) {
        return x < y;
    } else if (strcmp(op, ">=") == 0) {
        return x >= y;
    } else if (strcmp(op, "<=") == 0) {
        return x <= y;
    } else {
        printf("Invalid operator: %s\n", op);
        return false;
    }
}