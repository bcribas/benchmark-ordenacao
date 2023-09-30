/*
 * Copyright(C) 2023, Eduardo Belarmino Silva <eduardobelarmino100@gmail.com>
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

#ifndef __bstpoolsortH__
#define __bstpoolsortH__
#include "ordenacaomacros.h"

void bstpoolsort(Item *, int, int);

#ifdef __bstpoolsortonly__
#define sort(v,l,r) bstpoolsort(v,l,r)
#endif

#endif
