.PHONY: dirs clean

TEST= test/ut_circle.h test/ut_rectangle.h test/ut_triangle.h\
 	  test/ut_two_dimensional_vector.h
SRC= src/circle.h src/rectangle.h src/shape.h src/triangle.h src/two_dimensional_vector.h

all: dirs ut_all

ut_all: test/ut_main.cpp $(TEST) $(SRC)
	g++ -std=c++11 -Wfatal-errors -Wall test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

dirs:
	mkdir -p bin

clean:
	rm -f bin/*

stat:
	wc -l src/* test/*.h test/*.cpp
