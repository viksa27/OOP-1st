#include <iostream>
#include <set>
using namespace std;

class User {
public:
	User(const string uname) :
		username(uname)
	{};
	string getUsername() const { return username; }
	virtual bool department() { return false; }

protected:
	string username;
	int facultyNumber = 0, birthYear = 0, group = 0;
};

class allUsers {
public:
	bool userExists(const User& u);
	void addUser(const User& u);
private:
	set<string> registeredUsers;
};

void allUsers::addUser(const User& u) {
	registeredUsers.insert(u.getUsername());
}

bool allUsers::userExists(const User& u) {
	auto it = registeredUsers.find(u.getUsername());
	if (it == registeredUsers.end()) return false;

	return true;
}

class Student : public User {
public:
	int getGroup() { return group; };
	Student(string uname, int facNum, int bYear, int gr) :
		User(uname) {
		facultyNumber = facNum;
		birthYear = bYear;
		group = gr;
	}
};

class Teacher : public User {
public:
	Teacher(string uname) :
		User(uname) { }
	virtual bool departmentAccess() { return true; }
};

class TeacherStudent : public User {
public:
	TeacherStudent(string uname, int facNum, int bYear, int gr) :
		User(uname) {
		facultyNumber = facNum;
		birthYear = bYear;
		group = gr;
	}
	virtual bool departmentAccess() { return true; }
};

void printMenu() {
	cout << "1 - Register student" << endl;
	cout << "2 - Register teacher" << endl;
	cout << "3 - Register teacher/student" << endl;
	cout << "4 - Check username" << endl;
	cout << "5 - Exit" << endl;
}

int getChoice() {
	cout << "Enter: ";
	int choice; cin >> choice;
	return choice;
}

Student getStudent() {
	string newUser;
	int newFN, newBirthYear, newGroup;
	cout << "Register username: ";
	cin >> newUser;
	cout << "Enter faculty number: ";
	cin >> newFN;
	cout << "Enter birth year: ";
	cin >> newBirthYear;
	cout << "Enter group: ";
	cin >> newGroup;
	return Student(newUser, newFN, newBirthYear, newGroup);
}

Teacher getTeacher() {
	string newUser;
	cout << "Enter username: ";
	cin >> newUser;
	return Teacher(newUser);
}

TeacherStudent getTeacherStudent() {
	string newUser;
	int newFN, newBirthYear, newGroup;
	cout << "Register username: ";
	cin >> newUser;
	cout << "Enter faculty number: ";
	cin >> newFN;
	cout << "Enter birth year: ";
	cin >> newBirthYear;
	cout << "Enter group: ";
	cin >> newGroup;
	return TeacherStudent(newUser, newFN, newBirthYear, newGroup);
}

int main()
{
	allUsers users;
	for (;;)
	{
		printMenu();
		int choice = getChoice();
		if (choice < 1 || choice > 5) {
			cout << "Invalid input";
			cout << "\n\n";
			continue;
		}
		if (choice == 1)
		{
			Student s = getStudent();
			if (users.userExists(s))
			{
				cout << "Username taken!" << endl;
				cout << "\n\n";
				continue;
			}
			users.addUser(s);
			cout << "\n\n";
		}
		else if (choice == 2)
		{
			Teacher t = getTeacher();
			users.addUser(t);
			cout << "\n\n";
		}
		else if (choice == 3)
		{
			TeacherStudent ts = getTeacherStudent();
			if (users.userExists(ts)) {
				cout << "Username taken!" << endl;
				cout << "\n\n";
				continue;
			}
			users.addUser(ts);
			cout << "\n\n";
		}
		else if (choice == 4)
		{
			string usernameCheck;
			cin >> usernameCheck;
			User u(usernameCheck);
			if (users.userExists(u)) {
				cout << "The user has access to the portal." << endl;
				cout << "\n\n";
			}
			else {
				cout << "The user does NOT have access to the portal" << endl;
				cout << "\n\n";
			}
		}
		else { return 0; }
	}
}