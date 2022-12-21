#ifndef __insertionsortmetadesH__
#define __insertionsortmetadesH__
#include "ordenacaomacros.h"

void insertionsortmetades(Item *,int,int);

#ifdef __insertionsortmetadesonly__
#define sort(v,l,r) insertionsortmetades(v,l,r);
#endif
#endif
