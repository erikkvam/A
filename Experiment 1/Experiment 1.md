*Experiment 1:* Falsos positius de Mod (com explicat a classe) vs. Multiply-shift (Wikipedia) per obtenir H

Per compilar Bloom:
 #g++ experiment1_Bloom.cc Hash_Func_Mod.cc Bloom_Filter.cc -o experiment1_Bloom

Usage:

(Calculant la k optima donades una mida de la taula i un nombre de claus)
./experiment1_Bloom [p familia de hash] [m familia de hash] [n querys randoms] [max valor keyrandom] [mida taula filtre]

Exemple -> ./experiment1_Bloom 4235 2576 200 10000 2000


./experiment1_Bloom [k funcions de hash] [p familia de hash] [m familia de hash] [n querys randoms] [max valor keyrandom] [mida taula filtre]

Exemple -> ./experiment1_Bloom 4 4235 2576 200 10000 2000

Per compilar Cuckoo:
 #g++ experiment1_Cuckoo.cc Hash_Func_Mod.cc Cuckoo_Hashing.cc -o experiment1_Cuckoo

Usage:

./experiment_Cuckoo [num taules] [p familia de hash] [m familia de hash] [num inserts] [max valor keyrandom] [mida de les taules]

Exemple -> ./experiment1_Cuckoo 4 3556 2372 200 100000 200
 
