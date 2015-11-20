#include "classes.h"


//________________________________________________________________________________________________________________________

void Md::create_md(int size){

	md =new Array*[size];
		for(int i=0;i<size;i++){
			md[i]=new Array[size];
		}
		for(int i=0;i<size;i++){

			for(int j=0;j<size;j++){
				
				md[i][j].midenika();
				
			}
		}
	printf ("Md matrix is created with d: %d \n",size);
}

//________________________________________________________________________________________________________________________
void Md::init_md(){
	
}
