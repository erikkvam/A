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

//./main [k hashfunctions] [p familyhash] [m familyhash] [n iterations] [maximum n] [T tableSize] 
//./main [k hashfunctions] [p famylyhash] [m familyHash] [dir keys] [T tableSize]

int main(int argc, char *argv[]){
    int numberHashFunc;
    int pFamily;
    int mFamily;
    int nKeys;
    int maxN;
    int sizeT;
    if(argc == 7){
        //./main [k hashfunctions] [p familyhash] [m familyhash] [n iterations] [maximum n] [T tableSize] 
        numberHashFunc = charToInt(argv[1]);
        pFamily = charToInt(argv[2]);
        mFamily = charToInt(argv[3]);
        nKeys = charToInt(argv[4]);
        maxN = charToInt(argv[5]);
        sizeT = charToInt(argv[6]);
        
    }else if(argc == 6){
        //./main [p hash] [m hash] [n iterations] [max maximum] [T tableSize]
        pFamily = charToInt(argv[1]);
        mFamily = charToInt(argv[2]);
        nKeys = charToInt(argv[3]);
        maxN = charToInt(argv[4]);
        sizeT = charToInt(argv[5]);
        numberHashFunc = ((sizeT*9)/(nKeys*13));
        if(numberHashFunc <= 0) numberHashFunc = 1;
        cout << "Calculating optimal number of hash functions = " << numberHashFunc << endl;
    }else{
        exit(0);
    }
    srand(time(NULL));
    Bloom_Filter bloom(sizeT);
    cout << numberHashFunc << " : " << pFamily << " : ";
    cout << mFamily << " : " << nKeys << " : ";
    cout << maxN << " : " << sizeT << endl;

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
        keys.push_back(key);
        bloom.insertValue(key);
        //bloom.printFilter(); //imprimir la taula del filtre de bloom 
        ++n_iterations;
    }
    //bloom.printFilter(); //imprimir la taula del filtre de bloom 
    cout << "Number false positives: " << n_false_positive << endl;
    cout << "Total iterations: " << n_iterations << endl;
    cout << "Inserted keys: ";
    for(int i = 0; i < keys.size(); ++i){
        cout << keys[i] << " , ";
    }
    cout << endl << "Querys: ";
    int entry;
    while(cin >> entry){
        if(bloom.possiblyContains(entry)){
            cout << "On the filter!" << endl;
        }else{
            cout << "Not on filter" << endl;
        }
    }
}

