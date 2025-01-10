blah: blah.o
	cc blah.o -o blah

blah.o: blah.c
	cc -c blah.c -o blah.o

blah.c:
	echo "int main() { return 0; }" > blah.c

some_file: other_file
	echo "This will always run, and runs second"
	touch some_file

other_file:
	echo "This will always run, and runs first"

some_file:
	touch some_file

clean:
	rm -f some_file
