/*
 * Copyright(C) 2023, Lucas Soares Rodrigues <github.com/soaresrlucas>
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
#include "redblacktree.h"
#include "ordenacaomacros.h"
#include <stdbool.h>
#include <stdlib.h>
typedef enum color {RED, BLACK} color;

typedef struct no {
  Item item;
  struct no *esq, *dir;
  color color;
  int repeticoes;
}no;

no* novo_no(Item item, color color) {
  no *t = malloc(sizeof(no));
  t->item = item;
  t->color = color;
  t->esq = NULL;
  t->dir = NULL;
  t->repeticoes = 1;
}

bool isRed(no *r) {
  if(r == NULL)
    return false;
  if(r->color == RED)
    return true;
  return false;
}

no* rotateL(no* r) {
  no *t = r->dir;
  r->dir = t->esq;
  t->esq = r;
  t->color = r->color;
  r-> color = RED;
  return t;
}

no* rotateR(no* r) {
  no *t = r->esq;
  r->esq = t->dir;
  t->dir = r;
  t->color = r->color;
  r-> color = RED;
  return t;
}

void flipColors(no *r) {
  r->color = RED;
  r->esq->color = BLACK;
  r->dir->color = BLACK;
}

no* insereRB(no *r, Item item){
  if(r == NULL) return novo_no(item, RED);
  if(less(item, r->item)) r->esq = insereRB(r->esq, item);
  else if(less(r->item, item)) r->dir = insereRB(r->dir, item);
  else r->repeticoes++;

  if(!isRed(r->esq) && isRed(r->dir)) r = rotateL(r);
  if(isRed(r->esq) && isRed(r->esq->esq)) r = rotateR(r);
  if(isRed(r->esq) && isRed(r->dir)) flipColors(r);
  return r;
}

void em_ordem(no *r, Item *v, int *idx) {
  if(r == NULL)
    return;
  em_ordem(r->esq, v, idx);
  for(int i = 0; i < r->repeticoes; i++) {
    v[*idx] = r->item;
    *idx = *idx + 1;
  }
  em_ordem(r->dir, v, idx);
}

void redblacktree(Item *v, int l, int r){
  no *RBT = NULL;
  int idx = l;
  for(int i = l; i <= r; i++) {
    RBT = insereRB(RBT, v[i]);
  }
  em_ordem(RBT, v, &idx);
}
