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

#ifndef __bstsortH__
#define __bstsortH__
#include "ordenacaomacros.h"

void bstsort(Item *, int, int);

#ifdef __bstsortonly__
#define sort(v,l,r) bstsort(v,l,r)
#endif

#endif
