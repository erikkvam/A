/** @file Bloom_Filter_Knuth.hh
    @brief Classe Bloom_Filter_Knuth
 */

#define BLOOM_FILTER_KNUTH_HH

#include <sstream>
#include <vector>
#include <string>
#include "stdlib.h"
#include <random>
#include <iostream>
#include "Hash_Multiply_Shift.hh"

using namespace std;

/** @class Bloom_Filter_Knuth
    @brief Representa un filtre de bloom.
 */
class Bloom_Filter_Knuth {

private:
    
    vector<bool> table;

    vector<Hash_Multiply_Shift> hash_func;
    int M;
    int w;

public:
    // Constructor
    Bloom_Filter_Knuth(int k);

    void setFamilyHashFunc(int& mFamily, int wFamily);

    //genera una nova funcio de hash a,b de la familia p,m i la inserta en el vector de hash_func
    void generateHashFunc();

    //retorna true si l'ha insertat normalment, false si ja hi era
    void insertValue(string key);

    //retorna true si el conté, false en cas contrari
    bool possiblyContains(string key);

    void printFilter();
};


    