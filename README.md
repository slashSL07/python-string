# 📦 python-string — Simple C String Library

A lightweight string utility library for C, designed to make string handling less painful and more structured.

---

## ⚡ Features

* String struct wrapper (`str`)
* Convert to lowercase / uppercase
* Print helper
* Substring extraction (`chop`)
* Split by delimiter
* Character indexing
* count of charecters in a string
* reversing the string
* Simple C-string wrapper constructor (`pstr`)

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


## 🔧 Functions

### 📌 Create string

```c
str pstr(const char* cstr);
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

### 📌 reverse
```c
str reverse(str string);
```
reverses the str `string` and returns the reversed str
---

### 📌 Substring (slice)

```c
str chop(str s, int start, int end);
```

Extracts substring from `start` to `end`.

---

### 📌 Split

```c
str* split(str string, char rep, int* length);
```

Splits string by delimiter `rep`.

* returns dynamically allocated array
* `length` stores number of parts

---

### 📌 Find character index

```c
int _index(str string, char c);
```

Returns index of first occurrence of `c` returns `-1` if not found.

---

### 📌 Find the number of charecter in a string

```c
int count(str string, char n);
```

Returns number occurrence of `n`.

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
├── src/
│   └── *.c
│
├── lib/
│   └── libstr.a
│ 
└── README.md
```


## 🧪 Example Usage

```c
#include "str.h"

int main()
{
    str s = pstr("Hello World");

    str u = upper(s);
    _print(u);

    return 0;
}
```

Compile:

```bash
gcc main.c -Llib -lstr -Iinclude
```

---

## 🧨 Notes

* Strings are not deeply copied unless specified by function behavior.
* Be careful with memory returned by `split` (you may need to `free` it).
* This library is designed for simplicity, not full python replacement behavior.



