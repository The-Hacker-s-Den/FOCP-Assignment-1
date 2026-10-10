#include<iostream>
#include<string>
#include <iomanip>
using namespace std;

/* Global resources and state variables
trucks/supply_packs = current availale stock
disaster = which disaster has the user picked from the menu
request_handled, deferred = running counters
The string variables hold the yes/n and cateogircal answers collected from the user*/

int trucks = 5, supply_packs = 120, disaster = 0, families_affected = 0, deferred = 0, request_handled = 0;
string damage_level, access_route, aftershocks, area, medical_need, trapped_ppl, vulnerable_grps, local_clinic, previous_aid_received, selected_package, earth_quake, disas_start, update_inventory, main_option;


//Prints the welcome banner when the program starts
int welcome() {
	cout << "\033[36m"<<"\nHi!Welcome to the Relief Supply Distribution System!" << "\033[0m" << endl;
	return 0;
}

int main_menu() {
	cout << "\nThe available options are:" << endl;
	cout << "\033[4mCommand:\tFunction:\t\t\tDescription:\033[0m" << endl;
	cout << "Inventory\tView Inventory\t\t\tView the current inventory" << endl;
	cout << "Disaster\tSelect Disaster\t\t\tSelect a disaster to respond to" << endl;
	cout << "Exit\t\tExit Program\t\t\tExit the program" << endl;
	cout << "\nPlease enter a command to continue: ";
	cin >> main_option;
	while (main_option != "Inventory" && main_option != "Disaster" && main_option != "Exit" && main_option != "inventory" && main_option != "disaster" && main_option != "exit" && main_option != "d" && main_option != "e" && main_option != "i" && main_option != "D" && main_option != "E" && main_option != "I") {
		cout << "Invalid input. Please enter a valid option." << endl;
		cout << "\nThe available options are:" << endl;
		cout << "\033[4mCommand:\tFunction:\t\t\tDescription:\033[0m" << endl;
		cout << "Inventory\tView Inventory\t\t\tView the current inventory" << endl;
		cout << "Disaster\tSelect Disaster\t\t\tSelect a disaster to respond to" << endl;
		cout << "Exit\t\tExit Program\t\t\tExit the program" << endl;
		cout << "\nPlease enter a command to continue: ";
		cin >> main_option;
	}
	return 0;
}

/*Shows the current stock and lets the admin optionally overwrite / update the
resources when the program restarts once over before processing any requests.*/
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

/*Displays the disaster type menu and recors the user's choice
Currently only "Earthquake" is implemented */
int disasters() {
	cout << "\n\nBelow is a list of available disasters:" << endl;
	cout << "1. Earthquake" << endl;
	cout << "\nPlease select a disaster by entering the corresponding number: ";
	cin >> disaster;
	while (!(cin >> disaster)) {
		cin.clear(); // Clear the error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
		cout << "Invalid input. Please enter a valid disaster number." << endl;
		cout << "\n\nBelow is a list of available disasters:" << endl;
		cout << "1. Earthquake" << endl;
		cout << "\nPlease select a disaster by entering the corresponding number: ";
		cin >> disaster;
	}
	return 0;
}

