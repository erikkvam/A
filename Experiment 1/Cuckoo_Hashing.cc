// classe Cuckoo_Hashing

#include "Cuckoo_Hashing.hh"

// Constructor
    Cuckoo_Hashing::Cuckoo_Hashing(int& tsize){
        mida = tsize;
    }

    void Cuckoo_Hashing::setFamilyHashFunc(int& pFamily, int& mFamily){
        p = pFamily;
        m = mFamily;
    }

    //genera una nova funcio de hash a,b de la familia p,m i la inserta en el vector de hash_func
    void Cuckoo_Hashing::generateHashFunc(){
        vector<int> aux = vector<int>(mida,-1);
        vector_tables.push_back(aux);
        int a = rand() % p + 1;  // generates number in the range 1..p
        int b = rand() % p + 1;  // generates number in the range 1..p

        cout << "hash function: " << a << "," << b << endl;

        Hash_Func_Mod function(p,m,a,b);
        hash_func.push_back(function);
    }

    //retorna true si l'ha insertat normalment, false si ja hi era
    void Cuckoo_Hashing::insertValue(int key){
        bool done = false;
        int i = 0;
        while(!done){
            if(i >= 100000){
                cout << "Too many loops... collision with: " << key << endl;
                printFilter();
                exit(0);
            }
            int pos = hash_func[i%hash_func.size()].hash(key)%mida;
            done = true;
            int keyaux = vector_tables[i%hash_func.size()][pos];
            vector_tables[i%hash_func.size()][pos] = key;  
            if(keyaux != -1 && keyaux != key){
                key = keyaux;
                done = false;
            }          
            ++i;
        }
    }

    //retorna true si el conté, false en cas contrari
    bool Cuckoo_Hashing::contains(int& key){
        for(int i = 0; i < hash_func.size(); ++i){
            int pos = hash_func[i].hash(key)%mida;
            if(vector_tables[i][pos] == key){
                return true;
            }
        }
        return false;
    }

    void Cuckoo_Hashing::printFilter(){
        for(int i = 0; i < vector_tables.size(); ++i){
            for(int j = 0; j < mida; ++j){
                cout << " " << vector_tables[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }