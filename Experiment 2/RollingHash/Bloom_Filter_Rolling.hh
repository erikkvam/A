/** @file Bloom_Filter_Rolling.hh
    @brief Classe Bloom_Filter_Rolling
 */

#define BLOOM_FILTER_ROLLING_HH

#include <sstream>
#include <vector>
#include "stdlib.h"
#include <random>
#include <iostream>
#include <string.h>
#include "Hash_Rolling.hh"

using namespace std;

/** @class Bloom_Filter_Rolling
    @brief Representa un filtre de Bloom_Filter_Rolling.
 */
class Bloom_Filter_Rolling {

private:
    
    vector<bool> table;

    vector<Hash_Rolling> hash_func;
    int p;
    int m;

public:
    // Constructor
    Bloom_Filter_Rolling(int& k);

    void setFamilyHashFunc(int& pFamily, int& mFamily);

    //genera una nova funcio de hash a,b de la familia p,m i la inserta en el vector de hash_func
    void generateHashFunc();

    //retorna true si l'ha insertat normalment, false si ja hi era
    void insertValue(string key);

    //retorna true si el conté, false en cas contrari
    bool possiblyContains(string key);

    void printFilter();
};


    