all:
	gcc -O3 *.c -lblake2b
clean:
	rm -rf *.o *.out
	
