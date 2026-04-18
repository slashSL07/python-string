#ifndef STR_H
#define STR_H
#include <stddef.h>


typedef struct
{
  const char* content;
  size_t len;

}str;

void _print(str string);
str lower(str string);
str upper(str string);

str reverse(str string);
str pstr(const char* cstr);

str chop(str s, int start, int end);

str* split(str string, char rep, int* length);
int _index(str string, char c);
#endif
