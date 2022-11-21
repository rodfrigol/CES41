bison -d cm.y
flex cm.l
gcc -c *.c
gcc -o cm *.o -ll -lfl
./cm teste2.cm