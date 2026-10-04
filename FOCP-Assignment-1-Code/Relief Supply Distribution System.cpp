#include<iostream>
#include<string>
#include <iomanip>
using namespace std;

int trucks = 5, supply_packs = 120, disaster = 0, families_affected = 0, deferred = 0, request_handled = 0;
string damage_level, access_route, aftershocks, area, medical_need, trapped_ppl, vulnerable_grps, local_clinic, previous_aid_received, selected_package, earth_quake, disas_start, update_inventory;

int welcome() {
	cout << "\nHi! Welcome to the Relief Supply Distribution System!" << endl;
	return 0;
}

int inventory() {
	cout << "\nWe currently have " << supply_packs << " supply packs and " << trucks << " trucks available for distribution." << endl;
	cout << "Would you like to update the inventory? (y/n): ";
	cin >> update_inventory;
	if (update_inventory == "y" || update_inventory == "Y" || update_inventory == "yes" || update_inventory == "Yes") {
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
	if (disaster ==1) {
		earth_quake = "y";
	}
	return 0;
}
int earthquake() {
	cout << "\nEarthquake Disaster Selected!" << endl;
	cout << "\nDisaster Type: Earthquake" << endl;
	cout << "Please enter the details of the earthquake disaster." << endl;
	

	cout << "\nIs there an Earthquake Relief Request?(Yes/No)\t: ";
	cin >> earth_quake;
	while (earth_quake == "y" || earth_quake == "Y" || earth_quake == "yes" || earth_quake == "Yes") {
		cout << "\nEnter name of area\t\t\t\t: ";
		cin >> area;

		cout << "Infrastructure Damage Level (High, Medium, Low)\t: ";
		cin >> damage_level;
		while (damage_level != "High" && damage_level != "Medium" && damage_level != "Low" && damage_level != "high" && damage_level != "low" && damage_level != "medium" && damage_level != "h" && damage_level != "m" && damage_level != "l" && damage_level != "H" && damage_level != "M" && damage_level != "L") {
			cout << "Invalid input. Please enter High, Medium or Low." << endl;
			cout << "Infrastructure Damage Level\t\t: ";
			cin >> damage_level;
		}

		cout << "Families Affected (10-200)\t\t\t: ";
		cin >> families_affected;
		while (families_affected < 10 || families_affected > 200) {
			cout << "Invalid input. Please enter a value between 10 and 200." << endl;
			cout << "Families Affected\t\t: ";
			cin >> families_affected;
		}

		cout << "Access Route Availability (yes/no)\t\t: ";
		cin >> access_route;
		while (access_route != "yes" && access_route != "Yes" && access_route != "no" && access_route != "No" && access_route != "y" && access_route != "n" && access_route != "Y" && access_route != "N") {
			cout << "Invalid input. Please enter yes or no.";
			cout << "Access Route Availability:\t ";
			cin >> access_route;
		}

		cout << "Aftershock Warning (yes/no)\t\t\t: ";
		cin >> aftershocks;
		while (aftershocks != "yes" && aftershocks != "Yes" && aftershocks != "No" && aftershocks != "no" && aftershocks != "y" && aftershocks != "n" && aftershocks != "Y" && aftershocks != "N") {
			cout << "Invalid input. Please enter yes or no.";
			cout << "Aftershock Warning\t\t\t: ";
			cin >> aftershocks;
		}

		cout << "Medical Need (yes/no)\t\t\t\t: ";
		cin >> medical_need;
		while (medical_need != "yes" && medical_need != "Yes" && medical_need != "No" && medical_need != "no" && medical_need != "y" && medical_need != "n" && medical_need != "Y" && medical_need != "N") {
			cout << "Invalid input. Please enter yes or no.";
			cout << "Medical Need\t\t\t: ";
			cin >> medical_need;
		}

		cout << "Trapped People (yes/no)\t\t\t\t: ";
		cin >> trapped_ppl;
		while (trapped_ppl != "yes" && trapped_ppl != "Yes" && trapped_ppl != "No" && trapped_ppl != "no" && trapped_ppl != "y" && trapped_ppl != "n" && trapped_ppl != "Y" && trapped_ppl != "N") {
			cout << "Invalid input. Please enter yes or no.";
			cout << "Trapped People\t\t\t: ";
			cin >> trapped_ppl;
		}


		cout << "Vulnerable Groups Present (yes/no)\t\t: ";
		cin >> vulnerable_grps;
		while (vulnerable_grps != "yes" && vulnerable_grps != "Yes" && vulnerable_grps != "No" && vulnerable_grps != "no" && vulnerable_grps != "y" && vulnerable_grps != "n" && vulnerable_grps != "Y" && vulnerable_grps != "N") {
			cout << "Invalid input. Please enter yes or no.";
			cout << "Vulnerable Groups Present\t\t\t: ";
			cin >> vulnerable_grps;
		}

		cout << "Local Clinic Functional (yes/no)\t\t: ";
		cin >> local_clinic;
		while (local_clinic != "yes" && local_clinic != "Yes" && local_clinic != "No" && local_clinic != "no" && local_clinic != "y" && local_clinic != "n" && local_clinic != "Y" && local_clinic != "N") {
			cout << "Invalid input. Please enter yes or no.";
			cout << "Local Clinic Functional\t\t\t: ";
			cin >> local_clinic;
		}

		cout << "Previous Aid Received (yes/no)\t\t\t: ";
		cin >> previous_aid_received;
		while (previous_aid_received != "yes" && previous_aid_received != "Yes" && previous_aid_received != "No" && previous_aid_received != "no" && previous_aid_received != "y" && previous_aid_received != "n" && previous_aid_received != "Y" && previous_aid_received != "N") {
			cout << "Invalid input. Please enter yes or no.";
			cout << "Previous Aid Received\t\t\t: ";
			cin >> previous_aid_received;
		}

		int people_points = 0;
		if (families_affected >= 10 && families_affected <= 50)
			people_points = people_points + 5;
		else if (families_affected >= 51 && families_affected <= 100)
			people_points = people_points + 10;
		else if (families_affected >= 101 && families_affected <= 150)
			people_points = people_points + 15;
		else if (families_affected >= 151 && families_affected <= 200)
			people_points = people_points + 20;
		if (medical_need == "yes" || medical_need == "Yes" || medical_need == "y" || medical_need == "Y")
			people_points = people_points + 25;
		if (trapped_ppl == "yes" || trapped_ppl == "Yes" || trapped_ppl == "y" || trapped_ppl == "Y")
			people_points = people_points + 30;
		if (vulnerable_grps == "yes" || vulnerable_grps == "Yes" || vulnerable_grps == "y" || vulnerable_grps == "Y")
			people_points = people_points + 15;
		if (local_clinic == "no" || local_clinic == "No" || local_clinic == "n" || local_clinic == "N")
			people_points = people_points + 10;

		int impact = 0;
		if (damage_level == "High" || damage_level == "high" || damage_level == "H" || damage_level == "h")
			impact = impact + 60;
		else if (damage_level == "medium" || damage_level == "Medium" || damage_level == "M" || damage_level == "m")
			impact = impact + 36;
		else if (damage_level == "Low" || damage_level == "low" || damage_level == "L" || damage_level == "l")
			impact = impact + 12;
		if (aftershocks == "yes" || aftershocks == "Yes" || aftershocks == "y" || aftershocks == "Y")
			impact = impact + 40;

		int complexity = 0;
		if (access_route == "no" || access_route == "No" || access_route == "n" || access_route == "N")
			complexity = complexity + 100;


		float needscore;
		needscore = (0.5 * people_points) + (0.4 * impact) + (0.1 * complexity);
		if (previous_aid_received == "yes" || previous_aid_received == "Yes" || previous_aid_received == "y" || previous_aid_received == "Y")
			needscore = needscore - 10;
		if (needscore > 100)
			needscore = 100;
		if (needscore < 0)
			needscore = 0;
		cout << fixed << setprecision(1);
		cout << "\nThe Calculated Need Score: " << needscore;

		string action;
		int level = 0, trucksused = 0, packsused = 0;

		if (needscore < 20)
		{
			action = "Deferred";
			deferred++;

		}
		else
		{
			if (needscore >= 20 && needscore < 40)
				level = 3; //emergency
			else if (needscore >= 40 && needscore < 65)
				level = 2; //standard
			else if (needscore >= 65)
				level = 1; //full
			bool sent = false;
			while (!sent && level <= 3) {
				int trucksneeded = 0, packsneeded = 0;
				if (level == 1) {
					trucksneeded = 2; packsneeded = 50;
				}
				else if (level == 2) {
					trucksneeded = 1; packsneeded = 30;
				}
				else if (level == 3) {
					trucksneeded = 1; packsneeded = 10;
				}
				if (trucks >= trucksneeded && supply_packs >= packsneeded) {
					trucks = trucks - trucksneeded;
					supply_packs = supply_packs - packsneeded;
					packsused = packsneeded;
					trucksused = trucksneeded;
					sent = true;
					request_handled++;

					if (level == 1) action = "Full Relief";
					else if (level == 2) action = "Standard Relief";
					else if (level == 3) action = "Emergency Kit";
				}
				else
					level++;
			}
			if (!sent) {
				action = "Deferred - not enough stock";
				deferred++;
			}
		}

		cout << "\n\nRelief Given for "<<area<<": "<< action << endl;
		cout << "\nTrucks Used: " << trucksused << " Supply Packs Used: " << packsused << endl;
		cout << "Remaining stock: " << trucks << "trucks , " << supply_packs << " supply packs"<<endl;

		cout << "\nDo you have another relief request? (Yes/No)\t: ";
		cin >> earth_quake;
	}

	cout << "\n---SUMMARY OF THE EARTHQUAKE---";
	cout << "\nRequests served: " << request_handled << endl;
	cout << "Requests deferred: " << deferred << endl;
	cout << "Trucks remaining: " << trucks << endl;
	cout << "Supply packs remaining: " << supply_packs << endl;

	cout << endl;
	return 0;
}

int main() {
	welcome();
	inventory();
	do {
		disasters();
		if (disaster == 1) {
			earthquake();
		}
		cout << "\nIs there another disaster?(yes/no) ";
		cin >> disas_start;
	} while (disas_start != "no" && disas_start != "No");
	cout << "\nThank you for using the Relief Supply Distribution System." << endl;
	return 0;
}