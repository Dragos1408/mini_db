#include <string.h>
#include <ctype.h>
#include "utils.h"

char* my_strtrim(char* str) {
    char* end;

    // Trim leading spaces
    while(isspace((unsigned char)*str)) str++;

    if(*str == 0)  // All spaces?
        return str;

    // Trim trailing spaces
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    // Write new null terminator
    *(end+1) = '\0';

    return str;
}

