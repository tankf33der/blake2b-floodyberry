all:
	gcc -O3 *.c -lblake2b  && ./a.out
clean:
	rm -rf *.o *.out
	
