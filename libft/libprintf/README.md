# ft_printf

## Description

The ft_printf project is a task at 42 where the goal is to implement a custom version of the printf function found in the C standard library. The project involves handling various format specifiers (like %d, %s, %c, etc.) to properly format and output data types such as integers, strings, characters, and more. The purpose of the project is to deepen your understanding of variadic functions, string manipulation, memory management, and formatting output in C. It also provides hands-on experience with handling different data types.

**Technologies Used:**
- C

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [Contributing](#contributing)
- [Acknowledgments](#acknowledgments)

## Installation

To use this project locally:

1. Clone this repository:
   ```bash
   git clone https://github.com/jack-pepper/ft_printf.git
   ```
2. Use make. It will compile the library libft.a and create a new library libftprint.a:
    ```bash
    make
    ```
3. Include the library to your project files:
   ```bash
   #include "libft.h"
   ```

## Usage

1. This project helps understand the internal logic of functions that read data from a file descriptor, similar to those found in the standard C library, such as getline and fgets.
2. It shows how to handle memory buffers, efficiently read data line by line, and manage dynamic memory allocation. It also provides insight into how file I/O operations work under the hood, reinforcing key concepts like handling different data types, edge cases, and managing input/output efficiently in real-world scenarios.
3. If you are a student, I highly recommend you to do your own experiences before looking at my code. GNL can be realized through different means. My implementation works, but it is not the most effective!

## Features

In my implementation, I use the function ft_spec_conv to handle the conversion of data based on the format specifiers and the associated flags. 

First, I parse the format string to extract and store formatting options as flags. These flags are used to modify how the output is displayed. The ft_spec_conv function checks the format string to identify the conversion specifier (like %d, %x, %s, etc.). Based on the specifier, I use the appropriate conversion function to handle the data:

- For numerical data (like %d, %i, %u), I use a function to convert the integer to a string.
- For hexadecimal values (e.g., %x), I use a function to convert the number into hexadecimal format, then to a string.
- For string data (like %s), I simply handle the string as it is.

Once the correct conversion function is selected based on the specifier, I perform the necessary conversion and then handle the printing, taking into account any formatting options I stored earlier. The output is formatted according to the specified flags.

I tried to write a flexible code, easy to update to add other options eventually. The current version manages the following conversions:

 `%c`: Prints a single character.
 `%s`: Prints a string (as defined by the common C convention).
 `%p`: Prints the void * pointer argument in hexadecimal (as %#x or %#lx) 
 `%d`: Prints a decimal (base 10) number.
 `%i`: Prints an integer in base 10.
 `%u`: Prints an unsigned decimal (base 10) number.
 `%x`: Prints a number in hexadecimal (base 16) lowercase format.
 `%X`: Prints a number in hexadecimal (base 16) uppercase format.
 `%%`: Prints a percent sign.

It handles the following flags as printf does: #, <space>, +. It does NOT handle other flags.

## Contributing

Contributions are welcome! If you notice any areas where the implementation can be improved or have suggestions for new features, feel free to contribute. I am always willing to learn.

Specifically to this project: my implementation works but does not handle very well alternating file descriptors.

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## Acknowledgments

- Thanks to the Vogons for their brand new highway.
