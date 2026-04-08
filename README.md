# 📄 get_next_line

A custom implementation of a function that reads a file **line by line**, developed as part of the **42 School curriculum**.
This project focuses on mastering **file descriptors**, **buffer management**, and **static variables** in C.

---

## 📖 Overview

**get_next_line** is a function that reads and returns a single line from a file descriptor each time it is called. It allows efficient reading of files of **unknown size**, handling input incrementally instead of loading everything into memory at once.

The project emphasizes:

* Low-level file I/O operations
* Efficient memory and buffer management
* Persistent state using static variables
* Writing robust and reusable C functions

Each call to the function returns the next line, making it ideal for parsing files or streams. ([DEV Community][1])

---

## 🧠 Learning Objectives

By completing this project, you will gain experience with:

* File descriptors and system I/O
* Reading from files using `read()`
* Static variables and persistent state
* Dynamic memory allocation and cleanup
* Buffer management and optimization
* Handling edge cases and errors

---

## 📂 Project Structure

```id="a1b2c3"
get_next_line/
├── get_next_line.c        # Main function
├── get_next_line_utils.c  # Helper functions
├── get_next_line.h        # Header file
├── Makefile               # Build system
└── README.md
```

Typical components include:

* **Core logic** for reading and returning lines
* **Utility functions** for string manipulation
* **Header file** with function prototypes and macros

---

## ⚙️ Function Prototype

```c id="f4g5h6"
int get_next_line(int fd, char **line);
```

### Parameters

* `fd`: File descriptor to read from
* `line`: Pointer where the read line will be stored

### 🔁 Return Values

| Return | Meaning              |
| ------ | -------------------- |
| `1`    | A line has been read |
| `0`    | End of file reached  |
| `-1`   | An error occurred    |

A “line” is defined as a sequence of characters ending with `\n` or EOF.

---

## 🧩 How It Works

The implementation typically follows this logic:

1. **Read from file descriptor**

   * Use a buffer of size `BUFFER_SIZE`
   * Append data to a persistent storage

2. **Store remaining data**

   * Use a `static` variable to keep unread content
   * Allows continuation between function calls

3. **Extract a line**

   * Find newline (`\n`) or EOF
   * Return the current line

4. **Update storage**

   * Keep remaining content for the next call

5. **Repeat until EOF**

Using a static buffer allows the function to “remember” its position between calls.

---

## ⚙️ Compilation & Usage

To compile:

```bash id="i7j8k9"
make
```

### Cleaning

```bash id="l0m1n2"
make clean      # Remove object files
make fclean     # Remove object files + binaries
make re         # Rebuild everything
```

---

## 🚀 How to Use

1. Include the header:

```c id="o3p4q5"
#include "get_next_line.h"
```

2. Use the function in your program:

```c id="r6s7t8"
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;
    int ret;

    while ((ret = get_next_line(fd, &line)) > 0)
    {
        // Process the line
        free(line);
    }
    free(line);
    close(fd);
    return 0;
}
```

---

## 🌟 Bonus Features

Depending on implementation, bonus requirements may include:

* Handling **multiple file descriptors simultaneously**
* Managing separate buffers for each file descriptor
* Improved memory and performance handling

---

## 📌 Constraints

* Only a limited set of functions can be used:

  * `read`, `malloc`, `free`
* No use of standard high-level I/O functions
* Must be **memory leak free**
* Must handle arbitrary file sizes and line lengths

---

## 🎯 Key Concepts Covered

| Category          | Topics                            |
| ----------------- | --------------------------------- |
| File I/O          | File descriptors, `read()`        |
| Memory Management | Allocation, deallocation          |
| Static Variables  | Persistent state                  |
| Algorithms        | Buffer parsing, string extraction |
| Low-Level C       | Manual control over data flow     |

---

## 🚀 Purpose of the Project

The **get_next_line** project is designed to:

* Teach efficient file reading strategies
* Build strong understanding of system-level I/O
* Practice memory-safe programming
* Create a reusable utility for future C projects

---

## ⚠️ Notes

* Behavior with binary files is undefined
* Proper memory management is critical
* Edge cases (empty files, large inputs, invalid descriptors) must be handled carefully

---

## 🤝 Contributing

Contributions and improvements are welcome!

1. Fork the repository
2. Create a feature branch
3. Submit a pull request

---

## 📄 License

This project is for educational purposes.
Refer to the repository for licensing details (if provided).

---

## 📚 Resources

To deepen your understanding:

* `man read`
* `man open`
* File descriptor documentation
* Memory management in C
* Buffering and stream processing

---

[1]: https://dev.to/aerrfig/get-next-line-a-42-project-to-learn-how-to-deal-with-file-descriptors-and-io-of-system-3652?utm_source=chatgpt.com "GET NEXT LINE A 42 Project TO Learn How To Deal with File Descriptors and I/O of System - DEV Community"
