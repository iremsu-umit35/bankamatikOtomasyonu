#include "anaMenu.h"
#include "musteriIslem.h"
#include "yetkiliIslem.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

// Constructor for the anaMenu class
anaMenu::anaMenu()
{
}

// Destructor for the anaMenu class
anaMenu::~anaMenu()
{
}

// Method to handle administrator login
void anaMenu::yetkiliKontrol()
{
	system("clc"); // Clear the console screen
	char kullanýcýAdý[30], sifre[30];
	cout << "YETKILI GIRIS EKRANI.." << endl << endl;

	// Prompt for administrator username and password
	cout << "KULLANICI ADI:  ";
	cin.getline(kullanýcýAdý, 30);
	cin.ignore();

	cout << "SIFRE:  ";
	cin.getline(sifre, 30);
	cin.ignore();

	// Check if the username and password match the hardcoded admin credentials
	if (strcmp(kullanýcýAdý, "admin") == 0 && strcmp(sifre, "123") == 0) {
		yetkiliIslem y1; // Create an instance of yetkiliIslem
		y1.yetkiliGiris(); // Call the administrator menu
	}
	else {
		cout << "HATALI KULLANICI ADI VEYA PAROLA" << endl << endl; // Invalid login message
	}

	system("pause"); // Pause the screen to view the message
}

// Method to handle customer login
void anaMenu::musteriKontrol()
{
	system("clc"); // Clear the console screen
	char kullanýcýAdý[30], sifre[30], dosyaAdý[30];
	cout << "MUSTERÝ GIRIS EKRANI.." << endl << endl;

	// Prompt for customer username (which is the TC number) and password
	cout << "KULLANICI ADI:  ";
	cin.getline(kullanýcýAdý, 30);
	cin.ignore();

	cout << "SIFRE:  ";
	cin.getline(sifre, 30);
	cin.ignore();

	// Prepare the filename based on the TC number (username)
	strcpy_s(dosyaAdý, kullanýcýAdý);
	strcat_s(dosyaAdý, ".txt");

	// Open the file corresponding to the user's TC number
	ifstream file(dosyaAdý);
	file.read((char*)&m1, sizeof(musteriBilgi)); // Read the customer data from the file

	// Check if the file opened successfully
	if (!file.is_open()) {
		cout << "KULLANICI ADI/TCNO HATALI!" << endl << endl; // Error message if file not found
	}
	else {
		// Check if the password matches the one in the file
		if (strcmp(sifre, m1.getSifre()) == 0) {
			musteriIslem mi1; // Create an instance of musteriIslem
			mi1.musteriGiris(m1); // Proceed to the customer menu
		}
		else {
			cout << "HATALI TCNO/PAROLA" << endl << endl; // Invalid password message
		}
	}

	file.close(); // Close the file
	system("pause"); // Pause the screen to view the message
}

// Method to display the main menu
int anaMenu::menu()
{
	system("cls"); // Clear the console screen
	int secim = 0;
	cout << "BANKAMATIK OTOMASYONU... " << endl << endl;

	// Display options for administrator or customer login, or program exit
	cout << "[1]- YETKILI GIRIS" << endl;
	cout << "[2]- MUSTERI GIRIS" << endl;
	cout << "[0]- PROGRAMI KAPAT" << endl;

	cout << "SECIMINIZ:  ";
	cin >> secim; // Get user's selection
	return secim;
}

// Main method to manage the flow of the program based on user's selection
void anaMenu::giris()
{
	int secim = menu(); // Show the menu and get the selection
	while (secim != 0) {
		switch (secim) {
		case 1: yetkiliKontrol(); break; // Handle administrator login
		case 2: musteriKontrol(); break; // Handle customer login
		case 0:  break; // Exit the program
		default: cout << "Hatali Secim Yaptiniz!!" << endl; // Handle invalid selections
		}
		secim = menu(); // Show the menu again after each operation
	}
}
