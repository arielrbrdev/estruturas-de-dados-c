# estruturas-de-dados-c

Repositório de implementações e experimentos para a disciplina de Estruturas de Dados em C.

## Organização do Projeto

- [`q1/`](q1) – Implementações da Questão 1: busca sequencial, busca binária, estatísticas de tempo, e funções utilitárias de vetor.
- [`q2/`](q2) – Implementações da Questão 2: busca sequencial em lista ligada.
- [`arvore-hash/`](arvore-hash) – Sistema completo de busca de registros com árvore binária de busca (ABP), tabela hash e manipulação de arquivo binário.
- [`listase/`](listase) – Implementações de lista simplesmente encadeada, incluindo exemplos e exercícios (playlist, aula etc).
- [`sort/`](sort) – Algoritmos de ordenação diversos.
- [`verifica-malware/`](verifica-malware) – Implementação de detector simples de malware em arquivos.

Todo o código-fonte está organizado dentro das respectivas pastas, evitando duplicidade na raiz do repositório.

## Compilação

Cada questão/pasta possui Makefile próprio (quando aplicável). Para compilar os arquivos de cada questão, entre na respectiva pasta e execute:

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

### Compilar e executar Algoritmos de Ordenação (`sort`)

```sh
cd sort
# make ou gcc sort.c -o sort
./sort   # se aplicável
```

### Compilar e executar Lista Simplesmente Encadeada (`listase`)

```sh
cd listase
# make ou gcc listase.c -o listase
# explorar playlist.c, aula.c, usalse.c conforme comentários
```

### Compilar e executar Verificador de Malware (`verifica-malware`)

```sh
cd verifica-malware
# make ou gcc verificamalware.c -o verifica-malware
./verifica-malware   # se aplicável
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
listase/
├── aula.c
├── listase.c
├── listase.h
├── playlist.c
├── usalse.c
sort/
├── ordena.c
├── sort.c
├── sorts
verifica-malware/
├── verificamalware.c
```

## Orientações

- Sempre utilize os Makefiles fornecidos ao invés de compilar manualmente, quando disponíveis.
- Dúvidas sobre código ou organização? Sinta-se à vontade para abrir uma issue ou contribuir!

---

Para acessar o código da Questão 1 diretamente, [clique aqui](https://github.com/arielrbrdev/estruturas-de-dados-c/tree/main/q1).
Para acessar o sistema de árvore/hash/arquivo binário, [clique aqui](https://github.com/arielrbrdev/estruturas-de-dados-c/tree/main/arvore-hash).
Para explorar a lista encadeada, [clique aqui](https://github.com/arielrbrdev/estruturas-de-dados-c/tree/main/listase).
Para ver os algoritmos de ordenação, [clique aqui](https://github.com/arielrbrdev/estruturas-de-dados-c/tree/main/sort).
Para o detector de malware, [clique aqui](https://github.com/arielrbrdev/estruturas-de-dados-c/tree/main/verifica-malware).
