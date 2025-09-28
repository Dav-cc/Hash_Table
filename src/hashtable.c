// created at 9/27/2025 by Dave-cc

#include "hashtable.h"




ht_item* new_item(const char* k, const char* v){
    ht_item* i = malloc(sizeof(ht_item));
    i->key = strdup(k);
    i->value = strdup(v);
    return i;
}
 

ht_hash_table* ht_new(){
    ht_hash_table* tb = malloc(sizeof(ht_hash_table));
    tb->size = 53;
    tb->count = 0;
    tb->items = calloc(tb->size, sizeof(ht_item));
    return tb;
}

void ht_del_item(ht_item* i){
    free(i->key);
    free(i->value);
    free(i);
}

void ht_del_hash_table(ht_hash_table* tb){
    for(int i = 0; i<tb->count; i++){
        ht_item* item = tb->items[i];
        if(item != NULL){
            ht_del_item(item);
        }
    }
    free(tb->items);
    free(tb);
}


static long ht_hash(const char* s, const int a, const int m){
    long hash = 0;
    const int len_s = strlen(s);
    for(int i =0 ; i< len_s ; i++){
        hash += (long)pow(a, len_s - (i+1) * s[i]);
        hash = hash % m;
    }
    return hash;
}



static int get_hash(const char* s, const int num_bucket, const int attemp){
    const int hash_a = ht_hash(s, HT_PRIME1, num_bucket);
    const int hash_b = ht_hash(s, HT_PRIME2, num_bucket);
    return (hash_a + (attemp + (hash_b + 1))) % num_bucket;
}



