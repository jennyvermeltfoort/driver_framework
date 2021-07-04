
#include <stdarg.h>
#include <stdio.h>

void hw_error(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    printf("HW_ERROR: ");
    vprintf(fmt, args);
    printf("\n");
    va_end(args);
}