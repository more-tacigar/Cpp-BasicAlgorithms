a.out: test/test.cpp
	g++ test/test.cpp -o a.out -lcppunit -I. -std=c++1y
