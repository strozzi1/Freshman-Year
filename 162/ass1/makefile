CC=g++
exe_file = a.out
$(exe_file): geo.o main.o
	$(CC) geo.o main.o -o $(exe_file)
geo.o: geo.cpp
	$(CC) -c geo.cpp
main.o: main.cpp
	$(CC) -c main.cpp
clean:
	rm -f *.out *.o $(exe_file)

 
