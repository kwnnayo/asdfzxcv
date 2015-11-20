#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include <fstream>
#include <limits>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

std::fstream& GotoLine(std::fstream& , unsigned int); //goes to the selected line of text.txt and returns its content
//________________________________________________________________________________________________________________________

class Poluonumo{  
	int sizex,sizey;

	int** polynomial; //the matrix that polynomial is being stored

public:
	void analyse_pol(char*,int,Poluonumo);
	int getsizex();
	int getsizey();
	void set_size(int , int ); 	//gets the size of the polynomial matrix
	void create_pol(); 			//polynomial creation
	void printsize();			//just a print of polynomial size
	void set_value(int , int , int ); //fills in polynomial matrix with the right value
	void generate_pol(int, int );	//generates a random polynomial
	int get_value(int, int); 		//returns a polynomial value 
	void print_all();				//prints the polynomial matrix
	int print_byy(int);				//just a get of x and y sizes ,dependable of the given flag value 
	void katast();					//here polynomial matrix is deleted
	};

	//________________________________________________________________________________________________________________________

	class Array{
		int *data;
		
	public:

		void midenika();     //fills matrix with 0
		void arraysize(int); //memory allocation
		void gemisma(Poluonumo,int,int);	//memory allocation
		int get(int);						//printing a data value
		int getA0(int);						//returns data[0] for the A0 matrix
		int getAk(int,int);					//returns the data[k] for the Ak matrix
		double set(int);
		double setAk(int,int);
		void adeiasma();					//deletes data
	};
//________________________________________________________________________________________________________________________

	class Sy{
		int size;     //size of sylvester
		int max1,max2; //maximum powers 
		Array **sylvester; //the matrix sylvester is being stored

	public:
		
		 int hidden_var(Poluonumo,Poluonumo,int,int,int ,int); //finds which variable will be the "hidden" one and finds the size of sylvester matrix
		 void create_sylvester();							//sylvester creation
		 void init_sylvester(Array *, Array*,int,int,int,int);	//fills in sylvester with the corresponding value
		 void printA0_A1(Array *, Array*,int,int,int,int,int); //prints A0 or Ak,depend on the given value
		 void delete_sylv();	//deletes sylvester
	};
//________________________________________________________________________________________________________________________
	class Md{
	Array **md;
	public:
	
		void create_md(int);
		void init_md();
	
	};

	#endif
