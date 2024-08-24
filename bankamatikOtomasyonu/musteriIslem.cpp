#include "musteriIslem.h"
#include <iostream>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include <cstring> 
using namespace std;


musteriIslem::musteriIslem(){}


musteriIslem::~musteriIslem()
{
}

musteriIslem::musteriIslem(musteriBilgi mptr)
{
	m1 = mptr;
}

void musteriIslem::paraCek()
{    
	float sayi;
	char dosyaAd�[30];
	// Para �ekme ekran� mesajlar�
	cout << "PARA CEKME EKRANI..." << endl << endl;
	cout << "BAKIYENIZ: " << m1.getBakiye() << "TL" << endl;
	cout << "CEKECEGINIZ MIKTAR (TL):  "; cin >> sayi;// Kullan�c�dan �ekilecek miktar� al�r

	if (sayi > m1.getBakiye()) {
		cout << "YETERSIZ BAKIYE !" << endl;
	}
	else {
		m1.setBakiye(m1.getBakiye() - sayi);

		// Dosya ad� olarak T.C. Kimlik numaras� kullan�l�r
		strcpy_s(dosyaAd�, m1.getTcNo());
		strcat_s(dosyaAd�, ".txt");

		ofstream file(dosyaAd�);
		file.write((char*)&m1, sizeof(musteriBilgi));
		file.close();
		cout << "PARA CEKME ISLEMI TAMAM" << endl;

		char msj[30];
		strcpy_s(msj, "PARA CEKILDI");
		hareketKaydet(m1.getTcNo(), msj);
	}

	system("pause");   
}

void musteriIslem::paraYatir()
{
	system("clc");
	float sayi;
	char dosyaAd�[30];
	// Para yat�rma ekran� mesajlar�
	cout << "PARA YATIRMA EKRANI..." << endl << endl;
	cout << "BAKIYENIZ: " << m1.getBakiye() << "TL" << endl;
	cout << "YATIRACAGINIZ MIKTAR (TL):  "; cin >> sayi;

	
		m1.setBakiye((m1.getBakiye() + sayi));


		strcpy_s(dosyaAd�, m1.getTcNo());
		strcat_s(dosyaAd�, ".txt");

		// Dosyaya m��teri bilgilerini yazar
		ofstream file(dosyaAd�);
		file.write((char*)&m1, sizeof(musteriBilgi));
		file.close();
		cout << "PARA YATIRMA ISLEMI TAMAM" << endl;
	
		char msj[30];
		strcpy_s(msj, "PARA YATIRILDI");
		hareketKaydet(m1.getTcNo(), msj);
	system("pause");
}

void musteriIslem::bakiye()
{
	system("cls");
	
	cout << "BAKIYE EKRANI..." << endl << endl;
	cout << "BAKIYENIZ: " << m1.getBakiye() << "TL" << endl;
	hareketKaydet(m1.getTcNo(), "bakiye sorguland�");
	cout << "Devam etmek i�in bir tu�a bas�n..." << endl;
	cin.ignore();
	cin.get();

	char msj[30];
	strcpy_s(msj, "BAK�YE SORGULANDI");
	hareketKaydet(m1.getTcNo(), msj);
}

void musteriIslem::havale()
{
	/*
	float sayi;
	char dosyaAd�[30], dosyaAd�2[30];
	char hesapNo[20];
	cout << "HAVALE/EFT EKRANI..." << endl << endl;
	cout << "BAKIYENIZ: " << m1.getBakiye() << "TL" << endl;
	cout << "HAVALE EDILECEK MIKTAR (TL):  "; cin >> sayi;

	if (sayi > m1.getBakiye()) {
		cout << "YETERSIZ BAKIYE !" << endl;
	}
	else {
		cout << "ALICI HESAP NO: "; cin >> hesapNo;
	
		strcpy_s(dosyaAd�2, hesapNo);
		strcat_s(dosyaAd�2, ".txt");

		ifstream file(dosyaAd�2);
		if (!file.is_open()) {
			cout << "alici hesap numaras� hatasi!!" << endl;
		}
		else {
			musteriBilgi m2;
			file.read((char*)&m2, sizeof(musteriBilgi));
			file.close();

			ofstream file(dosyaAd�2);
			m2.setBakiye(m2.getBakiye() + sayi);

			file.write((char*)&m2, sizeof(musteriBilgi));
			file.close();
			

			strcpy_s(dosyaAd�, m1.getTcNo());
			strcat_s(dosyaAd�, ".txt");
			ofstream file(dosyaAd�);

			m1.setBakiye(m1.getBakiye() - sayi);
			file.write((char*)&m1, sizeof(musteriBilgi));
			file.close();
			
			cout << "HAVALE  ISLEMI TAMAM" << endl;
		}
		file.close();

	}
	system("pause");

	*/

	float sayi;
	string dosyaAdi, dosyaAdi2;
	string hesapNo;

	cout << "HAVALE/EFT EKRANI..." << endl << endl;
	cout << "BAKIYENIZ: " << m1.getBakiye() << "TL" << endl;
	cout << "HAVALE EDILECEK MIKTAR (TL):  "; cin >> sayi;

	if (sayi > m1.getBakiye()) {
		cout << "YETERSIZ BAKIYE !" << endl;
		return;
	}

	cout << "ALICI HESAP NO: "; cin >> hesapNo;

	dosyaAdi2 = hesapNo + ".txt";

	ifstream infile(dosyaAdi2, ios::binary);
	if (!infile) {
		cout << "Alici hesap numaras� hatasi!!" << endl;
		return;
	}

	musteriBilgi m2;
	infile.read(reinterpret_cast<char*>(&m2), sizeof(musteriBilgi));
	infile.close();

	m2.setBakiye(m2.getBakiye() + sayi);

	ofstream outfile(dosyaAdi2, ios::binary);
	if (!outfile) {
		cout << "Dosya yazma hatasi!" << endl;
		return;
	}
	outfile.write(reinterpret_cast<const char*>(&m2), sizeof(musteriBilgi));
	outfile.close();

	dosyaAdi = string(m1.getTcNo()) + ".txt";

	m1.setBakiye(m1.getBakiye() - sayi);

	ofstream outfile2(dosyaAdi, ios::binary);
	if (!outfile2) {
		cout << "Dosya yazma hatasi!" << endl;
		return;
	}
	outfile2.write(reinterpret_cast<const char*>(&m1), sizeof(musteriBilgi));
	outfile2.close();

	cout << "HAVALE ISLEMI TAMAM" << endl;
	cout << "Devam etmek i�in bir tu�a bas�n..." << endl;
	cin.ignore();
	cin.get();

}

