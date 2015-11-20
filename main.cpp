#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "classes.h"

using namespace std;

int main(){

Sy S;
Poluonumo Q,P;

		int choice,choice2,d1, d2,Ak;
		string ch;
		
		cout<<"Please,write 1 for equations,or 2 for their degrees :";
		getline (std::cin,ch);
		choice=atoi(ch.c_str());
		if(choice==1){
			cout<<"Please , write 1 to read equations from the text file,or 3 if you want to write them now: ";
			getline (std::cin,ch);
			choice2=atoi(ch.c_str());

		}else if(choice==2){
			cout<<"Please , write 2 to read the degrees from the text file ,or 4 if you want to write them now: ";
			getline (std::cin,ch);
			choice2=atoi(ch.c_str());
		}else{
			cout<<"Error,you provided invalid choice \n";
			return 0;
		}
if ( choice==1){
	int i,j,maxx1,maxx2,maxy1,maxy2,ls1,ls2;
	char * buffer,*buffer2;
	string line,line2;
	long size;
	if(choice2 ==1){
		printf("Reading the equations from the text.txt \n");
	       	fstream infile("text.txt");
	       	GotoLine(infile, 1);
	   		getline(infile,line);
	      
	       	// allocate memory for file content
	       	buffer = new char [line.size()];
	        
	 		strcpy (buffer,line.c_str());
	 		buffer[line.size()]='\n';
	 	 	GotoLine(infile, 2);    
	 	 	getline(infile,line2);
	       
	       // allocate memory for file content
	       buffer2 = new char [line2.size()];
	    
	 		strcpy (buffer2,line2.c_str());
	      
	      	buffer2[line2.size()]='\n';
			cout<<buffer<<endl;
	    	cout<<buffer2<<endl; 

	      	infile.close();   
	      	cout<<"Give me a number for the A[k] matrix to print: ";
	      	getline (std::cin,ch);
	      	Ak=atoi(ch.c_str());
				}
	else if (choice2==3){

		cout << "Please, enter first equation: ";
	getline (std::cin,line);
	buffer = new char [line.size()];
	strcpy (buffer,line.c_str());
	buffer[line.size()]='\n';
	cout << "Please, enter second equation: ";
	getline (std::cin,line2);
	buffer2 = new char [line2.size()];
	strcpy (buffer2,line2.c_str());
	buffer2[line2.size()]='\n';
	cout<<"Give me a number for the A[k] matrix to print: ";
	      	getline (std::cin,ch);
	      	Ak=atoi(ch.c_str());
	cout<<buffer<<endl;
	cout<<buffer2<<endl; 
	}  else{
		cout<<"Invalid argument!Error!"<<endl;
			return 0;}

/****************prwto poluonumo**************************************************************************/
	
	ls1=line.size();
	P.analyse_pol(buffer,ls1,P);
	 maxx1=P.getsizex();
	 maxy1=P.getsizey();
	 printf("Maxx:%d Maxy: %d \n",maxx1,maxy1);   
	 P.print_all();

	
/********************************Deutero Poluonumo********************************************************/
	ls2=line2.size();
	Q.analyse_pol(buffer2,ls2,Q);
	maxx2=Q.getsizex();
	maxy2=Q.getsizey();
	Q.print_all();
	printf("Maxx:%d Maxy: %d \n",maxx2,maxy2);   
	

		int flg3=0,mon1=0,mon2=0,arry1=0,arry2=0;
		flg3=S.hidden_var(P,Q,maxx1,maxy1,maxx2,maxy2);	//size
			if(!flg3){
					mon1=P.print_byy(!flg3);
					arry1=P.print_byy(flg3);
					mon2=Q.print_byy(!flg3);
					arry2=Q.print_byy(flg3);
					printf("Array apo %d monodiastatous kai apo %d monodiastatous\n",arry1, arry2);
					printf("Megethi monodiastatwn: Mhtroo1: %d kai Mhtroo2: %d\n", mon1, mon2);
			}else{
				mon1=P.print_byy(flg3);
				arry1=P.print_byy(!flg3);
				mon2=Q.print_byy(flg3);
				arry2=Q.print_byy(!flg3);
				printf("Array apo %d monodiastatous kai apo %d monodiastatous\n",arry1, arry2);
				printf("Megethi monodiastatwn: Mhtroo1:%d kai Mhtroo2: %d\n", mon1, mon2);
			}

			Array Ar1[arry1];
			for (i=0;i<arry1;i++){
				Ar1[i].arraysize(mon1);			
			}
			Array Ar2[arry2];
			for (i=0;i<arry2;i++){
				Ar2[i].arraysize(mon2);		
			}
			for(j=0;j<arry1;j++){
				printf("Filling Ar1[%d].data[%d] \n",j,j+1);
				Ar1[j].gemisma(P,mon1,j);	
			}

			for(j=0;j<arry2;j++){
				printf("Filling Ar2[%d].data[%d] \n",j,j+1);
				Ar2[j].gemisma(Q,mon2,j);	
			}
			
			S.create_sylvester();
			S.init_sylvester(Ar1,Ar2,arry1,arry2,mon1,mon2);
			S.printA0_A1(Ar1,Ar2,arry1,arry2,mon1,mon2,Ak);
			d=S.getd();
			M.create_md(d);
			
				for(j=0;j<arry1;j++){
					printf("Ar1[%d].data[%d] of first polynomial is deleted \n",j,j+1);
					Ar1[j].adeiasma();
					
				}
				for(j=0;j<arry2;j++){
					printf("Ar2[%d].data[%d] of second polynomial is deleted \n",j,j+1);
					Ar2[j].adeiasma();	
				}
			P.katast();
			Q.katast();
			 delete[] buffer;
			 delete[] buffer2;		 
	}
	else if(choice==2 ){
		int psif=0,num=0,d1,d2,i,maxx,maxy,maxx1,maxx2,maxy1,maxy2;
		char *buffer;
		string line;
	    long size;
		time_t seed;
		time(&seed);
		srand(seed);
	if(choice2==2){
	       fstream infile("text.txt");
	       GotoLine(infile, 3);
		   getline(infile,line);
		 
	       // allocate memory for file content
	       buffer = new char [line.size()];
	 	   strcpy (buffer,line.c_str());
		   cout<<buffer<<endl;
	
		for(i=0;i<line.size();i++){
				while(buffer[i]!=' '){
						while (buffer[i]>='0' && buffer[i]<='9' ){
											
								if (psif>0)
								num *=10;
						
							num +=(buffer[i] -48);
						
							psif++;
							i++;
						}
							
					d1=num;
					printf("The degree d1 is:%d \n",d1);
				}
				
				i++;
				psif=0;
				num=0;
				while (buffer[i]>='0' && buffer[i]<='9'){
											
								if (psif>0)
								num *=10;
								
							num +=(buffer[i] -48);
						
							psif++;
							i++;
				}							
		d2=num;
		printf("The degree d2 is:%d \n",d2);
		cout<<"Give me a number for the A[k] matrix to print: ";
	      	getline (std::cin,ch);
	      	Ak=atoi(ch.c_str());
		break;

	}
}else if(choice2==4){
	cout<<"Give me d1 degree: ";
	getline (std::cin,ch);
			d1=atoi(ch.c_str());
	cout<<"Give me d2 degree: ";
	getline (std::cin,ch);
			d2=atoi(ch.c_str());
	cout<<"Give me a number for the A[k] matrix to print: ";
	      	getline (std::cin,ch);
	      	Ak=atoi(ch.c_str());

			for (i=0;i<2;i++){
				maxx=0;
				maxy=0;
					while (maxx==0){
						if (i==0)	maxx=(rand()%d1);
						else maxx=(rand()%d2);
					}

					if (i==0) maxy=d1-maxx;
					else maxy=d2-maxx;

				int j=0,flg3=0,mon1=0,mon2=0,arry1=0,arry2=0,ready=0;
				printf("Maximum powers for polynomial %d is x: %d and y: %d \n",i+1 ,maxx, maxy);
					if (i==0){
						maxx1=maxx;
						maxy1=maxy;
						P.set_size(maxx+1,maxy+1);
						P.printsize();
						P.create_pol();
						P.generate_pol(maxx,maxy);
						P.print_all();	
					}
					else {
						maxx2=maxx;
						maxy2=maxy;
						Q.set_size(maxx+1,maxy+1);
						Q.create_pol();
						Q.printsize();
						Q.generate_pol(maxx,maxy);
						Q.print_all();
						ready=1;	
					}
					if (ready==1){
						flg3=S.hidden_var(P,Q,maxx1,maxy1,maxx2,maxy2);	//size
						if(!flg3){
						mon1=P.print_byy(!flg3);
						arry1=P.print_byy(flg3);
						mon2=Q.print_byy(!flg3);
						arry2=Q.print_byy(flg3);
						printf("Array apo %d monodiastatous kai apo %d monodiastatous\n",arry1, arry2);
						printf("Megethi monodiastatwn: %d kai : %d\n", mon1, mon2);
					}else{
						mon1=P.print_byy(flg3);
						arry1=P.print_byy(!flg3);
						mon2=Q.print_byy(flg3);
						arry2=Q.print_byy(!flg3);
						printf("Array  %d monodiastatous kai apo %d monodiastatous\n",arry1, arry2);
						printf("Megethi monodiastatwn: %d kai : %d\n", mon1, mon2);

					}
					Array Ar1[arry1];
					for (j=0;j<arry1;j++){
						Ar1[j].arraysize(mon1);
						
					}
					Array Ar2[arry2];
					for (j=0;j<arry2;j++){
						Ar2[j].arraysize(mon2);
						
					}
					cout<<endl;

					for(j=0;j<arry1;j++){
						printf("Filling Ar1[%d].data[%d] \n",j,j+1);
						Ar1[j].gemisma(P,mon1,j);
						
					}

					for(j=0;j<arry2;j++){
						printf("Filling Ar2[%d].data[%d] \n",j,j+1);
						Ar2[j].gemisma(Q,mon2,j);
						
					}
				S.create_sylvester();
				S.init_sylvester(Ar1,Ar2,arry1,arry2,mon1,mon2);
				S.printA0_A1(Ar1,Ar2,arry1,arry2,mon1,mon2,Ak);
				
					for(j=0;j<arry1;j++){
						printf("Ar1[%d].data[%d] of first polynomial is deleted \n",j,j+1);
						Ar1[j].adeiasma();
						
					}
					
					for(j=0;j<arry2;j++){
						printf("Ar2[%d].data[%d] of second polynomial is deleted \n",j,j+1);
						Ar2[j].adeiasma();
						
					}	
			}		
		}
		P.katast();
		Q.katast();
	}
	if(choice==4) delete[] buffer;
	}else{cout<<"Error! Invalid argument!"<<endl;}     

S.delete_sylv();
return 0;
}




