/** @file Hash_Rolling.hh
    @brief Classe Hash_Rolling
 */

#define HASH_ROLLING_HH

#include <sstream>
#include <vector>
#include <string.h>
#include <cmath>
#include "stdlib.h"
#include <iostream>

using namespace std;

/** @class Hash_Rolling
    @brief Representa una funció de hash Rolling.
 */
class Hash_Rolling {

private:

    int p;
    int MOD;

public:

    Hash_Rolling(int& paux,int& MODaux);

    unsigned int hash(string value);

};