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

#ifndef __SEPARAH__
#define __SEPARAH__

#include "ordenacaomacros.h"

int separaCORMEM(Item *V,int l,int r);
int separaSEDGEWICK(Item *V,int l,int r);

#ifdef __SEPARASEDGEWICKDEFAULT__
#define separa(v,l,r) separaSEDGEWICK(v,l,r)
#else
#define separa(v,l,r) separaCORMEM(v,l,r)
#endif

#endif
