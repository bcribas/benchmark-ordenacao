/*
 * Copyright(C) 2020, Thalisson Alves <thalisson2030@gmail.com>
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
#include <stdlib.h>
#include "countingsort.h"
#include "ordenacaomacros.h"

void countingsort(Item *v, int l, int r)
{
    Item min = v[l], max = v[l];
    for (int i = l + 1; i <= r; i++)
    {
        if (less(v[i], min))
            min = v[i];
        if (less(max, v[i]))
            max = v[i];
    }

    int range = max - min + 1;
    int *count = (int *)calloc(range, sizeof(int));

    for (int i = l; i <= r; i++)
        count[v[i] - min]++;

    int idx = 0;
    for (int i = 0; i < range; i++)
        for (int j = 0; j < count[i]; j++)
            v[idx++] = i + min;

    free(count);
}
