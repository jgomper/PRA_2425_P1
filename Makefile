bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp ListArray.h


bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h


bin/testListLinked: testListLinked.cpp ListLinked.h List.h
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp ListLinked.h


Point2D.o: Point2D.h Point2D.cpp
	g++ -c Point2D.cpp


bin/testPoint2D: testPoint2D.cpp Point2D.o
	g++ -c testPoint2D.cpp
	mkdir -p bin
	g++ -o bin/testPoint2D testPoint2D.o Point2D.o


Shape.o: Shape.cpp Shape.h
	g++ -c Shape.cpp


Circle.o: Circle.cpp Circle.h
	g++ -c Circle.cpp


bin/testCircle: testCircle.cpp Circle.o Shape.o Point2D.o
	g++ -c testCircle.cpp
	mkdir -p bin
	g++ -o bin/testCircle testCircle.o Circle.o Shape.o Point2D.o


Rectangle.o: Rectangle.cpp Rectangle.h Point2D.h Shape.h
	g++ -c Rectangle.cpp -o Rectangle.o


bin/testRectangle: testRectangle.cpp Rectangle.o Shape.o Point2D.o
	g++ -c testRectangle.cpp
	mkdir -p bin
	g++ -o bin/testRectangle testRectangle.o Rectangle.o Shape.o Point2D.o


Square.o: Square.cpp Square.h Rectangle.h
	g++ -c Square.cpp -o Square.o


bin/testSquare: testSquare.cpp Square.o Rectangle.o Point2D.o Shape.o
	g++ -c testSquare.cpp
	mkdir -p bin
	g++ -o bin/testSquare testSquare.o Square.o Rectangle.o Point2D.o Shape.o


Drawing.o: Drawing.cpp Drawing.h Square.h Rectangle.h
	g++ -c Drawing.cpp -o Drawing.o


bin/testDrawing: testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o
	mkdir -p bin
	g++ -o bin/testDrawing testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o


clean:
	rm -r *.o *.gch bin
