wordlist: WordList.o List.o encrypt.o Word_Instances.o
	gcc WordList.o List.o encrypt.o Word_Instances.o -o wordlist

WordList.o: WordList.c List.h encrypt.h Word_Instances.h
	gcc -c WordList.c

encrypt.o: encrypt.h encrypt.c
	gcc -c encrypt.c

List.o: List.h List.c
	gcc -c List.c

Word_Instances.o: Word_Instances.h Word_Instances.c
	gcc -c Word_Instances.c