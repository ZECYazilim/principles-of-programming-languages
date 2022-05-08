#ifndef OYUN_H
#define OYUN_H

#include "Kisi.h"

struct OYUN{
    Kisi kisi;
    double kasa;
    int kacinciTur;
    char* enZengin;
    double enZenginBakiye;
    void (*ekranaCiz)(struct OYUN*);
    void (*Yoket)(struct OYUN*);
    void (*sablonOlustur)(struct OYUN*,int,int,double,char*,int);
    void (*oyunBitti)(struct OYUN*,double);
};
typedef struct OYUN* Oyun;
Oyun OyunOlustur();
void EkranaCiz(const Oyun);
void OyunYoket(Oyun);
void SablonOlustur(const Oyun,int,int,double,char*,int);
void OyunBitti(const Oyun,double);
#endif