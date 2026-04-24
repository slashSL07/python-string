#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "str.h"


int inlist(int val, int* list, int len);
str tostr(const char* cstr)
{
   str string;
   string.content = cstr;
   string.len = strlen(cstr);
   return string;
   
   
}
char* tochararr(str string)
{
  char* c = malloc(string.len +1);
  for(int i = 0; i < string.len; i++)
  {
    c[i] = string.content[i];
  }
  c[string.len] = '\0';
  return c;
}
str reverse(str string)
{
  int p = strlen(string.content);
  char* s = (char*)malloc(p);
  while (p > 0)
  {
    s[strlen(string.content) - p] = string.content[p-1]; 
    p--;
  }
  str line = tostr(s);
  return line;
  
}

str replace(str old_str, char* rep, char* new_str)
{
  char* temp = malloc(sizeof(old_str.content) + 1 + (int)(old_str.len/strlen(rep))*(strlen(new_str) - strlen(rep)));
  int i = 0;
  int t = 0;
  while(i < old_str.len)
   {
     if(old_str.content[i] == rep[0])
      {
        int c = 1;
        for(int k = 1; k < strlen(rep); k++)
         {
           if(old_str.content[i+k] == rep[k])
            {
              c++;
            }
         }
        if(strlen(rep) == c)
         {
           for(int j = 0; j < strlen(new_str); j++)
            {
              temp[t+j] = new_str[j];
            }
           i += strlen(rep);
           t +=strlen(new_str);
         }
        else
         {
           temp[t] = old_str.content[i];
           i++; 
           t++;
         }
      }
     else
      {
        temp[t] = old_str.content[i];
        t++;
        i++; 
      }
   }
   str s = tostr(temp);
   free(temp);
   return s;
  
}


str capitalize(str string)
{
  char* var = malloc(string.len);
  int c = 0;
  for(int i = 0; i < string.len; i++)
  {
    if (string.content[i] == ' ')
    {
      c++;
    } 
  }
  int pos[c];
  int p = 0;
  
  for(int i = 0; i < string.len; i++)
  {
    if (string.content[i] == ' ')
    {
      pos[p] = i+1;
      p++;
    } 
  }
  for(int i = 0; i < string.len; i++)
   {
    if(inlist(i, pos, c) == 1)
     {
      if(string.content[i] >= 97 &&  string.content[i] <= 122)
       {
          var[i] = string.content[i] - 32;
       }
      
     }
     else
      {
        var[i] = string.content[i];
      }
   }
   if(string.content[0] >= 97 &&  string.content[0] <= 122)
    {
      var[0] = string.content[0] - 32;
    }
   str s = tostr(var);
   return s;

  
}

int inlist(int val, int* list, int len)
{
  for(int i = 0; i < len; i++)
  {
    if(val == list[i])
    {
      return 1;
    }
  }
  return 0; 
}

int _isupper(str string)
{
  int b = 0;
  str* word = split(string, ' ', &b);
   for(int j = 0; j < b; j++)
   {
     for(int i = 0; i < word[j].len ; i++)
     {
       if(word[j].content[i] < 'A' || word[j].content[i] > 'Z')
       {
         free(word);
         return 0;
       }
     } 
   }
   free(word);
   return 1;
}

int _islower(str string)
{
  int b = 0;
  str* word = split(string, ' ', &b);
   for(int j = 0; j < b; j++)
   {
     for(int i = 0; i < word[j].len ; i++)
     {
       if(word[j].content[i] < 'a' || word[j].content[i] > 'z')
       {
         free(word);
         return 0;
       }
     } 
   }
   free(word);
   return 1;
}

int isnumeric(str string)
{
  for(int i = 0; i < string.len; i++)
  {
    if(string.content[i] < '1' || string.content[i] > '9')
    {
      return 0;
    }
  }
  return 1;
}




str title(str string)
{
  char* b = malloc(string.len);
  
  if(string.content[0] >= 97 &&  string.content[0] <= 122)
  {
    b[0] = string.content[0] - 32;
  }
  else
  {
    return string;
  }
  
  for(int i = 1; i < string.len; i++)
  {
     b[i] = string.content[i];
  }
  
  str c;
  c.content = b;  
  c.len = string.len;
  return c;
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

str slice(str s, int start, int end)
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
  a[0] = slice(string, 0, pos[0]);
  for(int i = 1; i <= c+1; i++)
  {
     a[i] = slice(string, pos[i-1], pos[i]);
  }
  *length = c+1;
  return a;
}

int count(str string, char c)
{
  int s = 0;
  for(int i = 0; i < string.len; i++)
  {
    if(string.content[i] == c)
    {
      s++;
    }
  }
  return s;
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
  return -1;
}
