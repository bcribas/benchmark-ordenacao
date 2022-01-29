/*
 * Copyright(C) 2022, André Macedo Rodrigues Alves <andremralves@gmail.com>
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

#include "combsort.h"
#include "ordenacaomacros.h"

void combsort(Item *v,int l,int r)
{
  int gap = r-l;  
  double shrink = 1.3;
  int sorted = 0;

  while(sorted == 0)
  {
    gap = gap/shrink;
    if(gap < 1)
    {
      gap = 1;
      sorted = 1;
    }

    int i = l;
    while(i + gap <= r)
    {
      if(v[i] > v[i+gap])
      {
        exch(v[i], v[i + gap]);
        sorted = 0;
      }
      i++;
    } 
  }
}
