#ifndef STR_H
#define STR_H
#include <stddef.h>

// struct str(dataype)
typedef struct
{
  const char *content;
  size_t len;

} str;

// prints `str`
void _print(str string);
// returns a new `str` with all the charecters of `string` in lowercase
str lower(str string);
// returns a new `str` with all the charecters of `string` in uppercase
str upper(str string);

// returns a new `str` with all the charecters of `string` in reversed order
str reverse(str string);
// converts `char*` to `str` type
str tostr(const char *cstr);

// slices the given `str`
str slice(str s, int start, int end);
// replaces all the occurances of `char*` in the `old_str` with `new_str` and returns the `string`
str replace(str old_str, char *rep, char *new_str);

/*splits the `string` into an array of substring with the help of the given delimeter `rep`
size of the given array is stored in `length`*/
str *split(str string, char rep, int *length);
// returns the index of the first occurance of the given charecter in `string`, returns `-1` if the given charecter doesn't exist
int _index(str string, char c);
// returns the number of occurances of a charecter in a given `string`
int count(str string, char c);
// returns a new `str` from `string` with the first letter in uppercase
str title(str string);
// returns a new `str` with the first letter of every word in uppercase
str capitalize(str string);

// converts `str` to `char*`
char *tochararr(str string);
// checks if all the charecter in the given string is uppercase, returns `1` if true
int _isupper(str string);
// checks if all the charecter in the given string is lowercase, returns `1` if true
int _islower(str string);
// checks if all the charecter in the given string is numeric, returns `1` if true
int isnumeric(str string);
#endif
