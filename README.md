# 🧪 Libunit Test Framework

<div align="center">
  <img src="https://img.shields.io/badge/language-C-blue.svg" alt="Language: C">
  <img src="https://img.shields.io/badge/license-42-brightgreen.svg" alt="License: 42">
  <img src="https://img.shields.io/badge/status-stable-green.svg" alt="Status: Stable">
</div>

## 📋 Overview

Libunit is a lightweight unit testing framework for C programs, inspired by modern testing libraries but designed with simplicity and minimal dependencies in mind. It provides an easy way to write and run unit tests for C code, with support for test isolation, detailed error reporting, and comprehensive result summaries.

## ✨ Features

- **🔄 Simple API**: Easy-to-use interface for defining and running tests
- **🛡️ Process Isolation**: Each test runs in its own process for improved stability
- **🚨 Signal Handling**: Properly detects and reports segmentation faults, bus errors, and other signals
- **🎨 Colorized Output**: Visual differentiation between passing, failing, and crashing tests
- **📊 Detailed Reporting**: Provides clear summaries of test results
- **🧩 Modular Design**: Easily extend with new test suites

## 🏗️ Project Structure

```
libunit/
├── includes/         # Header files
│   ├── libunit.h     # Main framework header
│   └── colors.h      # Color definitions for output
├── srcs/             # Framework source code
│   ├── launch_tests.c # Test runner implementation
│   └── load_test.c   # Test registration functionality
├── tests/            # Test suites
│   ├── test_launchers.h  # Test launcher declarations
│   ├── strlen/       # strlen test suite
│   ├── strchr/       # strchr test suite
│   └── atoi/         # atoi test suite
├── main.c            # Example main program
└── Makefile          # Build system
```

## 🚀 Getting Started

### Building the Framework

```bash
make
```

This will compile the framework and all test suites, producing the `libunit` executable.

### Running the Tests

```bash
./libunit
```

### Example Output

When you run the tests, you'll see output similar to this:

```
==== LIBUNIT TESTS ====

STRLEN:
[OK]  :Basic test
[OK]  :Empty string test

2/2 tests passed.

STRCHR:
[OK]  :Basic test
[OK]  :Character not found test
[OK]  :Null terminator test

3/3 tests passed.

ATOI:
[OK]  :Positive number test
[OK]  :Negative number test
[OK]  :Zero test
[OK]  :Space test
[OK]  :Plus sign test

5/5 tests passed.

All tests passed!
```

If there are failures, they will be highlighted like this:

```
STRLEN:
[OK]  :Basic test
[KO]  :Empty string test

1/2 tests passed.

Some tests failed!
```

Crashes are also detected and reported:

```
[SEGV] :Test with segmentation fault
[BUSE] :Test with bus error
[ABRT] :Test with abort signal
```

## 📝 Creating New Tests

### 1. Create a test file

Create a new C file for your test:

```c
/* filepath: tests/my_function/01_my_function_test.c */
#include "libunit.h"
#include "libft.h"

int my_function_test(void)
{
    if (my_function(input) == expected_output)
        return (0);  // Success
    else
        return (-1); // Failure
}
```

### 2. Create or update the test header file

```c
/* filepath: tests/my_function/my_function_tests.h */
#ifndef MY_FUNCTION_TESTS_H
# define MY_FUNCTION_TESTS_H

int my_function_test(void);
// Add more test function prototypes

#endif
```

### 3. Create a launcher function

```c
/* filepath: tests/my_function/00_my_function_launcher.c */
#include "libunit.h"
#include "my_function_tests.h"

int my_function_launcher(void)
{
    t_unit_test *test_list;

    test_list = NULL;
    ft_printf("MY_FUNCTION:\n");
    load_test(&test_list, "Basic functionality test", &my_function_test);
    // Add more tests...
    return (launch_tests(test_list));
}
```

### 4. Update the test_launchers.h file

```c
/* Add your test launcher prototype */
int my_function_launcher(void);
```

### 5. Update main.c to include your new test suite

```c
/* Add your launcher to main */
result |= my_function_launcher();
```

### 6. Update the Makefile

Add your test files to the SRCS list in the Makefile:

```make
SRCS += tests/my_function/00_my_function_launcher.c \
        tests/my_function/01_my_function_test.c
```

## 🔍 Test Function Return Values

- **0**: Test passed ✅
- **-1**: Test failed ❌
- Other signals (like SIGSEGV) are caught by the framework 💥

## 📊 Test Launcher Return Values

- **0**: All tests in the suite passed ✅
- **-1**: At least one test in the suite failed ❌

## 🔄 Test Lifecycle

1. A test is registered with `load_test()` function
2. When `launch_tests()` is called:
   - For each test, a child process is created with `fork()`
   - The test function runs in the child process
   - The parent process waits for the child to complete
   - Results are collected and displayed
3. The process continues for each test in the list

## 📦 Dependencies

- **libft**: Basic utility functions
- **ft_printf**: Custom printf implementation

## 📜 License

This project is part of the curriculum at 42 School and follows their usage guidelines.
