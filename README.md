# 🃏 Paciência em C++ com SFML

Jogo de Paciência (Solitaire) implementado em C++ com interface gráfica usando SFML.

OBS.: Esse projeto nasceu a partir de um exercício proposto pelo prof. Vladimir Marques Erthal, no Cefet RJ - Maria da Graça, em sala de aula. Os requisitos do exercícios podem ser encontrados nesse mesmo README.

## 📦 Funcionalidades

- Baralho embaralhado com 52 cartas
- Regras opcionais: pilha por naipe e ordem decrescente iniciando com Rei (K)
- Interface visual com SFML
- Drag and drop (arraste e solte) para jogar cartas
- Pular cartas com a tecla `ESPAÇO`

### Requisitos Funcionais:

#### RF1 A cada rodada, o jogo deve retirar uma carta do baralho e mostrar para o jogador.
#### RF2 Após ver a carta da rodada, o jogador deve escolher em qual pilha da mesa quer colocar a carta. São 4 (quatro) pilhas possíveis.
#### RF3 Após escolher a pilha, o jogo deve exibir o conteúdo completo das 4 pilhas da mesa, antes de iniciar uma nova rodada.
#### RF4 Quando acabarem as cartas do baralho, o jogo será encerrado.

### Requisitos Não Funcionais:
#### RNF1 O baralho deve ser tratado com a estrutura de dados pilha utilizando vetores simples.
#### RNF2 Cada pilha da mesa devem ser tratada com uma estrutura de dados pilha utilizando vetores simples.
#### RNF3 Para tirar uma carta do baralho, utilize o método pop. Não haverá método push, pois o baralho não receberá novas cartas.
#### RNF4 Para colocar uma carta na mesa, utilize um único método push, que deve receber por parâmetro o número da pilha na qual se deseja colocar a carta.
#### RNF5 Para exibir todas as cartas das pilhas da mesa, deve existir uma função separada, para que a "main" não acesse o conteúdo das pilhas.
#### RNF6 Utilizar o seguinte trecho de código na seção global do programa para criar o baralho já embaralhado e a mesa vazia:

### Exercícios Opcionais:

```Implementar uma opção para pular a carta da rodada, sem adicionar em nenhuma pilha. Nesse caso, será preciso criar uma pilha adicional para guardar as cartas puladas. Quando acabarem as cartas do baralho, se existirem cartas nessa pilha adicional, retirar todas e adicionar no baralho, para prosseguir o jogo.```

```Só permitir que cada coluna da mesa receba um único naipe.```

```Só permitir que as cartas sejam colocadas na mesa na ordem correta (iniciando pelo "K").```

## 🚀 Requisitos

- SFML 2.5 ou superior
- CMake 3.10+

## 🔧 Compilação

```bash
mkdir build
cd build
cmake ..
make
./Patientia