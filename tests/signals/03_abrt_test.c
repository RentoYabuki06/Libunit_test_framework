#include "libunit.h"
#include <stdlib.h>
#include <assert.h>

int abrt_test(void)
{
    abort();  // SIGABRTを発生させる
    return (0);
}