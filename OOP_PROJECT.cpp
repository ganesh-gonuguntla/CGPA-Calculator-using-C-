#include<bits/stdc++.h>
using namespace std;

class Subject 
{ public:
	string name;
	string grade;
	int marks;
	int credits;
	int points;
	string result;

};


class sem :public Subject //single inheritence(Inheritence)
{ private:
	 Subject subject[6];
	 float sgpa;
	 
	 public:
	 	//function overloading.(polymorphism)
	 	setsem(string name1,int n1,string name2,int n2,string name3,int n3,string name4,int n4,string name5,int n5,string name6,int n6)
	 	{
	 		subject[0].name=name1;
	 	    subject[1].name=name2;
	 		subject[2].name=name3;	
	 		subject[3].name=name4;
	 		subject[4].name=name5;
	 		subject[5].name=name6;
	 		subject[0].credits = n1;
	 		subject[1].credits = n2;
	 		subject[2].credits = n3;
	 		subject[3].credits = n4;
	 		subject[4].credits = n5;
	 		subject[5].credits = n6;
		 }
		 
		 setsem(string name1,int n1)
		 {
		 		subject[0].name = name1;
		 			subject[0].credits = n1;
		 		
		 }
		 
		 float returnsgpa()
		 {
		 	return sgpa;
		 }
		 
		 float setsgpa(float sgpa)
		 {
		 	this->sgpa = sgpa;
		 }
	 	
	 	void displaycourses(int s,string name,string roll)
	 	{  
	 		cout<<"These are the cources of semester "<<s<<" : "<<endl<<endl;
	 		if(s!=8)
	 		{ int i;
	 		cout<<"   COURSE NAME             "<<"      CREDITS"<<endl;
	 		cout<<"   ------------------------"<<"      -------"<<endl;
	 	
	 		cout<<"1. "<<subject[0].name<<"     "<<subject[0].credits<<endl;
			cout<<"2. "<<subject[1].name<<"     "<<subject[1].credits<<endl;
			cout<<"3. "<<subject[2].name<<"     "<<subject[2].credits<<endl;
			cout<<"4. "<<subject[3].name<<"     "<<subject[3].credits<<endl;
			cout<<"5. "<<subject[4].name<<"     "<<subject[4].credits<<endl;
			cout<<"6. "<<subject[5].name<<"     "<<subject[5].credits<<endl;
	 
	 }
	 
	 else if(s==8)
	 {
	 	cout<<"   COURSE NAME                   "<<"      CREDITS"<<endl;
	 	cout<<"   ------------------------------"<<"      -------"<<endl;
	 	cout<<"1. "<<subject[0].name<<"      "<<subject[0].credits<<endl;
	 	 
	 }
	 	cout<<endl<<name<<"("<<roll<<"),"<<" You are enrolled in semester "<<s;
		 }
	
