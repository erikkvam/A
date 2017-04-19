/** @file Bloom_Filter.hh
    @brief Classe Bloom_Filter
 */

#define BLOOM_FILTER_HH

#include <sstream>
#include <vector>
#include <string>
#include "stdlib.h"
#include <random>
#include <iostream>
#include "Hash_Func_Mod.hh"

using namespace std;

/** @class Bloom_Filter
    @brief Representa un filtre de bloom.
 */
class Bloom_Filter {

private:
    
    vector<bool> table;

    vector<Hash_Func_Mod> hash_func;
    int p;
    int m;

public:
    // Constructor
    Bloom_Filter(int& k);

    void setFamilyHashFunc(int& pFamily, int& mFamily);

    //genera una nova funcio de hash a,b de la familia p,m i la inserta en el vector de hash_func
    void generateHashFunc();

    //retorna true si l'ha insertat normalment, false si ja hi era
    void insertValue(int& key);

    //retorna true si el conté, false en cas contrari
    bool possiblyContains(int& key);

    void printFilter();
};


    