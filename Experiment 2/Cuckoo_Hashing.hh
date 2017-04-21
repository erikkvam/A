/** @file Cuckoo_Hashing.hh
    @brief Classe Bloom_Filter
 */

#define CUCKOO_HASHING_HH

#include <sstream>
#include <vector>
#include <string>
#include "stdlib.h"
#include <random>
#include <iostream>
#include "Hash_Func_Mod.hh"

using namespace std;

/** @class Cuckoo_Hashing
    @brief Representa un filtre de bloom.
 */
class Cuckoo_Hashing {

private:
    
    vector<vector<int> > vector_tables;

    vector<Hash_Func_Mod> hash_func;
    int p;
    int m;

    int mida;

public:
    // Constructor
    Cuckoo_Hashing(int& tsize);

    void setFamilyHashFunc(int& pFamily, int& mFamily);

    //genera una nova funcio de hash a,b de la familia p,m i la inserta en el vector de hash_func
    void generateHashFunc();

    //retorna true si l'ha insertat normalment, false si ja hi era
    void insertValue(int key);

    //retorna true si el conté, false en cas contrari
    bool contains(int& key);

    void printFilter();
};