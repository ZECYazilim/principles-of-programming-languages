#include "PointerArray.h"

PointerArray Initialize_Component(){
	PointerArray dpa;
	dpa->source = malloc(sizeof(char*));
    dpa->source[0] = NULL;
	dpa->index=0;
	dpa->lineCount=0;
	dpa->veriSayisiGetir=&VeriSayisiGetir;
	dpa->veriYazdir=&VeriYazdir;
	dpa->hepsiniYazdir=&HepsiniYazdir;
	dpa->insertLine=&InsertLine;
	dpa->removeLine=&RemoveLine;
	dpa->insertString=&InsertString;
	dpa->freeAll=&FreeAll;
	return dpa;
}

int VeriSayisiGetir(const PointerArray dpa){
	      int count = 0;
      while(dpa->source[dpa->lineCount++]) ;
      return dpa->lineCount-1;
}
void InsertString(const PointerArray dpa,int index,int col,char* string){
	dpa->source[index] = realloc(dpa->source[index], strlen(dpa->source[index])+strlen(string)+1);
    memmove(dpa->source[index]+col+strlen(string), dpa->source[index]+col, strlen(dpa->source[index])-col);
    memmove(dpa->source[index]+col, string, strlen(string));
}
void VeriYazdir(const PointerArray dpa ,int line){
	printf("Veri %d: %p %p %s\n",line, &dpa->source[line],dpa->source[line],dpa->source[line]);
}
void HepsiniYazdir(const PointerArray dpa){
   	int count = dpa->veriSayisiGetir(dpa);
    int line = 0;
      printf("----- %d Satir Sayisi ----\n",count);
      while (line < count)
        dpa->veriYazdir(dpa,line++);
      printf("---------------------\n");
}
void InsertLine(const PointerArray dpa,int index,char* string){
      int count = dpa->veriSayisiGetir(dpa);
      dpa->source = realloc(dpa->source, (count+2) * sizeof(char*));
      memmove(&dpa->source[count+1], &dpa->source[count], (count-index+1)*sizeof(char*));
      dpa->source[index] = malloc(strlen(string)+1);
      strcpy(dpa->source[index],string);
}
void RemoveLine(const PointerArray dpa,int index)
{
      int count = dpa->veriSayisiGetir(dpa);
      free(dpa->source[index]);
      memmove(&dpa->source[index], &dpa->source[index+1], (count-index+1)*sizeof(char*));
      dpa->source = realloc(dpa->source,count * sizeof(char*));
}
void FreeAll(PointerArray dpa){
	int count = dpa->veriSayisiGetir(dpa);
    while (count >= 1)
    	free(dpa->source[count--]);

      free(dpa->source);
}