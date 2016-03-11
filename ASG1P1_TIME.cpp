#include<iostream>
#include<cstdio>

using namespace std;

class Time
{
	int hours=0;
	int minutes=0;//data members
	
	public://public member functions
	
	void input_time_in_format_12(void)//Function for taking time input in 12 hour format
	{
		cout<<"\n\t Enter the time in the format hh:mm A.M./P.M.:  ";
		if(scanf("%d",&hours)==1)//taking Input for Hours
		{
			if(scanf(":%d A.M.",&minutes)==1)//Taking Input for mins in given format 
			{	if(hours==12)
				hours=0;
				if(hours>12||minutes>60||hours<0||minutes<0)
					{	
						cout<<"\n\t Wrong entry";//Exception Handling
						hours=minutes=0;
					}
				else	
					cout<<"\n\t Your time has been accepted";
			}
			else if(scanf(":%d P.M.",&minutes)==1)//Taking Input for mins in given format 
			{
				if(hours>12||minutes>60||hours<0||minutes<0)
					{	
						cout<<"\n\t Wrong entry";//Exception Handling
						hours=minutes=0;//Initialising hrs and mins
					}
				
				else
					cout<<"\n\t Your time has been accepted";//Exception Handling
					
	
			}	
			else
			{	
				cout<<"\n\t Wrong entry";//Exception Handling
				hours=0;
				minutes=0;
			}
				
		}
		else
		{	
			cout<<"\n\t Wrong entry";//Exception Handling
			hours=0;
		}
		
			
	}//end of function to input in 12hrs

	void input_time_in_format_24(void)//Function for input in 24 hour format
	{
		cout<<"\n\t Enter the time in the format hh:mm hours:  ";
		if(scanf("%d",&hours)==1 && hours<24&&hours>=0)
		{
			if(scanf(":%d hours",&minutes)==1 && minutes<60)
				cout<<"\n\t Your time has been accepted";
				
			else
			{	
				cout<<"\n\t Wrong entry";
				hours=minutes=0;
				return;
			}
		}
		else
		{	
			cout<<"\n\t Wrong entry";
			hours=0;
			return;
		}
	return;
	}//end of function to input in 24 hours format
				
		
	void show_time_in_format_24(void)//display time in 24 hour
	{
		cout<<"\n\t Showing time in 24 hours format: ";
		if(hours<10)
		{
		cout<<"0"<<hours<<":";
		if(minutes<10)
		cout<<"0"<<minutes<<" hours";//Formatting output
		else 
		cout<<minutes<<" hours";
		}
		else
		{
		cout<<hours<<":";
		if(minutes<10)
		cout<<"0"<<minutes<<" hours";
		else 
		cout<<minutes<<" hours";
		}

}
		
	void show_time_in_format_12(void)//Display time in 12 hour format
	{	if(hours==12)
			cout<<"\n\t Showing time in 12 hours format: "<<(hours)<<":"<<minutes<<" P.M.\n\n";//Formatting Output
		else if(hours>12&& hours<24)
			cout<<"\n\t Showing time in 12 hours format: "<<(hours%12)<<":"<<minutes<<" P.M.\n\n";
		else{
			if(hours!=0)
			cout<<"\n\t Showing time in 12 hours format: "<<hours<<":"<<minutes<<" A.M.\n\n";
			else
			cout<<"\n\t Showing time in 12 hours format: 12"<<":"<<minutes<<" A.M.\n\n";
			
	}
}
	void add_time(void)//Function for adding time
	{	int add_minutes=0;
		cout<<"\n\t Please enter the minutes ";
		cin>>add_minutes;
		int hrs=0;
		if((minutes+=add_minutes)>=60)
		{	
			hrs=minutes/60;
			hours+=(hrs);
			hours%=24;
			minutes%=60;
		}
		}
	};//End of class Time

int main()//start of function main
{
	Time t;//Object of class Time{}
	int choice;
	do
	{//Main menu
		cout<<"\n\t\t\t --Welcome--"<<"\n\n\t Please enter your choice \n\t1.Input time in 12 hours format\n\t2.Input time in 24 hours format\n\t3.Show time in 12 hours format\n\t4.Show time in 24 hours format\n\t5.Add user input time\n\t6.Exit....-->";
			//scanf("%d",&choice);
			cin>>choice;			
			switch(choice)
			{
				case 1://cin.ignore();
					t.input_time_in_format_12();//Input for 12 hours
					break;
			
				case 2:
					t.input_time_in_format_24();//Input for 24 hours
					break;
			
				case 3:
					t.show_time_in_format_12();//Printing for 12 hours
					break;
			
				case 4:
					t.show_time_in_format_24();//printing for 24 hours
					break;
			
				case 5:
					t.add_time();//Function call for adding time
					break;
			
				case 6:
					cout<<"\n\t Thank You";//case for exiting 
					exit(0);
			
				default:
					cout<<"\n\n\t Wrong entry"; //wrong entry
					break;
					
			}//End of switch case
				
	}while(choice>0&&choice<7);//End of do{}while();
	
	return 0;
}//End of main	

// g++ ASG1P1_TIME.cpp -o ti -std=c++11 //Compilation command

