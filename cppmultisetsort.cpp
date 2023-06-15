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
#include <stdio.h>
#include <set>
#include "ordenacaomacros.h"

using namespace std;

struct Compare
{
  bool operator()(const Item &a,const Item &b) const
  {
    return less(a,b);
  }
};

int main(void)
{
  int t;
  int r;
  r=scanf("%d",&t);
  multiset<Item, Compare> st;
  for(int i=0;i<t;++i){
    Item it;
    r=scanf("%d",&it);
    st.insert(it);
  }
    

  for(auto &x : st)
    r=printf("%d\n",x);
  return 0;
}
