/*ASSIGNMENT 1
QUESTION 5

program to create a marksheet of students taking admission*/

 
#include<iostream>
#include<string.h>
#include<cstdlib>
#include <cctype>
#include <algorithm>
#include <string>
#include<stdio.h>

using namespace std;

/*date class to check the  validity of the admission date*/
class date{
		public:
			bool isleapyear(int year){//function to check if an year is a leap year or not
				return (!(year%4) && (year%100) || !(year%400));
			}
		
			int valid_date(int year,int month,int day){ //to check if a day is a valid day or not
				
				int monthlen[]={31,28,31,30,31,30,31,31,30,31,30,31};
				if (!year || !month || !day || month>12)
					return -1;
				if (isleapyear(year) && month==2)
					monthlen[1]++;
				if (day>monthlen[month-1])
					return -1;
				return 1;
			 }
			/*taking the date as dd/mm/yyyyy format*/
			int is_valid_date(string s){
		
				int c=s.length(),l=0,p[3];string k="";
				s=s+" ";
				/*extracting the day month and year from the string*/
				for(int h=0;h<c;h++){
					if(s[h]!='/')
						k=k+s[h];
					else{
						p[l++]=atoi(k.c_str());
						k="";
					}		
				}
				p[l++]=atoi(k.c_str());//converting from string to integer
				return(valid_date(p[2],p[1],p[0]));//calling function valid date
			}
} d1;//object of class date



class student{
	private:/*private data members defining the attributes of the class student*/
		char name[100];
		int roll;
		string date;
		string course;
		int marks[6];
		string sub[6];
	public:
		/*student(){          //user defined constructor
			roll=100000;
		}*/
		void get_data(student &);
		//int is_valid_date(string);
		void display(student);
		void update_roll(student &,int);
		int  get_roll(student);
		string  get_name(student);
		string  get_course(student);
		void change_marks(student &);
};


/*to get the details of a student*/
int student::get_roll(student s){//to get the student's roll no

		return(s.roll);
}
string student::get_name(student s){//to get  the students name

		return(s.name);
}
string student::get_course(student s){//to get the students course

		return(s.course);
}


/*asking the user to give details of the student*/
void student::get_data(student &s){
		int m,j;string s1;int fg=0;
		cout<<"\t ENTER  DETAILS OF THE STUDENT \n"<<endl;
		cout<<"Enter name:";
		cin.ignore();
		cin.getline(s.name,100,'\n');//to incorporate spaces in  the string
	/*to check if a string contains digits or not*/	
		for(int h=0;h<100;h++){
			if(s.name[h]=='1' || s.name[h]=='2'||s.name[h]=='3'||s.name[h]=='4'||s.name[h]=='5'||s.name[h]=='6'||s.name	[h]=='7'||s.name[h]=='8'||s.name[h]=='9'){
			
				fg=1;
				cout<<"Name contains digits enter correctly"<<endl;
				break;}
		}
		if(fg!=1){
			cout<<"\n";
			cout<<"Enter roll number:";
			cin>>s.roll;
			cout<<"\n";
			cout<<"\nEnter date(in dd/mm/yyyy format):";
			while(true){
				cin>>s.date;
				if(d1.is_valid_date(s.date)==-1){
					cout<<"wrong admission date given"<<endl;
				}
				else
					break;
			}
			cout<<"\nEnter course name :";
			cin>>s.course;
			/*cin.ignore();
			getline(cin,s.course);
			*/
			cout<<"\nEnter Subject and Marks in :* Subject_name Marks * Format\n";
			for(j=0;j<5;j++){
				cin>>s1>>m;
				if(m<0 || m>100){         //marks should not > 100 or <0
					cout<<"Wrong marks entered Enter in the Range of [0,100]"<<endl;break;}
				s.sub[j]=s1;
				s.marks[j]=m;
			}
		}
}

/*function to change the marks of any of the subjects of a particular student*/
void student::change_marks(student &s){
		int f,sub_code,new_marks;
		cout<<"Enter no. of subjects whose marks needs to be changed"<<endl;
		cin>>f;
		cout<<"Enter subject codes"<<endl;
		while(f!=0){
			cin>>sub_code;	
			if(sub_code>=1 && sub_code<=5){
				cout<<"Enter new marks \n";
				cin>>new_marks;
				if(new_marks>0&&new_marks<=100)
				s.marks[sub_code-1]=new_marks;
				else
				printf("Marks is NOT in Range!! Enter Again");
			}
			else{
				cout<<"wrong subject code entered"<<endl;
				break;
			}
			f--;
	}
	return;
}
	/*displaying the marksheet of a particular student*/		
