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
#ifndef __redblacktreeH__
#define __redblacktreeH__
#include "ordenacaomacros.h"

static no* novo_no(Item item, color color);
static bool isRed(no *r);
static no* rotateL(no* r);
static no* rotateR(no* r);
static void flipColors(no *r);
static no* insereRB(no *r, Item item);
static void em_ordem(no *r, Item *v, int *idx);
void redblacktree(Item *,int,int);

#ifdef __redblacktreeonly__
#define sort(v,l,r) redblacktree(v,l,r)
#endif

#endif
