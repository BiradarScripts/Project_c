#include <stdio.h>
#include "../include/interpreter.h"

int main() {
   char code[] =
        "int x = 10;\n"
        "int y = 5;\n"
        "int z = x + y;\n"
        "print z;\n"
        "if (z > 30) {\n"
        "    int w = 20;\n"
        "    print w;\n"
        "};\n";
    execute_c_minus_minus(code);
    return 0;
}
