run:
	g++ -std=c++11 ./src/*.cpp -I ./include -o ./build/main
	./build/main test "test is a test"

optim:
	g++ -std=c++11 -O3 ./src/*.cpp -I ./include -o ./build/main
	./build/main
