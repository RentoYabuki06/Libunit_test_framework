#include "libunit.h"
#include <signal.h> // raise() のために必要

int ill_test(void)
{
    // シグナルを直接送信（どのコンパイラでも動作）
    raise(SIGILL);
    return (0);
}