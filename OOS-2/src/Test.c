#include "Mean.h"

int main(){
	int notlar[]={18,63,97,100,52,27,35};
	Mean m = MeanOlustur(notlar,7);
	m->yazdir(m);
	m->yoket(m);
	return 0;
}