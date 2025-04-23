#include"user.cpp"
#include<fstream>

class Candidate: public User {
private:

public:
	string party;
    fstream candLog;

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
	Candidate(string a, string b): User(a, b) {
		candLog.open("candidate_cr.txt", ios :: in);

		if(!candLog.is_open()) {
			cerr << "Unable to open file...\n";
		}

		if(validate_cand()) {
			cout << "\nWelcome Mr.Candidate!\n\n";
			showMenu();
		}
		else cerr << "Incorrect username or password!\nPlease try again....\n";
	}

	~Candidate() {
		if(candLog.is_open()) candLog.close();
	}

    void showMenu() override {
        int x;
        cout << "\t\t\t\t\t====Candidate Menu==== \n"
                "\t\t\t\t\t1. View announced elections. \n"
                "\t\t\t\t\t2. View my votes. \n"
                "\t\t\t\t\t3. View my profile. \n"
                "\t\t\t\t\t4. Select/Update my party. \n";
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
