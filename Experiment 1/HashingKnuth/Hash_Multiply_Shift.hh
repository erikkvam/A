/** @file Hash_Multiply_Shift.hh
    @brief Classe Hash_Multiply_Shift
 */

#define HASH_MULTIPLY_SHIFT_HH

#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include "stdlib.h"
#include <iostream>

using namespace std;

/** @class Hash_Multiply_Shift
    @brief Representa una funció de hash Multiply-Shift.
 */
class Hash_Multiply_Shift {

private:

    int b;

    int w;
    int M;

public:

    Hash_Multiply_Shift(long& baux,int& waux,int& Maux);

    int hash(int& value);

};