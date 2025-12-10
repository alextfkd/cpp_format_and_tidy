# Norminette-inspired C++ Linter & Formatter

This repository provides configuration files and Makefile snippets to enforce style checks and automatic formatting for **42 C++ assignments** (C++98 standard).

It uses **Google Style** as a base but applies specific rules to maintain the spirit of 42's Norminette (originally for C).

## Formatting Rules (Current Specification)

The configuration is based on **Google Style** with the following modifications:

| Item | Value | Note |
| :--- | :--- | :--- |
| **Standard** | C++03 | Treated as C++98 compatible |
| **Indent Width** | 2 spaces | Follows Google Style |
| **Column Limit** | 80 chars | Same as Norminette |
| **Tab Usage** | Never | Spaces only |
| **Pointer Alignment** | Left | `int* n` (C++ style) |
| **Include Sorting** | True | Automatically sorts headers |

-----

## Setup & Usage

### 1\. Install Dependencies

Install the required tools (`clang-format` and `clang-tidy`) using the provided Makefile.

```bash
make install
```

*(Note: This executes `sudo apt install`. Adjust accordingly if you are using macOS/Homebrew.)*

### 2\. Configure Your Project

Copy the following configuration files to the **root directory** of your project:

  * `.clang-format`
  * `.clang-tidy`

### 3\. Update Your Makefile

Add the following rules to your project's `Makefile` to enable the linting commands:

```makefile
cppformat:
	clang-format -i *.cpp

hppformat:
	clang-format -i *.hpp

cpplint: cppformat
	clang-tidy --config-file=.clang-tidy --warnings-as-errors=* --quiet *.cpp -- -Wall -Wextra -Werror -std=c++98

hpplint: hppformat
	clang-tidy --config-file=.clang-tidy --warnings-as-errors=* --quiet *.hpp -- -Wall -Wextra -Werror -std=c++98

.PHONY: cppformat hppformat cpplint hpplint
```

### 4\. Run Linter

Use the following commands to automatically format your code and run static analysis:

  * **Check `.cpp` files:**

    ```bash
    make cpplint
    ```

  * **Check `.hpp` files:**

    ```bash
    make hpplint
    ```

-----

## Uninstall

To remove the tools from your system:

```bash
make uninstall
```