/* Handles the full earthquake relief overflow:
1. Collects request details
2. Validates input
3. Scores the request
4. Decides an action
5. Updates the stock
6. Prints a summary*/
int earthquake() {
	cout << "\n\033[36m" << "Earthquake Disaster Selected!" << "\033[0m" << endl;
	cout << "\nDisaster Type: Earthquake" << endl;
	cout << "Please enter the details of the earthquake disaster." << endl;
	

	cout << "\nIs there an Earthquake Relief Request?(Yes/No)\t: ";
	cin >> earth_quake;

	//Main loop: keep processing the relief requests until the user says no
	while (earth_quake == "y" || earth_quake == "Y" || earth_quake == "yes" || earth_quake == "Yes") {
		
		//Collect request details (each with input validation loops)
		cout << "\nEnter name of area\t\t\t\t: ";
		cin >> area;

		//Damage level: must be High/Medium/Low (various cases/abbreviations accepted
		cout << "Infrastructure Damage Level (\033[31mHigh,\033[33m Medium,\033[32m Low\033[0m) : ";
		cin >> damage_level;
		while (damage_level != "High" && damage_level != "Medium" && damage_level != "Low" && damage_level != "high" && damage_level != "low" && damage_level != "medium" && damage_level != "h" && damage_level != "m" && damage_level != "l" && damage_level != "H" && damage_level != "M" && damage_level != "L") {
			cout << "Invalid input. Please enter \033[31mHigh,\033[33m Medium\033[0m or\033[32m Low\033[0m." << endl;
			cout << "Infrastructure Damage Level\t\t: ";
			cin >> damage_level;
		}

		//NUmber of families affect: must be within the allowed 10-200 range
		cout << "Families Affected (10-200)\t\t\t: ";
		cin >> families_affected;
		while (families_affected < 10 || families_affected > 200) {
			cout << "Invalid input. Please enter a value between 10 and 200." << endl;
			cout << "Families Affected\t\t: ";
			cin >> families_affected;
		}


		//Whether the access route into the area is open or damaged
		cout << "Access Route Availability (\033[32myes/\033[31mno\033[0m)\t\t: ";
		cin >> access_route;
		while (access_route != "yes" && access_route != "Yes" && access_route != "no" && access_route != "No" && access_route != "y" && access_route != "n" && access_route != "Y" && access_route != "N") {
			cout << "Invalid input. Please enter yes or no." << endl;
			cout << "Access Route Availability:\t ";
			cin >> access_route;
		}


		//Whether an aftershock warning is in effect for the area
		cout << "Aftershock Warning (\033[31myes/\033[32mno\033[0m)\t\t\t: ";
		cin >> aftershocks;
		while (aftershocks != "yes" && aftershocks != "Yes" && aftershocks != "No" && aftershocks != "no" && aftershocks != "y" && aftershocks != "n" && aftershocks != "Y" && aftershocks != "N") {
			cout << "Invalid input. Please enter yes or no." << endl;
			cout << "Aftershock Warning\t\t\t: ";
			cin >> aftershocks;
		}

		//Whether the area has an urgent medical need
		cout << "Medical Need (\033[31myes/\033[32mno\033[0m)\t\t\t\t: ";
		cin >> medical_need;
		while (medical_need != "yes" && medical_need != "Yes" && medical_need != "No" && medical_need != "no" && medical_need != "y" && medical_need != "n" && medical_need != "Y" && medical_need != "N") {
			cout << "Invalid input. Please enter yes or no." << endl;
			cout << "Medical Need\t\t\t: ";
			cin >> medical_need;
		}

		//Whether there are people trapped in the area/ the rubble
		cout << "Trapped People (\033[31myes/\033[32mno\033[0m)\t\t\t\t: ";
		cin >> trapped_ppl;
		while (trapped_ppl != "yes" && trapped_ppl != "Yes" && trapped_ppl != "No" && trapped_ppl != "no" && trapped_ppl != "y" && trapped_ppl != "n" && trapped_ppl != "Y" && trapped_ppl != "N") {
			cout << "Invalid input. Please enter yes or no." << endl;
			cout << "Trapped People\t\t\t: ";
			cin >> trapped_ppl;
		}

		//Whether the vulnerable groups (elderly, children, disable, etc.) are present
		cout << "Vulnerable Groups Present (\033[31myes/\033[32mno\033[0m)\t\t: ";
		cin >> vulnerable_grps;
		while (vulnerable_grps != "yes" && vulnerable_grps != "Yes" && vulnerable_grps != "No" && vulnerable_grps != "no" && vulnerable_grps != "y" && vulnerable_grps != "n" && vulnerable_grps != "Y" && vulnerable_grps != "N") {
			cout << "Invalid input. Please enter yes or no." << endl;
			cout << "Vulnerable Groups Present\t\t\t: ";
			cin >> vulnerable_grps;
		}

		//Whether the local clinic is still functional (affects how much medical support is needed
		cout << "Local Clinic Functional (\033[32myes/\033[31mno\033[0m)\t\t: ";
		cin >> local_clinic;
		while (local_clinic != "yes" && local_clinic != "Yes" && local_clinic != "No" && local_clinic != "no" && local_clinic != "y" && local_clinic != "n" && local_clinic != "Y" && local_clinic != "N") {
			cout << "Invalid input. Please enter yes or no." << endl;
			cout << "Local Clinic Functional\t\t\t: ";
			cin >> local_clinic;
		}

		//Whether the area has already received aid previously (reduces priority slightly)
		cout << "Previous Aid Received (\033[31mno/\033[32myes\033[0m)\t\t\t: ";
		cin >> previous_aid_received;
		while (previous_aid_received != "yes" && previous_aid_received != "Yes" && previous_aid_received != "No" && previous_aid_received != "no" && previous_aid_received != "y" && previous_aid_received != "n" && previous_aid_received != "Y" && previous_aid_received != "N") {
			cout << "Invalid input. Please enter yes or no." << endl;
			cout << "Previous Aid Received\t\t\t: ";
			cin >> previous_aid_received;
		}

		/* ---NEED SCORE CALCULATION--
		The score is build from three sub-scores (people, impact and complexity)
		Each of them is weighted differently, combined and then adjusted. */

		//People points: how much people are affected due to the earthquake
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

		//Impact points: severity of physical/ structural damage and ongoing risks
		int impact_points = 0;
		if (damage_level == "High" || damage_level == "high" || damage_level == "H" || damage_level == "h")
			impact_points = impact_points + 60;
		else if (damage_level == "medium" || damage_level == "Medium" || damage_level == "M" || damage_level == "m")
			impact_points = impact_points + 36;
		else if (damage_level == "Low" || damage_level == "low" || damage_level == "L" || damage_level == "l")
			impact_points = impact_points + 12;
		if (aftershocks == "yes" || aftershocks == "Yes" || aftershocks == "y" || aftershocks == "Y")
			impact_points = impact_points + 40;

		//Complexity points: how hard it is to physically deliver aid
		int complexity_points = 0;
		if (access_route == "no" || access_route == "No" || access_route == "n" || access_route == "N")
			complexity_points = complexity_points + 100;

		/*Total needscore is the weighted combination of three categories:
		people (50%) + impact (40%) + complexity (10%) */
		float needscore;
		needscore = (0.5 * people_points) + (0.4 * impact_points) + (0.1 * complexity_points);
		//Penalty if the area has already received aid before (lower relative priority)
		if (previous_aid_received == "yes" || previous_aid_received == "Yes" || previous_aid_received == "y" || previous_aid_received == "Y")
			needscore = needscore - 10;
		//Clamp the score between the valid 0-100 range
		if (needscore > 100)
			needscore = 100;
		if (needscore < 0)
			needscore = 0;
		cout << fixed << setprecision(1);

		//Colorcode the printed score by severity band (just for readability in terminal)
		if (needscore < 20)
			cout << "\033[32m"; //Green Text
		else if (needscore >= 20 && needscore < 40)
			cout << "\033[33m"; //Yellow Text
		else if (needscore >= 40 && needscore < 65)
			cout << "\033[38;5;208m"; //Orange Text
		else if (needscore >= 65)
			cout << "\033[31m"; //Bright Red Text


		cout << "\nThe Calculated Need Score: " << needscore;

		//---Decision/Action Rules---
		string action;
		int level = 0, trucksused = 0, packsused = 0;

		if (needscore < 20)
		{
			//Scores below 20 are not urgent enough to act on right now
			action = "Deferred";
			deferred++;

		}
		else
		{
			//Map the score band to a starting relief "level"
			// (level 1 = largest relief package, level 3 = smallest)
			if (needscore >= 20 && needscore < 40)
				level = 3; //emergency first aid kit
			else if (needscore >= 40 && needscore < 65)
				level = 2; //standard aid
			else if (needscore >= 65)
				level = 1; //full aid

			/*Try to fulfill at the assigned level. 
			If stock is insufficient, step down to a smaller relief level instead of 
			refusing outright */
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
				//Only dispatch if enough trucks AND supply packs are available
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
					level++; // not enough stock at this level, try a smaller one
			}
			// If even the smallest relief level couldnt be met, defer the request
			if (!sent) {
				action = "Deferred - not enough stock";
				deferred++;
			}
		}

		cout << "\033[0m"; // Reset terminal color
		
		//---Print result for this request---
		cout << "\n\nRelief Given for "<<area<<": "<< action << endl;
		cout << "\nTrucks Used: " << trucksused << " Supply Packs Used: " << packsused << endl;
		cout << "Remaining stock: " << trucks << " trucks , " << supply_packs << " supply packs"<<endl;

		//Ask whether to process another request, loop continues if yes
		cout << "\nDo you have another relief request? (Yes/No)\t: ";
		cin >> earth_quake;
	}

	//---END OF DISASTER SUMMARY--
	cout << "\033[36m" << "\n--- SUMMARY OF THE EARTHQUAKE--- "<<"\033[0";
	cout << "\033[32m" << "\nRequests served : " << request_handled << "\033[0m" << endl;
	cout << "\033[31m" << "Requests deferred : " << deferred << "\033[0m" << endl;
	cout << "Trucks remaining: " << trucks << endl;
	cout << "Supply packs remaining: " << supply_packs << endl;

	cout << endl;
	return 0;
}

