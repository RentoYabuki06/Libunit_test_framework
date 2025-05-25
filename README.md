Looking at your codebase and framework, I'll update the README to include information about the new logging functionality.

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
- **📝 Comprehensive Logging**: Detailed test logs with timestamps are generated for each function tested
- **⏱️ Timeout Detection**: Tests that run too long are automatically terminated (bonus feature)
- **🚦 Extended Signal Support**: Detection of various signals including SIGFPE, SIGPIPE, SIGILL (bonus feature)

## 🏗️ Project Structure

```
libunit/
├── framework/          # Main framework code
│   ├── includes/       # Standard framework headers
│   ├── srcs/           # Standard implementation
│   └── bonus/          # Bonus features implementation
│       ├── includes/
│       └── srcs/
├── libft/              # Basic utility functions
├── printf/             # Custom printf implementation
├── tests/              # Basic test suites
│   ├── strlen/         # strlen test suite
│   ├── strchr/         # strchr test suite
│   └── atoi/           # atoi test suite
├── real-tests/         # More comprehensive test suites
│   ├── strlen/
│   ├── strchr/
│   ├── atoi/
│   ├── isalnum/
│   ├── isalpha/
│   ├── isascii/
│   ├── isdigit/
│   └── isprint/
├── signals_tests/      # Tests for signal handling features
└── Makefile            # Build system
```

## 🚀 Getting Started

### Building the Framework

```bash
make
```

This will compile the framework and all test suites.

### Running the Standard Tests

```bash
./unit_tests
```

### Running the Real Tests

```bash
./real_tests
```

### Running the Signal Handling Tests

```bash
./signals_test_bonus
```

## 📊 Example Output

When you run the tests, you'll see output similar to this:

```
==== LIBUNIT TESTS ====

STRLEN: Basic test : [OK]
STRLEN: Empty string test : [OK]

2/2 tests checked.

STRCHR: Basic test : [OK]
STRCHR: Not found test : [OK]
STRCHR: Null terminator test : [OK]

3/3 tests checked.

ATOI: Positive test : [OK]
ATOI: Negative test : [OK]
ATOI: Zero test : [OK]
ATOI: Space test : [OK]
ATOI: Plus sign test : [OK]

5/5 tests checked.

All tests passed!
```

If there are failures, they will be highlighted like this:

```
STRLEN: Basic test : [OK]
STRLEN: Empty string test : [KO]

1/2 tests checked.

Some tests failed!
```

Crashes are also detected and reported with colorized output:

```
SIGNALS: Segmentation fault (SIGSEGV) : [SEGV]
SIGNALS: Bus error (SIGBUS) : [BUSE]
SIGNALS: Abort (SIGABRT) : [ABRT]
SIGNALS: Floating point exception (SIGFPE) : [FPE]
SIGNALS: Broken pipe (SIGPIPE) : [PIPE]
SIGNALS: Illegal instruction (SIGILL) : [ILL]
SIGNALS: Infinite loop (TIMEOUT) : [TIME] :Infinite loop (TIMEOUT) (exceeded 10 seconds)
SIGNALS: Sleep timeout (TIMEOUT) : [TIME] :Sleep timeout (TIMEOUT) (exceeded 10 seconds)

0/8 tests checked.
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
    load_test(&test_list, "Basic functionality test", &my_function_test);
    // Add more tests...
    return (launch_tests(&test_list, "MY_FUNCTION"));
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

## 📄 Log Files

For each function tested, a log file is generated with detailed information:

- Log files are named `[function_name].log`
- Each log contains:
  - Timestamp for the test run
  - Function name being tested
  - Each test case's name and result
  - Detailed failure information for failed tests
  - Summary of test statistics

Example log file (`STRLEN.log`):

```
=== Test Run: Sun May 25 17:55:23 2025 ===
Function: STRLEN

[Sun May 25 17:55:23 2025] STRLEN: Basic test - OK

[Sun May 25 17:55:23 2025] STRLEN: Empty string test - OK

=== Summary ===
Total tests: 2
Passed: 2
Failed: 0

======================================
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
   - Test results are logged to a file
3. The process continues for each test in the list

## 🎛️ Bonus Features

### Timeout Detection

Tests that run for more than 10 seconds (configurable via `TIMEOUT_SECONDS`) are automatically terminated and reported as timeouts.

### Extended Signal Handling

The framework detects and reports on a variety of signals:

- `SIGSEGV`: Segmentation fault
- `SIGBUS`: Bus error
- `SIGABRT`: Abort
- `SIGFPE`: Floating point exception
- `SIGPIPE`: Broken pipe
- `SIGILL`: Illegal instruction
- `SIGALRM`: Timeout

### Colorized Output

Test results are displayed with colorized output for easier reading:
- Green: Passed tests
- Red: Failed tests
- Yellow: Signal-related failures

## 📦 Dependencies

- **libft**: Basic utility functions
- **ft_printf**: Custom printf implementation

## 📜 License

This project is part of the curriculum at 42 School and follows their usage guidelines.