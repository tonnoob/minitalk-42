*This project has been created as part of the 42 curriculum by osousa-d.*

# Minitalk

## Description

Minitalk is a project from the 42 curriculum that explores interprocess communication (IPC) in C using **UNIX signals**.
The goal is to establish a communication channel between a `client` and a `server`, where messages are transmitted bit by bit through signals.

The project reinforces low-level concepts such as signal handling, bitwise operations, process synchronization, and **UTF-8** character encoding, requiring careful control over timing and data interpretation.

Simply put, there's the `server` and the `client`. The `client` will pass a string to the `server`, however, it will break the entered string into only 1s and 0s (binary). The `server` will receive the 1 and 0 and reassemble the string, printing it to the screen.

---