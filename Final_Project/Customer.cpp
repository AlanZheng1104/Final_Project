#include "Customer.h"
Customer::Customer() {
	name = "test customer";
}

Customer::Customer(string in_name) {
	name = in_name;
	special_tool = "NA";
}

string Customer::show_name() {
	return "[Customer] " + name;
}

string Customer::show_tool() {
	return special_tool;
}

float Customer::buy(string tool) {
	if (tool == "NA") {
		cout << "I guess you got nothing to sell" << endl;
		return 0;
	}
	else {
		cout << "Thank you for " << tool << endl;
		return 1;
	}
}

Customer::~Customer() {

}