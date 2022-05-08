#include "Mean.h"

Mean MeanOlustur(int sayilar[],int uzunluk){
		Mean this;
		this = (Mean)malloc(sizeof(struct MEAN));
		this->super=OrderOlustur(sayilar,uzunluk);
		
		this->ortalama=&Ortalama;
		this->yazdir=&Yazdir;
		this->yoket=&MeanYoket;
		return this;
}
double Ortalama(const Mean this){
		double toplam=0;
		int i;
		for(i=0;i<this->super->uzunluk;i++){
			toplam+=this->super->sayilar[i];
		}
		return toplam/this->super->uzunluk;
}
	
void Yazdir(const Mean this){
	this->super->toString(this->super);
	printf ("\n");
	printf("Ortalama:%.2lf\n",this->ortalama(this));
}
void MeanYoket(Mean this){
	if(this==NULL) return;
	this->super->yoket(this->super);
	free(this);
}