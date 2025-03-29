//hi I can edit this
#include<iostream>
#include<string>
#include<fstream>
#include<windows.h>

using namespace std;

class admin {
private:
	fstream adminLog;
	fstream reg_user;
	fstream reg_cand;
	string username, password;

	bool validate_admin() {
	string usr, pas;
		while (getline(adminLog, usr, '*') && getline(adminLog, pas)) {
			if (usr == username && pas == password) {
				return true;
			}
		}
		return false;
	}

public:
	admin(string usr_name, string pass): username(usr_name), password(pass) {
		adminLog.open("admin_cr.txt", ios::in);

		if (!adminLog.is_open()) {
			cerr << "Unable to open file...\n";
		}

		if (validate_admin()) {
			cout << "\nWelcome Mr.Admin!\n\n";
			admin_options();
		}
		else {
			cout << "Invalid username or password!\nPlease try again...\n";
		}

	}

	~admin() {
		if(adminLog.is_open()) adminLog.close();
		if(reg_user.is_open()) reg_user.close();
		if(reg_cand.is_open()) reg_cand.close();
	}

	//Furthur options for admin i.e. add, remove and start elections etc 
	void admin_options() {
		int x;
		cout << "What would you like to perform! \n1. Register User/candidate. \n2. Update a User/Candidate. \n3. Remove a User/Candidate.\n4. Start Elections\n";
		cin >> x;
		switch(x) {
			case 1:
				int y;
				cout << "Add: \n1. User. \n2. Condidate.";
				cin >> y;
				if(y == 1) {
					add_user();
				}
				else if(y == 2) {
					add_cand();
				}
				else cerr << "Enter a valid option...\n";
				break;
			
			case 2:
				cout << "Update someone\n";
				break;
			
			case 3:
				cout << "Removing user\n";
				break;
			
			case 4:
				cout << "Start elections\n";
				break;
			
			default:
				cerr << "Please enter a valid choice (From 1-4)....\n";
				break;

		}
	}

	void add_user() {
		reg_user.open("user_cr.txt", ios::app);
		if (!reg_user.is_open()) {
			cerr << "Unable to open user file for writing.\n";
			break;
		}

		string new_username, new_password, NIC, region;
		int age;
		cout << "Enter new user's username: ";
		cin >> new_username;
		cout << "Enter new user's password: ";
		cin >> new_password;
		cout << "Enter user's CNIC: ";
		cin >> NIC;
		cout << "Enter user's region: ";
		cin >> region;
		cout << "Enter user's age: ";
		cin >> age;
		if(age >= 18) {
			reg_user << new_username << "*" << new_password << "*" << NIC << "*" << region << "*" << age << "\n";
			cout << "User added successfully!\n";
		}
		else cout << "User's age has to be above 18 for registeration....\n";

		reg_user.close();
	}

	void remove_user() {

	}

	void add_cand() {
		reg_cand.open("candidate_cr.txt", ios :: app);
		if(!reg_cand.is_open()) {
			cerr << "Unable to open file...\n";
			break;
		}

		string c_usr, c_pass, c_NIC, parties;
		int c_age;
		cout << "Enter new candidate's username: ";
		cin >> c_usr;
		cout << "Enter new candidate's password: ";
		cin >> c_pass;
		cout << "Enter candidate's CNIC: ";
		cin >> c_NIC;
		cout << "Enter parties the candidate can join: ";
		cin >> parties;
		cout << "Enter candidates age: ";
		cin >> c_age;
		if(c_age >= 18) {
			reg_cand << c_usr << "*" << c_pass << "*" << c_NIC << "*" << parties << "*" << age << endl;
			cout << "Candidate added successfully!\n";
		}
		else cout << "Candidate's age has to be above 18 for registeration....\n";

	}

	void remove_cand() {
		
	}


};

class candidate {
private:
	fstream candLog;
	string username, password;
	string party;

