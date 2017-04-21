// classe Bloom_Filter_Knuth

#include "Bloom_Filter_Knuth.hh"

Bloom_Filter_Knuth::Bloom_Filter_Knuth(int k) {
    table = vector<bool>(k,false);
}

void Bloom_Filter_Knuth::setFamilyHashFunc(int& mFamily, int wFamily){
    M = mFamily;
    w = wFamily;
    //cout << M << " , " << w << endl;
}

//genera una nova funcio de hash b de la familia w,M i la inserta en el vector de hash_func
void Bloom_Filter_Knuth::generateHashFunc(){
    long p = exp2(w-M);
    //cout << p;
    long b = rand() % p + 1;  // generates number in the range 1..p

    //cout << "hash function: " << b << endl;

    Hash_Multiply_Shift function(b,w,M);
    hash_func.push_back(function);
}

//inserta un element al filtre de hash
void Bloom_Filter_Knuth::insertValue(int& key){
    for(int i = 0; i < hash_func.size(); ++i){
        int pos = hash_func[i].hash(key)%table.size();
        if(!table[pos]){
            table[pos] = true;
        }
    }
}

//imprimeix la taula del filtre de bloom
void Bloom_Filter_Knuth::printFilter(){
    for(int i = 0; i < table.size(); ++i){
        cout << " " << table[i] << " ";
    }
    cout << endl;
}

//retorna true si el conté, false en cas contrari
bool Bloom_Filter_Knuth::possiblyContains(int& key){
    for(int i = 0; i < hash_func.size(); ++i){
        int pos = hash_func[i].hash(key)%table.size();
        if(!table[pos]){
            return false;
        } 
    }
    return true;
}