	float grading(int semno,string name, string roll)
	{
	cout<<"     Welcome to the grading portal for sem "<<semno<<" :   "<<endl;
	cout<<"------------------------------------------"<<endl;

	cout<<"Enter the marks secured in every subject respectively: "<<endl;
	for(int i=0;i<6;i++)
	{
	 cout<<"Enter the marks you secured in "<<subject[i].name<<": \n";
	 cin>>subject[i].marks;
	 	if(subject[i].marks>100 || subject[i].marks<0)
	 	{
		cout<<"wrong input, control is going out\n";
		exit(0);
	}
	 if(semno==8)
	 break;
	}
	
	for(int i=0;i<6;i++)
	{ 		subject[i].result="PASS";
		if(subject[i].marks>=91 && subject[i].marks<=100)
		{
			subject[i].grade="O";
			subject[i].points=10;
	
		}
		else if(subject[i].marks>=81 && subject[i].marks<=90 )
		{
			subject[i].grade="A+";
			subject[i].points=9;
		}
		else if(subject[i].marks>=71 && subject[i].marks<=80)
		{
			subject[i].grade="A";
			subject[i].points=8;
		}
		else if(subject[i].marks>=61 && subject[i].marks<=70)
		{
			subject[i].grade="B+";
			subject[i].points=7;
		}
		else if(subject[i].marks>=51 && subject[i].marks<=60)
		{
			subject[i].grade="B";
			subject[i].points=6;
		}
		else if(subject[i].marks>=41 && subject[i].marks<=50)
		{
			subject[i].grade="C";
			subject[i].points=5;
		}
		else if(subject[i].marks>=0 && subject[i].marks<=40)
		{
			subject[i].grade="F(fail)";
			subject[i].points=0;
					subject[i].result="FAIL";
		}
	
		
		if(semno==8)
		break;
	}
	
	
	
	cout<<"UNIVERSITY EXAM RESULTS (semester- "<<semno<<" )"<<endl;
	cout<<endl;
	cout<<"SEMESTER\t"<<"Subject Description\t"<<"Credit\t"<<"Grade\t"<<"Result\n";
	cout<<"--------\t"<<"-------------------\t"<<"------\t"<<"-----\t"<<"------\n";
	int sum=0,l;
	for( l=0;l<6;l++)
	{
		cout<<semno<<"\t"<<subject[l].name<<"\t"<<subject[l].credits<<"\t"<<subject[l].grade<<"\t"<<subject[l].result<<endl;
		sum = sum+subject[l].credits;
		if(semno==8)
		break;
	}
	float gpa=0;
	for(int i=0;i<6;i++)
	{
		gpa=gpa+(subject[i].points*subject[i].credits);
		if(semno==8)
		break;
	}
	cout<<fixed<<setprecision(3);
	cout<<"\n\nSGPA secured by "<<name<<"("<<roll<<") in semester "<<semno<<" is: "<<gpa/sum<<endl<<endl<<endl;
	sgpa = gpa/sum;
	return sgpa;
	
}

};

