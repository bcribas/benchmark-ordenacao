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

#ifndef __MAINH__
#define __MAINH__

#if defined(__bubblesort__)
#define __bubblesortonly__
#include "bubblesort.h"

#elif defined(__bubblesortsentinela__)
#define __bubblesortSentinelaonly__
#include "bubblesortsentinela.h"

#elif defined(__combsort__)
#define __combsortonly__
#include "combsort.h"

#elif defined(__countingsort__)
#define __countingsortonly__
#include "countingsort.h"

#elif defined(__selectionsort__)
#define __selectionsortonly__
#include "selectionsort.h"

#elif defined(__selectionsortR__)
#define __selectionsortRonly__
#include "selectionsortR.h"

#elif defined(__insertionsortslow__)
#define __insertionsortslowonly__
#include "insertionsortslow.h"

#elif defined(__insertionsort__)
#define __insertionsortonly__
#include "insertionsort.h"

#elif defined(__shellsort__)
#define __shellsortonly__
#include "shellsort.h"

#elif defined(__quicksort__)
#define __quicksortonly__
#include "quicksort.h"

#elif defined(__quicksortinsertion__)
#define __quicksortinsertiononly__
#include "quicksortinsertion.h"

#elif defined(__quicksortM3__)
#define __quicksortM3only__
#include "quicksortM3.h"

#elif defined(__mergesort__)
#define __mergesortonly__
#include "mergesort.h"

#elif defined(__insertionsortmetades__)
#define __insertionsortmetadesonly__
#include "insertionsortmetades.h"

#elif defined(__quicksortM3insertion__)
#define __quicksortM3insertiononly__
#include "quicksortM3insertion.h"

#elif defined(__introsortquickmerge__)
#define __introsortquickmergeonly__
#include "introsortquickmerge.h"

#elif defined(__introsortquickmergelongjmp__)
#define __introsortquickmergelongjmponly__
#include "introsortquickmergelongjmp.h"

#elif defined(__introsortquickheaplongjmp__)
#define __introsortquickheaplongjmponly__
#include "introsortquickheaplongjmp.h"

#elif defined(__systemqsort__)
#define __systemqsortonly__
#include "systemqsort.h"

#elif defined(__pqsortsimple__)
#define __pqsortonly__
#include "pqsortsimple.h"

#elif defined(__heapsort__)
#define __heapsortonly__
#include "heapsort.h"

#elif defined(__radixsort__)
#define __radixsortonly__
#include "radixsort.h"

#elif defined(__dummy__)
#warning "DUMMY SORT, it will not sort"
#define sort ;

#endif

#ifndef sort
#error "NO SORTING ALGORITHM DEFINED"
#endif

#endif
