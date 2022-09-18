#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
using namespace std;
class user
{
protected:
	char username[20];
	char password[20];
	long long int cnic;
public:
	void set_username(char arr[20])
	{
		for (int i = 0; i < 19; i++)
		{
			username[i] = arr[i];
		}
	}
	void set_password(char arr[20])
	{
		for (int i = 0; i < 19; i++)
		{
			password[i] = arr[i];
		}
	}
	/*virtual void login();
	virtual void signup();*/
};