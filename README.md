# estruturas-de-dados-c

Repositório de implementações e experimentos para a disciplina de Estruturas de Dados em C.

## Organização do Projeto

- [`q1/`](q1) – Implementações da Questão 1: busca sequencial, busca binária, estatísticas de tempo, e funções utilitárias de vetor.
- [`q2/`](q2) – Implementações da Questão 2: busca sequencial em lista ligada.
- [`arvore-hash/`](arvore-hash) – Sistema completo de busca de registros com árvore binária de busca (ABP), tabela hash e manipulação de arquivo binário.

Todo o código-fonte está organizado dentro das respectivas pastas, evitando duplicidade na raiz do repositório.

## Compilação

Cada questão/pasta possui um Makefile próprio. Para compilar os arquivos de cada questão, entre na respectiva pasta e execute:

### Compilar e executar Questão 1 (`q1`)

```sh
cd q1
make
./mainq1
```

### Compilar e executar Questão 2 (`q2`)

```sh
cd q2
make
./mainq2
```

### Compilar e executar Sistema "Árvore-Hash" (`arvore-hash`)

```sh
cd arvore-hash
make
./geraDados     # para criar o arquivo binário de dados
./interface     # para explorar as buscas nas estruturas (menu interativo)
```

Para limpar binários e arquivos objeto em qualquer pasta:

```sh
make clean
```

## Estrutura das pastas

```
q1/
├── busca.c
├── estatisticas.c
├── programa.h
├── resolveq1.c
├── vetor.c
├── Makefile
q2/
├── busca_sequencial.c
├── TADlista.h
├── mainpr.c
├── Makefile
arvore-hash/
├── abp.c
├── abp.h
├── hash.c
├── hash.h
├── geraDados.c
├── interface.c
├── Makefile
```

## Orientações

- Sempre utilize os Makefiles fornecidos ao invés de compilar manualmente.
- Dúvidas sobre código ou organização? Sinta-se à vontade para abrir uma issue ou contribuir!

---

Para acessar o código da Questão 1 diretamente, [clique aqui](https://github.com/arielrbrdev/estruturas-de-dados-c/tree/main/q1).
Para acessar o novo sistema com árvore, hash e arquivo binário, [clique aqui](https://github.com/arielrbrdev/estruturas-de-dados-c/tree/arvore-hash/arvore-hash).
