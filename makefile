.PHONY: clean test

all: directories ut_main

TEST: test/ut_rectangle.h test/ut_circle.h test/ut_triangle.h \
	  test/ut_two_dimensional_vector.h test/compound_shape.h test/iterator.h \
	  test/ut_utility.h test/ut_visitor.h

SHAPE: src/shape.h src/rectangle.h src/circle.h src/triangle.h \
	   src/two_dimensional_vector.h src/compound_shape.h src/utility.h \
	   shape_visitor.h src/tostring_visitor.h

ITERATOR: src/iterator.h src/null_iterator.h src/compound_iterator.h

SRC: $(SHAPE) $(ITERATOR)

OBJ = obj/tostring_visitor.o
ut_main: test/ut_main.cpp $(TEST) $(SRC) $(OBJ)
	g++ -std=c++11 -Wfatal-errors test/ut_main.cpp $(OBJ) -o bin/ut_all -lgtest -lpthread

obj/tostring_visitor.o: src/tostring_visitor.cpp src/tostring_visitor.h
	g++ -std=c++11 -Wfatal-errors -Wall -c src/tostring_visitor.cpp -o obj/tostring_visitor.o

directories:
	mkdir -p bin
	mkdir -p obj

clean:
	rm -rf bin/* obj/*

test: all
	bin/ut_all
