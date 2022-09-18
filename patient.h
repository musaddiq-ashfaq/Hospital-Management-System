#pragma once
#include"../OOP_Project/user.h"
#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
using namespace std;
bool patient_login_check = false;
bool patient_signup_check = false;
int patient_initial_balance;
class patient: public user
{
protected:
	char username[20]{};
	char password[20]{};
	long long int cnic;
public:
	long long int get_cnic()
	{
		return cnic;
	}
	patient()
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
				patient_signup_check = true;
				cout << "Patient Account Created\n";
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
				patient_signup_check = true;
				cout << "Successfullly Logged In\n";
			}
		}
		strcpy_s(password, pass.c_str());
	}
	void store_signup()
	{
		ofstream fout;
		fout.open("PatientloginFile.dat", ios::app | ios::binary);
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
	void show_patients_data()
	{
		cout << username << endl;
		cout << password << endl;
	}
	void view_patients_data()
	{
		ifstream fin;
		fin.open("PatientloginFile.dat", ios::in | ios::binary);
		if (!fin)
		{
			cout << "File not found\n";
		}
		else
		{
			fin.read((char*)this, sizeof(*this));
			while (!fin.eof())
			{
				show_patients_data();
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
		patient obj;
		enter_valid_password:cout << "Enter your username to login\n";
		cin >> username;
		cout << "Enter password to login\n";
		cin.ignore();
		cin.getline(password, 19);
		//fin.open("PatientloginFile.dat", ios::in | ios::binary);
		bool check = false;
		ifstream fin("PatientloginFile.dat", ios::binary);
		if (!fin)
		{
			cout << "File not found\n";
		}

		else
		{
			//cout << "File opened entering in else\n";
			while (fin.read((char*)&obj, sizeof(obj)))
			{
				if (!(strcmp(username, obj.username)))
				{
					//cout << "Username matched\n";
					if (!(strcmp(password, obj.password)))
					{
						cout << "------------Welcome to OLADOC-----------" << endl;
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
					//cout << strcmp(get_username().c_str(), obj.get_username().c_str()) << " <- this" << endl;
					cout << "Enter valid username and password\n";
					goto enter_valid_password;
					break;
				}
			}
		}
	}
};