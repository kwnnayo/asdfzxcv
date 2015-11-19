#include "classes.h"

using namespace std;
//________________________________________________________________________________________________________________________

 int Sy::hidden_var(Poluonumo P,Poluonumo Q,int x1 , int y1,int x2,int y2){
	 	int min1;
	 	int min2;
	 	int flag1=0;
	 	int flag2=0;
	 	int flag3=0;
	 	
	 	if (x1>y1){
	 		min1=y1;
	 	}else if (x1<y1){
	 		min1=x1;
	 		flag1=1;

	 	}else {
	 		if(x1%2==0){ //an einai isa ,an tuxei to x na nai zugos kribw auto
	 		min1=x1;
	 		flag1=1;
	 		}
	 		else min1=y1;
	 	}


	 	if (x2>y2){
	 		min2=y2;
	 	}else if (x2<y2){
	 		min2=x2;
	 		flag2=1;

	 	}else {

	 		if(x2%2==0){ //an einai isa ,an tuxei to x na nai zugos kribw auto
	 		min2=x2;
	 		flag2=1;
	 	}
	 	else min2=y2;
	 }

	 	if(min1<min2){
	 		if(flag1){
	 			max1=y1;
	 			max2=y2;
	 			printf("Hidden variable is x, with minimum power %d \n",min1);
	 			flag3=1;
	 		}else{
	 			max1=x1;
	 			max2=x2;
	 			printf("Hidden variable is y, with minimum power %d \n",min1);
	 		}
	 	}else if(min2<min1){
	 		if(flag2){
	 			max1=y1;
	 			max2=y2;
	 			printf("Hidden variable is x, with minimum power %d \n",min2);
	 			flag3=1;
	 		}else{
	 			max1=x1;
	 			max2=x2;
	 			printf("Hidden variable is y, with minimum power %d \n",min2);

	 		}
	 	}	

	 	else {

	 		if(min2%2==0){
	 			if(flag2){
	 				max1=y1;
	 				max2=y2;
	 			printf("Hidden variable is x, with minimum power %d \n",min2);
	 			flag3=1;
	 			}
	 			else{
	 				max1=x1;
	 				max2=x2;
	 			printf("Hidden variable is y, with minimum power %d \n",min2);

	 			}
	 		}else{
	 			if(flag1){
	 				max1=y1;
	 				max2=y2;
	 			printf("Hidden variable is x, with minimum power %d \n",min1);
	 			flag3=1;
	 			}else{
	 				max1=x1;
	 				max2=x2;
	 			printf("Hidden variable is y, with minimum power %d \n",min1);
	 			}

	 		}

	 	}
	 			
	 			
	 			printf("Sylvester matrix is degree\n");
	 			size=P.print_byy(flag3)+Q.print_byy(flag3)-2;
	 			cout<<size<<endl;
	 		
	 		return flag3;

	 }
//________________________________________________________________________________________________________________________

	 void Sy::create_sylvester(){
	 	
		sylvester =new Array*[size];
		for(int i=0;i<size;i++){
			sylvester[i]=new Array[size];
		}
		for(int i=0;i<size;i++){

			for(int j=0;j<size;j++){
				
				sylvester[i][j].midenika();
				
			}
		}
		
	}
//________________________________________________________________________________________________________________________

	void Sy::init_sylvester(Array *Array1, Array *Array2,int size1,int size2,int mon1,int mon2){
		int k;
		for(int i=0;i<max2;i++){
			k=i;
			for (int j=0;j<size1;j++){
					
				sylvester[i][k]=Array1[size1-j-1];		
				k++;
			}
	 }
	 int j=0;
	 	 printf("Max1:%d,Max2:%d \n",max1,max2);
	 for(int i=max2;i<size;i++){
	 		k=i-max2;
			for (int j=0;j<size2;j++){
				
				sylvester[i][k]=Array2[size2-j-1];
				k++;

			}
		
	 }

	 for (int i=0;i<max2;i++){
	 	int change=1;
	 	int exe=1;
		for ( j=0;j<size;j++){
			if (exe > size1) change=1;
			if (i==j){
					change=2;
			}
			if (change==1){
				sylvester[i][j].get(1); //ektiposi midenikou
			}
			if ((change==2) && (exe<=size1)) {
				
				sylvester[i][j].get(mon1);
				exe++;
			}

			}
			printf("\n");
	 }
	 int line=0;
	 for (int i=max2;i<size;i++){
	 	int change=1;
	 	int exe=1;
	 	
	 	for(j=0;j<size;j++){
	 		if (exe > size2) change=1;
	 		if (line==j)	change=2;
	 		if (change==1) sylvester[i][j].get(1); //ektiposi midenikou
	 		if ((change==2)&& (exe<=size2)){

	 			sylvester[i][j].get(mon2);
				exe++;
	 		}
	 		
	 	}
	 	printf("\n");
	 	line++;
	 }




}
//________________________________________________________________________________________________________________________

void Sy::printA0_A1(Array *Array1, Array *Array2,int size1,int size2,int mon1,int mon2,int Ak){
		if(Ak==0){

				printf("O A0 einai : \n");
				for (int i=0;i<max2;i++){
				int change=1;
				int exe=1;
				for ( int j=0;j<size;j++){
				if (exe > size1) change=1;
				if (i==j){
						change=2;
				}
				if (change==1){
					sylvester[i][j].get(1); //ektiposi midenikou
				}
				if ((change==2) && (exe<=size1)) {
					
					sylvester[i][j].getA0(1);
					exe++;
				}

				}
				printf("\n");
				}
				int line=0;
				for (int i=max2;i<size;i++){
				int change=1;
				int exe=1;

				for(int j=0;j<size;j++){
					if (exe > size2) change=1;
					if (line==j)	change=2;
					if (change==1) sylvester[i][j].get(1); //ektiposi midenikou
					if ((change==2)&& (exe<=size2)){

						sylvester[i][j].getA0(1);
					exe++;
					}
					
				}
				printf("\n");
				line++;
				}
	}else{

				 printf("O A%d einai : \n",Ak);
				 for (int i=0;i<max2;i++){
				 	int change=1;
				 	int exe=1;
					for ( int j=0;j<size;j++){
						if(mon1>Ak){
								if (exe > size1) change=1;
								if (i==j){
										change=2;
								}
								if (change==1){
									sylvester[i][j].get(1); //ektiposi midenikou
								}
								if ((change==2) && (exe<=size1)) {
									
									sylvester[i][j].getAk(mon1,Ak);
									exe++;
								}
							}else{
								printf("[ 0 ]");
							}	
						}
						printf("\n");
				 }
				 int line=0;
				 
				 for (int i=max2;i<size;i++){	
				 	 int change=1;
				 	int exe=1;
				 	
				 	for(int j=0;j<size;j++){
				 		if(mon2>Ak){
						 		if (exe > size2) change=1;
						 		if (line==j)	change=2;
						 		if (change==1) sylvester[i][j].get(1); //ektiposi midenikou
						 		if ((change==2)&& (exe<=size2) ){
						 			
						 			sylvester[i][j].getAk(mon2,Ak);
									exe++;
						 		}
						 	}else{
								printf("[ 0 ]");
							}
						 	}
						 	printf("\n");
						 	line++;
						 }
					
					

			

		}
	}
//________________________________________________________________________________________________________________________

	void Sy::delete_sylv(){
		printf("Sylvester with size:%d is deleted \n",size);
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				sylvester[i][j].adeiasma();

			}
			delete sylvester[i];
		}
		delete [] sylvester;
	}
