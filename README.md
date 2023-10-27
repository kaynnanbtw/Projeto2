# Interpretador de Linguagem Assembly Simples (Toy Assembly)

Este é um interpretador simples escrito em C para uma linguagem de assembly de nível básico. O interpretador é capaz de executar um conjunto limitado de instruções que incluem operações aritméticas, manipulação de registros e acesso à memória. O interpretador foi projetado para aceitar programas escritos em uma linguagem assembly customizada e executar as instruções de acordo com as especificações.

## Instruções Suportadas

As instruções suportadas pelo interpretador são as seguintes:

- `MOV RX INTEGER`: atribui o valor de um número inteiro a um registro específico.
- `MOV RX RY`: atribui o valor de um registro a outro registro.
- `ADD RX RY RZ`: adiciona os valores de dois registros e armazena o resultado em um terceiro registro.
- `SUB RX RY RZ`: subtrai o valor de um registro do valor de outro registro e armazena o resultado em um terceiro registro.
- `MUL RX RY RZ`: multiplica os valores de dois registros e armazena o resultado em um terceiro registro.
- `DIV RX RY RZ`: divide o valor de um registro pelo valor de outro registro e armazena o resultado em um terceiro registro.
- `MOD RX RY RZ`: calcula o resto da divisão entre dois registros e armazena o resultado em um terceiro registro.
- `BEQ RX RY ADDRESS`: direciona o fluxo do programa para uma instrução específica se dois registros forem iguais.
- `BLT RX RY ADDRESS`: direciona o fluxo do programa para uma instrução específica se um registro for menor que outro.
- `JMP ADDRESS`: direciona o fluxo do programa para uma instrução específica.
- `LOAD RX RY`: carrega o conteúdo da memória em um registro específico.
- `STORE RX RY`: armazena o conteúdo de um registro na memória.
- `PRINT RX`: imprime o valor de um registro na saída.
- `EXIT`: encerra a execução do programa.

## Compilação e Execução

Para compilar o código, certifique-se de ter o compilador GCC instalado no seu sistema. Você pode usar o seguinte comando para compilar o programa:

`gcc -o nome_do_executavel nome_do_arquivo.c`

Para executar o programa compilado, use o seguinte comando:

`./nome_do_executavel`

Substitua `nome_do_executavel` pelo nome que deseja dar ao executável e `nome_do_arquivo` pelo nome real do arquivo fonte em C.

Certifique-se de fornecer a entrada do programa conforme as instruções especificadas para garantir que o programa funcione corretamente.

Este interpretador de linguagem assembly foi desenvolvido como parte de um projeto de programação em C.
