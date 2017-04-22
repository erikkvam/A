#include <iostream>
#include <string>
#include "sha256.hh"
 
using namespace std;
 
int main(int argc, char *argv[]){
    cout << "Introduir clau: ";
    string key;
    while(cin >> key){
        string output1 = sha256(key);
        cout << "sha256('clau'):" << output1 << endl;
        cout << "Introduir clau: ";
    }
    return 0;
}