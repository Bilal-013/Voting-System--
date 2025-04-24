#include"../header/admin.h"
#include <fstream>
#include <iostream>
using namespace std;
#include "../header/User.h"

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
			showMenu();
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
	void showMenu() override {

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