#include "yasl_float.h"

#include <stdio.h>
#include <stdlib.h>

char *float64_to_str(yasl_float d) {
	int size = snprintf(NULL, 0, "%f", d);
	char *ptr = (char *)malloc((size_t)size+ 1);
	snprintf(ptr, (size_t)size+1, "%f", d);
	while (ptr[size - 1] == '0' && ptr[size - 2] != '.') {
		size--;
	}
	ptr[size] = '\0';
	ptr = (char *)realloc(ptr, (size_t)size + 1);
	return ptr;
}
