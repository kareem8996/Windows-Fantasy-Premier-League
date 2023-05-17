#include "Admin.h"
#include "System.h"
#include "Player.h"
#include "Defender.h"
#include "Attacker.h"
#include "Midfielder.h"
#include "GoalKeeper.h"

using namespace std;

Admin::Admin(int id,string name, string email, string Adminname, string password, string phoneNumber) {
	this->id = id;
	this-> name = name;
	this->phoneNumber = phoneNumber;
	this->email = email;
	this->userName = Adminname;
	this-> password = password;

}
Admin::Admin() {}

bool Admin::setPhoneNumber(string phone_number) {
	bool vPhone;

	vPhone = System::Check_Phone(phone_number);
	if (vPhone) {
		phoneNumber = phone_number;
		cout << "Your Phone number changed Successfully";
		return true;
	}

	else {
		cout << "Couldn't change your pohne number";
		return false;
	}
}

string Admin::getPhoneNumber() {
	return phoneNumber;
}
void Admin::setID(int id)
{
	this->id = id;
}
int Admin::getID()
{
	return id;
}
void Admin::setName(string name) {
	bool VName;

	VName = System::Check_Name(name);
	if (VName) {
		cout << "Your Name changed Successfully";
		this->name = name;
	}

	else {
		cout << "Couldn't change Name";

	}
}
void Admin::setEmail(string email)
{
	bool vEmail;

	vEmail = System::Check_Email(email);
	if (vEmail) {
		this->email = email;
		cout << "Your Email changed Successfully";

	}

	else {
		cout << "Couldn't change your Email";

	}

}
void Admin::setUsername(string username)
{
	bool vUserName;

	vUserName = System::Check_Username(username);
	if (vUserName) {
		this->userName = username;
		cout << "Your Username changed Successfully";

	}

	else {
		cout << "Couldn't change your username";

	}

}
string Admin::getName() {
	return name;
}
string Admin::getEmail()
{
	return email;
}
void Admin::setPassword(string pass, string conpass) {
	if (pass == conpass) {
		if (pass == getUsername())
			cout << "Sorry password can not be as the username";
		else if (pass == getPassword())
			cout << "Sorry this is your old password";
		else
			password = pass;

	}
	else {
		cout << "Sorry password does not match";

	}
}

void Admin::setPassword(string pass)
{
	password = pass;
}

string Admin::getUsername()
{
	return userName;
}

string Admin::getPassword() {
	return password;
}



//===================== Update Player Data=========================
void edit_player_options() {
	cout << "\t\tWhat would you like to do ??\n"
		<< "\t\t1 - change price \n"
		<< "\t\t2 - change team name \n"// validate  team existance
		<< "\t\t3 - change statuts \n"// cheack a d i n s u
		<< "\t\t4 - Change TotalPoints\n"
		<< "\t\t5 - Change TotalGoals\n"
		<< "\t\t6 - Change TotalAssists\n"
		<< "\t\t7 - Change TotalYellowCards\n"
		<< "\t\t8 - Change TotalRedCards\n";
}
void option_choise(int option,Player *&p) {
	
	int x = -1;
	switch (option) {
	case 1:
		cout << "do you want to increase or decrease " << p->getFullname() << " price \n";
		cout << "\t\t1 - increase price \n" << "\t\t2 - decrease price \n";
		if (x == 1)
			p->increasePrice();
		else if (x==2)
			p->decreasePrice();
		break;
	case 2:
	{cout << "what is the new team's name \n";
	string team;
	cin >> team;
	p->setClub(team);
	break;
	}
	case 3:
	{	cout << "what is the new status";
	string stat;
	cin >> stat;// cheack a d i n s u
	while (stat != "a" || stat != "d" || stat != "i" || stat != "n" || stat != "s" || stat != "u")
	{
		cout << "enter valid status from 'a d i n s u' ";
		cin >> stat;
	}
	p->setStatus(stat);
	break;
	}
	case 4:
		int points;
		cout << "enter total points";
		cin >> points;
		p->setTotalPoints(points);
		break;
	case 5:
		int goals;
		cout << "enter total goals";
		cin >> goals;
		p->setTotalGoals(goals);
		break;
	case 6:
		int assits;
		cout << "enter total assits";
		cin >> assits;
		p->setTotalAssists(assits);
		break;
	case 7:
		int yellow;
		cout << "enter total yellow cards";
		cin >> yellow;
		p->setTotalYellowCards(yellow);
		break;
	case 8:
		int red;
		cout << "enter total red cards";
		cin >> red;
		p->setTotalRedCards(red);
		break;
	default:
		cout << "enter valid number";
	}
}

