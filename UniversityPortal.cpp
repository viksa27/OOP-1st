#include <iostream>
#include <set>
using namespace std;

class Account {
public:
	Account(const string uname) :
		username(uname)
	{};

	string getUsername() { return username; }

	virtual bool departmentAccess() { return false; }

private:
	string username;
};

class Accounts {
public:
	bool userExists(const string username);
	bool FNexists(int num);
	void addUser(const string username);
	void addFN(int num);
private:
	set<string> registeredAccounts;
	set<int> registeredFN;
};

void Accounts::addUser(const string username) {
	registeredAccounts.insert(username);
}

void Accounts::addFN(int num) {
	registeredFN.insert(num);
}

bool Accounts::userExists(const string username) {
	auto it = registeredAccounts.find(username);
	if (it == registeredAccounts.end()) return false;

	return true;
}

bool Accounts::FNexists(int num) {
	auto it = registeredFN.find(num);
	if (it == registeredFN.end()) return false;

	return true;
}

class Student : public Account {
private:
	int numF, birthYear, group;
public:
	virtual bool departmentAccess() { return false; }
	void setNumF(int n) { numF = n; }
	int getNumF() { return numF; }
	void setBirthYear(int n) { birthYear = n; }
	int getBirthYear() { return birthYear; }
	void setGroup(int n) { group = n; }
	int getGroup() { return group; };
	Student(string n, int fn, int by, int gr) :
		Account(n),
		numF(fn),
		birthYear(by),
		group(gr) { }
};

class Teacher : public Account {
public:
	Teacher(string uname) :
		Account(uname) { };
	virtual bool departmentAccess() { return true; }
};

int main()
{
	Accounts acc;
	for (;;)
	{
		cout << "1 - Register student" << endl;
		cout << "2 - Register teacher" << endl;
		cout << "3 - Check username" << endl;
		cout << "4 - Exit" << endl;
		cout << "Enter: ";
		int choice; cin >> choice;
		if (choice < 1 || choice > 4) {
			cout << "Invalid input";
			cout << "\n\n";
			continue;
		}
		if (choice == 1)
		{
			string newUser;
			int newFN, newBirthYear, newGroup;
			cout << "Register username: ";
			cin >> newUser;
			if (acc.userExists(newUser)) {
				cout << "Username taken!" << endl;
				cout << "\n\n";
				continue;
			}
			cout << "Enter faculty number: ";
			cin >> newFN;
			if (acc.FNexists(newFN)) {
				cout << "This faculty number has a registered account!" << endl;
				cout << "\n\n";
				continue;
			}
			cout << "Enter birth year: ";
			cin >> newBirthYear;
			cout << "Enter group: ";
			cin >> newGroup;
			Student s(newUser,newFN,newBirthYear,newGroup);
			acc.addUser(s.getUsername());
			acc.addFN(s.getNumF());
			cout << "\n\n";
		}
		else if (choice == 2)
		{
			string newUser;
			cout << "Enter username: ";
			cin >> newUser;
			Teacher s(newUser);
			acc.addUser(s.getUsername());
			cout << "\n\n";
		}
		else if (choice == 3)
		{
			string enterUsername;
			cin >> enterUsername;
			if (acc.userExists(enterUsername)) {
				cout << "The user has access to the portal." << endl;
				cout << "\n\n";
			}
			else { cout << "The user does NOT have access to the portal" << endl; 
			cout << "\n\n"; 
			}
		}
		else { return 0; }
	}
}
