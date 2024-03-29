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

#ifndef __bubblesortSentinelaH__
#define __bubblesortSentinelaH__
#include "ordenacaomacros.h"
void bubblesortSentinela(Item *, int, int);

#ifdef __bubblesortSentinelaonly__
#define sort(v, l, r) bubblesortSentinela(v, l, r)
#endif

#endif
