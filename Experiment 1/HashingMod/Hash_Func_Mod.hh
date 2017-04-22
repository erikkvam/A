/** @file Hash_Func_Mod.hh
    @brief Classe Hash_Func_Mod
 */

#define HASH_FUNC_MOD_HH

#include <sstream>
#include <vector>
#include <string.h>
#include <cmath>
#include "stdlib.h"
#include <iostream>

using namespace std;

/** @class Hash_Func_Mod
    @brief Representa una funció de hash Modular.
 */
class Hash_Func_Mod {

private:

    int p;
    int m;

    int a;
    int b;

public:

    Hash_Func_Mod(int& paux,int& maux,int& aaux,int& baux);

    unsigned int hash(string value);

};