// classe Hash_Multiply_Shift

#include "Hash_Multiply_Shift.hh"

Hash_Multiply_Shift::Hash_Multiply_Shift(long& baux,int& waux,int& Maux){
    b = baux;
    w = waux;
    M = Maux;
    cout << "Shift: " << b << " , " << w << " , " << M << endl;
}

//return the result of "((ax+b)mod2^w)/(2^(w-M))"
int Hash_Multiply_Shift::hash(string value){
    unsigned long hash = 0;
    for(int i = 0; i < value.size(); ++i){
        hash = hash << 8;
        hash += value[i];
    }
    long a = 2654435761;
    return ((hash*a + b) >> (w - M));
}