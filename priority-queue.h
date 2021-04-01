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
#ifndef __PQ__
#define __PQ__
#include "ordenacaomacros.h"

void PQinit(int);
int PQempty();
void PQinsert(Item);
Item PQdelmax();
void fixUp(Item *, int);
void fixDown(Item *, int, int);
#endif
