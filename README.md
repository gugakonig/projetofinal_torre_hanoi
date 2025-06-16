
# Projeto Torre de Hanói

## 📌 Descrição

Este projeto implementa o clássico jogo Torre de Hanói em linguagem C, com interface de linha de comando. O programa permite ao usuário jogar, visualizar instruções, consultar o histórico de partidas e exibir os colaboradores do projeto.

O jogo utiliza estruturas de dados para representar as torres e seus discos, e mantém um histórico das partidas em memória e em arquivo texto.

---

## 📂 Arquivos do Projeto

- **main.c**  
Contém a função principal e o menu interativo do jogo.

- **torre.c / torre.h**  
Lógica do jogo: manipulação das torres, discos, validação de movimentos.

- **historico.c / historico.h**  
Gerenciamento de histórico com lista encadeada e persistência em arquivo texto.


---


## 🎮 Funcionalidades

- Menu interativo com opções para:
  - Ler instruções.
  - Jogar o jogo escolhendo o número de discos (entre 3 e 5).
  - Visualizar o histórico de partidas anteriores.
  - Exibir os colaboradores do projeto.

- Validação das regras do jogo Torre de Hanói:
  - Apenas um disco pode ser movido por vez.
  - Um disco maior não pode ser colocado sobre um disco menor.
  - Movimentos inválidos são rejeitados com mensagem de erro.

- Histórico persistente:
  - Cada partida finalizada é registrada em um arquivo texto.
  - O histórico é carregado ao iniciar o programa.
  - Visualização das partidas com nome do jogador, data, número de discos e quantidade de movimentos.

---

## 🕹️ Como Jogar

1. Escolha a opção **"Jogar"** no menu principal.  
2. Insira seu nome e a data da partida.  
3. Escolha o número de discos (3 a 5).  
4. O jogo exibirá as torres e pedirá os movimentos.  
5. Digite o movimento no formato de duas letras indicando a torre de origem e a torre de destino (exemplo: `AC` para mover o disco da torre A para a torre C).  
6. Use `Q` para sair e `R` para reiniciar o jogo a qualquer momento.  
7. O jogo termina quando todos os discos forem movidos para a torre C na ordem correta.  
8. O histórico da partida será salvo automaticamente.

---

## 🗂️ Estrutura de Pastas

```
TorreDeHanoi/
├── include/
│   ├── torre.h
│   ├── historico.h
│   
├── src/
│   ├── torre.c
│   ├── historico.c
│   └── main.c
└── README.md
```

---

## 🚀 Como Compilar e Executar

### 📌 Requisitos

- Compilador C (como **gcc**)  
- Ambiente com terminal compatível com ANSI (**Linux**, **WSL**, **macOS**)

---

### 🛠️ Compilar

Abra o terminal na pasta raiz do projeto e execute:

```
gcc main.c torre.c historico.c -o torre
```

---

### ▶️ Executar

Depois de compilar, execute o programa com:

```
./torre
```

---

## ⚠️ Aviso

- O arquivo de histórico é salvo automaticamente no mesmo diretório do executável com o nome:

```
HistoricoDePartidas.txt
```

---

## 📄 Licença e Créditos

Projeto acadêmico para a disciplina de **Estrutura de Dados**  
**Universidade Católica de Brasília (UCB)** – Engenharia de Software  

**Desenvolvido por:**  
- Gustavo Domingues de Sousa  
- Henrique Vinha Rocha  



