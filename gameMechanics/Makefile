
playertest: playertest.o character.o
		g++ playertest.o character.o -o playertest

playertest.o: playertest.cpp
		g++ -c playertest.cpp

character.o: character.cpp character.h
		g++ -c character.cpp

clean:
		rm *.o playertest
