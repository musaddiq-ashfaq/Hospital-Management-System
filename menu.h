#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<conio.h>
#include"../OOP_Project/admin.h"
#include"../OOP_Project/patient.h"
#include"patient.h"
using namespace std;
class menu
{
public:
	menu(){}
	doctor doc_login_obj;
	admin admin_login_obj;
	patient patient_login_obj;
	void before_login_menu()
	{
		int user_choice = 0;
		cout << "Enter 1 for Admin, 2 for Doctor and 3 for Patient:\n";
		cin >> user_choice;
		int signup_choice = 0;
		cout << "Enter 1 for Login and 2 for sign Up:\n";
		cin >> signup_choice;
		switch (user_choice)
		{
		case 1:
			if (signup_choice == 1)
			{
				admin_login_obj.Login();
				if(admin_login_check==true)
				{
					admin_menu();
				}
			}
			else if (signup_choice == 2)
			{
				admin_login_obj.signup();
				admin_login_obj.store_signup();
				if (admin_signup_check == true)
				{
					admin_menu();
				}	
			}
			break;
		case 2:
			if (signup_choice == 1)
			{
				doc_login_obj.login();
				if (doc_signup_check == true)
				{
					
				}
			}
			else if (signup_choice == 2)
			{
				doc_login_obj.doc_signup();
				if (doc_signup_check == true)
				{
					doc_login_obj.store_signup();
				}
			}
		case 3:
			if (signup_choice == 1)
			{
				patient_login_obj.login();
			}
			else if (signup_choice == 2)
			{
				patient_login_obj.signup();
				if(patient_signup_check==true)
				{
					patient_login_obj.store_signup();
				}
			}
		default:
			break;
		}
	}
	void doc_menu()
	{

	}
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
				before_login_menu();
				break;
			case 1:
			add_another_doc:cout << "Opening Menu for Adding doctor....\n";
				doc_login_obj.doc_signup();
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
				doc_login_obj.view_doctors_data();
			case 5:
				cout << "--------------Data of all the patients-------------\n";
				patient_login_obj.view_patients_data();
			default:
				break;
			}
			_getch();
		}
	}
};