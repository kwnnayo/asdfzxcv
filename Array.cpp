#include "classes.h"

using namespace std;
//________________________________________________________________________________________________________________________//

void Array::arraysize(int x){
	 	data=new int [x];
	 	
	 }
//________________________________________________________________________________________________________________________

	void Array::midenika(){
	 	data=new int [1];
	 	data[0]=0;
	 }
	void Array::gemisma(Poluonumo P,int mon, int j){
		for(int i=0;i<mon;i++){
			data[i]=P.get_value(j,i);
			printf("to Data[%d] einai %d\n",i,data[i]);
			
		}
	}
//________________________________________________________________________________________________________________________

	void Array::adeiasma(){
		
			delete [] data;		
	}
//________________________________________________________________________________________________________________________

	int Array::get(int i){
		printf("[");
		for(int j=0;j<i;j++){
			printf(" %d ",data[j]);
		}
		printf("]");

	}
	//maou

	int Array::getA0(int i){
		printf("[");
		for(int j=0;j<i;j++){
			printf(" %d ",data[0]);
		}
		printf("]");

	 	}
//________________________________________________________________________________________________________________________

	 	int Array::getAk(int i,int k){
		printf("[");
		for(int j=k;j<k+1;j++){
			printf(" %d ",data[j]);
		}
		printf("]");

	 	}
