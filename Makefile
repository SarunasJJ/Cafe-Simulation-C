test.exe : test.c BigInteger.h BigInteger.o cafe.h cafe.o stack.h stack.o
	gcc -std=c99 -o test.exe test.c BigInteger.o cafe.o stack.o 

cafe.o : cafe.c cafe.h
	gcc -c -std=c99 cafe.c
BigInteger.o : BigInteger.c BigInteger.h
	gcc -c -std=c99 BigInteger.c
stack.o : stack.c stack.h
	gcc -c -std=c99 stack.c