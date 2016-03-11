#include<cstdio>
#include<iostream>

using namespace std;

class tolltax{//Starting of class tolltax
 
	private :
	 	int toll; 	
		int no_of_cars[3];//datamembers
	
	public :
		int return_rate(int type){//function to return rate
		if(type==1)
			return 20;
		else if(type==2)//checking for types
			return 50;
		else if(type==3)
			return 100;
		else 
			return -1;
		}
		void receive_toll(void){
		int t=0;int n=0,tp=0;
		printf("Enter number of cars : ");
		scanf("%d",&n);//Taking the input for the number of cars
		printf ("\nEnter Type for cars :");
		printf("\nEnter 1 for Two Wheeler :");
		printf("\nEnter 2 for Three/Four Wheelers ");
		printf("\nEnter 3 for Trucks\n ");
		scanf("%d",&tp);//Input Type of cars	
		t=return_rate(tp);
		if(t>0&&n>0){
			toll+=t*n;//calculating the total toll to be paid
			no_of_cars[tp-1]+=n;
			}
		else
			printf("Error !!");
		}
		
		void display_cars(void)//function to display cars passed
		{	for(int i=0;i<3;i++)
			printf("\nThe Number of cars are of type %d: %d\n",(i+1),no_of_cars[i]);
		}
		void display_toll(void)//Function to display toll
		{
			printf("\nThe toll collected is :%d\n",toll);
		}
		tolltax(void)//Constructor to initialize the data members of class tolltax
		{
		toll=0;
		for(int i=0;i<3;i++)
		no_of_cars[i]=0;	
		}
};//End of class tolltax	

int main(void){//Start of main
	int choice=0;
	tolltax t;
	do{//Main Menu
	printf("\nEnter Choice :\n");
	printf("\nEnter 1 to receive toll :\n");
	printf("\nEnter 2 to display the number of cars passed :\n"); 
	printf("\nEnter 3 to display the number of toll received :\n");
	printf("\n Enter -1 to exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			t.receive_toll();//function call to receive toll
			break;
		case 2:
			t.display_cars();//Function call to display no fo cars passed
			break;
		case 3:
			t.display_toll();//Function call to display toll
			break;
		case -1:
			printf("Exiting !!");//Exit condition
			break;
		default:
			printf("ERROR!! Continue .....");//Exception Handling
			break;
	}
	}while(choice!=-1);
	
	return 0;
}//End of main

// g++ ASG1P3_TOLLTAX.cpp -o to
