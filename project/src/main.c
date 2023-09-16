#include <stdio.h>
#include "../include/interpreter.h"

int main() {
   char code[] =
        "int h = 100;\n"
        "int w = 50;\n"
        "int z = h + w;\n"
        "print z;\n"
        "if (z > 10) {\n"
        "    int m = 20;\n"
        "    int k = 120;\n"
        "    int l = m - k\n"
        "    print l;\n"
        "};\n";
    execute_c_minus_minus(code);
    return 0;
}
