// created at 9/27/2025 by Dave-cc

#ifndef __HASH_H_
#define __HASH_H_

#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

#define HT_PRIME1 17
#define HT_PRIME2 19

typedef struct {
    char* key;
    char* value;
}ht_item;

typedef struct{
    size_t size;
    size_t count;
    ht_item** items;
}ht_hash_table;




void ht_del_hash_table(ht_hash_table* tb);
void ht_del_item(ht_item* i);
ht_hash_table* ht_new();
ht_item* ht_new_item(const char* k, const char* v);
static int get_hash(const char* s, const int num_bucket, const int attemp);

#endif
