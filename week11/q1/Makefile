
q1: q1.o account.o
		@echo "Linking files together..."
		@g++ q1.o account.o -o q1

q1.o: q1.cpp
		@echo "Compiling the main file..."
		@g++ -c q1.cpp

account.o: account.cpp account.h
		@echo "Compiling the header file..."
		@g++ -c account.cpp

clean:
		rm *.o q1
