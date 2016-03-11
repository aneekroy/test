#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>

using namespace std;

class item
{	private :
	int item_code; // variable for item_code
	char name[15]; //variable for name
	int  rate; // variable for rate
	int quantity; //variable


		
	
	public:	 
		char* get_name(void){
			return name;	//returning name pointer for printing
		}
		int get_item_code(void){
			return item_code; //function returning item_code
		}
		int get_rate(void){
			return rate;	//function returning rate
		}
		int set_rate(int r=0){ //function accepting int value to set the rate
			 rate=r;
		}
		int get_quantity(void){ //function returning quantity
			return quantity;
		}
		int set_quantity(int q=0){ //function accepting int value to set the quantity
			this->quantity=q;
		}
		void update(int item_code=0,char *n='\0',int r=0,int q=0)
		{
		this->item_code=item_code;		//Initialising itemcode
		strcpy(name,n);				//Initialising name	
		rate=r;			//Initialising rate
		quantity=q; 	//Initialising quantity
	
		}
};//End of Class Item

class stock 
{
	item list[100];//Max no of list possible for items 
	public:
	
	static int no_of_items_in_list;//Static variable for current no of items in list

		 int check_exists_return_index(int itemcode=0)//Function to check for existence of item in list with given itemcode
		{
			int i=0,flag=0;
			for(i=0;i<=no_of_items_in_list;i++)
				if(list[i].get_item_code()==itemcode)
				{	
					return i;//If found returns the index of item in list
					flag=1;
				}
			if(flag==0)
				return -1;//If not found return (-1)
		}
				
		void add_to_list(void)//function to add new item to list
		{
			int item_code;
			char name[15];
			int  rate=0;
			int quantity;
			printf("\nEnter New Item Code to ADD to the List:");
			char choice='Y';int flag=0,f=0,flg=0,index=-1;
			do{
				scanf("%d",&item_code);
				if(item_code>0)//Checking for positive value of item_code 
				{	flg=1;
					if((index=(check_exists_return_index(item_code)))!=-1)//Checking for existence of itemcode in list
					{ 
	
					do{
						printf("\nItem already exists with Item Code %d\n",item_code);
		printf("\nDo You Want to add item with this Item_code to the already existing item in the list ? (Y/N)");
						cin>>choice;
						if(choice=='Y'||choice=='y')
						{
							this->receive(index);//call to receive already added item
							return;
						
						}				
						else if(choice=='N'||choice=='n')
						{
							printf("\nEnter New Item_Code ");//option for adding with new itemcode
							flg=0;	
							f=1;
						}
						else{
							printf("\nWRONG CHOICE !!! Enter Again :");//exception handling for wrong choice
							f=0;										
						}
					}while(f!=1);
					}
				else
				{	//Item code does not exists hence new item code has been entered
					flag=0;
					/*do
					{*/
							cin.ignore();	
						printf("\nEnter Name of the New Item :");	
							
						cin.getline(name,15,'\n');//Taking Input as entire line
						flag=0;
						/*for(int i=0;i<strlen(name);i++)
						{
							if(!isalnum(name[i])||name[i]!=' '){//checking for Alpha numeric
							printf("\n Name Can only be AlphaNumeric !! Enter Name again !!\n");
							flag=1;	
							break;
							}
						}
					}while(flag!=0);
					*/
					flag=0;
					do{
						printf("\nEnter Rate :");
						scanf("%d",&rate);
						if(rate>0)
						{	
							flag=1;
							printf("\nEnter Quantity :");
							scanf("%d",&quantity);
							if(quantity>=0)
							{
								no_of_items_in_list++;
							this->list[no_of_items_in_list].update(item_code,name,rate,quantity);//adding to the list
										
							}
							else{
								printf("\nNegative quantity of items NOT allowed\n");
								printf("\nEnter from Start\n");
								return;
							}
						}
						else{
							flag=0;
							printf("\nNegative Rate for Items NOT Allowed Enter Again\n");//Exception handling
						}
					}while(flag==0);
				}
			}
			else
			{
				printf("\nNegative Value for Item_code not allowed Enter Again!!");//Exception Handling
				flg=0;
			}
			}while(flg==0);
		return;
		}//End of function add to list

