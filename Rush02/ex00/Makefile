rush-02 : main.o print_num.o use_str.o chk_errors.o
	gcc -o rush-02 main.o print_num.o use_str.o chk_errors.o

main.o : main.c
	gcc -c -o main.o main.c

print_num.o : print_num.c
	gcc -c -o print_num.o print_num.c

use_str.o : use_str.c
	gcc -c -o use_str.o use_str.c

chk_errors.o : chk_errors.c
	gcc -c -o chk_errors.o chk_errors.c

fclean : 
	rm *.o rush-02
