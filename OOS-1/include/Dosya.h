#ifndef DOSYA_H
#define DOSYA_H

#include "stdio.h"
#include "stdlib.h"
#include <string.h>

struct DOSYA{
	char* icerik;
	char* kisiYol;
	char* sayiYol;
	char* (*DosyadanKisiOku)(struct DOSYA*);
	char* (*DosyadanSansliSayiOku)(struct DOSYA*);
    void (*Yoket)(struct DOSYA*);
};
typedef struct DOSYA* Dosya;

Dosya DosyaOlustur(char*,char*);
char* KisiVeriOku(const Dosya);
char* SansliSayiOku(const Dosya);
void DosyaVeriYoket(Dosya);
#endif
