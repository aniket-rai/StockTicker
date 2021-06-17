#include <string>

class Stock {
	public:
		Stock(std::string name, std::string symbol, double price);
		std::string getName();
		std::string getSymbol();
		double getPrice();
		void updatePrice();

		void _printStock();
	
	private:
		std::string _name;
		std::string _symbol;
		double _price;
};

