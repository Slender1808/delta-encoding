# Delta encoding

## Test
```shell
./cmake-build-release/delta c ../test.txt ../test2.txt ../out.compress
```

## Build
```shell
cmake --build "./cmake-build-release" --target delta -- -j 6
```
## Header File Compress

### Tamanho

Tamanho do arquivo original salvo como numero unsigned long long int

### Links

numero da posição bloco

se posição for negativa significa que bloco está internamente

### Blocos

são 64 bits salvo no final do arquivo


| Exemplo | Tipo |
|--|--|
| 8200 | unsigned long long int |
| 1641355534 | unsigned long long int |
| 1001001111011100 | bitset<16> |
| 1000101111001100011... | bitset<64> | 


## Test

Criando arquivo aleatório

```bash
head -c 4K /dev/urandom > /tmp/4k.rand
```

Criando arquivo zeros

```bash
head -c 4K /dev/zero > /tmp/4k.zero
```

## Debug

Massif

```bash
valgrind --tool=massif --heap=yes --stacks=yes  ./cmake-build-debug/delta ./massif.out
```

Callgrind

```bash
valgrind --tool=callgrind --collect-jumps=yes --collect-systime=yes --collect-bus=yes --dump-instr=yes ./cmake-build-debug/t3 ./callgrind.out
```

## Links

[https://www.cplusplus.com/reference/climits/](https://www.cplusplus.com/reference/climits/)

[https://en.cppreference.com/w/cpp/language/type](https://en.cppreference.com/w/cpp/language/types)

[https://en.m.wikipedia.org/wiki/Delta_encoding](https://en.m.wikipedia.org/wiki/Delta_encoding)