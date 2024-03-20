
q4: q4.o character.o
		@echo "Linking files together..."
		@g++ q4.o character.o -o q4

q4.o: q4.cpp
		@echo "Compiling the main file..."
		@g++ -c q4.cpp

character.o: character.cpp character.h
		@echo "Compiling the header file..."
		@g++ -c character.cpp

clean:
		rm *.o q4
