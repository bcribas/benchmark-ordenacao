/*
 * Copyright(C) 2023, Eduardo Belarmino Silva <eduardobelarmino100@gmail.com>
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

#include "redblacktreepoolsort.h"
#include "ordenacaomacros.h"
#include <stdlib.h>
#define isRed(a) ((a) && a->color == Red)

typedef enum {Red, Black}Color;
typedef struct no_st{
    Item data;
    struct no_st *right, *left;
    int bumps;
    Color color;
}no_st;

static no_st *pool_head = NULL;
static int grow_pool(int n){
    no_st *novo_no = malloc(sizeof(no_st)*n);
    if(novo_no == NULL)
        return 0;
    n--;
    for(int i=0; i<n; ++i)
        novo_no[i].right = &novo_no[i+1];
    novo_no[n].right = pool_head;
    pool_head = novo_no;
    return 1;
}

static no_st* get_free_node(){
    no_st *toReturn = pool_head;
    pool_head = pool_head->right;
    return toReturn;
}

static void free_node(no_st *node){
    node->right = pool_head;
    pool_head = node;
}

static no_st* create_node(Item data){
    no_st *novo_no = get_free_node();
    novo_no->data = data;
    novo_no->right = NULL;
    novo_no->left = NULL;
    novo_no->bumps = 0;
    return novo_no;
}

static no_st* rotate_left(no_st *h){
    no_st *x = h->right;
    h->right = x->left;
    x->left = h;
    h->color = Red;
    x->color = Black;
    return x;
}

static no_st* rotate_right(no_st *h){
    no_st *x = h->left;
    h->left = x->right;
    x->right = h;
    h->color = Red;
    x->color = Black;
    return x;
}

static void flip_colors(no_st *h){
    h->right->color = Black;
    h->left->color = Black;
    h->color = Red;
}

static no_st *insert(no_st *h, Item data){
    if(h == NULL)
        return create_node(data);

    if(less(data, h->data))
        h->left = insert(h->left, data);
    else if(less(h->data, data))
        h->right = insert(h->right, data);
    else
        h->bumps++;
    
    if(isRed(h->right) && !isRed(h->left))
        h = rotate_left(h);
    if(isRed(h->left) && isRed(h->left->left))
        h = rotate_right(h);
    if(isRed(h->left) && isRed(h->right))
        flip_colors(h);
    return h;
}

static void in_order(no_st *h, Item *v, int *it){
    if(h == NULL)
        return;
    int count = 0;
    in_order(h->left, v, it);
    while(count++ <= h->bumps){
        v[*it] = h->data;
        *it += 1;
    }
    in_order(h->right, v, it);
    free_node(h);
}

void redblacktreepoolsort(Item *v, int l, int r){
    grow_pool(r-l+1);
    no_st *root = NULL;
    int it = l;
    for(int i = l; i <= r; i++)
        root = insert(root, v[i]);
    in_order(root, v, &it);
}
