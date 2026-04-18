#include <stdio.h>
#include <stdlib.h>
#include "str.h"

int main()
{
  int len = 0;
  char rep = ' ';
  str s = pstr("wassup guys how are you");
  
  str* array = split(s, rep , &len);
  for(int i = 0; i < len; i++)
  {
    _print(array[i]);
    printf("\n");
  }
  free(array);
  str b = upper(s);
  _print(b);
  printf("index of h is %d", _index(s, 'f'));
}