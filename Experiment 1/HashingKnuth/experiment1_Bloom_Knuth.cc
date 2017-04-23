#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include "Bloom_Filter_Knuth.hh"

using namespace std;


bool contains(vector<string> keys, string key){
    for(int i = 0; i < keys.size(); i++){
        if(key.compare(keys[i]) == 0){
            return true;
        }
    }
    return false;
}

int charToInt(char *a){
    int result = 0;
    for(int i = 0; i < strlen(a); ++i){
        result *= 10;
        result += (int)a[i] - '0';
    }
    return result;
}

void gen_random(string& s, const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        char aux = (alphanum[rand() % (sizeof(alphanum) - 1)]);
        s.append(&aux);
    }
}

//./main [k hashfunctions] [M tableSize(2^M)] [n iterations] [num_characters_key n] [num proves]

int main(int argc, char *argv[]){
    int numberHashFunc;
    int mFamily;
    int nKeys;
    int maxN;

    int num_proves;
    if(argc == 6){
        //./main [k hashfunctions] [M tableSize(2^M)] [n iterations] [num_characters_key] [num proves]
        numberHashFunc = charToInt(argv[1]);
        mFamily = charToInt(argv[2]);
        nKeys = charToInt(argv[3]);
        maxN = charToInt(argv[4]);
        num_proves = charToInt(argv[5]);
    }else if(argc == 5){        
        //./main [M tableSize(2^M)] [n iterations] [num_characters_key] [num proves]
        mFamily = charToInt(argv[1]);
        nKeys = charToInt(argv[2]);
        maxN = charToInt(argv[3]);
        // cout << "Calculating optimal number of hash functions = ";
        numberHashFunc = ((exp2(mFamily)*9)/(nKeys*13));
        if(numberHashFunc <= 0) numberHashFunc = 1;
        // cout << numberHashFunc << endl;
        num_proves = charToInt(argv[4]);
    }else{
        exit(0);
    }

    int n_false_positive = 0;
    srand(time(NULL));
    for(int k = 0; k < num_proves; ++k){
        Bloom_Filter_Knuth bloom((int)exp2(mFamily));
        // cout << numberHashFunc << " : " << mFamily << endl;
        // cout << nKeys << " : " << maxN << endl;;

        int num_bits = maxN*8;
        bloom.setFamilyHashFunc(mFamily,num_bits);
        // cout << "Creating hash functions..." << endl;
        for(int i = 0; i < numberHashFunc; ++i){
            bloom.generateHashFunc();
        }
        vector<string> keys;

        int n_iterations = 0;

        // cout << "Entring to loop filter..." << endl;
        while(n_iterations < nKeys){
            string key;
            gen_random(key,maxN); // generates string with the size maxN

            // cout << "     key: " << key << endl;
            if(bloom.possiblyContains(key)){
                //cout << "already inserted" << endl;
                if(!contains(keys,key)){
                    ++n_false_positive;
                    //cout << "false positive" << endl;
                    keys.push_back(key);
                    bloom.insertValue(key);
                    ++n_iterations;
                }
            }else{
                keys.push_back(key);
                bloom.insertValue(key);
                ++n_iterations;
            }
            //bloom.printFilter(); //imprimir la taula del filtre de bloom 
        }
        // bloom.printFilter(); //imprimir la taula del filtre de bloom 
    }
    cout << "Average number false positives: " << n_false_positive/num_proves;
    cout << "  Factor m/n: " << (double)exp2(mFamily)/(double)nKeys << endl;
    // cout << "Inserted keys: ";
    // for(int i = 0; i < keys.size(); ++i){
    //     cout << keys[i] << " , ";
    // }
    // cout << endl << "Querys: ";
    // int entry;
    // while(cin >> entry){
    //     if(bloom.possiblyContains(entry)){
    //         cout << "On the filter!" << endl;
    //     }else{
    //         cout << "Not on filter" << endl;
    //     }
    // }
}

