// classe Bloom_Filter_Mod

#include "Bloom_Filter_Mod.hh"

Bloom_Filter_Mod::Bloom_Filter_Mod(int& k) {
    table = vector<bool>(k,false);
}

void Bloom_Filter_Mod::setFamilyHashFunc(int& pFamily, int& mFamily){
    p = pFamily;
    m = mFamily;
}

//genera una nova funcio de hash a,b de la familia p,m i la inserta en el vector de hash_func
void Bloom_Filter_Mod::generateHashFunc(){
    int a = rand() % p + 1;  // generates number in the range 1..p
    int b = rand() % p + 1;  // generates number in the range 1..p

    //cout << "hash function: " << a << "," << b << endl;

    Hash_Func_Mod function(p,m,a,b);
    hash_func.push_back(function);
}

//inserta un element al filtre de hash
void Bloom_Filter_Mod::insertValue(int& key){
    for(int i = 0; i < hash_func.size(); ++i){
        int pos = hash_func[i].hash(key)%table.size();
        if(!table[pos]){
            table[pos] = true;
        }
    }
}

//imprimeix la taula del filtre de bloom
void Bloom_Filter_Mod::printFilter(){
    for(int i = 0; i < table.size(); ++i){
        cout << " " << table[i] << " ";
    }
    cout << endl;
}

//retorna true si el conté, false en cas contrari
bool Bloom_Filter_Mod::possiblyContains(int& key){
    for(int i = 0; i < hash_func.size(); ++i){
        int pos = hash_func[i].hash(key)%table.size();
        if(!table[pos]){
            return false;
        } 
    }
    return true;
}