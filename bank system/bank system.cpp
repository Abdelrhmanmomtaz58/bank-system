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
	vector<string>info_Employee;
	vector<string>info_Client;
	public:
};
class Client:public Person
{
	double balance=0;
public:
	bool  login_Client(string name1, string password1)
	{
		int i = 0;
		int j = i + 1;
		for (i = 0; i < info_Client.size(); i++)
		{
			j = i + 1;
			if (info_Client[i] == name1 && info_Client[j] == password1)
			{
				cout << "Welcome, " << name << "\nyou have registered successfully\n";
				return true;
			}
		}
		cout << "The name or password is incorrect\n";
		return false;
	}
	void deposit(double deposit)
	{
		balance = balance + deposit;
	}
	void withdraw(double withdraw)
	{
		balance = balance - withdraw;
	}
	double check_his_balance()
	{
		return balance;
	}
	void transfer(double transfer)
	{
		balance = balance - transfer;
	}
};
class Employee :public Person
{
	ofstream input;
	ifstream output;
protected:
	string salary;

public:
	bool  login(string name1, string password1)
	{
		int i=0;
		int j = i + 1;
		for ( i= 0; i < info_Employee.size(); i++)
		{
			j = i + 1;
			if (info_Employee[i] == password1)
			{
				cout << "Welcome, " << name << "\nyou have registered successfully\n";
				return true;
			}
		}
		cout << "The name or password is incorrect\n";
		return false;
	}
	void add_new_Client()
	{
		input.open("Client.txt", ios::out | ios::app);
		cout << "Enter the new Client name\n";
		cin >> name;
		cout << "Enter the new Client id\n";
		cin >> id;
		cout << "Enter the new Client password\n";
		cin >> password;
		info_Client.push_back(name);
		info_Client.push_back(password);
		info_Client.push_back(id);
		input.write((char*)&info_Client, sizeof info_Client);
		input.close();
	}
	void search_Client(string id1)
	{
		for (int i = 0; i < info_Client.size(); i++)
		{
			if (info_Client[i] == id1)
			{
				int j = i - 2;
				cout << info_Client[j];
				return;
			}
		}
		cout << "the Client is not found\n";
	}
	void list_all_Client()
	{
		for (int i = 0; info_Client.size(); i=i+3)
		{
			cout << info_Client[i]<<"\n";
		}

	}
	void edit_info_of_client(string name1,string name2)
	{
		for (int i = 0; i < info_Client.size(); i++)
		{
			if (info_Client[i] == name1)
			{

			info_Client[i]= name2;
				return;
			}
		}
		cout << "The client is not found\n";
	}

};
class Admin :public Employee
{
	ofstream input;
	ifstream output;
public:
	
	void add_new_Employee()
	{
		input.open("Employee.txt",ios::app);
		cout << "Enter the new employee name\n";
		cin >> name;
		cout << "Enter the new employee id\n";
		cin >> id;
		cout << "Enter the new employee password\n";
		cin >> password;
		cout << "Enter the new employee salary\n";
		cin >> salary;
		info_Employee.push_back(name);
		info_Employee.push_back(password);
		info_Employee.push_back(id);
		info_Employee.push_back(salary);
		input.write((char*)&info_Employee, sizeof info_Employee);
		input.close();
	}
	void search_Employee(string name)
	{
		for (int i = 0; i < info_Employee.size(); i++)
		{
			if (info_Employee[i] == name)
			{
				cout << name;
				return;
			}
		}
		cout << "The employee is not found\n";
	}
	void edit_Employee(string name,string name2)
	{
		for (int i = 0; i < info_Employee.size(); i++)
		{
			if (info_Employee[i] == name)
			{
				info_Employee[i] = name2;
				return;
			}
		}
		cout << "The employee is not found\n";
	}
	void list_all_employees()
	{
		for (int i = 0; i < info_Employee.size(); i++)
		{
			cout << info_Employee[i]<<"\n";
		}
	}
};
class enterface
{
	Client c;
	Employee e;
	Admin a;
public:
	
	enterface()
	{
		cout << "Welcome to the banking system\n";
		cout << "who are you\n";
		cout << "1.Admin\n2.Employee\n3.client\n";
		cout << "to exit ctrl+z\n";
	}
	void input()
	{
		int n;
		while (cin>>n)
		{
			if (n == 1) 
			{
				cout << "\twelcome Admin\n";
				cout << "1. add new Employee\n";
				cout << "2. search for Employee\n";
				cout << "3. edit Employee\n";
				cout << "4. list all employees\n";
				int n1;
				cin >> n1;
				if (n1 == 1)
				{
					a.add_new_Employee();
				}
				else if (n1 == 2)
				{
					string name;
					cout << "Enter the employee's name\n";
					cin >> name;
					a.search_Employee(name);
				}
				else if (n1 == 3)
				{
					string data1, data2;
					cout << "Enter old data and new data\n";
					cin >> data1 >> data2;
					a.edit_Employee(data1, data2);
				}
				else if (n1 == 4)
				{
					a.list_all_employees();
				}
			}
			else if (n==2)
			{
				cout << "\tWelcome Employee\n";
				cout << "login to the system \n";
				cout << "Please enter your name and password\n";
				string name, password;
				cin >> name >> password;
				if (e.login(name, password))
				{
					cout << "1.add new Client\n";
					cout << "2.search for client by id\n";
					cout << "3. list all clients\n";
					cout << "4.edit info of client\n";
					int n1;
					cin >> n1;
					if (n1 == 1)
					{
						e.add_new_Client();
					}
					else if (n1==2)
					{
						cout << "Please enter the Client id\n";
						string id;
						cin >> id;
						e.search_Client(id);
					}
					else if (n1 == 3)
					{
						e.list_all_Client();
					}
					else if (n1 == 4)
					{
						string data1, data2;
						cout << "Enter old data and new data\n";
						cin >> data1 >> data2;
						e.edit_info_of_client(data1, data2);
					}
				}
			}
			else if (n == 3)
			{
				cout << "\twelcome Client\n";
				cout << "login to the system\n";
				cout << "enter name and password";
				string name, password;
				cin >> name >> password;
				if (c.login_Client(name, password))
				{
					cout << "1.deposit amount of money \n";
					cout << "2.withdraw amount of money\n";
					cout << "3.check his balance\n";
					cout << "4.transfer money to another client\n";
					int n1;
					cin >> n1;
					if (n1 == 1)
					{
						cout << "Please enter the amount you want to deposit\n";
						double deposit;
						cin >> deposit;
						c.deposit(deposit);
					}
					else if (n1 == 2)
					{
						double withdraw;
						cout << "Please enter the amount you want to withdraw\n";
						cin >> withdraw;
						c.withdraw(withdraw);
					}
					else if (n1 == 3)
					{
						cout<<"Your bank balance = " << c.check_his_balance()<<"\n";
					}
					else if (n1 == 4)
					{
						string name;
						int account_number;
						double transfer;
						cout << "Enter the name and account number of the person you want to transfer to\n";
						cin >> name >> account_number;
						cout << "Enter the amount you want to transfer\n";
						cin >> transfer;
						c.transfer(transfer);
					}
				}
			}
		}
	}
};
int main()
{
	enterface l;
	l.input();
	return 0;
}