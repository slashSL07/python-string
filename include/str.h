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
str tostr(const char* cstr);

str slice(str s, int start, int end);
str replace(str old_str, char* rep, char* new_str);

str* split(str string, char rep, int* length);
int _index(str string, char c);
int count(str string, char c);
str title(str string);
str capitalize(str string);
char* tochararr(str string);
int _isupper(str string);
int _islower(str string);
int isnumeric(str string);
#endif