//=============
void Admin::edit_player_menu() 
{
	int option;
	string position_picked;
	cout << "Pick a Position\n1.Goalkeeper\n2.Defender\n3.Midfielder\n4.Attacker\n5.Quit\n";
	cin >> position_picked;

	if (position_picked == "1") {
		{
			System::displayPlayers("GKP");
			int id;
			cout << "Enter the player ID\n";
			cin >> id;
			System::displayPlayers(System::AllPlayers["GKP"][id], false, "\n");
			// ASK what change i want make change in temp var


			string Player_Option;
			cout << "Are you sure you want to pick " << System::AllPlayers["GKP"][id]->getFullname() << " ?\n";
			cin >> Player_Option;
			if (Player_Option == "Y" || Player_Option == "y") {
				//assign temp var to obj

				edit_player_menu();
			cin >> option;
			//switch
			option_choise(option, System::AllPlayers["GKP"][id]);
		//	System::AllPlayers["GKP"][id];
			}
		}

	}
	else if (position_picked == "2")
	{
		System::displayPlayers("DEF");
		int id;
		cout << "Enter the player ID\n";
		cin >> id;
		System::displayPlayers(System::AllPlayers["DEF"][id], false, "\n");

		string Player_Option;
		cout << "Are you sure you want to pick " << System::AllPlayers["DEF"][id]->getFullname() << " ?\n";
		cin >> Player_Option;
		if (Player_Option == "Y" || Player_Option == "y") {
			edit_player_menu();
			cin >> option;
			//switch
			option_choise(option, System::AllPlayers["DEF"][id]);
			//System::AllPlayers["DEF"][id]
		}
	}
	else if (position_picked == "3") {

		System::displayPlayers("MID");
		int id;
		cout << "Enter the player ID\n";
		cin >> id;
		System::displayPlayers(System::AllPlayers["MID"][id], false, "\n");
		string Player_Option;
		cout << "Are you sure you want to pick " << System::AllPlayers["MID"][id]->getFullname() << " ?\n";
		cin >> Player_Option;
		if (Player_Option == "Y" || Player_Option == "y") {
			edit_player_menu();
			cin >> option;
			//switch
			option_choise(option, System::AllPlayers["MID"][id]);
			//System::AllPlayers["MID"][id];
		}
	}
	else if (position_picked == "4") {
		System::displayPlayers("FWD");
		int id;
		cout << "Enter the player ID\n";
		cin >> id;
		System::displayPlayers(System::AllPlayers["FWD"][id], false, "\n");

		string Player_Option;
		cout << "Are you sure you want to pick " << System::AllPlayers["FWD"][id]->getFullname() << " ?\n";
		cin >> Player_Option;
		if (Player_Option == "Y" || Player_Option == "y") {

			edit_player_menu();
			cin >> option;
			//switch
			option_choise(option, System::AllPlayers["FWD"][id]);
			//System::AllPlayers["FWD"][id];



		}
	}
	else if (position_picked == "5") 
	{
		return;//not sure what 5 does
	}	
}

//===================== Update Team Data=========================
void edit_club_options() {
	cout << "\t\tWhat would you like to do ??\n"
		<< "\t\t1 - remove palyer from club  \n"
		<< "\t\t2 - add palyer to club \n";

		
}


void Admin::edit_team_menu() {
	int option;
	int id;
	string PlayerName;
	string PlayerTeam;
	int PlayerTotalPoints;
	int PlayerPrice;
	string PlayerPosition;
	string PlayerStatus;
	int TotalCleanSheets;
	int TotalSaves;
	string PlayerPositionoption=NULL;
	cout << "\t\tWhat would you like to do ??\n"
		<< "\t\t1 - add palyer to club \n"
		<< "\t\t2 - remove palyer from club \n";
	cin >> option;
	do
	{
		cin >> option;

	} while (option != 1 || option != 1);
	switch (option) {
		
	case 1: {
		cout << "enter players id";
		cin >> id;
		cout << "enter players name";
		cin >> PlayerName;
		cout << "enter players total points";
		cin >> PlayerTotalPoints;
		cout << "enter players price";
		cin >> PlayerPrice;
		cout << "Pick a Position\n1.Goalkeeper\n2.Defender\n3.Midfielder\n4.Attacker\n";
		cin >> PlayerPositionoption;
		cout << "enter players status";
		cin >> PlayerStatus;
		cout << "enter players Total Clean Sheets";
		cin >> TotalCleanSheets;





	validate:
		switch (PlayerPositionoption[0])//add the temp to the file
		{
		case '1': {
			cout << "enter goalkeeper's total saves";
			cin >> TotalSaves;
			GoalKeeper golytemp(id, PlayerName, PlayerTeam, PlayerTotalPoints, PlayerPrice, PlayerPosition, PlayerStatus, TotalSaves, TotalCleanSheets);
			break; }
		case '2': {
			Defender deftemp(id, PlayerName, PlayerTeam, PlayerTotalPoints, PlayerPrice, PlayerPosition, PlayerStatus, TotalCleanSheets);
			break;
		}
		case '3': {

			Midfielder midtemp(id, PlayerName, PlayerTeam, PlayerTotalPoints, PlayerPrice, PlayerPosition, PlayerStatus, TotalCleanSheets);
			break;
		}
		case '4': {

			Attacker atktemp(id, PlayerName, PlayerTeam, PlayerTotalPoints, PlayerPrice, PlayerPosition, PlayerStatus);
			break;
		}
		default:
			cout << "enter valid number";
			cin >> PlayerPositionoption;
			goto validate;
			break;
		}

		break;
	}
	


	case 2: {
		
		string club_name;



	DisplayClubs:

		System::displayClubs();

		cout << "enter club name";
		cin >> club_name ; 

		if (System::AllClubs.find(club_name) == System::AllClubs.end())
			goto DisplayClubs;

	Display_squad:

		System::AllClubs[club_name]->DisplaySquad();
		string player_id;

		cout << "Please enter Player ID (or -1 to go back)";
		cin >> player_id;

		unordered_map<int, Player*> squad = System::AllClubs[club_name]->getSquad();

		if (squad.find(stoi(player_id)) == squad.end())
			goto Display_squad;
		else if (player_id == "-1")
			break;
		System::AllClubs[club_name]->deletePlayer(stoi(player_id));
		
		break;



	}
	default:
		cout << "enter valid number";
	}

}
	//club
	



//===================== Update User Account Data=========================


	void Admin::edit_user() { cout <<"ss"; }
//===================== Update League Data=========================

void Admin::edit_leagues() {}

void Admin::displaydata()
{
	cout << "Name: " << getName() << endl;
	cout << "Email: " << getEmail() << endl;
	cout << "Username: " << getUsername() << endl;
	cout << "Phone Number: " << getPhoneNumber() << endl;

}