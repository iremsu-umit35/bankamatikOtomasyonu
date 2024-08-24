#ifndef ANAMENU_H
#define ANAMENU
#include"musteriBilgi.h"
class anaMenu
{
private:
	musteriBilgi m1;
public:
	anaMenu();
	~anaMenu();

	void yetkiliKontrol();
	void musteriKontrol();

	int menu();
	void giris();

};

#endif