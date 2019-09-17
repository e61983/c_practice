#pragma once

typedef void (*func_t)(char *);

struct func_package {
    char *name;
    func_t func;
};

extern void *__start_my_func;
extern void *__stop_my_func;

static void inline *get_first_package() { return &__start_my_func; }

#define foreach_func(start)                                          \
        for (struct func_package *i = (start); \
             i < (struct func_package *)&__stop_my_func; i++)

#define REGISTER_FUNC(f)                                                  \
    static struct func_package __func_info__##f                           \
        __attribute((__section__("my_func"))) __attribute((__used__)) = { \
            .name = #f,                                                   \
            .func = f,                                                    \
    }
