#include "musteriBilgi.h"
#include<string.h>
#include<iostream>
#include<stdlib.h>


// musteri bilgilerini alma
musteriBilgi::musteriBilgi() {
	strcpy_s(tcNo, "");
	strcpy_s(adSoyad, "");
	strcpy_s(adres, "");
	strcpy_s(tel, "");
	strcpy_s(sifre, "");
	bakiye = 0.0;
}

musteriBilgi::~musteriBilgi() {

}


musteriBilgi::musteriBilgi(char* tc, char* ads,char *adr, char* tl, char* sf, float bk) {
	strcpy_s(tcNo, tc);
	strcpy_s(adSoyad, ads);
	strcpy_s(adres,adr );
	strcpy_s(tel, tl);
	strcpy_s(sifre, sf);
	bakiye = bk;


}
// T.C. Kimlik Numaras� setter fonksiyonu
void musteriBilgi::setTcNo(char* ptr) {
	strcpy_s(tcNo, ptr);
}
// T.C. Kimlik Numaras� getter fonksiyonu
char* musteriBilgi::getTcNo(){
	return tcNo;
}
// Ad ve Soyad setter fonksiyonu
void musteriBilgi::setAdSoyad(char* ptr){
	strcpy_s(adSoyad, ptr);

}
// Ad ve Soyad getter fonksiyonu
char* musteriBilgi::getAdSoyad(){
	return adSoyad;
}
// Adres setter fonksiyonu
void musteriBilgi::setAdres(char* ptr){
	strcpy_s(adres, ptr);

}
// Adres getter fonksiyonu
char* musteriBilgi::getAdres(){
	return adres;
}
// Telefon Numaras� setter fonksiyonu
void musteriBilgi::setTel(char* ptr){
	strcpy_s(tel, ptr);
}
// Telefon Numaras� getter fonksiyonu
char* musteriBilgi::getTel(){
	return tel;
}
// �ifre setter fonksiyonu
void musteriBilgi::setSifre(char* ptr){
	strcpy_s(sifre, ptr);
}
// �ifre getter fonksiyonu
char* musteriBilgi::getSifre(){
	return sifre;
}
// Bakiye setter fonksiyonu
void musteriBilgi::setBakiye(float fb){
	bakiye = fb;
}
// Bakiye getter fonksiyonu
float musteriBilgi::getBakiye(){
	return bakiye;
}