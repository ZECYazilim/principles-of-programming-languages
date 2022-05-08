#ifndef MEAN_H
#define MEAN_H

#include "Order.h"

struct MEAN {
	Order super;
	
	double (*ortalama)(struct MEAN*);
	void (*yazdir)(struct MEAN*);
	void (*yoket)(struct MEAN*);
};
typedef struct MEAN* Mean;

Mean MeanOlustur(int sayilar[],int);
double Ortalama(const Mean);
void Yazdir(const Mean);
void MeanYoket(Mean);

#endif