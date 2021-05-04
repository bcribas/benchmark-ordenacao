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
#include "pqsortsimple.h"
#include "ordenacaomacros.h"
#include "priority-queue.h"

void pqsortsimple(Item *v, int l, int r)
{
  int k;
  PQinit((r-l+1));
  for(k=l;k<=r;k++) PQinsert(v[k]);
  for(k=r;k>=l;k--) v[k]=PQdelmax();
}
