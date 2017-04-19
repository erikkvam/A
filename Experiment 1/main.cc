#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include "Bloom_Filter.hh"

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

//./main [k hashfunctions] [p familyhash] [m familyhash] [n maxrandomkeys] [maximum n] [T tableSize] 
//./main [k hashfunctions] [p famylyhash] [m familyHash] [dir keys] [T tableSize]

int main(int argc, char *argv[]){
    if(argc == 7){
        //./main [k hashfunctions] [p familyhash] [m familyhash] [n maxrandomkeys] [maximum n] [T tableSize] 
        int numberHashFunc = charToInt(argv[1]);
        int pFamily = charToInt(argv[2]);
        int mFamily = charToInt(argv[3]);
        int nKeys = charToInt(argv[4]);
        int maxN = charToInt(argv[5]);
        int sizeT = charToInt(argv[6]);
        Bloom_Filter bloom(sizeT);
        cout << numberHashFunc << " : " << pFamily << " : ";
        cout << mFamily << " : " << nKeys << " : ";
        cout << maxN << " : " << sizeT << endl;;

        bloom.setFamilyHashFunc(pFamily, mFamily);
        cout << "Creating hash functions..." << endl;
        for(int i = 0; i < numberHashFunc; ++i){
            bloom.generateHashFunc();
        }
        vector<int> keys;

        int n_false_positive = 0;
        int n_iterations = 0;

        cout << "Entring to loop filter..." << endl;
        while(n_iterations < nKeys){
            int key = rand() % maxN + 1; // generates number in the range 1..maxN
            //cout << "     key: " << key << endl;
            if(bloom.possiblyContains(key)){
                //cout << "already inserted" << endl;
                if(!contains(keys,key)){
                    ++n_false_positive;
                    //cout << "false positive" << endl;
                }
            }
            bloom.insertValue(key);
            bloom.printFilter();
            ++n_iterations;
        }
        cout << "Number false positives: " << n_false_positive << endl;
        cout << "Total iterations: " << n_iterations << endl;
    }else if(argc == 6){
        //./main [k hashfunctions] [p famylyhash] [m familyHash] [dir keys] [T tableSize]

    }else{
        //Usage
    }
}

