#include "Oyun.h"

char** kisiler;
Oyun OyunOlustur(){
    Oyun this;
    this = (Oyun)malloc(sizeof(struct OYUN));
    this->kisi=KisiOlustur();
    kisiler = malloc(sizeof(char*));
    kisiler[0] = NULL;   
    this->enZenginBakiye = 0;
    this->kacinciTur=0;
    this->kasa=0;
    this->ekranaCiz=&EkranaCiz;
    this->Yoket=OyunYoket;
    this->sablonOlustur=&SablonOlustur;
}
int CountLines()
{
    int count = 0;
    while (kisiler[count++]);
    return count - 1;
}

void EkranaCiz(const Oyun this)
{
    int i,k=0,t=0,counter=0;
    this->kisi->VeriTurDon(this->kisi);
    this->kisi->sayilariGetir(this->kisi);
    char * token = strtok(this->kisi->_kisiverileri2, "#");
    while( token != NULL ) {   
        k++;
        if(k==1){
            int num_lines = CountLines();
            kisiler = realloc(kisiler, (num_lines+2) * sizeof(char*));
            memmove(&kisiler[t+1], &kisiler[t], (num_lines-t+1)*sizeof(char*));
            kisiler[t] = malloc(strlen(token)+1);
            strcpy(kisiler[t],token);
            t++;
        }  
        if(k==4)
            k=0;
        token = strtok(NULL, "#");  
    }   

     this->enZengin = kisiler[0];
     this->enZenginBakiye = this->kisi->paralar[0];
    while (this->kisi->toplamTur>counter)
    {
        for (i = 0; i < this->kisi->toplamOyuncu; i++)
        {
           if(this->kisi->paralar[i]<1000) continue;     
           if(this->kisi->yatirdigiSayi[i]==this->kisi->sayilar[counter])
           { 
               this->kasa-=9 * (this->kisi->oranlar[i] * this->kisi->paralar[i]);
               this->kisi->paralar[i]= (this->kisi->paralar[i]-(this->kisi->oranlar[i] * this->kisi->paralar[i]))+(10*(this->kisi->oranlar[i] * this->kisi->paralar[i]));    
           }
           else
           {
                this->kasa+= this->kisi->oranlar[i] * this->kisi->paralar[i];
                this->kisi->paralar[i]=this->kisi->paralar[i] - (this->kisi->oranlar[i] * this->kisi->paralar[i]);            
           }
           if (this->kisi->paralar[i] > this->enZenginBakiye)
           {
               this->enZenginBakiye = this->kisi->paralar[i];
               this->enZengin = kisiler[i];
           }
        }    
        system("cls");
        SablonOlustur(this, this->kisi->sayilar[counter], counter + 1, this->kasa, this->enZengin, this->enZenginBakiye);
        this->enZenginBakiye = 0;
        counter++;
    }
    system("cls");
    OyunBitti(this, this->kasa);     
}
void SablonOlustur(const Oyun this, int sansliSayi, int tur, double kasa, char* zengin, int bakiyesi) {
    printf("\n\n\n\n");
    printf("\n%s", "                                 #############################################");
    printf("\n%s %d %s", "                                 ##              SANSLI SAYI: ",sansliSayi,"           ##");
    printf("\n%s", "                                 #############################################");
    printf("\n%s", "                                 #############################################");
    printf("\n%s %d %s", "                                 ##              TUR: ",tur,"                 ##");
    printf("\n                                 ##     KASA BAKIYESI: %d %s  ",(int)kasa  ,  "TL         ##");
    printf("\n%s", "                                 ##                                         ##");
    printf("\n%s", "                                 ##                                         ##");
    printf("\n%s", "                                 ##-----------------------------------------##");
    printf("\n%s", "                                 ##--------------EN ZENGIN KISI-------------##");
    printf("\n%s %s %s", "                                 ##--------------",zengin,"------------ ##");
    printf("\n%s %d %s", "                                  ##              BAKIYESI: ",bakiyesi,"          ##");
    printf("\n%s", "                                 ##                                         ##");
    printf("\n%s", "                                 #############################################");
}
void OyunBitti(const Oyun this, double kasa){
    printf("\n\n\n\n");
    printf("\n%s", "                                    #############################################");
    printf("\n%s %d %s", "                                    ##              TUR: ",this->kisi->toplamTur,"                 ##");
    printf("\n                                    ##        KASA BAKIYESI: %d %s   ",(int)kasa," TL      ##");
    printf("\n%s", "                                    ##                                         ##");
    printf("\n%s", "                                    ##                                         ##");
    printf("\n%s", "                                    ##-----------------------------------------##");
    printf("\n%s", "                                    ##              OYUN BITTI                 ##");
    printf("\n%s", "                                    ##                                         ##");
    printf("\n%s", "                                    ##                                         ##");
    printf("\n%s", "                                    #############################################");
    printf("%s","\n\n");
}
void OyunYoket(Oyun this){
    if(this==NULL) return;
    if(kisiler!=NULL){
        int line = CountLines();
      while (line >= 0)
        free(kisiler[line--]);
      free(kisiler);
    };
    if(this->kisi!=NULL) this->kisi->Yoket(this->kisi);  
    free(this); 
}