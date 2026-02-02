# Entendendo um pouco sobre caracteres em binário

Os caracteres da tabela **ASCII** original (127 caracteres) são representados usando 7 bits.
Exemplo: 
```bash
000 0000
```
(usando 7 bits)

“Mas caracteres não possuem 8 bits?”
A resposta é: SIMMM!

Nos sistemas atuais, os caracteres são armazenados em bytes de `8 bits`, então o bit mais à esquerda é `0` para caracteres **ASCII**. Isso vem do padrão antigo, onde o **ASCII** usava apenas `7 bits`.

---
Em **UTF-8**, caracteres fora do intervalo **ASCII** (acima de 127) tornam-se multi-byte, ou seja, são codificados usando mais de um byte.

O sistema identifica um caractere **multi-byte** observando o padrão de bits do primeiro byte:
```bash
(0)0000000 → caractere ASCII
```
Se o caractere possuir mais de um byte, o primeiro byte (start byte) começa com uma sequência de `1 que indica quantos bytes o caractere possui:

Exemplo:
Caractere com 2 bytes, byte inicial:
```bash
11000000
```
Caractere com 3 bytes, byte inicial:
```bash
11100000
```
Caractere com 4 bytes, byte inicial:
```bash
11110000
```
Os demais bytes de um caractere **multi-byte** (bytes de continuação) sempre começam com `10`.
Exemplo:
```bash
🤓 = 11110000 10011111 10100100 10010011
🚀 = 11110000 10011111 10011010 10000000
```

---
É preciso ter cuidado com caracteres combinados:

```bash
2️⃣ = 00110010 11100010 10000011 10100011
```
Ele começa com o caractere **ASCII** "2" → `00110010`
e é combinado com o caractere quadrado `11100010 10000011 10100011`	.

Isso é chamado de ***COMBINING ENCLOSING KEYCAP***.

Resumindo:
```bash
⃣  = 11100010 10000011 10100011
2  = 00110010

00110010 + 11100010 10000011 10100011 = 2️⃣
```
---
Se quiser entender melhor, este vídeo é muito bom:

https://www.youtube.com/watch?v=vpSkBV5vydg