#include <iostream>
#include <string>

#include <random>
#include <ctime>

#include "stock.hpp"

Stock::Stock(std::string name, std::string symbol, double price) {
	_name = name;
	_symbol = symbol;
	_price = price;
}

std::string Stock::getName() {
	return _name;
}

std::string Stock::getSymbol() {
	return _symbol;
}

double Stock::getPrice() {
	return _price;
}

void Stock::updatePrice() {
	// this function will currently simulate getting the price from the market
	std::random_device device;
	std::mt19937 gen(device()); // mersenne twister random generator;
	std::uniform_real_distribution<> dist(-5, 5);	
	
	_price += dist(gen);
}

void Stock::_printStock() {
	std::cout << _name << ", " << _symbol << ": $" << _price;
}
