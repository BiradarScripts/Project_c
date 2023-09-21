#include<stdio.h>
#include<string.h>
#include "../include/print.h" 
#include "../include/variable.h"

void print_variable(char *token)

{

    char * tok = strtok(token, " ");

    tok = strtok(NULL, " ");

    char *var_name = tok;

    int val = get_variable_value(var_name);

    printf("%d\n", val);

}