void student::display(student s){int l=0;float cg=0;
		
		printf("--------------------------MARKSHEET---------------------------------------\n");
		cout<<"\n";
		cout<<"--------------------------------------------------------------------------"<<endl;
		cout<<"NAME: "<<s.name<<"                     "<<"     COURSE:"<<s.course<<endl;
		cout<<"\n";
		cout<<"---------------------------------------------------------------------------"<<endl;
		cout<<"ROLL NO: "<<s.roll<<" "<<endl;
		cout<<"---------------------------------------------------------------------------"<<endl;
		cout<<"Sl no \t\t SUBJECT \t\t MARKS"<<endl;
		for(int y=0;y<5;y++){
			l=s.sub[y].size();
			printf("%d \t\t ",(y+1));
			cout<<s.sub[y];
			printf("%*d\n",26-l,s.marks[y]);
			cg+=s.marks[y];
			
		}
		cg/=50.0;
		printf("\n************************************************************************\n");
		printf("\t\tCGPA IS %f ON a SCALE OF 10.0",cg);		
		printf("\n*************************************************************************\n");
}		
/*to make changes in the roll no of any particular student*/
void student::update_roll(student &s,int k){
		s.roll=k;
}
/*batch class which contains a list of student objects*/
class batch{
	student list[70];//list of student objects
	static int count;
	public:
		void admit_student(batch &,student &);
		int exists_or_not(batch,int);                //to check the index of a particular student
		int get_count(batch b);                      //to find the no of students taking admission     
		void display1(batch b);                      //display the details of all the students taking admission
};
/*to check if the roll number given by the user already exists or not*/
int batch::exists_or_not(batch g,int c){
		
	int j,flag=-1;
	for(j=0;j<count;j++){
		if((g.list[j]).get_roll(g.list[j])==c){
			flag=j;
			break;
		}
	}
	return(flag);
}

/*function to admit a new student*/
void batch::admit_student(batch &b,student &y){
	
	
	y.get_data(y);
	if(b.exists_or_not(b,y.get_roll(y))==-1)	{//to check if the given item already exists or not
		b.list[count]=y;
		count++;
		if(count>70)
			cout<<"batch is full"<<endl;
	}
	else
		cout<<"student already exists"<<endl;
	
}
		

int batch::count=0;//initialization of the static variable

/*function to return the number of students taking admission*/
int batch::get_count(batch b){
		return(count);
}

/*to display all the students details*/
void batch::display1(batch b){ int l1=0;
		cout<<"NAME \t\t"<<"ROLL NO \t\t "<<"COURSE"<<endl;
		cout<<"\n***************************************************"<<endl;
		for(int i=0;i<count;i++){
			l1=b.list[i].get_name(b.list[i]).size();
			cout<<b.list[i].get_name(b.list[i]);
			printf("%*d \t\t\t ",20-l1,b.list[i].get_roll(b.list[i]));//Formatting OUTPUT
			cout<<b.list[i].get_course(b.list[i])<<endl;
		}
		cout<<"\n***************************************************"<<endl;
}

/*main function*/
int main(void){
	batch b;student s;int gh,choice,pos;
	while(true){
		
	/*giving the user the choice to enter any of the following options*/
		cout<<"\n*******************Main Menu***********************"<<endl;
		cout<<"1.ADMIT A NEW STUDENT"<<endl;
		cout<<"2.CHANGE MARKS OF A PARTICULAR STUDENT"<<endl;
		cout<<"3.DISPLAY THE GENERAL DETAILS OF ALL THE STUDENTS"<<endl;
		cout<<"4.DISPLAY THE MARKSHEET OF ANY PARTICULAR STUDENT"<<endl;
		cout<<"5.DISPLAY THE TOLTAL NO OF STUDENTS TAKING ADMISSION"<<endl;
		cout<<"6.EXIT"<<endl;
		cout<<"\n***************************************************"<<endl;
		cout<<"\n\nEnter Choice :";
		cin>>choice;
		if(choice==6)
			break;
		else{
			switch(choice){
				case 1:b.admit_student(b,s);//to admit a new student
				       break;
				
				case 2:cout<<"give the roll no of students whose marks is to be changed"<<endl;
				       cin>>gh;
				       s.update_roll(s,gh);
				       pos=b.exists_or_not(b,s.get_roll(s));//checking if the roll no exists or not
					if(pos==-1)
						cout<<"student not found"<<endl;
					else{
						s.change_marks(s);
					}
					break;
				case 3:b.display1(b);//to display the entire list of students(their name roll and course)taking admission
					break;
				case 4:cout<<"give the roll no of students whose marks is to be displayed"<<endl;
				       cin>>gh;
				       s.update_roll(s,gh);
				       pos=b.exists_or_not(b,s.get_roll(s));
					if(pos==-1)
						cout<<"student not found"<<endl;
					else{
						s.display(s);//Display The Marksheet of Particular Student
					}
					break;	
				case 5:cout<<"the no of students is taken admission is:"<<b.get_count(b)<<endl;//to display the no of students-Taking admission
					break;
				default: cout<<"wrong input"<<endl;//to take care of bad inputs
			}
		}
	}
	return 0;
}//main function ends

//g++ student.cpp -o st -std=c++11
