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

void redblacktreesort(Item *,int,int);

#ifdef __redblacktreesortonly__
#define sort(v,l,r) redblacktree(v,l,r)
#endif

#endif
