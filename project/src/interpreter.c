#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/variable.h"
#include "../include/condition.h"
#include "../include/print.h"

void execute_c_minus_minus(char* input_code){
    char *tok_arr[1000];
    char* code_copy = strdup(input_code);
    char* token = strtok(code_copy, ";\n");
    int tok_count = 0;
    while (token != NULL) {
        tok_arr[tok_count++] = token;
        token = strtok(NULL, ";\n");
    }
    
    for (int i = 0; i < tok_count; i++)
    {
        char *token = tok_arr[i];
        int if_flag = 0;        

        if (strstr(token, "if") || if_flag==1)
        {
            char *code = strtok(token, " ");
            int m = 0, v1, v2;
            char *op;
            while (strcmp(code, "{") != 0)
            {
                m++;
                if (m==2)     
                {
                    int j = 1;
                    if (isdigit(code[j]))
                    {
                        char v1_val[100] = "";
                        while (code[j] != '\0')
                        {
                            v1_val[j-1] = code[j];
                            j++;
                        }
                        v1 = atoi(v1_val);
                    }
                    else
                    {
                        char v1_name[100] = "";
                        while (code[j] != '\0')
                        {
                            v1_name[j-1] = code[j];
                            j++;
                        }
                        v1 = get_variable_value(v1_name);
                    }
                }
                else if (m==3)
                {
                    op = code;
                }
                else if (m==4)
                {
                    int j = 1;
                    if (isdigit(code[j]))
                    {
                        char v2_val[100] = "";
                        while (code[j] != '\0')
                        {
                            v2_val[j-1] = code[j];
                            j++;
                        }
                        v2 = atoi(v2_val);
                    }
                    else
                    {
                        char v2_name[100] = "";
                        while (code[j] != ')')
                        {
                            v2_name[j-1] = code[j];
                            j++;
                        }
                        v2 = get_variable_value(v2_name);
                    }
                }
                code = strtok(NULL, " ");
            }
            int result = evaluate_condition(v1, op, v2);
            

            if (result == 0)
            {
               
                while (!strstr(tok_arr[i], "}"))
                {
                    strtok(NULL, " ");
                    i++;
                }
            }

            else
            {
                i++;
                char new_code[10000] = "";
                int new_code_idx = 0;
                while (!strstr(tok_arr[i], "}"))
                {
                    strcat(new_code, tok_arr[i]);
                    strcat(new_code, "\n");
                    strtok(NULL, " ");
                    i++;
                }
                execute_c_minus_minus(new_code);
            }
        }
        else if (strstr(token, "else if"))
        {
            break;
        }
        else if (strstr(token, "else"))
        {
            break;
        }
        else if (strstr(token, "print"))
        {
            print_variable(token);
        }
        else if (strstr(token, "int"))
        {
            create_variable(token);
        }
    }

    free(code_copy); 
}