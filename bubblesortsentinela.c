#include "ordenacaomacros.h"

void bubbleSortSentinela(Item *v, int l, int r)
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
    {
      break;
    }
  }
}
