# Projeto de codificação Delta

Este é um projeto educacional desenvolvido para aprender sobre compactação de dados, otimização de desempenho, uso eficiente de memória e depuração em C++. Inclui scripts de teste que geram arquivos de entrada aleatórios ou com preenchimento zero. As ferramentas Valgrind e Callgrind são utilizadas para detecção de vazamentos de memória e análise de desempenho.

## Como compilar

Para compilar o código, utilize o seguinte comando:

```shell
cmake --build "./cmake-build-release" --target delta -- -j 6
```

## Como executar

Para executar a compactação usando o algoritmo de codificação Delta, utilize o seguinte comando:

```shell
./cmake-build-release/delta c ../test.txt ../test2.txt ../out.compress
```

## Estrutura de dados da compressão

O arquivo compactado segue a seguinte estrutura de dados:

- **Tamanho**: Representa o tamanho do arquivo original, salvo como um número unsigned long long int.
- **Links**: Representa a posição do bloco. Se a posição for negativa, isso significa que o bloco está contido internamente.
- **Blocos**: Representados por 64 bits, são salvos no final do arquivo.

Exemplo de estrutura de dados:

| Dado | Tipo |
|--|--|
| 8200 | unsigned long long int |
| 1641355534 | unsigned long long int |
| 1001001111011100 | bitset<16> |
| 1000101111001100011... | bitset<64> |

## Testando o programa

Criando um arquivo de teste com dados aleatórios:

```bash
head -c 4K /dev/urandom > /tmp/4k.rand
```

Criando um arquivo de teste com zeros:

```bash
head -c 4K /dev/zero > /tmp/4k.zero
```

## Debug

Utilizando o Massif para análise de uso de memória:

```bash
valgrind --tool=massif --heap=yes --stacks=yes  ./cmake-build-debug/delta ./massif.out
```

Utilizando o Callgrind para análise de desempenho:

```bash
valgrind --tool=callgrind --collect-jumps=yes --collect-systime=yes --collect-bus=yes --dump-instr=yes ./cmake-build-debug/t3 ./callgrind.out
```

## Links úteis

- [cplusplus.com: Referência de limites de C++](https://www.cplusplus.com/reference/climits/)
- [cppreference.com: Tipos de linguagem C++](https://en.cppreference.com/w/cpp/language/types)
- [Wikipedia: Codificação Delta](https://en.m.wikipedia.org/wiki/Delta_encoding)
