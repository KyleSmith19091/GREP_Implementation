run:
	g++ -std=c++11 Main.cpp -I ./include -o main
	./main test "test is a test"

optim:
	g++ -std=c++11 -O3 Main.cpp -I ./include -o main
	./main
