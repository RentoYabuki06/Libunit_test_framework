#ifndef SIGNALS_TESTS_H
# define SIGNALS_TESTS_H

int segv_test(void);
int bus_test(void);
int abrt_test(void);
int fpe_test(void);
int pipe_test(void);
int ill_test(void);
int timeout_test(void);
int sleep_timeout_test(void);

#endif