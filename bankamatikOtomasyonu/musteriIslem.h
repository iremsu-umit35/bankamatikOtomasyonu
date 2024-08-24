#ifndef MUSTERIISLEM_H
#define MUSTERIISLEM_H
#include "musteriBilgi.h"

#include <string>  // std::string için gerekli
#include <iostream>  

class musteriIslem
{
private:
	musteriBilgi m1;
public:
	musteriIslem();
	~musteriIslem();

	musteriIslem(musteriBilgi m1 );
	void paraCek();
	void paraYatir();
	void bakiye();
	void havale();
	void hareketKaydet(const std::string& tcNo, const std::string& mesaj);
	void hesapHareketleri();
	void sifreDegistir();
	int musteriMenu();
	void musteriGiris(musteriBilgi m1);

};



#endif