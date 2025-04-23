#include"user.cpp"
#include <fstream>
#include <iostream>
using namespace std;


class admin: public User{
private:
	fstream adminLog;
	fstream reg_user;
	fstream reg_cand;

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
	admin(string usr_name, string pass): User(usr_name, pass) {
		adminLog.open("admin_cr.txt", ios::in);

		if (!adminLog.is_open()) {
			cerr << "Unable to open file...\n";
		}

		if (validate_admin()) {
			system("cls");
			cout << "\nWelcome Mr.Admin!\n\n";
			admin_options();
		}
		else {
			system("cls");
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
		cout << "\t\t\t\t\t====Admin Menu==== \n"
                "\t\t\t\t\t1. Register User/candidate. \n"
                "\t\t\t\t\t2. Update a User/Candidate. \n"
                "\t\t\t\t\t3. Remove a User/Candidate.\n"
                "\t\t\t\t\t4. Start Elections\n";
		cin >> x;
		switch(x) {
			case 1:
				int y;
				cout << "Add: \n1. User. \n2. Condidate. \n";
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
		system("cls");
		reg_user.open("user_cr.txt", ios::app);
		if (!reg_user.is_open()) {
			cerr << "Unable to open user file for writing.\n";
			return;
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
		system("cls");
		reg_cand.open("candidate_cr.txt", ios :: app);
		if(!reg_cand.is_open()) {
			cerr << "Unable to open file...\n";
			return;
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
			reg_cand << c_usr << "*" << c_pass << "*" << c_NIC << "*" << parties << "*" << c_age << endl;
			cout << "Candidate added successfully!\n";
		}
		else cout << "Candidate's age has to be above 18 for registeration....\n";

	}

	void remove_cand() {
		
	}
};