	bool validate_cand() {
		string a, b;
		while(getline(candLog, a, '*') && getline(candLog, b)) {
			if(a == username && b == password) {
				return true;
			}
		}
		return false;
	}

public:
	candidate(string a, string b): username(a), password(b) {
		candLog.open("candidate_cr.txt", ios :: in);

		if(!candLog.is_open()) {
			cerr << "Unable to open file...\n";
		}

		if(validate_cand()) {
			cout << "\nWelcome Mr.Candidate!\n\n";
			cand_options();
		}
		else cerr << "Incorrect username or password!\nPlease try again....\n";
	}

	~candidate() {
		if(candLog.is_open()) candLog.close();
	}

	//Furthur options for candidate i.e. view election, view votes etc
	void cand_options() {
		int x;
		cout << "What would you like to perform! \n1. View announced elections. \n2. View my votes. \n3. View my profile. \n4. Select/Update my party. \n";
		cin >> x;
		switch(x) {
			case 1:
				cout << "Viewing elections...\n";
				break;
			
			case 2:
				cout << "Viewing votes...\n";
				break;
			
			case 3:
				cout << "Viewing your profile...\n";
				break;

			case 4:
				cout << "Available parties...\n";
				break;
			
			default:
				cerr << "Please enter a valid choice (From 1-4)....\n";
				break;
		}
	}


};

class user {
private:
	fstream userLog;
	string vote;
	string username, password;

	bool validate_user() {
		string usr, pass;
		while (getline(userLog, usr, '*') && getline(userLog, pass)) {
			if (usr == username && pass == password) {
				return true;
			}
		}

		return false;
	}

public:

	user(string usr, string p): username(usr), password(p) {
		userLog.open("user_cr.txt", ios::in);
		if (!userLog.is_open()) {
			cerr << "Unable to open user file.\n";
			return;
		}

		if(validate_user()) {
			cout << "\nWelcome Mr. User!\n\n";
			user_options();
		}
		else 
			cout << "Incorrect username or password!\nPlease try again...\n";
	}

	~user() {
		if(userLog.is_open()) userLog.close();
	}
	
	//Furthur options for user i.e. vote, select candidate etc
	void user_options() {
		int x;
		cout << "What would you like to chosse! \n1. View available elections. \n2. View candidate information. \n3. Cast your vote. \n4. Log out.\n5. Help/FAQs";
		cin >> x;
		switch(x) {
			case 1:
				cout << "Elections viewer...\n";
				break;
			
			case 2:
				cout << "Viewing candidate's information...\n";
				break;
			
			case 3:
				cout << "Casting your vote...\n";
				break;	
			
			case 4:
				cout << "Logging out...\n";
				break;

			case 5:
				cout << "FAQs...\n";
				break;
			
			default:
				cerr << "Please enter a valid choice (From 1-5)....\n";
				break;
		}

	}


};


void adminLogin(string& , string& );

void candLogin(string& , string& );

void userLogin(string& , string& );

int main() {

	int var;
	cout << "How would you like to log in! \n1. Admin.\n2. Candidate.\n3. User.\n";
	cin >> var;
	system("cls");
	string a, b;
	
	switch(var) {

		case 1:
			adminLogin(a, b); 
			break;

		case 2:
			candLogin(a, b);
			break;

		case 3:
			userLogin(a, b);
			break;

		default:
			cerr << "Enter a vaild choice...\n";
			break;

	}

	return 0;
}


void adminLogin(string& usr, string& pass) { //this function will take you to admin panel

	cout << "Enter Admin Username: ";
	cin >> usr;
	cout << "Enter Admin Password: ";
	cin >> pass;
	admin one(usr, pass);

}

void userLogin(string& usr, string& pass) { //this function will take you to user panel

	cout << "Enter your Username: ";
	cin >> usr;
	cout << "Enter your Password: ";
	cin >> pass;
	user u1(usr, pass);
}

void candLogin(string& usr, string& pass) { //this function will take you to candidate panel

	cout << "Enter your Username: ";
	cin >> usr;
	cout << "Enter your Password: ";
	cin >> pass;
	candidate c1(usr, pass);
	
}
