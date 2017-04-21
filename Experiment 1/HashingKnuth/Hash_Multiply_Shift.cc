// classe Hash_Multiply_Shift

#include "Hash_Multiply_Shift.hh"

Hash_Multiply_Shift::Hash_Multiply_Shift(long& baux,int& waux,int& Maux){
    b = baux;
    w = waux;
    M = Maux;
}

//return the result of "((ax+b)mod2^w)/(2^(w-M))"
int Hash_Multiply_Shift::hash(int& value){
    long a = 2654435761;
    return ((value*a + b) >> (w - M));
}