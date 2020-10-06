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
#ifndef __introsortquickmergeH__
#define __introsortquickmergeH__
#include "ordenacaomacros.h"

void introsortquickmerge(Item *V,int l,int r);

#ifdef __introsortquickmergeonly__
#define sort(v,l,r) introsortquickmerge(v,l,r)
#endif

#endif
