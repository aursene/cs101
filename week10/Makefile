
w10q4: w10q4.o w10.o
		echo "Linking files together..."
		g++ w10q4.o w10.o -o w10q4

w10q4.o: w10q4.cpp
		echo "Compiling the main file..."
		g++ -c w10q4.cpp

w10.o: w10.cpp w10.h
		echo "Compiling the header file..."
		g++ -c w10.cpp

clean:
		rm *.o w10q3
