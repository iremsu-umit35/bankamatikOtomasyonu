#ifndef YETKILIISLEM_H
#define YETKILIISLEM_H
#include"musteriBilgi.h"

class yetkiliIslem
{
private:
	musteriBilgi m1;

public:
	yetkiliIslem();
	~yetkiliIslem();

	void musteriEkle();
	void musteriSil();
	void musteriAra();
	void musteriGuncelle();

	int yetkiliMenu();
	void yetkiliGiris();







};

#endif // !YETKILIISLEM_H

