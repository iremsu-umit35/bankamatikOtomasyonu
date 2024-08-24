#include "yetkiliIslem.h"
#include <iostream>
#include <memory>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>

using namespace std;

yetkiliIslem::yetkiliIslem(){

}

yetkiliIslem::~yetkiliIslem() {


}

//musteri ekleme fonksiyonu
void yetkiliIslem:: musteriEkle() {
	system("clc");
	char kelime[100]; // Kelime i�in bir alan tahsis et
	float sayi; // sayi i�in bir alan tahsis et

	cout << "MUSTERI EKLEME ISLEMI..." << endl;
	cout << "MUSTERI TC NO: ";
	cin.getline(kelime, 100);
	cin.ignore();
	m1.setTcNo(kelime);
	

	cout << "MUSTERI AD SOYAD: ";
	cin.getline(kelime, 100);
	cin.ignore();
	m1.setAdSoyad(kelime);

	cout << "MUSTERI ADRES: ";
	cin.getline(kelime, 100);
	cin.ignore();
	m1.setAdres(kelime);

	cout << "MUSTERI TELEFON: ";
	cin.getline(kelime, 100);
	cin.ignore();
	m1.setTel(kelime);

	m1.setSifre(m1.getTcNo()); // �ifre varsay�lan olarak tc olu�turuldu

	cout << "MUSTERI BAKIYE: ";
	cin >> sayi;
	m1.setBakiye(sayi); // Bakiye de�erini ayarlay�n, setBakiye fonksiyonunu s�n�f�n�za ekleyin



	/*
	char kelime[30];
	float sayi;
	system("clc");
	cout << "MUSTER� EKLEME �SLEM�..." << endl;
	cout << "MUSTER� TC NO: "; scanf("%[^\n]s", kelime); m1.setTcNo(kelime); 
	cout << "MUSTER� AD SOYAD: "; scanf("%[^\n]s", kelime); m1.setAdSoyad(kelime);
	cout << "MUSTER� ADRES: "; scanf("%[^\n]s", kelime); m1.setAdres(kelime);
	cout << "MUSTER� TELEFON: "; scanf("%[^\n]s", kelime); m1.setTel(kelime);
	m1.setSifre(m1.getTcNo());  // sifre varsay�lan olarak tc olusturuldu
	cout << "MUSTER� BAK�YE: "; scanf("%f", &sayi); m1.setBakiye(sayi);
	// m1 m�steri bilgi s�n�f�nda �retilmi� bir nesne
	// musteri bilgileri al�n�p m1 nesnesinde tutuldu
	*/
	//al�nan veriler bir txt dosyas�na kaydedildi
	char dosyaAd�[30];
	strcpy_s(dosyaAd�, m1.getTcNo());
	strcat_s(dosyaAd�, ".txt");

	ofstream file(dosyaAd�);
	file.write((char*)&m1, sizeof(musteriBilgi));
	file.close();
	cout << "YENI MUSTERI KAYDI TAMAM" << endl << endl;
	system("pause");
}


//musteri kayd� silme fonksiyonu  // bu kodda hata var
void yetkiliIslem::musteriSil() {
	char kelime[30];
	float sayi;
	system("clc");
	cout << "MUSTERI SILME ISLEMI..." << endl;
	cout << "MUSTERI TC NO: ";
	cin.getline(kelime, 30);
	cin.ignore();


	// dosya i�inde aramak i�in yaz�ld�
	char dosyaAd�[30];
	strcpy_s(dosyaAd�, kelime);
	strcat_s(dosyaAd�, "txt");



	ifstream file(dosyaAd�);
	if (!file.is_open()) {// tc nolu musteri sorgulama
		cout << kelime << "NUMARALI MUSTERI KAYDI YOK !!" << endl;
	}

	else {
		file.read((char*)&m1, sizeof(musteriBilgi));
		cout << "MUSTERI TC NO     : " << m1.getTcNo() << endl;
		cout << "MUSTERI AD SOYAD  : " << m1.getAdSoyad() << endl;
		cout << "MUSTERI ADRES     : " << m1.getAdres() << endl;
		cout << "MUSTERI TELEFON   : " << m1.getTel() << endl;
		cout << "MUSTERI BAK�YE    : " << m1.getBakiye() << endl;
        file.close();
		
		char tercih;
		cout << "MUSTERI KAYDINI SILMEK ISTEDIGINIZE EMIN MISINIZ?[E/H]   " << endl;
		cin >> tercih;
		
		cin.ignore();

		if (tercih == 'e' || tercih == 'E') {
			if (remove(dosyaAd�) != 0) {
				cerr << "DOSYA SILINEMEDI!" << endl;
			}
			else {
				cout << "SILME ISLEMI BASARILI " << endl;
			}
		}
		else {
			cout << "SILME ISLEMI IPTAL EDILDI " << endl;
		}

	}

	file.close();//if d�ng�s�ne tak�l�rsa dosyay� kapatmak i�in kullan�l�r
	system("pause");

}

