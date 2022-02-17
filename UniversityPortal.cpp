#include <iostream>
#include <set>
using namespace std;

class User {
public:
	User(const string uname) :
		username(uname)
	{};
	User() {
		username = "";
	}
	string getUsername() const { return username; }
protected:
	string username;
};

class UserStorage {
public:
	bool isUsernameTaken(const User& userToCheck);
	void addUser(const User& newUser);
private:
	int userCount = 0;
	User registeredUsers[1000];
};

void UserStorage::addUser(const User& newUser) {
	registeredUsers[userCount] = newUser;
	userCount++;
}

bool UserStorage::isUsernameTaken(const User& userToCheck) {

	for (int i = 0; i < userCount; i++)
	{
		if (registeredUsers[i].getUsername() == userToCheck.getUsername())
			return true;
	}

	return false;
}

class Student : virtual public User {
public:
	int getGroup() { return group; };
	Student(string uname, int facNum, int bYear, int gr) :
		User(uname) {
		facultyNumber = facNum;
		birthYear = bYear;
		group = gr;
	}
protected:
	int facultyNumber = 0, birthYear = 0, group = 0;
};

class Teacher : virtual public User {
public:
	Teacher(string uname, string dment) :
		User(uname) {
		department = dment;
	}
protected:
	string department;
};

class TeacherStudent : public Student, public Teacher {
public:
	TeacherStudent(string uname, int facNum, int bYear, int gr, string dment) :
		User(uname), Student(uname, facNum, bYear, gr), Teacher(uname, dment) { }
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
	string newUser, department;
	cout << "Enter username: ";
	cin >> newUser;
	cout << "Enter department: ";
	cin >> department;
	return Teacher(newUser, department);
}

TeacherStudent getTeacherStudent() {
	string newUser, department;
	int newFN, newBirthYear, newGroup;
	cout << "Register username: ";
	cin >> newUser;
	cout << "Enter faculty number: ";
	cin >> newFN;
	cout << "Enter birth year: ";
	cin >> newBirthYear;
	cout << "Enter group: ";
	cin >> newGroup;
	cout << "Enter department: ";
	cin >> department;
	return TeacherStudent(newUser, newFN, newBirthYear, newGroup, department);
}

int main()
{
	UserStorage registeredUsers;
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
			if (registeredUsers.isUsernameTaken(s))
			{
				cout << "Username taken!" << endl;
				cout << "\n\n";
				continue;
			}
			registeredUsers.addUser(s);
			cout << "\n\n";
		}
		else if (choice == 2)
		{
			Teacher t = getTeacher();
			registeredUsers.addUser(t);
			cout << "\n\n";
		}
		else if (choice == 3)
		{
			TeacherStudent ts = getTeacherStudent();
			if (registeredUsers.isUsernameTaken(ts)) {
				cout << "Username taken!" << endl;
				cout << "\n\n";
				continue;
			}
			registeredUsers.addUser(ts);
			cout << "\n\n";
		}
		else if (choice == 4)
		{
			string usernameCheck;
			cin >> usernameCheck;
			User u(usernameCheck);
			if (registeredUsers.isUsernameTaken(u)) {
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