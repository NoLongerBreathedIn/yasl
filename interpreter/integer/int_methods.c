#include "int_methods.h"

#include "interpreter/VM/VM.h"
#include "yasl_state.h"
#include "yasl_conf.h"

int int_tofloat(struct YASL_State *S) {
    ASSERT_TYPE((struct VM *)S, Y_INT, "int64.tofloat64");
    vm_push((struct VM *)S, YASL_FLOAT((yasl_float)YASL_GETINT(vm_pop((struct VM *)S))));
    return 0;
}

int int_tostr(struct YASL_State *S) {
    ASSERT_TYPE((struct VM *)S, Y_INT, "int64.tostr");
    yasl_int val = YASL_GETINT(vm_pop((struct VM *)S));
    int n;
    char *ptr = malloc(n = snprintf(NULL, 0, "%" PRId64 "", val) + 1);
    snprintf(ptr, n,"%" PRId64 "", val);
    String_t* string = str_new_sized_heap(0, snprintf(NULL, 0, "%" PRId64 "", val), ptr);
    vm_push((struct VM *)S, YASL_STR(string));
    return 0;
}
