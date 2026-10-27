#include "Human.h"
Human::Human() {
	name = "test";

}

Human::Human(string in_name, int in_money) {
	name = in_name;
	money = in_money;
}

string Human::show_name() {
	return name;
}

int Human::show_money() {
	return money;
}

void Human::quota(int in_quota) {
	money = money - in_quota;
}
void Human::upgrade_cost(int in_money) {
	money = money - in_money;
}

Human::~Human() {

}