//musteri arama fonksiyonu
void yetkiliIslem::musteriAra() {
	
	char kelime[30];
	float sayi;
	system("clc");
	cout << "MUSTERI ARAMA ISLEMI..." << endl;
	cout << "MUSTERI TC NO: ";
	cin.getline(kelime, 30);
	cin.ignore();


	// dosya i�inde aramak i�in yaz�ld�
	char dosyaAd�[30];
	strcpy_s(dosyaAd�, kelime);	
	strcat_s(dosyaAd�, "txt");



    ifstream file(dosyaAd�);
	if (!file.is_open()) {// tc nolu musteri sorgulama
		cout << kelime << "NUMARALI MUSTERI KAYDI YOK !!" << endl;
	}

	else {
		file.read((char*)&m1, sizeof(musteriBilgi));
		cout << "MUSTERI TC NO     : " << m1.getTcNo()   << endl;
		cout << "MUSTERI AD SOYAD  : " << m1.getAdSoyad()<<endl;
		cout << "MUSTERI ADRES     : " << m1.getAdres()  << endl;
		cout << "MUSTERI TELEFON   : " << m1.getTel()    << endl;
		cout << "MUSTERI BAKIYE    : " << m1.getBakiye() << endl;

	}

	file.close();
	system("pause");
}


//musteri guncelleme fonksiyonu
void yetkiliIslem::musteriGuncelle() {
	char kelime[30];
	float sayi;
	system("clc");
	cout << "MUSTERI GUNCELLEME ISLEMI..." << endl;
	cout << "MUSTERI TC NO: ";
	cin.getline(kelime, 30);
	cin.ignore();


	// dosya i�inde aramak i�in yaz�ld�
	char dosyaAd�[30];
	strcpy_s(dosyaAd�, kelime);
	strcat_s(dosyaAd�, "txt");



	ifstream file(dosyaAd�);
	if (!file.is_open()) {// tc nolu musteri sorgulama
		cout << kelime << "NUMARALI MUSTERI KAYDI YOK !!" << endl;
	}

	else {
		file.read((char*)&m1, sizeof(musteriBilgi));
		cout << "MUSTERI TC NO     : " << m1.getTcNo() << endl;
		cout << "MUSTERI AD SOYAD  : " << m1.getAdSoyad() << endl;
		cout << "MUSTERI ADRES     : " << m1.getAdres() << endl;
		cout << "MUSTERI TELEFON   : " << m1.getTel() << endl;
		cout << "MUSTERI BAK�YE    : " << m1.getBakiye() << endl;

		cout << "BILGILERI GUNCELLLEYINZ..." << endl << endl;
		// musteri bilgilerini g�ncellleme i�lemi
		cout << "MUSTERI ADRES: ";
		cin.getline(kelime, 100);
		m1.setAdres(kelime);

		cout << "MUSTERI TELEFON: ";
		cin.getline(kelime, 100);
		m1.setTel(kelime);

		file.close();

		ofstream file(dosyaAd�);
		file.write((char*)&m1, sizeof(musteriBilgi));
		file.close();
		cout << "MUSTERI BILGILERI GUNCELLENDI..." << endl << endl;

	}

	file.close();//if d�ng�s�ne tak�l�rsa dosyay� kapatmak i�in kullan�l�r
	system("pause");

}


//menu
int yetkiliIslem::yetkiliMenu() {
	system("cls");
	int secim = 0;
	cout << "Sayin Admin Hosgeldiniz.." << endl<<endl;
	cout << "[1]- Musteri Ekle" << endl;
	cout << "[2]- Musteri Sil" << endl;
	cout << "[3]- Musteri Ara" << endl;
	cout << "[4]- Musteri guncelle" << endl;
	cout << "[0]- Cikis" << endl;
	cout << "Seciminiz: " ; cin >> secim;
	return secim;

}

//menu secim
void yetkiliIslem::yetkiliGiris() {
	int secim = yetkiliMenu();
	while (secim != 0) {
		switch (secim) {
		case 1: musteriEkle(); break;
		case 2: musteriSil(); break;
		case 3: musteriAra(); break;
		case 4: musteriGuncelle(); break;
		case 0:  break;

		default: cout << "Hatali Secim Yaptiniz!!" << endl;
		}
		secim = yetkiliMenu();
	}

}
