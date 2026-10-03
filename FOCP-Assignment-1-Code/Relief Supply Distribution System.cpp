#include<iostream>
using namespace std;

int trucks = 5, supply_packs = 120, disaster = 0, families_affected = 0;
char update_inventory, access_route, aftershocks, medical_need, previous_aid_received;
string damage_level;

int welcome() {
	cout << "\nHi! Welcome to the Relief Supply Distribution System!" << endl;
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
	cout << "\nPlease select a disaster by entering the corresponding number: ";
	cin >> disaster;
	return 0;
}
int earthquake() {
	cout << "\nEarthquake Disaster Selected!" << endl;
	cout << "\nPlease enter the details of the earthquake disaster:" << endl;

	cout << "Disaster:" << endl;
	if (disaster == 1) {
		cout << "\nType: Earthquake" << endl;
	}

	cout << "Damage Level\t\t: ";
	cin >> damage_level;

	
	cout << "Families Affected (10-200)\t\t: ";
	cin >> families_affected;
	while (families_affected < 10 || families_affected > 200) {
		cout << "\nInvalid input. Please enter a value between 10 and 200." << endl;
		cout << "Families Affected\t\t: ";
		cin >> families_affected;
	}

	cout << "Access Route Availability (y/n)\t: ";
	cin >> access_route;

	cout << "Aftershocks (y/n)\t\t\t: ";
	cin >> aftershocks;

	cout << "Medical Need\t\t\t: ";
	cin >> medical_need;

	cout << "Previous Aid Received (y/n)\t: ";
	cin >> previous_aid_received;

	cout << endl;
	return 0;
}

int main() {
	welcome();
	inventory();
	disasters();
	if (disaster == 1) {
		earthquake();
	}
	
	return 0;
}