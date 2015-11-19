#include "classes.h"

	using namespace std;

std::fstream& GotoLine(std::fstream& file, unsigned int num){  
	long size;
    file.seekg(std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    
    return file;

}
//________________________________________________________________________________________________________________________

	void Poluonumo::analyse_pol(char* buffer,int ls,Poluonumo P){
		int maxx=0,maxy=0,i=0,j=0,flag=0,num=0,psif=0,k=0,thx=0,thy=0;
	

	for (i=0;i<=ls;i++){
		     	int a=0,f=0;
		     	psif=0;
		     	num=0;
		     	if (buffer[i]=='^'){
			     	while(buffer[i]!='*' && buffer[i]!=' ' && buffer[i]!='+' && buffer[i]!='-' && buffer[i]!='\n'){
					int temp=i-1;
					i++;
					printf ("O ekthetis tou: %c einai:",buffer[i-2]);
					while (buffer[i]>='0' && buffer[i]<='9'){			
						if (psif>0)
						num *=10;
				
						num +=(buffer[i] -48);
				
						psif++;
						i++;
					}
					cout<<num<<endl;
					if ((buffer[i]=='x'|| buffer[i]=='y') && (buffer[i+1]=='*' || buffer[i+1]=='+' || buffer[i+1]=='-' || buffer[i+1]==' ' || buffer[i+1]=='\n')){
						temp=i;
						num=1;
					}
					
					if (buffer[temp]=='x'){
						thx=num;
						if (maxx<thx) maxx=thx+1;
					}	
					else if (buffer[temp]=='y'){
						
						thy=num;
						if (maxy<thy) maxy=thy+1;
					}
					}
				}
				if ((buffer[i]=='x'|| buffer[i]=='y') && (buffer[i+1]=='*' || buffer[i+1]=='+' || buffer[i+1]=='-' || buffer[i+1]==' ' || buffer[i+1]=='\n')){
					
					a=i;

					num=1;
					printf("O ekthetis tou %c einai %d \n",buffer[a],num);
				}
				
				if (buffer[a]=='x'){
					thx=num;
					if (maxx<thx) maxx=thx+1;
				}	
				else if (buffer[a]=='y'){
					
					thy=num;
					if (maxy<thy) maxy=thy+1;
				}
		     }

	 printf("Maxx:%d Maxy: %d \n",maxx,maxy);   
	 set_size(maxx,maxy);
	 create_pol();
	 printsize();
	thx=0;
	thy=0;
			for(i=0;i<=ls;i++) {
			int b=0;
			num=0;
			psif=0;
			if (buffer[i]>='0' && buffer[i]<='9'){
				int arn=0;
						if(buffer[i-1]=='-') arn=1;
						while (buffer[i]>='0' && buffer[i]<='9'){
								if (psif>0)
									num *=10;
									
							num +=(buffer[i] -48);
							
							psif++;
							i++;
						}
					if(arn) num=-num;
					cout<<num<<endl;
					k=num;
					if (buffer[i]==' ' || buffer[i]=='-' || buffer[i]=='+' || buffer[i]=='\n') {
						set_value(thx,thy,k);
						printf("H stathera: %d tha apothikeutei sti thesi: %d,%d \n",k,thx,thy);
						num=0;
						//continue;
					}
					i++;
					
					if (buffer[i]=='x' || buffer[i]=='y'){
						j=i;
						j++;
						flag=0;
						
						while(buffer[j]!=' ' && buffer[j]!='-' && buffer[j]!='+' && buffer[j]!='\n'){
							if (buffer[j]=='x' || buffer[j]=='y'){
								flag=1;									
								printf("O suntelestis twn: %c%c einai : %d \n",buffer[i],buffer[j],num);
								break;
							}
							j++;
						
						}
						if(!flag)
						printf("O suntelestis tou: %c einai : %d \n",buffer[i],num);
					}
			}

			
			else if (buffer[i]=='^'){

				int temp=i-1;
				i++;

				printf ("O ekthetis tou: %c einai:",buffer[i-2]);
				while (buffer[i]>='0' && buffer[i]<='9'){
										
						if (psif>0)
						num *=10;
								
					num +=(buffer[i] -48);
						
					psif++;
					i++;
				}

				cout<<num<<endl;
				//cout<<buffer[temp]<<endl;
						

				if (buffer[temp]=='x'){
						thx=num;
						
				}	
				else{
					
						thy=num;
						
				}
				if(buffer[i]==' '  || buffer[i]=='-' || buffer[i]=='+' || buffer[i]=='\n'){
						set_value(thx,thy,k);
					printf("O suntelestis : %d tha apothikeutei sti thesi : %d,%d \n",k,thx,thy);
				thx=0;
				thy=0;
				}	
				
				continue;
			}
			if ((buffer[i]=='x'|| buffer[i]=='y') && (buffer[i+1]=='*' || buffer[i+1]=='+' || buffer[i+1]=='-' || buffer[i+1]==' ' || buffer[i+1]=='\n')){
					
					b=i;
					num=1;
					if(buffer[b]=='x') thx=1;
					if(buffer[b]=='y') thy=1;
					printf("O ekthetis tou %c einai %d \n",buffer[b],num);
					if(buffer[i+1]!='*') set_value(thx,thy,k);

			}
				
			if (buffer[b]=='x'){
					thx=num;
					
			}	
			else if (buffer[b]=='y'){
					
				thy=num;
					
			}	
			if (buffer[i]==' '|| buffer[i]=='-' || buffer[i]=='+' || buffer[i]=='\n'){
				thx=0;
				thy=0;
				
			}
			
			}
}
//________________________________________________________________________________________________________________________

	int Poluonumo::getsizex(){
		return sizex-1;
	}
//________________________________________________________________________________________________________________________

	int Poluonumo::getsizey(){
		return sizey-1;
	}
//________________________________________________________________________________________________________________________

	void Poluonumo::set_size(int x,int y){		
		sizex=x;
		sizey=y;
		
	}
//________________________________________________________________________________________________________________________

	void Poluonumo::printsize(){ 
		printf("Megethos poluonumou : \n Sizex: %d Sizey: %d \n",sizex,sizey);
	}
//________________________________________________________________________________________________________________________

	void Poluonumo::create_pol(){

		polynomial= new int*[sizex];
		for(int i=0;i<sizex;i++){
			polynomial[i]=new int[sizey];
		}
		for(int i=0;i<sizex;i++){
			for(int j=0;j<sizey;j++){
				polynomial[i][j]=0;
				
			}
		}
	}
//________________________________________________________________________________________________________________________

	void Poluonumo::set_value(int x,int y, int v){
		polynomial[x][y]=v;
		printf("Apothikeusa to %d sti thesi %d,%d \n",polynomial[x][y],x,y);

	}
//________________________________________________________________________________________________________________________

	int Poluonumo::get_value(int i,int j){
		
		return polynomial[i][j];

	}
//________________________________________________________________________________________________________________________

	void Poluonumo::print_all(){
		printf("Polynomial matrix is:\n");
		for(int i=0;i<sizex;i++){
			for(int j=0;j<sizey;j++){
				
				printf(" %d" ,polynomial[i][j] );
			}
			cout<<endl;
		}
	}
//________________________________________________________________________________________________________________________

	int Poluonumo::print_byy(int flag){
		if (flag){
			return sizey;
		}else {
			return sizex;
		}
	}
//________________________________________________________________________________________________________________________

	void Poluonumo::generate_pol(int maximx, int maximy){
		time_t seed;
		time(&seed);
		srand(seed);

		for(int i=0;i<=maximx;i++){
			for(int j=0;j<=maximy;j++){
				polynomial[i][j]=(rand()%199) + (-99);
			}
		}
		printf("Polynomial is created: \n");
		for (int i=0;i<=maximx;i++){
			for(int j=0;j<=maximy;j++){
				if (i==0 && j==0)	printf("%d",polynomial[i][j]);
				
				else{
					if(polynomial[i][j]<0) printf(" %dx^%dy^%d",polynomial[i][j],i,j);
					if(polynomial[i][j]>0) printf(" +%dx^%dy^%d",polynomial[i][j],i,j);
					//if(polynomial[i][j]==0) printf(" +0");
				}
				

			}
		}
		printf("\n\n");
	}

//________________________________________________________________________________________________________________________

	void Poluonumo::katast( ){
		cout<<"Polynomial is deleted \n"<<endl;
		for (int i=0; i<sizex; i++){
			
			delete [] polynomial[i];
		}
		delete [] polynomial;
		
	 }
