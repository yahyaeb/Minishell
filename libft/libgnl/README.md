# get_next_line

## Description
GNL is a project at 42 where the goal is to implement a function that reads a line from a file descriptor, handling multiple calls to return one line at a time. The function must be able to efficiently manage memory and handle cases as varying line lengths and files with multiple lines. The project helps students practice their understanding of file handling, memory management, and string manipulation in C, while reinforcing the importance of working with buffers and ensuring performance in real-world applications.

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
   git clone https://github.com/jack-pepper/get_next_line.git
   ```

2. Uncomment the main in get_next_line.c and adapt it depending on your needs.

3. Compile the project:
   ```bash
   cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c
   ```

## Usage

1. This project helps understand the internal logic of functions that read data from a file descriptor, similar to those found in the standard C library, such as getline and fgets.
2. It shows how to handle memory buffers, efficiently read data line by line, and manage dynamic memory allocation. It also provides insight into how file I/O operations work under the hood, reinforcing key concepts like handling different data types, edge cases, and managing input/output efficiently in real-world scenarios.
3. If you are a student, I highly recommend you to do your own experiences before looking at my code. GNL can be realized through different means. My implementation works, but it is not the most effective!

## Features

I used a single "stash" static variable to manage the leftover content in the buffer after each call to the get_next_line function, in order to "remember" the leftover part of the buffer when it’s called again, ensuring that subsequent calls can pick up where the last one left off.

How it works: When get_next_line reads from a file descriptor, it fills a buffer with data. If a newline character (\n) is found, the function returns everything up to that point as a complete line. Any leftover data after the newline is saved in the "stash". On the next call to get_next_line, the function will start processing the "stash" (the leftover data) before reading more from the file, effectively maintaining continuity between calls.

In my implementation, I chose to copy the buffer's content first to the "stash", from where I seize the next line, before copying the leftover data to the start of the stash.

## Contributing

Contributions are welcome! If you notice any areas where the implementation can be improved or have suggestions for new features, feel free to contribute. I am always willing to learn.

Specifically to this project: my implementation works but does not handle very well alternating file descriptors.

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## Acknowledgments

- Thanks to the number 42, which is close to the number of times I redid this project to find my way out.
