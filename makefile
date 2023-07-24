hex: calculator.o driver.o
	g++ -o hex calculator.o driver.o

calculator.o: calculator.h calculator.cpp
	g++ -c calculator.cpp

driver.o: calculator.h driver.cpp
	g++ -c driver.cpp

clean:
	rm *.o hex