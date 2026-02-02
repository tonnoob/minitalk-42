*This project was created as part of curriculum 42 by osousa-d.*

[Versão em Português 🇧🇷](doc/README-ptbr.md)

# Minitalk

## Description

Minitalk is a project from curriculum 42 that explores inter-process communication (IPC) in C using **UNIX signals**.

The goal is to establish a communication channel between a client and a server, where messages are transmitted bit by bit through signals.

The project reinforces low-level concepts such as signal handling, bitwise operations, process synchronization, and **UTF-8** character encoding, requiring careful timing control and data interpretation.

Simply put: there is a server and a client. The client receives a string, breaks it into bits (0 and 1), and sends these bits individually through signals. The server receives the signals corresponding to 0 and 1, reconstructs the bytes, and finally reassembles the original string, printing the result on the screen.

---
## Compilation

To compile, it's simple. In the project root, run:

```bash
make
```
Generating the executables `server` and `client`

or
```bash
make bonus
```
Generating the executables `server_bonus` and `client_bonus`

(this creates the bonus executables)

---
You can also use these commands:

Cleans up `.o` files
```bash
make clean
```
Cleans up `.o` files and executable files
```bash
make fclean
```
Recompiles everything
```bash
make re
```

---
## Instructions

Now it works as follows, regardless of whether it's the bonus or not:

Start the `server`
```bash
./server
```
It will print your **PID** in the terminal.

Example:
```bash
➜ minitalk-42 git:(main) ✗ ./server
PID Server: 360539
```
(we won't change this anymore)

Open another terminal and don't terminate (ctrl + c) the server process we just started.

In the new terminal, run the client with the **PID** that the server will display
```bash
./client 360539 "<string you want>"
```
In the string you pass, you can pass anything: symbols, emojis, chat messages... Be creative!
(remember that it has to be in double quotes)

After pressing `Enter`, look at the terminal that was running your server. The message you entered will have been displayed by the server, and all of this was possible through the symbols **SIGUSR1** and **SIGUSR2** (1 and 0).

---
## BONUS
What would the bonus be?

- 1. The `server` must confirm each received message by sending a signal to the `client`.
	- After reading a message completely, the `server` sends a signal to the client, and the `client` terminal prints a message confirming this:
```Bash
✅ Message received!

```
- 2. Support for **Unicode** characters!

An interesting point to highlight is that both my mandatory and bonus versions support Unicode, being able to receive any kind of unusual character you might use.

To run with the bonus, just replace `./server` with `./server_bonus`, the same for the client.
(Don't forget to run `make bonus`)

---
## Finalization
During the project creation, I studied a bit about **UTF-8**, maybe it can help you!!

📚 Additional Documentation:

- [Understanding UTF-8 - pt-br](doc/utf8_explaned-ptbr.md)

- [Understanding UTF-8 - en](doc/utf8_explaned.md)

---
## Sources
This video helped me a lot:

[UTF-8, Explained Simply](https://www.youtube.com/watch?v=vpSkBV5vydg)
