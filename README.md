# Libunit Test Framework

## Overview

Libunit is a lightweight unit testing framework for C programs, inspired by modern testing libraries but designed with simplicity and minimal dependencies in mind. It provides an easy way to write and run unit tests for C code, with support for test isolation, detailed error reporting, and comprehensive result summaries.

## Features

- **Simple API**: Easy-to-use interface for defining and running tests
- **Process Isolation**: Each test runs in its own process for improved stability
- **Signal Handling**: Properly detects and reports segmentation faults, bus errors, and other signals
- **Colorized Output**: Visual differentiation between passing, failing, and crashing tests
- **Detailed Reporting**: Provides clear summaries of test results
- **Modular Design**: Easily extend with new test suites

## Project Structure

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

## Getting Started

### Building the Framework

```bash
make
```

This will compile the framework and all test suites, producing the `libunit` executable.

### Running the Tests

```bash
./libunit
```

### Adding New Tests

1. Create a new test function:

```c
int my_new_test(void)
{
    // Test logic here
    if (condition_is_true)
        return (0);  // Success
    else
        return (-1); // Failure
}
```

2. Add the test to a test launcher:

```c
int my_test_launcher(void)
{
    t_unit_test *test_list;

    test_list = NULL;
    ft_printf("MY TEST SUITE:\n");
    load_test(&test_list, "Test description", &my_new_test);
    // Add more tests...
    return (launch_tests(test_list));
}
```

3. Update the `test_launchers.h` file:

```c
/* Add your test launcher prototype */
int my_test_launcher(void);
```

4. Call your launcher from main:

```c
int main(void)
{
    int result;

    result = 0;
    // Other launchers...
    result |= my_test_launcher();
    // ...
    return (result);
}
```

## Return Values

- **Test Functions**:
  - `0`: Test passed
  - `-1`: Test failed
  - Other signals (like SIGSEGV) are caught by the framework

- **Launcher Functions**:
  - `0`: All tests in the suite passed
  - `-1`: At least one test in the suite failed

## Dependencies

- **libft**: Basic utility functions
- **ft_printf**: Custom printf implementation

## License

This project is part of the curriculum at 42 School and follows their usage guidelines.
