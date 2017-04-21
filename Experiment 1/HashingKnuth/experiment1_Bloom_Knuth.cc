#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include "Bloom_Filter_Knuth.hh"

using namespace std;


bool contains(vector<int> keys, int key){
    for(int i = 0; i < keys.size(); i++){
        if(keys[i] == key){
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

//./main [k hashfunctions] [M tableSize(2^M)] [n iterations] [maximum n] [num proves]
//./main [k hashfunctions] [p famylyhash] [m familyHash] [dir keys] [T tableSize] [num proves]

int main(int argc, char *argv[]){
    int numberHashFunc;
    int mFamily;
    int nKeys;
    int maxN;

    int num_proves;
    if(argc == 6){
        //./main [k hashfunctions] [M tableSize(2^M)] [n iterations] [maximum n(in bits)] [num proves]
        numberHashFunc = charToInt(argv[1]);
        mFamily = charToInt(argv[2]);
        nKeys = charToInt(argv[3]);
        maxN = charToInt(argv[4]);
        num_proves = charToInt(argv[5]);
    }else if(argc == 5){        
        //./main [M tableSize(2^M)] [n iterations] [maximum n] [num proves]
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
        // cout << numberHashFunc << " : " << mFamily << " : ";
        // cout << nKeys << " : " << maxN << endl;;

        bloom.setFamilyHashFunc(mFamily,maxN);
        // cout << "Creating hash functions..." << endl;
        for(int i = 0; i < numberHashFunc; ++i){
            bloom.generateHashFunc();
        }
        vector<int> keys;

        int n_iterations = 0;

        // cout << "Entring to loop filter..." << endl;
        while(n_iterations < nKeys){
            int key = rand() % (int)exp2(maxN) + 1; // generates number in the range 1..maxN
            //cout << "     key: " << key << endl;
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
    }
    //bloom.printFilter(); //imprimir la taula del filtre de bloom 
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