int main()
{
	 int i=1;
	string name;
	string roll;
	int currentsem;
	
	cout<<"-----------------WELCOME TO STUDENT PORTAL----------------\n"<<endl;
	cout<<"ENTER YOUR NAME:\n";
	getline(cin,name);
	cout<<endl<<"Hello "<<name<<", Enter your Registration Number:\n";
    cin>>roll;
    fflush(stdin);
    cout<<"Enter your current semester:"<<endl;
    cin>>currentsem;
    float cgpa[currentsem];
    int d;
    for(d=0;d<currentsem;d++)
    cgpa[d]=0.0;
    cout<<name<<"("<<roll<<") YOU ARE ENROLLED INTO THE PORTAL"<<endl;
    
    sem s[8];
   cout<<"\n\nPlease be careful while entering the options , you get only one chance!!"<<endl;
    for(i=1;i<=currentsem;i++)
  {  
    switch(i)
    {
    	case 1 :
    		{   float sgpa1=0;
    		  cout<<"\n\nWELCOME TO SEMESTER-1:\n";
    			s[0].setsem("Engineering Physics           ",3,"Calculus for Engineers        ",3,"C programming                 ",4,"Analytical Reasoning          ",3,"Environmental Science         ",2,"Emerging technologies         ",2);
    			s[0].displaycourses(1,name,roll);
    			cout<<"\n\nSemester Completed\n";
    			cout<<name<<", if you know your sem1 sgpa, enter 2 and then enter sgpa\n\notherwise enter 1 to know your sgpa"<<endl;
	int p;
	cin>>p;
	
 if(p==2)
	{ float sgpa1;
		cout<<"enter sem1 sgpa:"<<endl;
		cin>>sgpa1;
			if(sgpa1<0||sgpa1>10)
			{
		cout<<"wrong input, sgpa should be in between 0 and 10"<<endl<<"Reenter the sgpa";
		cin>>sgpa1;
	}
	
		s[0].setsgpa(sgpa1);
}
	else if(p==1)
	{
    s[0].setsgpa(s[0].grading(1,name,roll));
	}
	else
	{
		cout<<"wrong key, control is going to exit, retry from beginning."<<endl;
		exit(0);
	}
	 	break;
		}
			
		case 2 :
			{ cout<<"\n\nWELCOME TO SEMESTER-2:\n";
				s[1].setsem("Ethics and Human Values       ",2,"Economics and management      ",3,"Data Structures               ",4,"Basics of EEE                 ",3,"Entreprenurial mindset        ",2,"Linear Algebra and DE         ",3);
    			s[1].displaycourses(2,name,roll);
    					cout<<"\n\nSemester Completed\n";
							cout<<name<<", if you know your sem2 sgpa, enter 2 and then enter sgpa\n\notherwise enter 1 to know your sgpa"<<endl;
	int p;
	cin>>p;
	
	
if(p==2)
	{ float sgpa2;
		cout<<"enter sem2 sgpa:"<<endl;
		cin>>sgpa2;
			if(sgpa2<0||sgpa2>10)
			{
		cout<<"wrong input, sgpa should be in between 0 and 10"<<endl<<"Reenter the sgpa";
		cin>>sgpa2;
	}
	s[1].setsgpa(sgpa2);
	}
	else if(p==1)
	{
s[1].setsgpa(s[1].grading(2,name,roll));
 
	}
	
else 
{
	cout<<"wrong key, control is going to exit, retry from beginning."<<endl;
	exit(0);
}

	break;
			}
			
		case 3 :
			{cout<<"\n\nWELCOME TO SEMESTER-3:\n"; 
			cout<<"From this Semester we are offering Open Electives"<<endl;
				int n;
				cout<<"Which Open Elective do you want to select:\n1.Financial Markets\n2.PHYSIOLOGY\n3.Japanese\n4.Phsycology\n";
				 minorsubject1:
				cin>>n;
				string k;
				
				switch(n)
				{
					case 1 : k = "Financial Markets             "; break;
					
					case 2 : k = "Physiology                    "; break;
					
					case 3 : k = "Japanese                      "; break;
					
					case 4 : k = "Phsycology                    "; break;
					
					default : {
					cout<<" Wrong decision";
					goto minorsubject1;
					break;
					}
				};
				
			s[2].setsem("OOPS with C++                 ",4,"DAA                           ",4,k,3,"Discrete Mathematics          ",3,"Digital Electronics           ",3,"Problem solving skills        ",2);
    			s[2].displaycourses(3,name,roll);
    			cout<<"\n\nSemester Completed\n";
    					cout<<"\n\nSemester Completed\n";
						cout<<name<<", if you know your sem3 sgpa, enter 2 and then enter sgpa\n\notherwise enter 1 to know your sgpa"<<endl;
	int p;
	cin>>p;	
	
	if(p==2)
	{ float sgpa3;
		cout<<"enter sem3 sgpa:"<<endl;
		cin>>sgpa3;
		if(sgpa3<0||sgpa3>10)
			{
		cout<<"wrong input, sgpa should be in between 0 and 10"<<endl<<"Reenter the sgpa";
		cin>>sgpa3;
		}
		else
		s[2].setsgpa(sgpa3);
	}
	else if(p==1)
	{
s[2].setsgpa(s[2].grading(3,name,roll));
	}
	
	else 
	{
		cout<<"wrong key, control is going to exit, retry from beginning."<<endl;
	exit(0);
}
	break;			
			}
			
		case 4 :
			{ 
			cout<<"\n\nWELCOME TO SEMESTER-4:\n";
				int n;
				cout<<"Which Open Elective do you want to select:\n1.Robotics\n2.Stock Market trading\n3.Japanese(II)\n4.Phsycology(II)\n";
				 minorsubject2:
				cin>>n;
				string k;
				
				switch(n)
				{
					case 1 : k = "Robotics                      "; break;
					
					case 2 : k = "Stock market trading          "; break;
					
					case 3 : k = "Japanese(II)                  "; break;
					
					case 4 : k = "Phsycology(II)                "; break;
					
					default : {
					cout<<" WRONG DECISION, CHOOSE ANY ONE OF THE FOLLOWING:\n";
					goto minorsubject2;
					break;
					
					}
				};
			s[3].setsem("Web Technology                ",4,"PYTHON                        ",2,"DBMS                          ",4,k,3,"Thinking&Creative skills      ",2,"Probability & statistics      ",3);
    			s[3].displaycourses(4,name,roll);
    			
    					cout<<"\n\nSemester Completed\n";
						cout<<name<<", if you know your sem4 sgpa, enter 2 and then enter sgpa\n\notherwise enter 1 to know your sgpa"<<endl;
	int p;
	cin>>p;
	
if(p==2)
	{ float sgpa4;
		cout<<"enter sem4 sgpa:"<<endl;
		cin>>sgpa4;
			if(sgpa4<0||sgpa4>10)
			{
		cout<<"wrong input, sgpa should be in between 0 and 10"<<endl<<"Reenter the sgpa";
		cin>>sgpa4;
	}
	cgpa[3] = sgpa4;
	}
	else if(p==1)
	{
cgpa[3] = s[3].setsgpa(s[3].grading(4,name,roll));
	}

	else 
	{  
	cout<<"wrong key, control is going to exit, retry from beginning."<<endl;
		exit(0);
	}
		break;	
			}	
				
		case 5 :
			{  cout<<"\n\nWELCOME TO SEMESTER-5:\n";
					int n;
				cout<<"Which Open Elective do you want to select:\n1.ROBOTICS(II)\n2.STATISTICS\n3.DIGITAL MARKETING\n4.STARTUP FINANCING\n";
				 minorsubject3:
				cin>>n;
				string k;
				
				switch(n)
				{
					case 1 : k = "ROBOTICS(II)                  "; break;
					
					case 2 : k = "STATISTICS                    "; break;
					
					case 3 : k = "DIGITAL MARKETING             "; break;
					
					case 4 : k = "Startup Financing             "; break;
					
					default : {
					cout<<" WRONG DECISION, CHOOSE ANY ONE OF THE FOLLOWING:\n";
					goto minorsubject3;
					break;
					
					}
				};
				
				
				s[4].setsem("Computer Networks             ",4,k,3,"Machine Learning              ",4,"Operating Sytems              ",4,"Automata & compilerdesign     ",3,"Computer Architecture         ",4);
    			s[4].displaycourses(5,name,roll);
    			
    					cout<<"\n\nSemester Completed\n";
					cout<<name<<", if you know your sem5 sgpa, enter 2 and then enter sgpa\n\notherwise enter 1 to know your sgpa"<<endl;
	int p;
	cin>>p;
		
	if(p==2)
	{ float sgpa5;
		cout<<"enter sem5 sgpa:"<<endl;
		cin>>sgpa5;
			if(sgpa5<0||sgpa5>10)
			{
		cout<<"wrong input, sgpa should be in between 0 and 10"<<endl<<"Reenter the sgpa";
		cin>>sgpa5;
	}
	s[4].setsgpa(sgpa5);
	}
	else if(p==1)
	{
cgpa[4] = s[4].setsgpa(s[4].grading(5,name,roll));
	}
	
	else 
	{  cout<<"wrong key, control is going to exit, retry from beginning."<<endl;
		exit(0);
	}		
	break;	
    		}
				
						
		case 6 :
			{  cout<<"\n\nWELCOME TO SEMESTER-6:\n";
				int n;
				cout<<"Which Open Elective do you want to select:\n1.STARTUP FINANCING(II)\n2.STATISTICS(II)\n3.ANGER MANANGEMENT\n4.ENVIRONMENTAL RESPONSIBILITY\n";
				 minorsubject4:
				cin>>n;
				string k;
				
				switch(n)
				{
					case 1 : k = "STARTUP FINANCING(II)         "; break;
					
					case 2 : k = "STATISTICS(II)                "; break;
					
					case 3 : k = "ANGER MANANGEMENT             "; break;
					
					case 4 : k = "ENVIRONMENTAL RESPONSIBILITY  "; break;
					
					default : {
					cout<<" WRONG DECISION, CHOOSE ANY ONE OF THE FOLLOWING:\n";
					goto minorsubject4;
					break;
					
					}
				};
				
				s[5].setsem("Software Engineering          ",4,k,3,"Core-Elective(1)              ",3,"STREAM ELECTIVE(1)            ",4,"STREAM ELECTIVE(2)            ",4,"App Development(JAVA)         ",4);
    			s[5].displaycourses(6,name,roll);
    					cout<<"\n\nSemester Completed\n";
						cout<<name<<", if you know your sem6 sgpa, enter 2 and then enter sgpa\n\notherwise enter 1 to know your sgpa"<<endl;
	int p;
	cin>>p;
			
 if(p==2)
	{ float sgpa6;
		cout<<"enter sem6 sgpa:"<<endl;
		cin>>sgpa6;
			if(sgpa6<0||sgpa6>10)
			{
		cout<<"wrong input, sgpa should be in between 0 and 10"<<endl<<"Reenter the sgpa";
		cin>>sgpa6;
	}
	s[5].setsgpa(sgpa6);
	}
	else if(p==1)
	{
cgpa[5] = s[5].setsgpa(s[5].grading(6,name,roll));
	}
	
	else
	{  cout<<"wrong key, control is going to exit, retry from beginning."<<endl;
		exit(0);
	}	
	break;		
  			}
							
		case 7 :
			{      
			cout<<"\n\nWELCOME TO SEMESTER-7:\n";
				int n;
				cout<<"Which Open Elective do you want to select:\n1.PERSONALITY DEVELOPMENT\n2.COMMUNICATION SKILLS\n3.GREAT INDIAN HISTORY\n4.ENVIRONMENTAL SCIENCE\n";
				minorsubject5:
				cin>>n;
				string k;
				
				switch(n)
				{
					case 1 : k = "PERSONALITY DEVELOPMENT       "; break;
					
					case 2 : k = "COMMUNICATION SKILLS          "; break;
					
					case 3 : k = "GREAT INDIAN HISTORY          "; break;
					
					case 4 : k = "ENVIRONMENTAL SCIENCE         "; break;
					
					default : {
					cout<<" WRONG DECISION, CHOOSE ANY ONE OF THE FOLLOWING:\n";
					goto minorsubject4;
					break;
				}
					};
				
			
					s[6].setsem("Internship/Project            ",4,k,3,"Core-Elective(2)              ",3,"Stream Elective(3)            ",4,"STREAM ELECTIVE(4)            ",4,"Mock Interview Training       ",3);
    			s[6].displaycourses(7,name,roll);
    					cout<<"\n\nSemester Completed\n";
							cout<<name<<", if you know your sem7 sgpa, enter 2 and then enter sgpa\n\notherwise enter 1 to know your sgpa"<<endl;
	int p;
	cin>>p;
		

	if(p==2)
	{ float sgpa7;
		cout<<"enter sem7 sgpa:"<<endl;
		cin>>sgpa7;
			if(sgpa7<0||sgpa7>10)
			{
		cout<<"wrong input, sgpa should be in between 0 and 10"<<endl<<"Reenter the sgpa";
		cin>>sgpa7;
	}
	s[6].setsgpa(sgpa7);
	}
	else if(p==1)
	{
s[6].setsgpa(s[6].grading(7,name,roll));
	}
	
	else if(p!=1||p!=2)
	{  cout<<"wrong key, control is going to exit, retry from beginning."<<endl;
		exit(0);
	}	
	break;		
			}	
												
		case 8 :
			{   cout<<"\n\nWELCOME TO SEMESTER-8:\n";
				s[7].setsem("MAJOR PROJECT                 ",12);
						
    			s[7].displaycourses(8,name,roll);
    		
    					cout<<"\n\nSemester Completed\n";
						cout<<name<<", if you know your sem8 sgpa, enter 2 and then enter sgpa\n\notherwise enter 1 to know your sgpa"<<endl;
	int p;
	cin>>p;
if(p==2)
	{ float sgpa8;
		cout<<"enter sem8 sgpa:"<<endl;
		cin>>sgpa8;
			if(sgpa8<0||sgpa8>10)
			{
		cout<<"wrong input, sgpa should be in between 0 and 10"<<endl<<"Reenter the sgpa";
		cin>>sgpa8;
	}
	s[7].setsgpa(sgpa8);
	}
	else if(p==1)
	{
s[7].setsgpa(s[7].grading(8,name,roll));
}
	
	else if(p!=1||p!=2)
	{  cout<<"wrong key, control is going to exit, retry from beginning."<<endl;
		exit(0);
	}	
	break;
			}				
																																							
		default:
		{
			cout<<name<<", there are only 1 - 8 semesters, you might me wrong, pleae check and input again."<<endl;
			break;
		}															
	};
}


cout<<"\n\n----------------------------------------------------------------------------------------\n\n";
int li;
float sum=0;
cout<<name<<"("<<roll<<") , WELCOME TO GRADE INFO:\n\n";
for(li=0;li<currentsem;li++)
{
 cout<<"SGPA OF SEM- "<<li+1<<fixed<<setprecision(2)<<":  "<<s[li].returnsgpa()<<endl;
}
for(li=0;li<currentsem;li++)
{
	 sum = sum+ s[li].returnsgpa();
}
cout<<"\n\nCGPA:  "<<fixed<<setprecision(2)<<sum/currentsem<<endl;
	return 0;
}