void musteriIslem::hareketKaydet(const std::string& tcNo, const std::string& mesaj)
{
	string dosyaAdi = tcNo + "rapor.txt";
	ofstream file(dosyaAdi, ios::app);
	if (!file) {
		cerr << "Dosya yazma hatas�!" << endl;
		return;
	}
	file << mesaj << endl;
	file.close();

}

void musteriIslem::hesapHareketleri()
{
	system("clc");
	char dosyaAd�[30];
	cout << "HESAP HARAKET EKRANI EKRANI..." << endl << endl;

	strcpy_s(dosyaAd�, m1.getTcNo());
	strcat_s(dosyaAd�, "rapor.txt");

	ifstream file(dosyaAd�);
	char harf;
	while (file.get(harf)) {
		cout << harf;
	}

	file.close();
	system("pause");
}

void musteriIslem::sifreDegistir()
{

	system("clc");
	char dosyaAd�[30];
	char eSifre[20], ySifre[20];
	cout << "SIFRE DEGISTIRME EKRANI..." << endl << endl;
	cout << "ESKI SIFRENIZ: " << scanf_s("[^\n]s", eSifre);
	cout << "YENI SIFRENIZ: " << scanf_s("[^\n]s", ySifre);

	strcpy_s(dosyaAd�, m1.getTcNo());
	strcat_s(dosyaAd�, ".txt");

	ifstream file(dosyaAd�);
	file.read((char*)&m1, sizeof(musteriBilgi));
	if (strcmp(eSifre, m1.getSifre()) != 0)
		cout << "eski sifre eslesmedi! " << endl;
	else {
		file.close();
		ofstream file(dosyaAd�);
		m1.setSifre(ySifre);
		file.write((char*)&m1, sizeof(musteriBilgi));
		file.close();
		cout << "SIFRE DEGISTIRME ISLEMI TAMAM" << endl;
	}
	file.close();
	system("pause");

}

int musteriIslem::musteriMenu()
{
	system("cls");
	int secim = 0;
	cout << "Sayin "<<m1.getAdSoyad() <<"Hosgeldiniz.." << endl << endl;
	cout << "Hesap no:  " << m1.getTcNo()  << endl << endl;
	
	cout << "[1]- PARA CEK" << endl;
	cout << "[2]- PARA YATIR" << endl;
	cout << "[3]- BAKIYE" << endl;
	cout << "[4]- HAVALE/EFT" << endl;
	cout << "[5]- HESAP HAREKETLERI" << endl;
	cout << "[6]- SIFRE DEGISTIR " << endl;
	cout << "[0]- CIKIS " << endl;
	cout << "SECIMINIZ:  "; cin >> secim;
	return secim;
}

void musteriIslem::musteriGiris(musteriBilgi mPtr)
{

	m1 = mPtr;
	int secim = musteriMenu();
	while (secim != 0) {
		switch (secim) {
		case 1: paraCek(); break;
		case 2: paraYatir(); break;
		case 3: bakiye(); break; 
		case 4: hesapHareketleri(); break;
		case 5: havale(); break;
		case 6: sifreDegistir(); break;
		case 0:  break;

		default: cout << "Hatali Secim Yaptiniz!!" << endl;
		}
		secim = musteriMenu();
	}
	
}
