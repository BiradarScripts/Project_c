#include <stdio.h>
#include <stdlib.h>
#include "../include/variable.h"
#include "../include/arithmetic.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

struct data
{
    char *var_name;
    int *value;
};

struct data s[1000];

void assign_variable(char *token)
{
    for (int i = 0; i < 1000; i++)
    {
        if (s[i].var_name && !s[i].value)
        {

            s[i].value = (int *)malloc(1000*sizeof(int));

            char *token_copy = strdup(token);
            char *var_token = strtok(token_copy, " ");
            char *var1_name=(char *)malloc(1000*sizeof(char));;
            char *var2_name=(char *)malloc(1000*sizeof(char));;
            char *op_name;

            for (int j = 0; j < 6; j++)
            {
                if (j == 3)
                {
                    int is_numeric = 1;
                    for (int k = 0; var_token[k] != '\0'; k++)
                    {
                        if (!isdigit(var_token[k]))
                        {
                            is_numeric = 0; 
                            break;          
                        }
                    }
                    if (is_numeric)
                    {
                        *s[i].value = atoi(var_token);
                        break;
                    }
                    else
                    {
                        var1_name=strdup(var_token);
                    }
                }
                if (j == 4)
                {
                    op_name=strdup(var_token);
                }
                if (j == 5)
                {
                    var2_name=strdup(var_token);
                    *s[i].value = perform_arithmetic(get_variable_value(var1_name), op_name, get_variable_value(var2_name));
                }
                var_token = strtok(NULL, " ");
            }
        }
    }
}

void create_variable(char *token)
{
    for (int i = 0; i < 1000; i++)
    {
        if (!s[i].var_name)
        {
            s[i].var_name = (char *)malloc(1000*sizeof(char));

            char *token_copy = strdup(token);
            char *var_token = strtok(token_copy, " ");

            for (int j = 0; j < 2; j++)
            {
                if (j == 1)
                {
                    strcpy(s[i].var_name, var_token);
                    break;
                }
                var_token = strtok(NULL, " ");
            }
            if (s[i].var_name)
            {
                assign_variable(token);
                break;
            }
        }
    }
}

int get_variable_value(char *var_name)
{
    for (int i = 0; i < 1000; i++)
    {
        if (s[i].var_name && strcmp(s[i].var_name, var_name) == 0)
        {
            return *s[i].value;   
        }
    }
    return -1;
}

