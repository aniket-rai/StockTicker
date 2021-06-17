#include <iostream>
#include <chrono>
#include <thread>

#include "stock.hpp"

#define RESET "\033[0m";
#define RED "\033[31m";
#define GREEN "\033[32m";

using namespace std::chrono_literals;

double percentageDifference(double oldPrice, double newPrice) {
	return ((newPrice-oldPrice)/oldPrice)*100*100;
}

int main() {
	Stock stock = Stock("Apple", "APPL", 327.54);
	double oldPrice = stock.getPrice();
	
	while(true) {
		stock.updatePrice();
		stock._printStock();

		double diff = percentageDifference(oldPrice, stock.getPrice());

		if (diff < 0) {
			std::cout << ": " << "\033[31m" << diff << "bp" << "\033[0m" << std::endl;
		} else {
			std::cout << ": " << "\033[32m" << diff << "bp" << "\033[0m" << std::endl;
		}

		std::cout << "\033[2J\033[1;1H";

		oldPrice = stock.getPrice();
		std::this_thread::sleep_for(1s);
	}

	return 0;
}

