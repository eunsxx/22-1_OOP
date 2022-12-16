#include <iostream>

using namespace std;

class item {
private:
	int price;
	int stock;
	int discount;
public:
	item(int price, int stock) {
		this->price = price;
		this->stock = stock;
		discount = 0;
	}
	int getprice() { return price; }
	int getstock() { return stock; }
	int getdiscount() { return discount; }
	void addStock(int num) { this->stock += num; }
	void sell_item(int num) { this->stock -= num; }
	void setdiscount(int num) { discount = num; }
};

class pen : private item {
public:
	pen(int price, int stock) : item(price, stock) {
		cout << "---------Pen----------" << endl;
		cout << "Price: " << 3 * getprice() << endl;
		cout << "Stock: " << getstock() << endl;
		cout << "Discount: " << getdiscount() << "%" << endl;
		cout << "----------------------" << endl;
	}
	void changeStock(int num) {
		sell_item(num * 3);
	}
	void plusStock(int num) {
		addStock(num);
	}
	int penSales(int num) {
		return (getprice() * 3 * num * (1 - ((float)getdiscount() / 100)));
	}
	void changeDiscount(int num) {
		setdiscount(num);
	}
	void printNow() {
		cout << "---------Pen----------" << endl;
		cout << "Price: " << 3 * getprice() << endl;
		cout << "Stock: " << getstock() << endl;
		cout << "Discount: " << getdiscount() << "%" << endl;
		cout << "----------------------" << endl;
	}
};

class pencil : private item {
public:
	pencil(int price, int stock) : item(price, stock) {
		cout << "--------Pencil--------" << endl;
		cout << "Price: " << 12 * getprice() << endl;
		cout << "Stock: " << getstock() << endl;
		cout << "Discount: " << getdiscount() << "%" << endl;
		cout << "----------------------" << endl;
	}
	void changeStock(int num) {
		sell_item(num * 12);
	}
	void plusStock(int num) {
		addStock(num);
	}
	int pencilSales(int num) {
		return getprice() * 12 * num * (1 - ((float)getdiscount() / 100));
	}
	void changeDiscount(int num) {
		setdiscount(num);
	}
	void printNow() {
		cout << "--------Pencil--------" << endl;
		cout << "Price: " << 12 * getprice() << endl;
		cout << "Stock: " << getstock() << endl;
		cout << "Discount: " << getdiscount() << "%" << endl;
		cout << "----------------------" << endl;
	}
};

class eraser : private item {
public:
	eraser(int price, int stock) : item(price, stock) {
		cout << "--------eraser--------" << endl;
		cout << "Price: " << getprice() << endl;
		cout << "Stock: " << getstock() << endl;
		cout << "Discount: " << getdiscount() << "%" << endl;
		cout << "----------------------" << endl;
	}
	void changeStock(int num) {
		sell_item(num);
	}
	void plusStock(int num) {
		addStock(num);
	}
	int eraserSales(int num) {
		return getprice() * num * (1 - ((float)getdiscount() / 100));
	}
	void changeDiscount(int num) {
		setdiscount(num);
	}
	void printNow() {
		cout << "--------eraser--------" << endl;
		cout << "Price: " << getprice() << endl;
		cout << "Stock: " << getstock() << endl;
		cout << "Discount: " << getdiscount() << "%" << endl;
		cout << "----------------------" << endl;
	}
};

int main(void) {
	cout << "======================" << endl;
	pen Pen(200, 100);
	pencil Pencil(100, 100);
	eraser Eraser(500, 100);
	cout << "======================" << endl;
	int sales = 0;

	string command;
	int number;
	string item;
	do {
		cout << "Enter Any Command(0: Sell, 1: AddStock, 2: Discount, 3: Print, 4: Quit) :";
		cin >> command;
		if (command[0] == '0') {
			cin >> item;
			cin >> number;
			if (item == "Pen") {
				sales += Pen.penSales(number);
				Pen.changeStock(number);
			}
			else if (item == "Pencil") {
				sales += Pencil.pencilSales(number);
				Pencil.changeStock(number);
			}
			else if (item == "Eraser") {
				sales += Eraser.eraserSales(number);
				Eraser.changeStock(number);
			}
		}
		else if (command[0] == '1') {
			cin >> item >> number;
			if (item == "Pen") {
				Pen.plusStock(number);
			}
			else if (item == "Pencil") {
				Pencil.plusStock(number);
			}
			else if (item == "Eraser") {
				Eraser.plusStock(number);
			}
		}
		else if (command[0] == '2') {
			cin >> item >> number;
			if (item == "Pen") {
				Pen.changeDiscount(number);
			}
			else if (item == "Pencil") {
				Pencil.changeDiscount(number);
			}
			else if (item == "Eraser") {
				Eraser.changeDiscount(number);
			}
		}
		else if (command[0] == '3') {
			Pen.printNow();
			Pencil.printNow();
			Eraser.printNow();
		}
		else if (command[0] == '4') break;
		cout << "======================" << endl;
		cout << "Sales: " << sales << endl;
		cout << "======================" << endl;
	} while (command[0] != '4');
	return 0;
}