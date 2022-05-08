#include "Oyun.h"

int main(){
    Oyun oyun;
    oyun=OyunOlustur();  
    oyun->ekranaCiz(oyun);
    oyun->Yoket(oyun);
    return 0;
}