*Este projeto foi criado como parte do currículo 42 por osousa-d.*

# Minitalk

## Descrição

Minitalk é um projeto do currículo da 42 que explora comunicação entre processos (IPC) em C utilizando **sinais UNIX**.
O objetivo é estabelecer um canal de comunicação entre um `client` e um `server`, onde as mensagens são transmitidas bit a bit por meio de sinais.

O projeto reforça conceitos de baixo nível como tratamento de sinais, operações bitwise, sincronização de processos e codificação de caracteres **UTF-8**, exigindo controle cuidadoso de tempo e interpretação dos dados.

Simplificando: existem um `server` e um `client`. O `client` recebe uma string, a quebra em bits (0 e 1) e envia esses bits individualmente através de sinais. O `server` recebe os sinais correspondentes a 0 e 1, reconstrói os bytes e, ao final, monta novamente a string original, imprimindo o resultado na tela.

---
## Compilação

Pra compilar é simples, Na raiz do projeto, execute:
```bash
Make
```
Gerando os executaveis `server` e `client`

ou
```bash
Make bonus
```
Gerando os executaveis `server_bonus` e `client_bonus`
(isso cria os executaveis do bonus)

---
Pode também utilizar esses comandos:

Limpa os arquivos `.o`
```bash
make clean
```

Limpa arquivos `.o` e os `executaveis`
```bash
make fclean
```
Recompila tudo
```bash
make re 
```

---
## Instruções

Agora funciona da seguinte forma, independente se for os bonus ou não

Inicie o `server`
```bash
./server
```
Ele vai printar no terminal o seu **PID**
Exemplo:
```bash
➜  minitalk-42 git:(main) ✗ ./server
PID Server: 360539

```
(agora não vamos mais mexer aqui)

Abra outro terminal e não encerre (ctrl + c) o processo do server que acabamos de iniciar

No novo terminal execute o client com o **PID** que o server vai ter exibido
```bash
./client 360539 "<string que você quiser>"
```
Na string que tu vai passar pode passar qualquer coisa, sinais, emojis, mensgens de chat... Seja criativo!
(lembre-se que tem que estar entre aspas dupla)

Após um `Enter` olhe o terminal que estava o rodando o seu server, A mensagem que você inseriu vai ter sido exibida pelo server e tudo isso foi possivel através de sinais **SIGUSR1** e **SIGUSR2** (1 e 0). 

---
## BÔNUS
O que seria o bonus? 

- 1. O `servidor` deve confirmar cada mensagem recebida enviando um sinal para o `cliente`.
	- O `server` após ler uma mensagem completamente envia um sinal pro client e no terminal do `client` imprime uma mensagens confirmando isso
```Bash
✅ Message received!
```

- 2. Suporte a caracteres **Unicode**!

Um ponto bem interessante de ressaltar é que tanto o meu mandatório quanto o meu bônus tem suporte para Unicode, podendo receber todo tipo de caractér estranho que tu colocar.

Pra executar com o bônus é só trocar o `./server` por `./server_bonus`, o mesmo pro client.
(Não se esqueça de rodar `make bonus`)

---
## Finalização
Durante a criação do projeto eu estudei um pouco sobre **UTF-8**, talvez possa te ajudar!!

📚 Documentação adicional:
- [Entendendo UTF-8 - pt-br](doc/utf8_explaned-ptbr.md)

- [Understanding UTF-8 - en](doc/utf8_explaned.md)

---
## Fontes
Esse vídeo me ajudou muito:

[UTF-8, Explicado de forma simples](https://www.youtube.com/watch?v=vpSkBV5vydg)