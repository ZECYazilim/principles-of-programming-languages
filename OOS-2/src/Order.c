#include "Order.h"

Order OrderOlustur(int sayilar[],int uzunluk){
	Order this;
	this = (Order)malloc(sizeof(struct ORDER));
	this->sayilar=malloc(sizeof(int)*uzunluk);
	this->uzunluk=uzunluk;
	this->sirala= &Sirala;
	this->toString= &ToString;
	this->yoket= &OrderYoket;
	int i;
	for(i=0;i<uzunluk;i++)
	{
		this->sayilar[i]=sayilar[i];
	}
	return this;
}
int* Sirala(const Order this){
	int i;
	for(i=0;i<this->uzunluk-1;i++)
	{
		int j;
		for(j=1;j<this->uzunluk-i;j++)
		{
			if(this->sayilar[j]< this->sayilar[j-1])
			{
				int tmp= this->sayilar[j-1];
				this->sayilar[j-1]=this->sayilar[j];
				this->sayilar[j]=tmp;
			}
		}
	}
	return this->sayilar;
}
void ToString(const Order this){
	this->sirala(this);
	int i;
	for(i=0;i<this->uzunluk;i++){
		printf("%d ",this->sayilar[i]);
	}
	printf("\n");
}
void OrderYoket(Order this){
	if(this==NULL) return;
	free(this->sayilar); //Önce içeridekini yoket.
	free(this);
}