/*Program entry point:
1. shows welcome message
2. sets up inventory
3. loops over disasters until the user indicates there are no more to process */
int main() {
	welcome();
	main_menu();
	while (main_option != "Exit" && main_option != "exit" && main_option != "e" && main_option != "E") {
		if (main_option == "Exit" || main_option == "exit" || main_option == "e" || main_option == "E") {
			cout << "\nThank you for using the Relief Supply Distribution System." << endl;
			return 0;
		}
		else if (main_option == "Inventory" || main_option == "inventory" || main_option == "i" || main_option == "I") {
			inventory();
			main_menu();
		}
		else if (main_option == "Disaster" || main_option == "disaster" || main_option == "d" || main_option == "D") {
			disasters();
		}
		if (disaster == 1) {
			earthquake();
			cout << "\nIs there another disaster?(yes/no) ";
			cin >> disas_start;
		}

		if (disas_start == "yes" || disas_start == "Yes" || disas_start == "y" || disas_start == "Y") {
			disasters();
		}
		else if (disas_start == "no" || disas_start == "No" || disas_start == "n" || disas_start == "N") {
			cout << "\nThank you for using the Relief Supply Distribution System." << endl;
			return 0;
		}
	}
cout << "\nThank you for using the Relief Supply Distribution System." << endl;
return 0;
}