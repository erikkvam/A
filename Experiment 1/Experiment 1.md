*Experiment 1:* Falsos positius de Mod (com explicat a classe) vs. Multiply-shift (Wikipedia) per obtenir H

Per compilar:
 #g++ main.cc Hash_Func_Mod.cc Bloom_Filter.cc -o experiment1
 
Usage:
  //Calculant la k optima donades una mida de la taula i un nombre de claus
  ./experiment1 [p familia de hash] [m familia de hash] [n querys randoms] [max valor keyrandom] [mida taula filtre]
  Exemple -> ./experiment1 4235 2576 200 10000 2000
  
  
  ./experiment1 [k funcions de hash] [p familia de hash] [m familia de hash] [n querys randoms] [max valor keyrandom] [mida taula filtre]
  Exemple -> ./experiment1 4 4235 2576 200 10000 2000
