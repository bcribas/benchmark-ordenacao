# Copyright(C) 2020, Bruno César Ribas <bruno.ribas@unb.br>
#
# This program is free software; you can redistribute it and/or modify it
# under the terms of version 2.1 of the GNU Lesser General Public License
# as published by the Free Software Foundation.
#
# This program is distributed in the hope that it would be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

SOURCE=$(wildcard *.c)
BINARY?=dummy\
				bubblesort\
				bubblesortsentinela\
				combsort\
				selectionsort\
				selectionsortR\
				insertionsortslow\
				insertionsort\
				shellsort\
				quicksort\
				quicksortinsertion\
				quicksortM3\
				quicksortM3insertion\
				mergesort\
				systemqsort\
				introsortquickmerge\
				introsortquickmergelongjmp\
				introsortquickheaplongjmp\
				radixsort\
				cppsort\
				pqsortsimple\
				heapsort\
				countingsort

ORDENADO=$(wildcard input/*ordenado)
ALEATORIO=$(wildcard input/*aleatorio)
REVERSO=$(wildcard input/*reverso)
TIMEOUT?=0
CFLAGS=-O2 -static
CXXFLAGS=-O2 -static

all: input/.in ${BINARY}

check:
	@for COMANDO in time timeout shuf md5sum sort bash gcc; do\
		if ! which $$COMANDO >/dev/null; then\
			echo "Faltando comando '$$COMANDO'";\
			exit 1;\
		fi;\
	done
	@echo "As dependências parecem estar todas presentes"

input/.in:
	mkdir -p input
	cd input && bash ../gera-entrada
	touch input/.in

%: main.c %.c
	gcc -D__$@__ $(CFLAGS) $^ -o $@

dummy: main.c
	gcc -D__$@__ $(CFLAGS) $^ -o $@

quicksort: main.c quicksort.c separa.c
	gcc -D__$@__ $(CFLAGS) $^ -o $@

quicksortinsertion: main.c quicksortinsertion.c separa.c insertionsort.c
	gcc -D__$@__ $(CFLAGS) $^ -o $@

quicksortM3: main.c quicksortM3.c separa.c
	gcc -D__$@__ $(CFLAGS) $^ -o $@

quicksortM3insertion: main.c quicksortM3insertion.c separa.c insertionsort.c
	gcc -D__$@__ $(CFLAGS) $^ -o $@

introsortquickmerge: main.c introsortquickmerge.c separa.c insertionsort.c mergesort.c
	gcc -D__$@__ $(CFLAGS) $^ -o $@ -lm

introsortquickmergelongjmp: main.c introsortquickmergelongjmp.c separa.c insertionsort.c mergesort.c
	gcc -D__$@__ $(CFLAGS) $^ -o $@ -lm

introsortquickheaplongjmp: main.c introsortquickheaplongjmp.c separa.c insertionsort.c heapsort.c priority-queue.c
	gcc -D__$@__ $(CFLAGS) $^ -o $@ -lm

radixsort: main.c radixsort.c
	gcc -D__$@__ $(CFLAGS) $^ -o $@ -lm

pqsortsimple: main.c pqsortsimple.c priority-queue.c
	gcc -D__$@__ $(CFLAGS) $^ -o $@

heapsort: main.c heapsort.c priority-queue.c
	gcc -D__$@__ $(CFLAGS) $^ -o $@

printorder:
	@for T in 08 09 10 11 12 13 14 15 16 17 18 19 20;do\
		printf "  %s  " $$T;\
	done;\
	echo

time.%: $(BINARY) input/.in
	@echo "--- $@ ---"
	@ulimit -s 32000
	@for B in $(BINARY); do\
		echo "# $$B";\
		for F in input/*-$(subst time.,,$@);do\
			printf " ";\
			timeout $(TIMEOUT) time -f %e ./$$B < $$F >/dev/null|| echo " TLE ";\
		done 2>&1|tr -d '\n';\
		echo;\
	done | tee $@

teste: $(BINARY) input/.in
	@for F in input/15*;do\
		echo "# $$F";\
		for B in $(BINARY); do\
			printf "$$B ";\
			timeout $(TIMEOUT) ./$$B < $$F |md5sum|| echo " TLE ";\
		done;\
		echo;\
	done

testesimples: $(BINARY) input/.in
	@for B in $(BINARY); do\
		printf "$$B ";\
		./$$B < input/10-reverso|md5sum;\
	done

echo%:
	@echo

.PHONY: teste testesimples check

clean:
	rm -f $(BINARY) time.*

dist-clean: clean
	rm -rf input/
