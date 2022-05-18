#include "PointerArray.h"

int main()
{
    PointerArray pointerArray = Initialize_Component();
    pointerArray->insertLine(pointerArray,0,"Zekeriya Altunkaynak");
    pointerArray->insertLine(pointerArray,1,"Zekeriya Altunkaynak");
    pointerArray->insertLine(pointerArray,2,"Zekeriya Altunkaynak");
    pointerArray->insertLine(pointerArray,3,"Zekeriya Altunkaynak");
    pointerArray->insertLine(pointerArray,4,"Zekeriya Altunkaynak");
    pointerArray->insertLine(pointerArray,5,"Zekeriya Altunkaynak");
    pointerArray->insertLine(pointerArray,6,"Zekeriya Altunkaynak");
    pointerArray->hepsiniYazdir(pointerArray);
    pointerArray->freeAll(pointerArray);
    return 0;
}