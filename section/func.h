#pragma once

typedef void (*func_t)(char *);

struct func_package {
    char *name;
    func_t func;
};

#define REGISTER_FUNC(f)                                               \
    static struct func_package __func_info__##f                        \
        __attribute((__section__("my_func"))) __attribute((__used__)) = { \
            .name = #f,                                                 \
            .func = f,                                                \
    }

