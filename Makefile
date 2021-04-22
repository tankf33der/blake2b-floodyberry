all:
	gcc -O3 -Wall -Wextra *.c -lblake2b  && ./a.out
clean:
	rm -rf *.o *.out
	
