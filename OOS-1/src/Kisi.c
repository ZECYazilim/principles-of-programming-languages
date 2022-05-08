#include "Kisi.h"
Kisi KisiOlustur(){
    Kisi this;
    this = (Kisi)malloc(sizeof(struct DOSYA));
    this->veriAl=DosyaOlustur(".\\doc\\Kisiler.txt",".\\doc\\Sayilar.txt");
    this->_sansliSayiVerileri=this->veriAl->DosyadanSansliSayiOku(this->veriAl);
    this->_kisiVerileri=this->veriAl->DosyadanKisiOku(this->veriAl);
    this->_kisiverileri2=(char*)malloc(sizeof(char)*strlen(this->_kisiVerileri)); 
    this->toplamOyuncu=OyuncuSayisiGetir(this);
    this->toplamTur=TurSayisiGetir(this);
    this->paralar=(double*)malloc(sizeof(double)*this->toplamOyuncu);  
    this->oranlar=(float*)malloc(sizeof(float)*this->toplamOyuncu);
    this->yatirdigiSayi=(int*)malloc(sizeof(int)*this->toplamOyuncu);
    this->sayilar=(int*)malloc(sizeof(int)*this->toplamTur);
    this->VeriTurDon=&VerileriDon;
    this->sayilariGetir=&SayilariGetir;
    this->turSayisiGetir=&TurSayisiGetir;
    this->oyuncuSayisiGetir=&OyuncuSayisiGetir;
    this->Yoket=&KisiYoket;
}
void VerileriDon(const Kisi this)
{
    int i, kisiSayisi = 1;
    int disDongu=0;
    int icDongu=0;
    for (i=0; i < strlen(this->_kisiVerileri); i++)
    {
        if (this->_kisiVerileri[i] == '\n')
        {
            this->_kisiVerileri[i]='#';
            kisiSayisi++;

        }      
    }
    strcpy(this->_kisiverileri2,this->_kisiVerileri); //strtok problemi nedeniyle kopyaladım.
    int k=0,pIndex=-1,oIndex=-1,sIndex=-1,sira=1;
            char * token = strtok(this->_kisiVerileri, "#");
            while( token != NULL ) {            
              k++;             
                if((4*sira)-2==k){
                    pIndex++;
                    this->paralar[pIndex]=strtod(token,NULL);                   
                }
                if((4*sira)-1==k){
                    oIndex++;
                    this->oranlar[oIndex]=atof(token);
                }
                 if(4*sira==k){
                    sIndex++;
                    this->yatirdigiSayi[sIndex]=atoi(token);
                    sira++;
                }
                  token = strtok(NULL, "#");  
              }                                               
}
void SayilariGetir(const Kisi this){
    int i;
    int k=0;
    int turSayisi = 1;  
    for (i=0; i < strlen(this->_sansliSayiVerileri); i++)
    {
        if (this->_sansliSayiVerileri[i] == '\n')
        {
            turSayisi++;
        }      
    }
    char * token = strtok(this->_sansliSayiVerileri, "\n");
            while( token != NULL ) {  
                this->sayilar[k]=atoi(token);          
              k++;
              token = strtok(NULL, "\n"); 
            }
}
int OyuncuSayisiGetir(const Kisi this)
{
   int i, kisiSayisi = 1;
    for (i=0; i < strlen(this->_kisiVerileri); i++)
    {
        if (this->_kisiVerileri[i] == '\n')
        {
            kisiSayisi++;
        }      
    }
    return kisiSayisi;
}
int TurSayisiGetir(const Kisi this)
{
 int i, turSayisi = 1;
    for (i=0; i < strlen(this->_sansliSayiVerileri); i++)
    {
        if (this->_sansliSayiVerileri[i] == '\n')
        {
            turSayisi++;
        }      
    }
    return turSayisi;
}
void KisiYoket(Kisi this){
    if(this==NULL) return;
    free(this->oranlar);
    free(this->paralar);
    free(this->sayilar);
    free(this->yatirdigiSayi);
    free(this->_kisiverileri2);
    if(this->veriAl!=NULL) this->veriAl->Yoket(this->veriAl);
    free(this);
}

