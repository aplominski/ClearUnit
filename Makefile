
build_example:
	gcc src/main.c src/test.c example.c -Iinclude
	g++ src/main.c src/test.c cppthrow_example.cpp -Iinclude