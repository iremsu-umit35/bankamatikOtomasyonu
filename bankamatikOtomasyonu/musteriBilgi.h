#ifndef MUSTERÝBÝLGÝ_H
#define MUSTERÝBÝLGÝ_H

class musteriBilgi
{
private:
	char tcNo[20], adSoyad[30], adres[30], tel[20], sifre[20];
	float bakiye;
public:
	musteriBilgi();
	~musteriBilgi();

	musteriBilgi(char *tc,char *ads,char *adr,char *tl, char *sf, float bk );

	void setTcNo(char  *ptr);
	char * getTcNo();

	void setAdSoyad(char *ptr);
	char * getAdSoyad();

	void setAdres(char *ptr);
	char * getAdres();

	void setTel(char *ptr);
	char * getTel();

	void setSifre(char *ptr);
	char * getSifre();

	void setBakiye(float fb);
	float getBakiye();

};
#endif