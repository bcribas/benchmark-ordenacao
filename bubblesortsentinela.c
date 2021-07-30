/*
 * Copyright(C) 2021, Christian Fleury <chfleurysiq@gmail.com>
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

#include "ordenacaomacros.h"

void bubblesortSentinela(Item *v, int l, int r)
{
  int sentinela;
  for (int i = l; i < r; i++)
  {
    sentinela = 0;
    for (int j = l + 1; j <= r; j++)
    {
      if (less(v[j], v[j - 1]))
      {
        exch(v[j - 1], v[j]);
        sentinela = 1;
      }
    }
    if (!sentinela)
      break;
  }
}
