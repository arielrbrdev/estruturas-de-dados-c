# estruturas-de-dados-c

Repositório de implementações e experimentos para a disciplina de Estruturas de Dados em C.

## Organização do Projeto

- [`q1/`](q1) – Implementações da Questão 1: busca sequencial, busca binária, estatísticas de tempo, e funções utilitárias de vetor.
- [`q2/`](q2) – Implementações da Questão 2: busca sequencial em lista ligada.

Todo o código-fonte está organizado dentro das respectivas pastas, evitando duplicidade na raiz do repositório.

## Compilação

Cada questão possui um Makefile próprio. Para compilar os arquivos de cada questão, entre na respectiva pasta e execute:

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

Para limpar binários e arquivos objeto:

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
```

## Orientações

- Sempre utilize os Makefiles fornecidos ao invés de compilar manualmente.
- Dúvidas sobre código ou organização? Sinta-se à vontade para abrir uma issue ou contribuir!

---

Para acessar o código da Questão 1 diretamente, [clique aqui](https://github.com/arielrbrdev/estruturas-de-dados-c/tree/main/q1).
