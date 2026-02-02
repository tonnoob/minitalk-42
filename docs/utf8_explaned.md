# Understanding a little about binary characters

Characters from the real **ASCII** table (127 characters) identify bytes like this:
Example:
```bash
000 0000
```
(using 7 bits)

“But don’t characters have 8 bits?”
The answer is: YESSS!

In the system, the leftmost bit of the byte gets a zero, because in the past it was only `7 bits`.
Example:
```bash
(0)000 0000
```
---
But in **UTF-8**, characters from the extended **ASCII** table (above 127)
become **multi-byte**, meaning they use more than `8 bits` (more than 1 byte).

And the system only knows that a character is **multi-byte** because the most significant bit of the first byte is always `1 if it is **multi-byte**.
Example: 
```bash
(1)0000000 00000000
```
If the character has more than 2 bytes, the first byte starts with a sequence of `1 based on how many bytes the character has:

Example:
Character with 2 bytes, start byte:
```bash
11000000
```
Character with 3 bytes, start byte:
```bash
11100000
```
Character with 4 bytes, start byte:
```bash
11110000
```
The remaining bytes of **multi-byte** characters, after the start byte, always begin with `10`.

Example:
```bash
🤓 = 11110000 10011111 10100100 10010011
🚀 = 11110000 10011111 10011010 10000000
```
And be careful with combined characters:
```bash
2️⃣ = 00110010 11100010 10000011 10100011
```
It starts the same as the **ASCII** character "2" → 00110010`
and then joins with `11100010 10000011 10100011`

This is a **COMBINING ENCLOSING KEYCAP**.

In short:
```bash
2  = 00110010
⃣  = 11100010 10000011 10100011

00110010 + 11100010 10000011 10100011 = 2️⃣
```
---
If you want to understand this better, this video is very good:

https://www.youtube.com/watch?v=vpSkBV5vydg
