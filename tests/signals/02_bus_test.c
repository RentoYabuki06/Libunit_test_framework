#include "libunit.h"
#include <string.h>
#include <unistd.h>

// メモリアライメント違反によるバスエラー
int bus_test(void)
{
    char buffer[sizeof(int)];
    int *ptr;
    
    ptr = (int *)(buffer + 1);  // アライメントされていないアドレス
    *ptr = 42;  // ここでSIGBUSが発生する可能性がある
    
    return (0);
}