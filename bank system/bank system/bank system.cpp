#include <iostream>
#include<fstream>
#include <istream>
#include <vector>
#include <string>
using namespace std;
class  Person
{
protected:
	string id;
	string name;
	string password;
	public:
};
class Client:public Person
{
protected: 
	string balance;
public:
	


};
class Employee :public Person
{
protected:
	string salary;
public:

};
class Admin :public Employee
{
public:
	ofstream input;
	ifstream output;
	vector<string>info;
	void add_new_Employee()
	{
		input.open("Employee.txt",ios::out|ios::app);
		cout << "Enter the new employee name\n";
		cin >> name;
		cout << "Enter the new employee id\n";
		cin >> id;
		cout << "Enter the new employee password\n";
		cin >> password;
		cout << "Enter the new employee salary\n";
		cin >> salary;
		info.push_back(name);
		info.push_back(id);
		info.push_back(password);
		info.push_back(salary);
		input.write((char*)&info, sizeof info);
		input.close();
	}
	void search_Employee(string name)
	{
		for (int i = 0; i <info.size(); i++)
		{
			if (info[i] == name)
			{
				cout << name;
				return;
			}
		}
		cout << "The employee is not found\n";
	}
	void edit_Employee(string name,string name2)
	{
		for (int i = 0; i < info.size(); i++)
		{
			if (info[i] == name)
			{
				info[i] = name2;
				return;
			}
		}
		cout << "The employee is not found\n";
	}
	void list_all_employees()
	{
		for (int i = 0; i < info.size(); i++)
		{
			cout << info[0];
		}
	}


};
int main()
{
	

	return 0;
}