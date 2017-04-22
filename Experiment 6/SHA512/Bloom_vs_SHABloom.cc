#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include <string>
#include "sha512.hh"
#include "Bloom_Filter_Mod.hh"

using namespace std;

int charToInt(char *a){
    int result = 0;
    for(int i = 0; i < strlen(a); ++i){
        result *= 10;
        result += (int)a[i] - '0';
    }
    return result;
}

bool contains(vector<string> keys, string key){
    for(int i = 0; i < keys.size(); i++){
        if(key.compare(keys[i]) == 0){
            return true;
        }
    }
    return false;
}

void printKeys(vector<string> keys){
    for(int i = 0; i < keys.size(); ++i){
        cout << keys[i] << " , ";
    }
    cout << endl;
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

//./main [k hashfunctions] [p familyhash] [m familyhash] [n iterations] [sizeKey n] [T tableSize] [num proves] 
//./main [k hashfunctions] [p famylyhash] [m familyHash] [dir keys] [T tableSize] [num proves] 

int main(int argc, char *argv[]){
    int numberHashFunc;
    int pFamily;
    int mFamily;
    int nKeys;
    int maxN;
    int sizeT;

    int num_proves;

    if(argc == 8){
        //./main [k hashfunctions] [p familyhash] [m familyhash] [n iterations] [sizeKey n] [T tableSize] [num proves]
        numberHashFunc = charToInt(argv[1]);
        pFamily = charToInt(argv[2]);
        mFamily = charToInt(argv[3]);
        nKeys = charToInt(argv[4]);
        maxN = charToInt(argv[5]);
        sizeT = charToInt(argv[6]);
        num_proves = charToInt(argv[7]);
    }else if(argc == 7){
        //./main [p hash] [m hash] [n iterations] [sizeKey n] [T tableSize] [num proves] 
        pFamily = charToInt(argv[1]);
        mFamily = charToInt(argv[2]);
        nKeys = charToInt(argv[3]);
        maxN = charToInt(argv[4]);
        sizeT = charToInt(argv[5]);
        //cout << "Calculating optimal number of hash functions = " << numberHashFunc << endl;
        numberHashFunc = ((sizeT*9)/(nKeys*13));
        if(numberHashFunc <= 0) numberHashFunc = 1;
        num_proves = charToInt(argv[6]);
    }else if(argc == 6){
        //./main [p hash] [m hash] [n iterations] [sizeKey n] [T tableSize]
        pFamily = charToInt(argv[1]);
        mFamily = charToInt(argv[2]);
        nKeys = charToInt(argv[3]);
        maxN = charToInt(argv[4]);
        sizeT = charToInt(argv[5]);
        //cout << "Calculating optimal number of hash functions = " << numberHashFunc << endl;
        numberHashFunc = ((sizeT*9)/(nKeys*13));
        if(numberHashFunc <= 0) numberHashFunc = 1;
    }else{
        exit(0);
    }

    int n_false_positive = 0;

    srand(time(NULL));
    for(int k = 0; k < num_proves; ++k){
        Bloom_Filter_Mod bloom(sizeT);
        // cout << numberHashFunc << " : " << pFamily << " : ";
        // cout << mFamily << " : " << nKeys << " : ";
        // cout << maxN << " : " << sizeT << endl;

        bloom.setFamilyHashFunc(pFamily, mFamily);
        // cout << "Creating hash functions..." << endl;
        for(int i = 0; i < numberHashFunc; ++i){
            bloom.generateHashFunc();
        }
        // cout << "Hash functions created" << endl;
        vector<string> keys = vector<string>(nKeys);
        int n_iterations = 0;

        // cout << "Entring to loop filter..." << endl;
        while(n_iterations < nKeys){
            //int key = rand() % maxN + 1; 

            string key;
            gen_random(key,maxN); // generates string with the size maxN
            key = sha512(key);

            //cout << "     key: " << key << endl;
            if(bloom.possiblyContains(key)){
                cout << "Already inserted" << endl;
                //printKeys(keys);
                if(!contains(keys,key)){
                    ++n_false_positive;
                    cout << "False positive" << endl;
                    keys.push_back(key);
                    bloom.insertValue(key);
                    ++n_iterations;
                }
            }else{
                keys.push_back(key);
                bloom.insertValue(key);
                ++n_iterations;
            }
        }
    }
    //bloom.printFilter(); //imprimir la taula del filtre de bloom 
    cout << "Average number false positives: " << n_false_positive/num_proves;
    cout << "  Factor m/n: " << (double)sizeT/(double)nKeys << endl;
    // cout << "Inserted keys: ";
    exit(0);
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

