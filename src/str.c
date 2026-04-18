#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "str.h"



str pstr(const char* cstr)
{
   str string;
   string.content = cstr;
   string.len = strlen(cstr);
   return string;
   
   
}
str upper(str string)
{
  char* b = malloc(string.len);
  for(int i = 0; i < string.len; i++)
  {
    if(string.content[i] >= 97 &&  string.content[i] <= 122)
    {
      b[i] = string.content[i] - 32;
    }
    else
    {
       b[i] = string.content[i];
    }
  }
  
  str c;
  c.content = b;  
  c.len = string.len;
  return c;
}
str lower(str string)
{
  char* b = malloc(string.len);
  for(int i = 0; i < string.len; i++)
  {
    if(string.content[i] >= 65 && string.content[i] <= 90)
    {
      b[i] = string.content[i] + 32;
    }
    else
    {
       b[i] = string.content[i];
    }
  }
  
  str c;
  c.content = b;  
  c.len = string.len;
  return c;
}
void _print(str string)
{
  printf("%.*s", (int)string.len, string.content);
}

str chop(str s, int start, int end)
{
 
    if (start < 0) start = 0;
    if (end > s.len) end = s.len;
    if (start > end) start = end;

    s.content += start;
    s.len = end - start;

    return s;
}

str* split(str string, char rep, int* length)
{
  int c = 0;
  for(int i = 0; i < string.len; i++)
  {
    if (string.content[i] == rep)
    {
      c++;
    } 
  }
  int pos[c+1];
  pos[c] = string.len;
  
  int p = 0;
  
  for(int i = 0; i < string.len; i++)
  {
    if (string.content[i] == rep)
    {
      pos[p] = i;
      p++;
    } 
  }
 
  str* a = malloc((c+1) * sizeof(str));
  a[0] = chop(string, 0, pos[0]);
  for(int i = 1; i <= c+1; i++)
  {
     a[i] = chop(string, pos[i-1], pos[i]);
  }
  *length = c+1;
  return a;
}

int _index(str string, char c)
{
  for(int i = 0; i < string.len; i++)
  {
    if(string.content[i] == c)
    {
      return i;
    }
  }
}