#pragma once
#include"../OOP_Project/user.h"
#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
using namespace std;
bool admin_signup_check = false;
bool admin_login_check = false;
class admin : public user
{
protected:
	char username[20]{};
	char password[20]{};
	long long int cnic;
public:
	void admin_menu()
	{
		int admin_menu_choice;
		while (1)
		{
			system("cls");
			cout << "Press 1 to add any doctor:\n";
			cout << "Press 2 to edit any doctor information:\n";
			cout << "Press 3 to delete any doctor:\n";
			cout << "Press 4 to view all doctors data:\n";
			cout << "Press 5 to view all patient's data:\n";
			cout << "Press 6 to schedule any doctor availability:\n";
			cout << "Press 7 to view appointments of doctors:\n";
			cout << "Press 0 to logout:\n";
			cin >> admin_menu_choice;
			switch (admin_menu_choice)
			{
			case 0:
				cout << "You pressed logout\n";
				//before_login_menu();
				break;
			case 1:
			add_another_doc:cout << "Opening Menu for Adding doctor....\n";
				//doc_login_obj.doc_signup();
				int add_another_doctor_choice;
				cout << "Press 1 if you want to add another doctor or press 2 for admin main menu or enter any digit to continue:\n";
				cin >> add_another_doctor_choice;
				if (add_another_doctor_choice == 1)
				{
					goto add_another_doc;
				}
				else if (add_another_doctor_choice == 2)
				{
					admin_menu();
				}
				else
				{
					break;
				}
				break;
			case 4:
				cout << "----------------Data of all the doctors-------------\n";
				//doc_login_obj.view_doctors_data();
			case 5:
				cout << "--------------Data of all the patients-------------\n";
				//patient_login_obj.view_patients_data();
			default:
				break;
			}
			
		}
	}
	long long int get_cnic()
	{
		return cnic;
	}
	admin()
	{
		cnic = 0;
		username[0] = '\0';
		password[0] = '\0';
	}
	void signup()
	{
		bool _lower = false, _upper = false, _special = false, _eightDigits = false;
		string pass;
		cout << "Enter username:\n";
		cin >> username;
		cout << "Enter your CNIC number(only digits):\n";
		cin >> cnic;
		while (check_cnic(cnic)== false)
		{
			cin >> cnic;
		}
	enter_8_digit: cout << "Enter password (8 digits):\n";
		cin >> pass;
		int l;
		l = pass.size();
		if (l == 8)
		{
			_eightDigits = true;
		}
		else
		{
			cout << "Password you have entered doesn't consist of 8 digits\n";
			goto enter_8_digit;
		}

		if (_eightDigits == true)
		{
			for (int i = 0; i < 8; i++)
			{
				if (pass[i] >= 65 && pass[i] <= 90)
				{
					//cout << pass[i];
					_upper = true;
				}
				if (pass[i] >= 97 && pass[i] <= 122)
				{
					_lower = true;
				}
				if (pass[i] >= 33 && pass[i] <= 47)
				{
					_special = true;
				}
			}
			if (_upper == false || _lower == false || _special == false)
			{
				goto enter_8_digit;
			}
			else
			{
				admin_signup_check = true;
				cout << "Admin Account Created\n";
			}
		}
		strcpy_s(password, pass.c_str());
	}
	void Login()
	{
		bool _lower = false, _upper = false, _special = false, _eightDigits = false;
		string pass;
		cout << "Enter username:\n";
		cin >> username;
		cout << "Enter your CNIC number(only digits):\n";
		cin >> cnic;
		while (check_cnic(cnic) == false)
		{
			cin >> cnic;
		}
	enter_8_digit: cout << "Enter password (8 digits):\n";
		cin >> pass;
		int l;
		l = pass.size();
		if (l == 8)
		{
			_eightDigits = true;
		}
		else
		{
			cout << "Password you have entered doesn't consist of 8 digits\n";
			goto enter_8_digit;
		}

		if (_eightDigits == true)
		{
			for (int i = 0; i < 8; i++)
			{
				if (pass[i] >= 65 && pass[i] <= 90)
				{
					//cout << pass[i];
					_upper = true;
				}
				if (pass[i] >= 97 && pass[i] <= 122)
				{
					_lower = true;
				}
				if (pass[i] >= 33 && pass[i] <= 47)
				{
					_special = true;
				}
			}
			if (_upper == false || _lower == false || _special == false)
			{
				goto enter_8_digit;
			}
			else
			{
				admin_signup_check = true;
				cout << "Successfully Logged In\n";
			}
		}
		strcpy_s(password, pass.c_str());
	}
	void store_signup()
	{
		ofstream fout;
		fout.open("AdminloginFile.dat", ios::app | ios::binary);
		fout.write((char*)this, sizeof(*this));
		fout.close();
	}
	bool check_cnic(long long int c)
	{
		string str;
		int length;
		str = to_string(c);
		length = str.size();
		if (length == 13)
		{
			return true;
		}
		else
		{
			cout << "Enter Valid CNIC number\n";
			return false;
		}
	}
	void show_username()
	{
		cout << username << endl;
		cout << password << endl;
	}
	void view_username()
	{
		ifstream fin;
		fin.open("AdminloginFile.dat", ios::in | ios::binary);
		if (!fin)
		{
			cout << "File not found\n";
		}
		else
		{
			fin.read((char*)this, sizeof(*this));
			while (!fin.eof())
			{
				show_username();
				fin.read((char*)this, sizeof(*this));
			}
			fin.close();
		}
	}
	string get_username()const
	{
		return username;
	}
	void login()
	{
		admin obj;
		enter_valid_password:cout << "Enter your username to login\n";
		cin >> username;
		cout << "Enter password to login\n";
		cin.ignore();
		cin.getline(password, 19);
		//fin.open("AdminloginFile.dat", ios::in | ios::binary);
		bool check = false;
		ifstream fin("AdminloginFile.dat", ios::binary);
		if (!fin)
		{
			cout << "File not found\n";
		}
		else
		{
			//cout << "File opened entering in else\n";
			while (fin.read((char*)&obj, sizeof(obj)))
			{
				/*cout << obj.username;
				cout << obj.password;*/
				if (!(strcmp(username, obj.username)))
				{
					cout << "Username matched\n";
					if (!(strcmp(password, obj.password)))
					{
						cout << "------------Welcome to OLADOC-----------" << endl;
						admin_login_check = true;
						break;
					}
					else
					{
						cout << "Enter valid password\n";
						goto enter_valid_password;
					}
				}
				else
				{
					cout << strcmp(get_username().c_str(), obj.get_username().c_str()) << " <- this" << endl;
					cout << "Enter valid username and password\n";
					goto enter_valid_password;
					break;
				}
			}
		}
	}
};