#include<iostream>
#include<cstdio>
using namespace std;

class complex{
	
		private :
			int real;
			int comp;//data members

		public :
		complex(void)//publc constructor for initialising pvt data members
		{
		real=0;
		comp=0;
		}
			void set(){//Taking Input for real and imaginary
				
				printf("Input the Real and Imaginary part :");
				scanf("%d %d",&real,&comp);
			return ;
			}
			void get(){//Function to print the complex and Imaginary values
				if(comp>0&&real!=0)
				printf("\nThe Complex Number is : %d +i %d \n",real,comp);//Formatting OUTPUT
				else if(comp<0&&real!=0)
				printf("\nThe Complex Number is : %d -i %d \n",real,(-1)*comp);
				else if(real==0){
					if(comp<0)
						printf("\nThe Complex Number is : -i %d \n",((-1)*comp));
					else
						printf("\nThe Complex Number is : +i %d \n",comp);
				}
				else if(comp==0){
					printf("\nThe Complex Number is : %d \n",real);
				}
			}
		
			void add(complex a,complex b){//Function to add 
				real=a.real+b.real;
				comp=a.comp+b.comp;
				return ;
			}
			void subtract(complex a,complex b){//Function to subtract
				real=a.real-b.real;
				comp=a.comp-b.comp;
				return ;
			}

};//End of class complex

int main(void){//START of main function
	complex x,y,c;//daclaring objects of class complex
	int choice=0;
	do{
	printf("\n**************Main Menu*************");
	printf("\nEnter choice\n");
	printf("\nEnter 1 to input\n");
	printf("\nEnter 2 to display\n");
	printf("\nEnter 3 to add\n");
	printf("\nEnter 4 to subtract\n");
	printf("\nEnter any other number to exit\n");	
	printf("***************************************\n Enter Choice :");
	scanf("%d",&choice);//Taking Choice as Input
	switch(choice){
		case 1 :
			x.set();//Function call to take inputs for Complex Numbers x and y
			y.set();
			break;
		case 2 :
			x.get();//Function Call to display the complex numbers
			y.get();
			break;
		case 3 :
			c.add(x,y);//Function Call to add the 2 complex numbers
			c.get();//Function call to display the result of addition
			break;
		case 4 :
			c.subtract(x,y);//Function Call to subtract the 2 comlpex numbers
			c.get();//Function Call to Display the result of subtraction
			break;
		default :
			printf("ERROR!!!!!\n");//Exception Handling
			break;
		}//End of switch case
	}while(choice>0&&choice<5);
	//End of do{}while
	
	return 0;
	}//End of main()

//g++ complex.cpp -o comp
	
