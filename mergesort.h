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

#ifndef __mergesortH__
#define __mergesortH__

#include "ordenacaomacros.h"
void merge(Item *, int, int, int);
void mergesort(Item *,int, int);

#ifdef __mergesortonly__
#define sort(v,l,r) mergesort(v,l,r);
#endif

#endif
