// classe Bloom_Filter_Rolling

#include "Bloom_Filter_Rolling.hh"

Bloom_Filter_Rolling::Bloom_Filter_Rolling(int& k) {
    table = vector<bool>(k,false);
}

void Bloom_Filter_Rolling::setFamilyHashFunc(int& pFamily, int& mFamily){
    p = pFamily;
    m = mFamily;
}

//genera una nova funcio de hash a,b de la familia p,m i la inserta en el vector de hash_func
void Bloom_Filter_Rolling::generateHashFunc(){
    int a = rand() % p + 1;  // generates number in the range 1..p

    //cout << "hash function: " << a << endl;

    Hash_Rolling function(a,m);
    hash_func.push_back(function);
}

//inserta un element al filtre de hash
void Bloom_Filter_Rolling::insertValue(string key){
    for(int i = 0; i < hash_func.size(); ++i){
        unsigned int pos = hash_func[i].hash(key)%table.size();
        if(!table[pos]){
            table[pos] = true;
        }
    }
}

//imprimeix la taula del filtre de bloom
void Bloom_Filter_Rolling::printFilter(){
    for(int i = 0; i < table.size(); ++i){
        cout << " " << table[i] << " ";
    }
    cout << endl;
}

//retorna true si el conté, false en cas contrari
bool Bloom_Filter_Rolling::possiblyContains(string key){
    for(int i = 0; i < hash_func.size(); ++i){
        unsigned int pos = hash_func[i].hash(key)%table.size();
        if(!table[pos]){
            return false;
        } 
    }
    return true;
}