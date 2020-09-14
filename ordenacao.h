/*
 * Copyright(C) 2020, Bruno César Ribas <bruno.ribas@unb.br>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2.1 of the GNU Lesser General Public License
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it would be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */
#ifndef __ORDENACAO__
#define __ORDENACAO__
typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void bubblesort(Item *v,int l,int r);
void insertionsortslow(Item *v,int l,int r);
void insertionsort(Item *v,int l,int r);
void quicksort(Item *v,int l, int r);
void quicksortM3(Item *v,int l, int r);
void selectionsort(Item *v,int l,int r);
void selectionsortR(Item *v,int l,int r);
void shellsort(Item *v,int l,int r);

#ifdef __dummy__
#define sort(v,l,r) ;
#endif
#ifdef __bubblesort__
#define sort(v,l,r) bubblesort(v,l,r);
#endif
#ifdef __selectionsort__
#define sort(v,l,r) selectionsort(v,l,r);
#endif
#ifdef __selectionsortR__
#define sort(v,l,r) selectionsortR(v,l,r);
#endif
#ifdef __insertionsortslow__
#define sort(v,l,r) insertionsortslow(v,l,r);
#endif
#ifdef __insertionsort__
#define sort(v,l,r) insertionsort(v,l,r);
#endif
#ifdef __shellsort__
#define sort(v,l,r) shellsort(v,l,r);
#endif
#ifdef __quicksort__
#define sort(v,l,r) quicksort(v,l,r);
#endif
#ifdef __quicksortM3__
#define sort(v,l,r) quicksortM3(v,l,r);
#endif

#endif
