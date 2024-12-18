/*
Copyright © 2024 Rudolf Farkas @rudifa rudi.farkas@gmail.com
*/

#include <iostream>

int main()
{
    const char *code[] = {
        "#include <iostream>",
        "",
        "int main() {",
        "    const char* code[] = {",
        "        ", // Placeholder for source code
        "    };",
        "    for (int i = 0; i < 4; ++i)",
        "        std::cout << code[i] << std::endl;",
        "    for (int i = 0; i < sizeof(code) / sizeof(code[0]); ++i)",
        "        std::cout << \"        \\\"\" << code[i] << \"\\\",\" << std::endl;",
        "    for (int i = 4; i < sizeof(code) / sizeof(code[0]); ++i)",
        "        std::cout << code[i] << std::endl;",
        "    return 0;",
        "}"};

    for (int i = 0; i < 4; ++i)
        std::cout << code[i] << std::endl;

    for (int i = 0; i < sizeof(code) / sizeof(code[0]); ++i)
        std::cout << "        \"" << code[i] << "\"," << std::endl;

    for (int i = 4; i < sizeof(code) / sizeof(code[0]); ++i)
        std::cout << code[i] << std::endl;

    return 0;
}
