// classe Hash_Func_Mod

#include "Hash_Func_Mod.hh"

Hash_Func_Mod::Hash_Func_Mod(int& paux,int& maux,int& aaux,int& baux){
    p = paux;
    m = maux;
    a = aaux;
    b = baux;
}

//return the result of "((ax + b) mod p) mod m"
int Hash_Func_Mod::hash(int& value){
    return (((a*value+b)%p)%m);
}