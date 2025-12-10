# Norminette-inspired C++ Linter & Formatter

This repository provides configuration files and Makefile snippets to enforce style checks and automatic formatting for **42 C++ assignments**.

It is designed to simulate a "C++ Norminette" by enforcing **C++98 compliance**, **Orthodox Canonical Form**, and strict naming conventions based on Google Style.

## Style & Coding Rules

The configuration enforces the following rules using `clang-format` and `clang-tidy`:

### 1\. General Formatting

| Item | Value | Note |
| :--- | :--- | :--- |
| **Standard** | C++03 | Treated as C++98 compatible |
| **Indent Width** | 2 spaces | No tabs allowed |
| **Column Limit** | 80 chars | Hard limit |
| **Pointer Alignment** | Left | `int* n` (Not `int *n`) |
| **Include Sorting** | True | Headers are sorted automatically |

### 2\. Linting & Complexity (C++98)

| Item | Value | Note |
| :--- | :--- | :--- |
| **Function Length** | **Max 45 lines** | C++ allows slightly longer functions than C |
| **Orthodox Canonical Form** | **Required** | Classes must have default constructor, copy constructor, assignment operator, and destructor |
| **C++11 Features** | **Forbidden** | Pedantic C++98 check (No `auto`, `nullptr`, etc.) |

### 3\. Naming Conventions

| Type | Case Style | Example |
| :--- | :--- | :--- |
| **Classes** | UpperCamelCase | `class MyClass` |
| **Functions** | UpperCamelCase | `void MyFunction()` |
| **Variables** | snake\_case | `int my_variable;` |
| **Private Members** | snake\_case + `_` | `int private_member_;` |
| **Struct Members** | snake\_case | `int struct_member;` |
| **Global Constants** | `k` + CamelCase | `const int kGlobalConstant = 42;` |

-----

## Setup & Usage

### 1\. Install Dependencies

Install the required tools (`clang-format` and `clang-tidy`).

```bash
make install
```

### 2\. Configure Your Project

Copy the `.clang-format` and `.clang-tidy` files provided in this repository to the **root directory** of your project.

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
