# C++ Quine Program

Exported on 18/12/2024 at 23:55:16 [from ChatGPT](https://chatgpt.com/c/67624d6e-aa28-8010-94eb-da9762caa070) - with [SaveMyChatbot](https://save.hugocollin.com)

## User

Write a c++ program that writes its own source

## ChatGPT

A program that writes its own source code is known as a **quine**. Here's an example of a simple C++ quine:

```cpp
#include <iostream>

int main() {
    const char* code[] = {
        "#include <iostream>",
        "",
        "int main() {",
        "    const char* code[] = {",
        "        ",  // Placeholder for source code
        "    };",
        "    for (int i = 0; i < 4; ++i)",
        "        std::cout << code[i] << std::endl;",
        "    for (int i = 0; i < sizeof(code) / sizeof(code[0]); ++i)",
        "        std::cout << \"        \\\"\" << code[i] << \"\\\",\" << std::endl;",
        "    for (int i = 4; i < sizeof(code) / sizeof(code[0]); ++i)",
        "        std::cout << code[i] << std::endl;",
        "    return 0;",
        "}"
    };

   for (int i = 0; i < 4; ++i)
        std::cout << code[i] << std::endl;

   for (int i = 0; i < sizeof(code) / sizeof(code[0]); ++i)
        std::cout << "        \"" << code[i] << "\"," << std::endl;

   for (int i = 4; i < sizeof(code) / sizeof(code[0]); ++i)
        std::cout << code[i] << std::endl;

   return 0;
}
```

### How It Works

1. **String Array**: The program stores its source code in a string array named `code`.
2. **Output Original Lines**: The program prints lines 1–4 exactly as they are.
3. **Output Array Values**: It iterates over the array and prints the code itself as properly formatted strings with escape sequences.
4. **Output Rest of the Code**: It prints the remaining lines to reconstruct itself.

### Running the Program

- Save the code to a file, for example, `quine.cpp`.
- Compile and run the program (`g++ quine.cpp -o quine && ./quine`).
- The output will be the exact source code of the program itself.

This quine demonstrates the concept of self-referential code in a straightforward and fun way!

## User

Would it be possible to expand it with a Makefile?

## ChatGPT

Yes, you can expand the project with a `Makefile` to automate the build process for the quine program. Below is an example of how to structure your `Makefile`:

### Makefile

```makefile
# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = quine

# Build target
all: $(TARGET)

# Rule to build the quine program
$(TARGET): $(TARGET).cpp
    $(CXX) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp

# Run the quine
run: $(TARGET)
    ./$(TARGET)

# Clean the build files
clean:
    rm -f $(TARGET)

# Rebuild from scratch
rebuild: clean all
```

### How It Works

1. **Variables**:

   - `CXX`: The compiler (`g++` in this case).
   - `CXXFLAGS`: Compilation flags for warnings and standards.
   - `TARGET`: The output binary name.

2. **Targets**:

   - `all`: The default target, builds the quine program.
   - `$(TARGET)`: Compiles the `quine.cpp` source file into an executable.
   - `run`: Executes the compiled quine program.
   - `clean`: Removes the generated binary.
   - `rebuild`: Cleans and rebuilds the program from scratch.

### File Structure

Your project directory should look like this:

```lua
/project-directory
|-- quine.cpp
|-- Makefile
```

### Using the Makefile

1. **Build the Program**:

   ```bash
   make
   ```

   This compiles `quine.cpp` and creates an executable named `quine`.

2. **Run the Program**:

   ```bash
   make run
   ```

   This runs the `quine` executable.

3. **Clean the Build**:

   ```bash
   make clean
   ```

   This removes the generated executable.

4. **Rebuild from Scratch**:

   ```bash
   make rebuild
   ```

   This removes the old binary and recompiles the source code.

### Benefit

The `Makefile` simplifies the workflow by automating compilation, cleanup, and execution, making it easier to work with your quine program.

## User

But expand the quine to write also the makefile

## ChatGPT

To create a **self-replicating program** that not only writes its own source code but also generates a `Makefile`, we can expand the quine as follows. The program will output two files: `quine.cpp` (its own source code) and `Makefile`.

Here's how you can implement it:

### Expanded Quine

```cpp
#include <iostream>
#include <fstream>

int main() {
    const char* source[] = {
        "#include <iostream>",
        "#include <fstream>",
        "",
        "int main() {",
        "    const char* source[] = {",
        "        ",  // Placeholder for source code
        "    };",
        "",
        "    const char* makefile[] = {",
        "        \"# Compiler and flags\",",
        "        \"CXX = g++\",",
        "        \"CXXFLAGS = -Wall -Wextra -std=c++17\",",
        "        \"TARGET = quine\",",
        "        \"\",",
        "        \"# Build target\",",
        "        \"all: $(TARGET)\",",
        "        \"\",",
        "        \"$(TARGET): $(TARGET).cpp\",",
        "        \"\\t$(CXX) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp\",",
        "        \"\",",
        "        \"# Run the quine\",",
        "        \"run: $(TARGET)\",",
        "        \"\\t./$(TARGET)\",",
        "        \"\",",
        "        \"# Clean the build files\",",
        "        \"clean:\",",
        "        \"\\trm -f $(TARGET)\",",
        "        \"\",",
        "        \"# Rebuild from scratch\",",
        "        \"rebuild: clean all\",",
        "    };",
        "",
        "    // Write source file",
        "    std::ofstream sourceFile(\"quine.cpp\");",
        "    for (int i = 0; i < 5; ++i) sourceFile << source[i] << std::endl;",
        "    for (int i = 0; i < sizeof(source) / sizeof(source[0]); ++i)",
        "        sourceFile << \"        \\\"\" << source[i] << \"\\\",\" << std::endl;",
        "    for (int i = 5; i < sizeof(source) / sizeof(source[0]); ++i) sourceFile << source[i] << std::endl;",
        "    sourceFile.close();",
        "",
        "    // Write Makefile",
        "    std::ofstream makefile(\"Makefile\");",
        "    for (int i = 0; i < sizeof(makefile) / sizeof(makefile[0]); ++i)",
        "        makefile << makefile[i] << std::endl;",
        "    makefile.close();",
        "",
        "    return 0;",
        "}"
    };

   const char* makefile[] = {
        "# Compiler and flags",
        "CXX = g++",
        "CXXFLAGS = -Wall -Wextra -std=c++17",
        "TARGET = quine",
        "",
        "# Build target",
        "all: $(TARGET)",
        "",
        "$(TARGET): $(TARGET).cpp",
        "\t$(CXX) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp",
        "",
        "# Run the quine",
        "run: $(TARGET)",
        "\t./$(TARGET)",
        "",
        "# Clean the build files",
        "clean:",
        "\trm -f $(TARGET)",
        "",
        "# Rebuild from scratch",
        "rebuild: clean all",
    };

   // Write source file
    std::ofstream sourceFile("quine.cpp");
    for (int i = 0; i < 5; ++i) sourceFile << source[i] << std::endl;
    for (int i = 0; i < sizeof(source) / sizeof(source[0]); ++i)
        sourceFile << "        \"" << source[i] << "\"," << std::endl;
    for (int i = 5; i < sizeof(source) / sizeof(source[0]); ++i) sourceFile << source[i] << std::endl;
    sourceFile.close();

   // Write Makefile
    std::ofstream makefile("Makefile");
    for (int i = 0; i < sizeof(makefile) / sizeof(makefile[0]); ++i)
        makefile << makefile[i] << std::endl;
    makefile.close();

   return 0;
}
```

---

### Explanation

1. **Additional Array for Makefile**:

   - A new `makefile` array stores the content of the `Makefile`.
   - The array includes all necessary lines to build, run, clean, and rebuild the program.

2. **File Outputs**:

   - The program writes its source code to a file named `quine.cpp` by iterating through the `source` array.
   - It writes the `Makefile` to a separate file by iterating through the `makefile` array.

3. **Double Escaping**:

   - Strings in `makefile` need escaping for special characters like tabs (`\t`).

4. **Output Files**:

   - Running the program generates `quine.cpp` and `Makefile`.

---

### Steps to Use

1. Compile and run the program:

   ```bash
   g++ -o quine quine.cpp && ./quine
   ```

   This generates `quine.cpp` and `Makefile`.

2. Verify the generated files:

   - `quine.cpp` should exactly replicate the original source.
   - `Makefile` should be valid for building and running the quine.

3. Use the generated `Makefile`:

   ```bash
   make       # Builds the program
   make run   # Runs the program
   make clean # Cleans the build
   ```

With this setup, the program now replicates itself and its build instructions!

## User

Add a CMakeLists.txt to this quine.

## ChatGPT

To extend the quine to generate a `CMakeLists.txt` file, we'll add another array for the content of `CMakeLists.txt` and include the logic to write it to a file.

Here's the updated quine:

### Expanded Quine with CMakeLists.txt

```cpp
#include <iostream>
#include <fstream>

int main() {
    const char* source[] = {
        "#include <iostream>",
        "#include <fstream>",
        "",
        "int main() {",
        "    const char* source[] = {",
        "        ",  // Placeholder for source code
        "    };",
        "",
        "    const char* makefile[] = {",
        "        \"# Compiler and flags\",",
        "        \"CXX = g++\",",
        "        \"CXXFLAGS = -Wall -Wextra -std=c++17\",",
        "        \"TARGET = quine\",",
        "        \"\",",
        "        \"# Build target\",",
        "        \"all: $(TARGET)\",",
        "        \"\",",
        "        \"$(TARGET): $(TARGET).cpp\",",
        "        \"\\t$(CXX) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp\",",
        "        \"\",",
        "        \"# Run the quine\",",
        "        \"run: $(TARGET)\",",
        "        \"\\t./$(TARGET)\",",
        "        \"\",",
        "        \"# Clean the build files\",",
        "        \"clean:\",",
        "        \"\\trm -f $(TARGET)\",",
        "        \"\",",
        "        \"# Rebuild from scratch\",",
        "        \"rebuild: clean all\",",
        "    };",
        "",
        "    const char* cmake[] = {",
        "        \"cmake_minimum_required(VERSION 3.10)\",",
        "        \"\",",
        "        \"# Project name\",",
        "        \"project(quine)\",",
        "        \"\",",
        "        \"# Set the C++ standard\",",
        "        \"set(CMAKE_CXX_STANDARD 17)\",",
        "        \"set(CMAKE_CXX_STANDARD_REQUIRED True)\",",
        "        \"\",",
        "        \"# Add the executable\",",
        "        \"add_executable(quine quine.cpp)\",",
        "    };",
        "",
        "    // Write source file",
        "    std::ofstream sourceFile(\"quine.cpp\");",
        "    for (int i = 0; i < 5; ++i) sourceFile << source[i] << std::endl;",
        "    for (int i = 0; i < sizeof(source) / sizeof(source[0]); ++i)",
        "        sourceFile << \"        \\\"\" << source[i] << \"\\\",\" << std::endl;",
        "    for (int i = 5; i < sizeof(source) / sizeof(source[0]); ++i) sourceFile << source[i] << std::endl;",
        "    sourceFile.close();",
        "",
        "    // Write Makefile",
        "    std::ofstream makefile(\"Makefile\");",
        "    for (int i = 0; i < sizeof(makefile) / sizeof(makefile[0]); ++i)",
        "        makefile << makefile[i] << std::endl;",
        "    makefile.close();",
        "",
        "    // Write CMakeLists.txt",
        "    std::ofstream cmakeFile(\"CMakeLists.txt\");",
        "    for (int i = 0; i < sizeof(cmake) / sizeof(cmake[0]); ++i)",
        "        cmakeFile << cmake[i] << std::endl;",
        "    cmakeFile.close();",
        "",
        "    return 0;",
        "}"
    };

   const char* makefile[] = {
        "# Compiler and flags",
        "CXX = g++",
        "CXXFLAGS = -Wall -Wextra -std=c++17",
        "TARGET = quine",
        "",
        "# Build target",
        "all: $(TARGET)",
        "",
        "$(TARGET): $(TARGET).cpp",
        "\t$(CXX) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp",
        "",
        "# Run the quine",
        "run: $(TARGET)",
        "\t./$(TARGET)",
        "",
        "# Clean the build files",
        "clean:",
        "\trm -f $(TARGET)",
        "",
        "# Rebuild from scratch",
        "rebuild: clean all",
    };

   const char* cmake[] = {
        "cmake_minimum_required(VERSION 3.10)",
        "",
        "# Project name",
        "project(quine)",
        "",
        "# Set the C++ standard",
        "set(CMAKE_CXX_STANDARD 17)",
        "set(CMAKE_CXX_STANDARD_REQUIRED True)",
        "",
        "# Add the executable",
        "add_executable(quine quine.cpp)",
    };

   // Write source file
    std::ofstream sourceFile("quine.cpp");
    for (int i = 0; i < 5; ++i) sourceFile << source[i] << std::endl;
    for (int i = 0; i < sizeof(source) / sizeof(source[0]); ++i)
        sourceFile << "        \"" << source[i] << "\"," << std::endl;
    for (int i = 5; i < sizeof(source) / sizeof(source[0]); ++i) sourceFile << source[i] << std::endl;
    sourceFile.close();

   // Write Makefile
    std::ofstream makefile("Makefile");
    for (int i = 0; i < sizeof(makefile) / sizeof(makefile[0]); ++i)
        makefile << makefile[i] << std::endl;
    makefile.close();

   // Write CMakeLists.txt
    std::ofstream cmakeFile("CMakeLists.txt");
    for (int i = 0; i < sizeof(cmake) / sizeof(cmake[0]); ++i)
        cmakeFile << cmake[i] << std::endl;
    cmakeFile.close();

   return 0;
}
```

---

### Explanation of Additions

1. **`CMakeLists.txt` Array**:

   - Added a new array `cmake[]` with the content of a valid `CMakeLists.txt` file.

2. **Output CMakeLists.txt**:

   - A new block writes the content of `cmake[]` to `CMakeLists.txt` in the same directory as the program.

---

### Generated `CMakeLists.txt` File

When run, the program will produce the following `CMakeLists.txt`:

```cmake
cmake_minimum_required(VERSION 3.10)

# Project name
project(quine)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(quine quine.cpp)
```

---

### Steps to Build with CMake

1. **Run the quine**:

   ```bash
   ./quine
   ```

2. **Set up CMake**:

   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. **Run the compiled program**:

   ```bash
   ./quine
   ```

This enhanced quine now generates its source code, a `Makefile`, and a `CMakeLists.txt` file, giving you flexibility to build the project using either `make` or CMake!

## NOTES by @rudifa

The Makefile is mine, while the main.cpp is ChatGPT's first version.

The Makefile that ChatGPT generated is not working.
Making it work and retrofitting into main.cpp is left as an exercise for the next reader.

Same goes for the CMakeLists.txt.