		void rate_change(void)//Funtion to change the rate
		{	
			int i=0,rt=0,flag=0,itemcode=0;
			printf("\nEnter ItemCode of Item whose rate is to be updated:");
			do
			{		
				
				scanf("%d",&itemcode);//Input Itemcode	
				if((i=check_exists_return_index(itemcode))!=-1){//checking for item with given itemcode in list
					flag=1;
					printf("\nEnter the New Rate :\n");//Input rate
					scanf("%d",&rt);
					do
					{
						if(rt>0){	//Checking for Positive value of rate
							flag=1;	
							list[i].set_rate(rt);
						}
						else
							printf("\nThe rate can NOT be negative!!! Enter again\n");//Exception handling
					}while(flag==0);
				}		
				else
					printf("\nItem Code does NOT exist Enter Again:");	//Exception handling		
			}while(flag!=1);
		return;
		}
		void receive(int index=-1)
		{	
			int i=0,rt=0,flag=0,itemcode=0,q=0;
			
			if(index!=-1){
			goto label1;
			i=index;
			}	
			else
			{			
			printf("\nEnter ItemCode of Item which is to be received:");
			do
			{	scanf("%d",&itemcode);	
				if((i=check_exists_return_index(itemcode))!=-1)//Checking for Existence of Itemcode in list
				{
					
				label1:	flag=1;
					printf("\nEnter the Quantity  :\n");
					scanf("%d",&rt);
					do
					{
						if(rt>0){	printf("\nThe Quantity is updated !!");//Checking positive value of rate
								flag=1;	
								q=this->list[i].get_quantity();
								list[i].set_quantity(q+rt);//Setting rate
							}
						else
							printf("\nThe quantity can NOT be negative!!! Enter again\n");//Exception handling	
					}while(flag==0);
				}		
				else
					printf("\nItem Code does NOT exist Enter Again:");//Exception handling				
			}while(flag!=1);
		
			}
		return;
		}
		void issue(int index=-1)//Function for issuing item
		{	
			int i=0,rt=0,flag=0,itemcode=0,q=0;
			
			if(index!=-1){
			goto label;
			i=index;
			}	
			else
			{									
			printf("\nEnter ItemCode of Item whose rate is to be updated:");
			do
			{		
				
				scanf("%d",&itemcode);	
				if((i=check_exists_return_index(itemcode))!=-1)//Checking for Existence of Itemcode in list
				{
					label : 
					flag=1;
					printf("\nEnter the Quantity of Items to be Issued :\n");
					scanf("%d",&rt);
					do
					{
						if(rt<=list[i].get_quantity()){	
							flag=1;	
							q=list[i].get_quantity();
							list[i].set_quantity(q-rt);//Issuing Quantity
			printf("\n %d Quantity of items with name %s and %d Itemcode has been issued",rt,list[i].get_name(),itemcode);
						}
						else
					printf("\nThe Quantity  asked to be Issued is more than existing quantity!!! Enter again\n");
					}while(flag==0);
				}		
				else
					printf("\nItem Code does NOT exist Enter Again:");			
			}while(flag!=1);
			}
		return;
		}
		
		void show_price(void)//Function for showing Price for item
		{	
			int i=0,rt=0,flag=0,itemcode=0;
			printf("\nEnter ItemCode of Item whose price is to be displayed:");
			do
			{	scanf("%d",&itemcode);	
				if((i=check_exists_return_index(itemcode))!=-1){ //Checking for Existence of Itemcode in list
				
					flag=1;
printf("\nThe Price of Item with name %s and Itemcode %d is :%d",list[i].get_name(),list[i].get_item_code(),list[i].get_rate());	
			}
				else
					printf("\nItem Code does NOT exist Enter Again:");			
			}while(flag!=1);
		return;
		}
		void show_quantity(void)//Function for showing quantity for item
		{	
			int i=0,rt=0,flag=0,itemcode=0;
			printf("\nEnter ItemCode of Item whose price is to be displayed:");
			do
			{	scanf("%d",&itemcode);	
				if((i=check_exists_return_index(itemcode))!=-1) //Checking for Existence of Itemcode in list
				{
				flag=1;
printf("\nThe Quantity of Item with name %s and Itemcode %d is :%d",list[i].get_name(),list[i].get_item_code(),list[i].get_quantity());
			}
				else
					printf("\nItem Code does NOT exist Enter Again:");//Exception handling			
			}while(flag!=1);
		return;
		}
};//End of class stock

int stock :: no_of_items_in_list=-1;//Initialising Static Variable

int main(void){//Start of main()fnction
	int choice=0;
	stock obj;
	do//main Menu
	{
		printf("\n\n*************************Main Menu*******************************\n\n");
		printf("\nEnter 1 To Add New Item To the List\n");
		printf("\nEnter 2 To Change the Rate of Item Already in the List\n");
		printf("\nEnter 3 To Issue an Item with Respect to ItemCode\n");
		printf("\nEnter 4 To Receive an Item with respect to ItemCode\n");
		printf("\nEnter 5 To display the Price of an item with respect to Itemcode\n");
		printf("\nEnter 6 To display the QuanTity of an Item with respect to Itemcode\n");
		printf("\nEnter -1 To EXIT !!\n");
		printf("**********************************************************************\n\n");
		scanf("%d",&choice);

		switch(choice)
		{	case -1:
				printf("\nEXITING!! Thank You !!");
				break;
			case 1:
				obj.add_to_list();//CAll for adding to list
				break;
			case 2:
				obj.rate_change();//call for rate change
				break;
			case 3:
				obj.issue();//call for issuing item
				break;
			case 4:
				obj.receive();//call for receiving item
				break;
			case 5:
				obj.show_price();//call for displaying price
				break;
			case 6:
				obj.show_quantity();//call for showing quantity
				break;
			default :
				printf("WRONG CHOICE !!");//Exception handling
				break;
		}
	}while(choice!=-1);
	return 0;
}//End of main()

//g++ item.cpp -o it

//Compiling command
