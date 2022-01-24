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
#ifndef __countingsortH__
#define __countingsortH__
#include "ordenacaomacros.h"

void countingsort(Item *, int, int);

#ifdef __countingsortonly__
#define sort(v, l, r) countingsort(v, l, r)
#endif

#endif
