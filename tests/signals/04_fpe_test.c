#include "libunit.h"
#include <signal.h>

int fpe_test(void)
{
    int result = 0;
    int zero = 0;
    
    result = 42 / zero;  // ここでSIGFPEが発生
    return (result);
}