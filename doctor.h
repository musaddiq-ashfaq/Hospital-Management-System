#pragma once
#include"../OOP_Project/user.h"
#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
using namespace std;
bool doc_signup_check = false;
bool doc_login_check = false;
class doctor : public user
{
protected:
	char username[20]{};
	char password[20]{};
	long long int cnic;
	//char re_enter[20]{};
	/*string specialization;
	string location;*/
	int starting_hour;
	int ending_hour;
public:
	long long int get_cnic()
	{
		return cnic;
	}
	doctor()
	{
		cnic = 0;
		username[0] = '\0';
		password[0] = '\0';
		//re_enter[0] = '\0';
	/*	specialization = "";
		location = "";*/
		starting_hour = 0;
		ending_hour = 0;
	}
	void doc_signup()
	{
		bool _lower=false, _upper=false, _special=false,_eightDigits=false;
		string pass;
		string user;
		cout << "Enter username:\n";
		cin >> user;
		cout << "Enter your CNIC number (only digits):\n";
		cin >> cnic;
		while(check_cnic(cnic) == false)
		{
			cout << "Enter valid cnic:\n";
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
			if ( _upper ==false || _lower==false || _special==false) 
			{
				goto enter_8_digit;
			}
			else
			{
				doc_signup_check = true;
				cout << "Doctor Account Created\n";
			}
		}
		strcpy_s(password, pass.c_str());
		strcpy_s(username, user.c_str());
		/*cout << "Please Re-Enter your password:\n";
		cin.ignore();
		cin.getline(re_enter, 19);
		while (check_reEnter(re_enter) == false)
		{
			cin >> re_enter;
		}*/
	}
	void store_signup()
	{
		ofstream fout;
		fout.open("loginFile.dat", ios::app | ios::binary);
		if (fout.write((char*)this, sizeof(*this))) {
			cout << username<<endl;
			cout << password << endl;
			fout.close();
		}
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
			return false;
		}
	}
	/*bool check_reEnter(char pass[19])
	{
		for (int i = 0; i < 19; i++)
		{
			if (password[i] == pass[i])
			{
				return true;
			}
			else
			{
				cout << "Please enter the same password you entered before:\n";
				return false;
			}
		}
	}*/
	void show_doctors_data()
	{
		cout << username << endl;
		cout << password << endl;
		cout << cnic << endl;
	}
	void view_doctors_data()
	{
		ifstream fin;
		fin.open("loginFile.dat", ios::in | ios::binary);
		if (!fin)
		{
			cout << "File not found\n";
		}
		else
		{
			fin.read((char*)this, sizeof(*this));
			while (!fin.eof())
			{
				show_doctors_data();
				fin.read((char*)this, sizeof(*this));
			}
			fin.close();
		}
	}
	void update_doc_info()
	{
		doctor obj;
		fstream file;
		file.open("loginFile.dat", ios::in | ios::out | ios::ate | ios::binary);
		file.seekg(0);
		file.read((char*)this, sizeof(*this));
		while (!file.eof())
		{
			if (strcmp(username, obj.username))
			{

			}
		}
	}
	string get_username()const
	{
		return username;
	}
	void login()
	{
		cout << "Enter username:\n";
		cin >> username;
		cout << "Enter Password:\n";
		cin >> password;
		doctor obj;
		ifstream fin("loginFile.dat", ios::binary);
		while (fin.read((char*)&obj, sizeof(obj))) {
			if (password == obj.password && username == obj.username)
			{
				//check = true;
				*(this) = obj;
				cout << "you have been logged in" << endl;
				//logged_in = true;

			}
		}
		fin.close();
	}
}; 