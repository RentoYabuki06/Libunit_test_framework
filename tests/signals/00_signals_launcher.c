#include "libunit.h"
#include "signals_tests.h"

int signals_launcher(void)
{
    t_unit_test *test_list;

    test_list = NULL;
    ft_printf("SIGNAL TESTS:\n");
    load_test(&test_list, "Segmentation fault (SIGSEGV)", &segv_test);
    load_test(&test_list, "Bus error (SIGBUS)", &bus_test);
    load_test(&test_list, "Abort (SIGABRT)", &abrt_test);
    load_test(&test_list, "Floating point exception (SIGFPE)", &fpe_test);
    load_test(&test_list, "Broken pipe (SIGPIPE)", &pipe_test);
    load_test(&test_list, "Illegal instruction (SIGILL)", &ill_test);
    load_test(&test_list, "Infinite loop (TIMEOUT)", &timeout_test);
    load_test(&test_list, "Sleep timeout (TIMEOUT)", &sleep_timeout_test);
    return (launch_tests(test_list));
}