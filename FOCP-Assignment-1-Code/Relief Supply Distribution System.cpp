#include<iostream>
#include<string>
using namespace std;

int trucks = 5, supply_packs = 120, disaster = 0, families_affected = 0;
char update_inventory;
string damage_level, access_route, aftershocks, area, radius,  medical_need, trapped_ppl, vulnerable_grps, local_clinic, previous_aid_received;

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
	cout << "Please enter the details of the earthquake disaster." << endl;
	cout << "\nDisaster Type: Earthquake" << endl;
	cout << "Enter name of area: ";
	cin >> area;
	cout << "Enter radius of area affected: ";
	cin >> radius;

	cout << "Infrastructure Damage Level (High, Medium, Low):\t\t ";
	cin >> damage_level;
	while (damage_level != "High" && damage_level != "Medium" && damage_level != "Low" && damage_level != "high" && damage_level != "low" && damage_level != "medium") {
		cout << "\nInvalid input. Please enter High, Medium or Low." << endl;
		cout << "Infrastructure Damage Level\t\t: ";
		cin >> damage_level;
	}

	cout << "Families Affected (10-200):\t\t: ";
	cin >> families_affected;
	while (families_affected < 10 || families_affected > 200) {
		cout << "\nInvalid input. Please enter a value between 10 and 200." << endl;
		cout << "Families Affected\t\t: ";
		cin >> families_affected;
	}

	cout << "Access Route Availability (yes/no):\t ";
	cin >> access_route;
	while (access_route != "yes" && access_route != "Yes" && access_route != "no" && access_route != "No") {
		cout << "\nInvalid input. Please enter yes or no.";
		cout << "Access Route Availability:\t ";
		cin >> access_route;
	}

	cout << "Aftershock Warning (yes/no)\t\t\t: ";
	cin >> aftershocks;
	while (aftershocks != "yes" && aftershocks != "Yes" && aftershocks != "No" && aftershocks != "no") {
		cout << "\nInvalid input. Please enter yes or no.";
		cout << "Aftershock Warning\t\t\t: ";
		cin >> aftershocks;
	}

	cout << "Medical Need (yes/no)\t\t\t: ";
	cin >> medical_need;
	while (medical_need != "yes" && medical_need != "Yes" && medical_need != "No" && medical_need != "no") {
		cout << "\nInvalid input. Please enter yes or no.";
		cout << "Medical Need\t\t\t: ";
		cin >> medical_need;
	}

	cout << "Trapped People (yes/no): ";
	cin >> trapped_ppl;
	while(trapped_ppl != "yes" && trapped_ppl != "Yes" && trapped_ppl != "No" && trapped_ppl != "no") {
		cout << "\nInvalid input. Please enter yes or no.";
		cout << "Trapped People\t\t\t: ";
		cin >> trapped_ppl;
	}

	
	cout << "Vulnerable Groups Present (yes/no): ";
	cin >> vulnerable_grps;
	while(vulnerable_grps != "yes" && vulnerable_grps != "Yes" && vulnerable_grps != "No" && vulnerable_grps != "no") {
		cout << "\nInvalid input. Please enter yes or no.";
		cout << "Vulnerable Groups Present\t\t\t: ";
		cin >> vulnerable_grps;
	}

	cout << "Local Clinic Functional (yes/no): ";
	cin >> local_clinic;
	while (local_clinic != "yes" && local_clinic != "Yes" && local_clinic != "No" && local_clinic != "no") {
		cout << "\nInvalid input. Please enter yes or no.";
		cout << "Local Clinic Functional\t\t\t: ";
		cin >> local_clinic;
	}

	cout << "Previous Aid Received (yes/no)\t: ";
	cin >> previous_aid_received;
	while (previous_aid_received != "yes" && previous_aid_received != "Yes" && previous_aid_received != "No" && previous_aid_received != "no") {
		cout << "\nInvalid input. Please enter yes or no.";
		cout << "Previous Aid Received\t\t\t: ";
		cin >> previous_aid_received;
	}

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