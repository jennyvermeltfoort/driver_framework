
#ifndef __COMMON_H
#define __COMMON_H

#include <stdio.h>
#include <stddef.h>

#define container_of(ptr, type, member) (                  \
    {                                                      \
        const typeof(((type *)0)->member) *__mptr = (ptr); \
        (type *)((char *)__mptr - offsetof(type, member)); \
    })

void hw_error(const char *fmt, ...);

#endif /* __COMMON_H */