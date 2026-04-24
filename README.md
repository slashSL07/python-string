# 📦 python-string — Simple C String Library

A lightweight string utility library for C, designed to make string handling less painful and more structured.

---

## ⚡ Features

* String struct wrapper (`str`)
* Convert to lowercase / uppercase
* Title & capitalization utilities
* Print helper
* Substring extraction (`slice`)
* Split by delimiter
* Character indexing
* Count of characters in a string
* Reversing the string
* Simple C-string wrapper constructor (`tostr`)
* String checks (upper/lower/numeric)
* Convert to raw `char*`
* Replace substring 

---

## 🧠 Core Type

```c
typedef struct
{
    const char* content;
    size_t len;
} str;
```

A simple immutable-style string wrapper around `const char*`.

---

## 🔧 Functions

### 📌 Create string

```c
str tostr(const char* cstr);
```

Creates a `str` from a C-string.

---

### 📌 Print

```c
void _print(str string);
```

Prints the string.

---

### 📌 Case conversion

```c
str lower(str string);
str upper(str string);
```

Returns a new string in lowercase / uppercase.

---

### 📌 Title / Capitalization

```c
str title(str string);
str capitalize(str string);
```

* `capitalize` → Capitalizes the first letter of each word
* `title` → Formats the string in title case

---

### 📌 Reverse

```c
str reverse(str string);
```

Reverses the `str` and returns the result.

---

### 📌 Replace

```c
str replace(str old_str, char* rep, char* new_str);
```

Replaces the `rep` substring in the `old_str` with `new_str` and returns the result.

---

### 📌 Substring (slice)

```c
str slice(str s, int start, int end);
```

Extracts substring from `start` to `end`.

---

### 📌 Split

```c
str* split(str string, char rep, int* length);
```

Splits string by delimiter `rep`.

* Returns dynamically allocated array
* `length` stores number of parts

---

### 📌 Find character index

```c
int _index(str string, char c);
```

Returns index of first occurrence of `c`, returns `-1` if not found.

---

### 📌 Count characters

```c
int count(str string, char n);
```

Returns number of occurrences of `n`.

---

### 📌 Conversions

```c
char* tochararr(str string);
```

Converts `str` to a C-style `char*`.

---

### 📌 Checks

```c
int _isupper(str string);
int _islower(str string);
int isnumeric(str string);
```

* `_isupper` → Returns `1` if all characters are uppercase
* `_islower` → Returns `1` if all characters are lowercase
* `isnumeric` → Returns `1` if string contains only numeric characters

---

## 📁 Project Structure

```
my-lib/
│
├── example/
│   └── example.c
│
├── include/
│   └── str.h
│
├── lib/
│   └── libstr.a
│ 
├── src/
│   └── str.c
│ 
└── README.md
```

---

## 🧪 Example Usage

```c
#include "str.h"

int main()
{
    str s = tostr("hello guys welcome");

    str t = title(s);
    _print(t);

    char* raw = tochararr(t);
    printf("%s\n", raw);

    return 0;
}
```

Compile:

```bash
gcc main.c -Llib -lstr -Iinclude
```

---

## 🧨 Notes

* Strings are not deeply copied unless specified by function behavior
* Be careful with memory returned by functions like `split` and `tochararr` (you may need to `free` it)
* Some functions allocate new memory — manage it properly
* This library is designed for simplicity, not full Python-level behavior

ADDITIONAL NOTE: the library file is built (and targeted) for windows if you using any other opperating system feel free to built the lib file from the src file
