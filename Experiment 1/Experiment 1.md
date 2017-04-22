*Experiment 1:* Falsos positius de Mod (com explicat a classe) vs. Multiply-shift(Knuth) (Wikipedia) per obtenir H

Per compilar Bloom:
 #g++ Bloom_Filter_Mod.cc Hash_Func_Mod.cc experiment1_Bloom_Mod.cc -o experiment1_Bloom_Mod

Usage:

(Calculant la k optima donades una mida de la taula i un nombre de claus)
./experiment1_Bloom_Mod [p familia de hash] [m familia de hash] [n keys randoms] [max valor keyrandom] [mida taula filtre] [num de proves]

Exemple -> ./experiment1_Bloom 4235 2576 200 10000 2000 100


./experiment1_Bloom_Mod [k funcions de hash] [p familia de hash] [m familia de hash] [n key randoms] [max valor keyrandom] [mida taula filtre] [num de proves]

Exemple -> ./experiment1_Bloom 4 4235 2576 200 10000 2000 100

Per compilar Knuth:
 #g++ Bloom_Filter_Knuth.cc Hash_Multiply_Shift.cc experiment1_Bloom_Knuth.cc -o experiment1_Bloom_Knuth

Usage:

./experiment1_Bloom_Knuth [tablesize(en bits)] [n keys randoms] [max valor keyrandom(en bits)] [num de proves]

Exemple -> ./experiment1_Bloom_Knuth 17 1024 20 10

*************************************************************

Per fer les proves he anat recollint les dades de falsos positius, cada execució et retorna la mitjana de falsos positius de l'execució en 'num de proves' vegades i la rel·lació entre la mida de la taula i el nombre de keys que s'inseriran (m/n).
Utilitzant la comanda:

./experiment1_Bloom_Knuth 17 1024 20 100 > echo >> experiment1_Knuth.txt

amb cada un dels programes. Canviant la mida de la taula per provar el nombre de falsos positius segons la rel·lació m/n manteint tots els altres paràmetres constants.

 
