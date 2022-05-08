#include "Dosya.h"

Dosya DosyaOlustur(char* kisiYol,char* sayilarYol){
    Dosya this;
    this = (Dosya)malloc(sizeof(struct DOSYA));
    this->icerik=NULL;
    this->kisiYol=kisiYol;
    this->sayiYol=sayilarYol;
    this->DosyadanKisiOku=&KisiVeriOku;
    this->DosyadanSansliSayiOku=&SansliSayiOku;
    this->Yoket=&DosyaVeriYoket;
    return this;
}

char* KisiVeriOku(const Dosya this){
    int boyut=0;
    FILE *fp;
    fp = fopen(this->kisiYol,"r");
    fseek(fp,0,SEEK_END);
    boyut = ftell(fp);
    rewind(fp);
    this->icerik=(char*)malloc(sizeof(char)*boyut);
    fread( this->icerik,1,boyut,fp);
    this->icerik[boyut-1]='\0';
    fclose(fp);
    return this->icerik;
}
char* SansliSayiOku(const Dosya this){
    FILE *fp;
    long lSize;
    char *buffer;
    fp = fopen (this->sayiYol, "rb" );
    if( !fp ) perror(this->sayiYol),exit(1);

    fseek( fp , 0L , SEEK_END);
    lSize = ftell( fp );
    rewind( fp );

    /* allocate memory for entire content */
    buffer = calloc( 1, lSize+1 );
    if( !buffer ) fclose(fp),fputs("memory alloc fails",stderr),exit(1);

    /* copy the file into the buffer */
    if( 1!=fread( buffer , lSize, 1 , fp) )
    fclose(fp),free(buffer),fputs("entire read fails",stderr),exit(1);
    char* icerik=(char*)malloc(sizeof(char)*lSize);
    strcpy(icerik,buffer);
    fclose(fp);
    free(buffer);
    return icerik;
}
void DosyaVeriYoket(Dosya this){
    if(this==NULL) return;
    free(this->icerik);
    free(this);
}