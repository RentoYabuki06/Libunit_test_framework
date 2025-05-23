#include "libunit.h"

int segv_test(void)
{
    char *ptr;
    
    ptr = NULL;
    *ptr = 'a';  // ここでSIGSEGVが発生
    return (0);
}