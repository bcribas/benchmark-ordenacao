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

#include <stdlib.h>
#include "bstsort.h"
#include "ordenacaomacros.h"

typedef int Item;
typedef struct no_st{
    Item data;
    struct no_st *right, *left;
    int bumps;
}no_st;

static no_st *pool_head = NULL;

static int empty_pool(){ return pool_head == NULL ? 1 : 0;}

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
    toReturn->bumps = 0;
    toReturn->right = NULL;
    toReturn->left = NULL;
    return toReturn;
}

static void free_node(no_st *node){
    node->right = pool_head;
    pool_head = node;
}

static no_st *creat_node(Item data){
    // no_st *novo_no = malloc(sizeof(no_st)); // aloca cada nó individualmente
    no_st *novo_no = get_free_node(); // pega um nó da piscina de nós
    novo_no->data = data;
    novo_no->right = NULL;
    novo_no->left = NULL;
    novo_no->bumps = 0;
    return novo_no;
}

static no_st *insert(no_st *h, Item data){
    if(h == NULL)
        return creat_node(data);

    if(less(data, h->data))
        h->left = insert(h->left, data);
    else if(less(h->data, data))
        h->right = insert(h->right, data);
    else
        // h->data = data; // atualiaza o Item
        h->bumps++; // incrementa no contador de colisões
    return h;
}

static void in_order(no_st *h){
    int count = 0;
    if(h == NULL)
        return;
    in_order(h->left);
    while(count++ <= h->bumps);
    in_order(h->right);
}

void bstsort(Item *v, int l, int r){
    no_st *root = NULL;
    for(int i=l; i<=r; ++i)
        root = insert(root, v[i]);
    in_order(root);
}
