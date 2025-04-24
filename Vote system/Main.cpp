#include"../src/header/user.h"
#include"../src/header/candidate.h"
#include"../src/header/admin.h"
#include"../src/header/voter.h"


int main() {

	int var;
	cout << "How would you like to log in! \n1. Admin.\n2. Candidate.\n3. User.\n";
	cin >> var;
	system("cls");
	string a, b;
	
	switch(var) {
		case 1:
		{
			admin a1("bilal", "0000");
			break;
		}
		case 2:
		{	

			break;
		}
		case 3:
		{	
			break;
		}
		default:
			cerr << "Enter a vaild choice...\n";
			break;

	}

	return 0;
}
