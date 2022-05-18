#ifndef POINTERARRAY_H
#define POINTERARRAY_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct POINTERARRAY{
	char** source;
	int index;
	int lineCount;
	
	int (*veriSayisiGetir)(struct POINTERARRAY*);
	void (*insertString)(struct POINTERARRAY*,int,int,char*);
	void (*veriYazdir)(struct POINTERARRAY*,int);
	void (*hepsiniYazdir)(struct POINTERARRAY*);
	void (*insertLine)(struct POINTERARRAY*,int,char*);
	void (*removeLine)(struct POINTERARRAY*,int);	
	void (*freeAll)(struct POINTERARRAY*);
};
typedef struct POINTERARRAY* PointerArray;

PointerArray Initialize_Component();
int VeriSayisiGetir(const PointerArray);
void VeriYazdir(const PointerArray,int);
void HepsiniYazdir(const PointerArray);
void InsertLine(const PointerArray,int,char*);
void RemoveLine(const PointerArray,int);
void InsertString(const PointerArray,int,int,char*);
void FreeAll(PointerArray);
#endif