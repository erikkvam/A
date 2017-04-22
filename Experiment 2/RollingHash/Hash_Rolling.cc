// classe Hash_Rolling

#include "Hash_Rolling.hh"

Hash_Rolling::Hash_Rolling(int& paux,int& MODaux){
    p = paux;
    MOD = MODaux;
}

//return the result of rolling hash
unsigned int Hash_Rolling::hash(string value){
    int hash = 0;
    size_t str_len = value.size();
    for(int i = 0, k = str_len -1; i < str_len; i++, k--) {
            hash = hash + (int)(value[i] * pow(p, k))%MOD;
            hash = hash % MOD;
    }
    return hash;
}