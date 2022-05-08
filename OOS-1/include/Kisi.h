#ifndef KISI_H
#define KISI_H

#include "Dosya.h"

struct KISI{
    Dosya veriAl;
    char* _kisiVerileri;
    char* _kisiverileri2; //strtok problemi nedeniyle iki defa kopyaladım.
    char* _sansliSayiVerileri;
    double* paralar;
    float* oranlar;
    int* yatirdigiSayi;
    int* sayilar;
    int toplamOyuncu;
    int toplamTur;
    void (*VeriTurDon)(struct KISI*);
    void (*sayilariGetir)(struct KISI*);
    int (*oyuncuSayisiGetir)(struct KISI*);
    int (*turSayisiGetir)(struct KISI*);
    void (*Yoket)(struct KISI*);
};
typedef struct KISI* Kisi;
Kisi KisiOlustur();
void VerileriDon(const Kisi);
void SayilariGetir(const Kisi);
int OyuncuSayisiGetir(const Kisi);
int TurSayisiGetir(const Kisi);
void KisiYoket(Kisi);
#endif