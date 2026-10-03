#include<iostream>
using namespace std;

int trucks = 5, supply_packs = 120, disaster = 0;
char update_inventory;

int welcome() {
	cout << "\nWelcome to the Relief Supply Distribution System!" << endl;
	return 0;
}

int inventory() {
	cout << "\n\nWe currently have " << supply_packs << " supply packs and " << trucks << " trucks available for distribution." << endl;
	cout << "Would you like to update the inventory? (y/n): ";
	cin >> update_inventory;
	if (update_inventory == 'y' || update_inventory == 'Y') {
		cout << "Enter the new number of trucks: ";
		cin >> trucks;
		cout << "Enter the new number of supply packs: ";
		cin >> supply_packs;
		cout << "Inventory updated successfully!" << endl;
	}
	else {
		cout << "Inventory remains unchanged." << endl;
	}
	return 0;
}
int disasters() {
	cout << "\n\nBelow is a list of available disasters:" << endl;
	cout << "1. Earthquake" << endl;
	cin >> disaster;
	return 0;
}

int main() {
	welcome();
	inventory();
	disasters();
	return 0;
}