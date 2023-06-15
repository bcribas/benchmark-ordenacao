# Benchmark simples de algoritmos de ordenação

Este repositório possui um pequeno e simples benchmark para os algoritmos de
ordenação ensinados na disciplina de EDA-2 da UnB/FGA.

A ideia é ajudar a compreensão do tempo de execução de cada algoritmo na 
prática e também para que o aluno modifique parte dos métodos para entender
se há possibilidade de melhoria em cada método.

# Verificando as dependências

Para verificar se você possui instaladas todas as dependências necessárias, execute:

```
make check
```

Será mostrado na tela caso alguma esteja faltando. Você deverá
instalar as dependências que faltam para conseguir executar o
experimento com sucesso.

A lista de dependências ainda pode não ser exaustiva, se você identificar a
falta de alguma verificação, abra uma [ISSUE](https://github.com/bcribas/benchmark-ordenacao/issues/new/choose) ou mande um [PULL REQUEST](https://github.com/bcribas/benchmark-ordenacao/compare) :)

# Compilando e gerando arquivos de benchmark

Para compilar e gerar os arquivos de benchmark, basta rodar o comando:

```
make
```

Dessa maneira, ele irá compilar todos os algoritmos disponíveis e gerar os arquivos de teste.

## Arquivos de teste

Atualmente os arquivos de teste são gerados em 3 categorias:

 - Ordenado - gera arquivos que já estejam ordenados
 - Ordenado reversamente - gerar arquivos com números ordenamos do maior
   para o menor
 - Aleatório - permutação aleatória dos valores

O tamanho das entradas variam de $2^8$ a $2^{20}$, ou de $256$ a $1048576$,
elementos, com números inteiros podendo variar de $0$ a $5000000$.

Os arquivos gerados ficam armazenados no diretório `input` e a sua
nomenclatura indica exatamente do que se trata: POTENCIA-CATEGORIA

# Métodos disponíveis

## Ordenação

- [bubblesort](bubblesort.c)
- [combsort](combsort.c)
- [countingsort](countingsort.c)
- [cppsort](cppsort.cpp)
- [cppmultisetsort](cppmultisetsort.c)
- [heapsort](heapsort.c)
- [insertionsort](insertionsort.c)
- [insertionsortslow](insertionsortslow.c) 
  - versão bobinha do insertion sort
- [introsortquickheaplong](introsortquickheaplongjmp.c)
- [introsortquickmerge](introsortquickmerge.c)
- [introsortquickmergelong](introsortquickheaplongjmp.c)
- [mergesort](mergesort.c)
- [pqsortsimple](pqsortsimple.c)
- [quicksort](quicksort.c) 
  - versão ingênua do quicksort
- [quicksortM3](quicksortM3.c) 
  - quick com Mediana de 3 elementos
- [quicksortM3insertion](quicksortM3insertion.c)
- [quicksortinsertion](quicksortinsertion.c)
- [radixsort](radixsort.c)
- [selectionsort](selectionsort.c)
- [selectionsortR](selectionsortR.c) 
  - versão recursiva
- [shellsort](shellsort.c)
- [systemqsort](systemqsort.c)


## Outros  

- [separa](separa.c)
- [priorityqueue](priority-queue.c)
- [gera-entrada](gera-entrada)
- [ordenacaomacros](ordenacaomacros.h)
- dummy

# Verificando corretude dos algoritmos

Para verificar se os algoritmos estão corretos, você pode executar:

```
make testesimples
```

O comando iniciará o teste com todos os algoritmos em cima do arquivo `10-reverso`,
$1024$ elementos ordenados de forma não crescente, e mostrará o resultado do
`digest` do arquivo gerado. Todos os algoritmos, exceto o dummy, devem possuir
o mesmo valor.

Agora, com:

```
make teste
```

Todos os algoritmos serão testados com todas as variações do arquivo com
$2^15$, $32768$ elementos. Da mesma forma, o HASH deve coincidir em todas as
implementações.

# Benchmark

Para rodar o benchmark com todos os algoritmos, basta executar:

```
make time.ordenado time.reverso time.aleatorio
```

Desta forma, serão testadas todas as implementações com todas as
configurações. Você também pode executar apenas uma das configurações por vez, como no exemplo: 

```
make time.aleatorio
```

 - gerando apenas as saídas contra os arquivos com disposição aleatória.

Por padrão, o tempo limite de execução está desligado e você pode definir um
tempo em segundos, por exemplo:

```
TIMEOUT=3 make time.aleatorio
```

Assim, as implementações terão apenas $3$ segundos de tempo de execução.

Você também pode testar apenas um subconjunto de métodos definindo a
variável `BINARY`, por exemplo:

```
BINARY="quicksort shellsort" make time.reverso
```

E ainda pode combinar com a variável de `TIMEOUT` sem nenhum problema.

# Limpando o ambiente

Com a diretiva `clean`, todos os arquivos gerados serão removidos. Tanto os
binários, quanto os arquivos de testes e os arquivos de resultado.
