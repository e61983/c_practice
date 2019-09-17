#pragma once

typedef void (*func_t)(char *);

struct func_package {
    char *name;
    func_t func;
};

extern void *__start_my_func;
extern void *__stop_my_func;

static void inline *get_first_package() { return &__start_my_func; }

#define __COMBINE__(s1, s2) s1##_##s2
#define COMBINE(s1, s2) __COMBINE__(s1, s2)

#define foreach_func(start)                \
    for (struct func_package *i = (start); \
         i < (struct func_package *)&__stop_my_func; i++)

#define REGISTER_FUNC(f)                                                  \
    static struct func_package COMBINE(__func_info__##f, __LINE__)        \
        __attribute((__section__("my_func"))) __attribute((__used__)) = { \
            .name = #f,                                                   \
            .func = f,                                                    \
    }
