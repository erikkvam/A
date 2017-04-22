// classe Hash_Func_Mod

#include "Hash_Func_Mod.hh"

Hash_Func_Mod::Hash_Func_Mod(int& paux,int& maux,int& aaux,int& baux){
    p = paux;
    m = maux;
    a = aaux;
    b = baux;
}

//return the result of "((ax + b) mod p) mod m"
unsigned int Hash_Func_Mod::hash(string value){
    unsigned long hash = 0;
    for(int i = 0; i < value.size(); ++i){
        hash = hash << 8;
        hash += value[i];
    }
    hash = (((a*hash+b)%p)%m);
    //cout << "Key: " << value << " HashPosition: " << hash << endl;
    return hash;
}