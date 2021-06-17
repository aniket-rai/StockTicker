run: ticker.o stock.o
	@g++ -o ticker ticker.o stock.o
	@rm *.o
	@./ticker

ticker.o: ticker.cpp
	@g++ -c ticker.cpp

stock.o: stock.cpp stock.hpp
	@g++ -c stock.cpp
