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
	char kelime[100]; // Kelime için bir alan tahsis et
	float sayi; // sayi için bir alan tahsis et

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

	m1.setSifre(m1.getTcNo()); // þifre varsayýlan olarak tc oluþturuldu

	cout << "MUSTERI BAKIYE: ";
	cin >> sayi;
	m1.setBakiye(sayi); // Bakiye deðerini ayarlayýn, setBakiye fonksiyonunu sýnýfýnýza ekleyin



	/*
	char kelime[30];
	float sayi;
	system("clc");
	cout << "MUSTERÝ EKLEME ÝSLEMÝ..." << endl;
	cout << "MUSTERÝ TC NO: "; scanf("%[^\n]s", kelime); m1.setTcNo(kelime); 
	cout << "MUSTERÝ AD SOYAD: "; scanf("%[^\n]s", kelime); m1.setAdSoyad(kelime);
	cout << "MUSTERÝ ADRES: "; scanf("%[^\n]s", kelime); m1.setAdres(kelime);
	cout << "MUSTERÝ TELEFON: "; scanf("%[^\n]s", kelime); m1.setTel(kelime);
	m1.setSifre(m1.getTcNo());  // sifre varsayýlan olarak tc olusturuldu
	cout << "MUSTERÝ BAKÝYE: "; scanf("%f", &sayi); m1.setBakiye(sayi);
	// m1 müsteri bilgi sýnýfýnda üretilmiþ bir nesne
	// musteri bilgileri alýnýp m1 nesnesinde tutuldu
	*/
	//alýnan veriler bir txt dosyasýna kaydedildi
	char dosyaAdý[30];
	strcpy_s(dosyaAdý, m1.getTcNo());
	strcat_s(dosyaAdý, ".txt");

	ofstream file(dosyaAdý);
	file.write((char*)&m1, sizeof(musteriBilgi));
	file.close();
	cout << "YENI MUSTERI KAYDI TAMAM" << endl << endl;
	system("pause");
}


//musteri kaydý silme fonksiyonu  // bu kodda hata var
void yetkiliIslem::musteriSil() {
	char kelime[30];
	float sayi;
	system("clc");
	cout << "MUSTERI SILME ISLEMI..." << endl;
	cout << "MUSTERI TC NO: ";
	cin.getline(kelime, 30);
	cin.ignore();


	// dosya içinde aramak için yazýldý
	char dosyaAdý[30];
	strcpy_s(dosyaAdý, kelime);
	strcat_s(dosyaAdý, "txt");



	ifstream file(dosyaAdý);
	if (!file.is_open()) {// tc nolu musteri sorgulama
		cout << kelime << "NUMARALI MUSTERI KAYDI YOK !!" << endl;
	}

	else {
		file.read((char*)&m1, sizeof(musteriBilgi));
		cout << "MUSTERI TC NO     : " << m1.getTcNo() << endl;
		cout << "MUSTERI AD SOYAD  : " << m1.getAdSoyad() << endl;
		cout << "MUSTERI ADRES     : " << m1.getAdres() << endl;
		cout << "MUSTERI TELEFON   : " << m1.getTel() << endl;
		cout << "MUSTERI BAKÝYE    : " << m1.getBakiye() << endl;
        file.close();
		
		char tercih;
		cout << "MUSTERI KAYDINI SILMEK ISTEDIGINIZE EMIN MISINIZ?[E/H]   " << endl;
		cin >> tercih;
		
		cin.ignore();

		if (tercih == 'e' || tercih == 'E') {
			if (remove(dosyaAdý) != 0) {
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

	file.close();//if döngüsüne takýlýrsa dosyayý kapatmak için kullanýlýr
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


	// dosya içinde aramak için yazýldý
	char dosyaAdý[30];
	strcpy_s(dosyaAdý, kelime);	
	strcat_s(dosyaAdý, "txt");



    ifstream file(dosyaAdý);
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


	// dosya içinde aramak için yazýldý
	char dosyaAdý[30];
	strcpy_s(dosyaAdý, kelime);
	strcat_s(dosyaAdý, "txt");



	ifstream file(dosyaAdý);
	if (!file.is_open()) {// tc nolu musteri sorgulama
		cout << kelime << "NUMARALI MUSTERI KAYDI YOK !!" << endl;
	}

	else {
		file.read((char*)&m1, sizeof(musteriBilgi));
		cout << "MUSTERI TC NO     : " << m1.getTcNo() << endl;
		cout << "MUSTERI AD SOYAD  : " << m1.getAdSoyad() << endl;
		cout << "MUSTERI ADRES     : " << m1.getAdres() << endl;
		cout << "MUSTERI TELEFON   : " << m1.getTel() << endl;
		cout << "MUSTERI BAKÝYE    : " << m1.getBakiye() << endl;

		cout << "BILGILERI GUNCELLLEYINZ..." << endl << endl;
		// musteri bilgilerini güncellleme iþlemi
		cout << "MUSTERI ADRES: ";
		cin.getline(kelime, 100);
		m1.setAdres(kelime);

		cout << "MUSTERI TELEFON: ";
		cin.getline(kelime, 100);
		m1.setTel(kelime);

		file.close();

		ofstream file(dosyaAdý);
		file.write((char*)&m1, sizeof(musteriBilgi));
		file.close();
		cout << "MUSTERI BILGILERI GUNCELLENDI..." << endl << endl;

	}

	file.close();//if döngüsüne takýlýrsa dosyayý kapatmak için kullanýlýr
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
