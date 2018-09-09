/*SRAVAN PUTIKAM
  Hotel and Bank Management System
  High School Final Project
*/
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdio.h>
#include<fstream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<process.h>
#include<time.h>
#include<ctype.h>
#include<graphics.h>
struct tic
{ char square[10];
  int player;
}ob;
const int MAXLENGTH=80;
const int MAX_TRIES=5;
const int MAXROW=7;
int Fill (char, char[], char[]);
void Unknown (char[], char[]);
int check(tic& ob);//FUNTION FOR RESULT//
void board(tic& ob);//FUNCTION TO DRAW THE BOARD//
void init(tic& ob);
void games();
class account
{  int acno;
   char name[50];
   long int deposit;
   char type;
  public:
   void createacc();
   void display();
   void modify();
   void dep(int);
   void draw(int);
   void report();
   int getacno();
   int getdeposit();
   char getype();
};
void account::createacc()
{    R: char a[20],check[20];
     clrscr();
	gotoxy(1,1);
	time_t t;
	t = time(NULL);
	cout<<"\n "<<ctime(&t);
	t -= 24L*60L*60L;
     cout<<"\nEnter Details";
     cout<<"\nEnter The account No.:";
    cin>>acno;
    { ifstream fb; fb.open("account.dat",ios::binary);
      account fbk;
     while(fb.read((char*)&fbk,sizeof(account)))
      {   if(fbk.getacno()==acno)
	     { cout<<"Sorry the Account number entered has already been used\nPlease type again";
		getch(); goto R;
	     }
      }
       fb.close();
    }
    cout<<"\nEnter The Name of the Account Holder : ";
    gets(name);
    T:
    int f=0; int d=0;
    cout<<"\nEnter Type of the Account (C/S) : ";
    gets(a);
    if(strcmp(a,"c")==0||strcmp(a,"C")==0||strcmp(a,"S")==0||strcmp(a,"s")==0)
      { type=a[0]; }
    type=toupper(type);
    if(type=='C'||type=='S')
	 f=1;
    if(f==0)
     { cout<<"Wrong type entered....Enter again!!!"; goto T ;}
      Q:
    cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
    cin>>check;
    for(int z=0;check[z]!='\0';z++)
    { if(!isdigit(check[z]))
	 { cout<<"Please Enter numerical value......";d=1;getch(); goto Q;}
    }
    if(d==0)
    { deposit=atoi(check); }
      if(type=='C'&& deposit<1000)
	  {  cout<<"Enter again as deposit is less than 1000"; goto Q; }
	 else if (type=='S'&& deposit<500)
	  {  cout<<"Enter again as deposit is less than 500"; goto Q; }
    clrscr();
    for(int i=0; i<5; i++)
       {   gotoxy(30,10);delay(500);cout<<"Verifying details....."; delay(500); clrscr();}
       cout<<"\nCreating Account........"; delay(1000);
       clrscr();
     cout<<"\n\n\n\t\tAccount Created..";
     getch();
}
void account::display()
{  cout<<"\nAccount No. : "<<acno;
   cout<<"\nAccount Holder Name : ";
   cout<<name;
   cout<<"\nType of Account : "<<type;
   cout<<"\nBalance amount : "<<deposit;
}
void account::modify()
{ char check[20];
  cout<<"\nThe account No."<<acno;
  cout<<"\n\nEnter The Name of The account Holder : ";
  gets(name);
   T:
   int f=0; char a[20];
    cout<<"\nEnter Type of the Account (C/S) : ";
    gets(a);
    type=a[0];
    type=toupper(type);
    if(type=='C'||type=='S')
	 f=1;
    if(f==0)
     { cout<<"Wrong type entered....Enter again!!!"; goto T ;}
      Q:
   cout<<"\nEnter The amount(>=500 for Saving and >=1000 for current ) : ";
   cin>>check;
    int d=0;
    for(int z=0;check[z]!='\0';z++)
      { if(!isdigit(check[z]))
	  { cout<<"Please Enter numerical value......";d=1;getch(); goto Q;}
      }
   if(d==0)
    { deposit=atoi(check); }
   if(type=='C'&& deposit<1000)
	  {  cout<<"Enter again as deposit is less than 1000"; goto Q; }
	 else if (type=='S'&& deposit<500)
	  {  cout<<"Enter again as deposit is less than 500"; goto Q; }
   clrscr();
    for(int i=0; i<5; i++)
      { gotoxy(30,10);delay(500);cout<<"Modifying.....";  delay(500);clrscr();}
}
void account::dep(int x)
{   deposit+=x;
}
void account::draw(int x)
{    deposit-=x;
}
void account::report()
{    cout<<acno<<"\t\t"<<name<<"\t\t"<<type<<"\t  "<<deposit;
}
int account::getacno()
 {   return acno;
 }
int account::getdeposit()
{ return deposit;
}
char account::getype()
{ return type;
}
void write_account();
void backg();
void back();
char *password = "isis";
void displayaccn(int);
void modifyaccn(int);
void deleteaccn(int);
void display_all();
void depdraw(int, int);
void bank()
{
     char  ch[20],a;
     int num;
     clrscr();
      do
	{       B:
		clrscr();
		gotoxy(1,1);time_t t;
		t = time(NULL);
		cout<<"\n                                  "<<ctime(&t);
		t -= 24L*60L*60L;
		backg();
		gotoxy(35,7); cout<<"MENU\n";
		gotoxy(30,9);
		cout<<"1. New Account\n";
		gotoxy(30,10);
		cout<<"2. Deposit Amount\n";
		gotoxy(30,11);
		cout<<"3. Withdraw Amount\n";
		gotoxy(30,12);
		cout<<"4. Balance Enquiry\n";
		gotoxy(30,13);
		cout<<"5. All Account Holder List\n";
		gotoxy(30,14);
		cout<<"6. Close an Account\n";
		gotoxy(30,15);
		cout<<"7. Modify an Account\n";
		gotoxy(30,16);
		cout<<"8. Go back";
		gotoxy(30,17);
		cout<<"9. Exit\n";
		gotoxy(30,18);
		cout<<"Select Your Option (1-9): ";
		cin>>ch;
		if(strcmp(ch,"1")==0||strcmp(ch,"2")==0||strcmp(ch,"3")==0||strcmp(ch,"4")==0||strcmp(ch,"5")==0||strcmp(ch,"6")==0||strcmp(ch,"7")==0||strcmp(ch,"8")==0||strcmp(ch,"9")==0)
		   {  a=ch[0];  }
		else
		 { cout<<"Wrong Choice!!!!!!Enter Again....."; getch(); goto B;}
		clrscr();
		switch(a)
		{
		case '1' : write_account();
			 break;
		case '2' : cout<<"\n\n\tEnter The account No. : "; cin>>num;
			 depdraw(num, 1);
			 break;
		case '3' : cout<<"\n\n\tEnter The account No. : "; cin>>num;
			 depdraw(num, 2);
			 break;
		case '4' : cout<<"\n\n\tEnter The account No. : "; cin>>num;
			 displayaccn(num);
			 break;
		case '5' : display_all();
			 break;
		case '6' : cout<<"\n\n\tEnter The account No. : "; cin>>num;
			  deleteaccn(num);
			  break;
		case '7' : cout<<"\n\n\tEnter The account No. : "; cin>>num;
			  modifyaccn(num);
			   break;
		case '8' :break;
		case '9' : cout<<"\n\n\tTa Ta Bye bye see u later";
			   exit(0);
			    break;
		 default :cout<<"Wrong choice!!!!"; getch(); goto B;
	       }
	}while(a!='8');
}
char roomtype[4][20] = { "Single","Double","Couple","President"};
class hotel
{  int d,outd;//
   int m,outm;  //
   int y,outy;    //
   char name[30];  //
   long int hbill;    //
   int roombill(); //
   int rprice[5];  //
   long int hprice;    //
   int age;      //
   int bkn;      //
   char status[10];//
   char occupation[30]; //
   char rtype[20];
   public:
   hotel()
   { hbill=0;}
    int gety(){return y;} int getm(){return m;} int getd(){return d;}   //
     int getouty(){return outy;} int getoutm(){return outm;} int getoutd(){return outd;}  //
    void getdata();//
    void hdisplay(); //
    void disp3();
    int getrbill()   //
    { return hbill;}   //
    void disp2();//
    int getprice()        //
    { return hprice;}
    int getbkn()       //
    { return bkn ; }
    void allocate(); //!!!
    void state()         //
    { strcpy(status,"OUT");
     }
    void room();   //!!!
    void upd_hbill(int e) //
    {  hbill=hbill+e;
    }
    char* getname()  //
    {  return name ; }
    char* getstatus() //
     { return status; }
    void welcome();  //
    void adm();    //
    void modify();   //
    void login();   //
    void disp(int);   //
};
void add_cust(); //
void disp_cust(); //
void checko_cust();//
void modi_cust(); //
void search_cust();//
void del_cust(); //
void pay(int);
int  rdn(int y, int m, int d)
{   if (m < 3)
	y--, m += 12;
    return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;
}
class indian
{ int price;
  int item;
  char fname[30];
  public:
  void add()
  {
    cout<<"Enter Item no.-"; cin>>item;
    cout<<"\nEnter Name - "; gets(fname);
    cout<<"\nEnter Price -"; cin>>price;
  }
   int getprice()
   { return price;}
   int getitem()
   { return item;}
  void dispin(int);
};
void addind()
{   clrscr();
    ofstream fo;
    indian a;
    fo.open("ind.dat",ios::app|ios::binary);
     a.add();
    fo.write((char*)&a,sizeof(indian));
    fo.close();
}
class chinese
{ int price;
  int item;
  char fname[30];
  public:
  void add()
  {
    cout<<"Enter Item no.-"; cin>>item;
    cout<<"\nEnter Name - "; gets(fname);
    cout<<"\nEnter Price -"; cin>>price;
  }
  int getprice()
   { return price;}
   int getitem()
   { return item;}
  void dispch(int);
};
void addchin()
{   clrscr();
    ofstream fo;
    chinese a;
    fo.open("chin.dat",ios::app|ios::binary);
      a.add();
     fo.write((char*)&a,sizeof(indian));
     fo.close();
}
void indian::dispin(int x)
{   //Item no.       NAME          Price
   gotoxy(27,x); cout<<item;gotoxy(40,x); cout<<fname; gotoxy(57,x); cout<<price;
}
void chinese::dispch(int x)
{  gotoxy(27,x); cout<<item;gotoxy(40,x); cout<<fname; gotoxy(57,x); cout<<price;
}
void dispinf()
{  clrscr();   int t=7;
   ifstream fin;  indian b;
   fin.open("ind.dat",ios::binary);
gotoxy(20,3);     cout<<"                MENU(INDIAN)           \n" ;
gotoxy(20,4);     cout<<"============================================\n";
gotoxy(20,5);     cout<<"    Item no.         NAME            Price\n";
gotoxy(20,6);     cout<<"============================================\n";
   while(fin.read((char*)&b,sizeof(indian)))
     { b.dispin(t);t++; }
    getch();
    fin.close();
}
void dispchf()
{  clrscr(); int t=7;
   ifstream fin;  chinese b;
   fin.open("chin.dat",ios::binary);
gotoxy(20,3);     cout<<"                MENU(CHINESE)           \n" ;
gotoxy(20,4);     cout<<"============================================\n";
gotoxy(20,5);     cout<<"    Item no.         NAME            Price\n";
gotoxy(20,6);     cout<<"============================================\n";
   while(fin.read((char*)&b,sizeof(chinese)))
     { b.dispch(t);t++; }
    getch();
  fin.close();
}
void delind()
{       clrscr();
	int n,f;
	indian in;
	ifstream fin;
	ofstream fo;
	fin.open("ind.dat",ios::binary);
	if(!fin)
	{   cout<<"File could not be open !! Press any Key...";
	    return;
	}
	fo.open("Temp.dat",ios::binary);
	cout<<"\n\n\tEnter item number to deleted"; cin>>n;
	fin.seekg(0,ios::beg);
	while(fin.read((char *)&in,sizeof(indian)))
	{   if(in.getitem()!=n)
	     { 	fo.write((char *) &in, sizeof(indian));
	     }
	     else if(in.getitem()==n)
	     {  f=1; cout<<"Food item deleted"; }
	}
	fin.close();
	fo.close();
	if(f==0)
	 {  cout<<"Item not found"; }

	remove("ind.dat");
	rename("Temp.dat","ind.dat");
     getch();
}
void delchin()
{       int n;   clrscr();
	chinese chn;
	ifstream fin; int f=0;
	ofstream fo;
	fin.open("chin.dat",ios::binary);
	if(!fin)
	{   cout<<"File could not be open !! Press any Key...";
	    return;
	}
	cout<<"\n\n\tEnter intem number to be deleted: "; cin>>n;
	fo.open("Temp.dat",ios::binary);
	fin.seekg(0,ios::beg);
	while(fin.read((char *)&chn,sizeof(chinese)))
	{   if(chn.getitem()!=n)
	     { 	fo.write((char *) &chn, sizeof(chinese));
	     }
	    else if(chn.getitem()==n)
	     {  f=1; cout<<"Food item deleted"; }
	}
	fin.close();
	fo.close();
	if(f==0)
	 {  cout<<"Item not found"; }
	remove("chin.dat");
	rename("Temp.dat","chin.dat");
     getch();
}
class restaurant
{ int bill;
  char f[10];
  int c;
  public:
  restaurant()
  { bill=0;}
  void restrant();
  int getroom();
  int ind();
  int chin();
  void addfood();
  void delfood();
  void dispfood();
 int price();
  ~restaurant()
    {}
};
void restaurant::restrant()
{  time_t t;           restaurant d;
     clrscr();
     t=time(NULL);
     cout<<"\n                                                        "<<ctime(&t);
     t -= 24L*60L*60L;
   hotel q; int r,f=0;
   clrscr(); cout<<"\n\t\nEnter your booking number:"; cin>>r;
   fstream fin; fin.open("customer!.dat",ios::in|ios::out|ios::binary);
   bill=0;
   while(fin.read((char*)&q,sizeof(hotel)))
 { if(r==q.getbkn()&&strcmpi(q.getstatus(),"in")==0)
  { f=1;
    do
    {
    cout<<"Waiter: Which cuisine would you like to have sir.Indian(1)/Chinese(2)?\n";
    cout<<"        If you want to exit then press 3\n";
    cout<<"   Enter your choice:"; cin>>c;
    switch(c)
     {   case 1: bill=ind();
		break;
	 case 2: bill=chin(); break;
	 case 3:  break ;
	 default : "Wrong Choice";
     }
      q.upd_hbill(bill);
     int pos=(-1)*sizeof(hotel);
     fin.seekg(pos,ios::cur);
     fin.write((char*)&q,sizeof(hotel));
  }while(c!=3);
 }
 else if(r==q.getbkn()&&strcmpi(q.getstatus(),"out")==0)
   { cout<<"Sorry the person with this booking number has already checked out"; getch();}
}
  if(f==0);
  cout<<"room not found";
  fin.close();
}
void restaurant::addfood()
{  time_t t;
    clrscr();
    t=time(NULL);
    cout<<"\n                                                        "<<ctime(&t);
    t -= 24L*60L*60L;
  int ch; indian i; chinese c;
   do
  { Q:
    clrscr();
    cout<<"\t\tWhich Cuisine food do you want to add?\n" ;
    cout<<"\t\t\t1.Indian\n";
    cout<<"\t\t\t2.Chinese\n";
    cout<<"\t\t\t3.Go back\n";
    cout<<"\t\t\t4.Exit\n";
    cout<<"\t\tEnter Choice : ";cin>>ch;
      switch(ch)
      { case 1 : addind();
		 break;
	case 2 : addchin();
		 break;
	case 3 : break;
	case 4 : exit(0);
		 break ;
	default :  cout<<"Wrong Choice!!";
		  getch(); goto Q;
      }
    }while(ch!=3);
}
void restaurant::delfood()
{ time_t t;
    clrscr();
    t=time(NULL);
    cout<<"\n                                                        "<<ctime(&t);
    t -= 24L*60L*60L;
  int ch; indian i; chinese c;
   do
  { Q:
    clrscr();
    cout<<"Which Cuisine food do you want to Delete?\n" ;
    cout<<"1.Indian\n";
    cout<<"2.Chinese\n";
    cout<<"3.Go back\n";
    cout<<"4.Exit\n";
    cout<<"Enter Choice : ";cin>>ch;
      switch(ch)
      { case 1 : delind();
		 break;
	case 2 : delchin();
		 break;
	case 3 : break;
	case 4 : exit(0);
		 break ;
	default :  cout<<"Wrong Choice!!";
		  getch(); goto Q;
      }
    }while(ch!=3);
}
void restaurant::dispfood()
{   time_t t;
    clrscr();
    t=time(NULL);
    cout<<"\n                                                        "<<ctime(&t);
    t -= 24L*60L*60L;
  int ch; indian i; chinese c;
   do
  { Q:
    clrscr();
    cout<<"Which Cuisine food do you want to Display?\n" ;
    cout<<"1.Indian\n";
    cout<<"2.Chinese\n";
    cout<<"3.Go back\n";
    cout<<"4.Exit\n";
    cout<<"Enter Choice : ";cin>>ch;
      switch(ch)
      { case 1 : dispinf();
		 break;
	case 2 : dispchf();
		 break;
	case 3 : break;
	case 4 : exit(0);
		 break ;
	default :  cout<<"Wrong Choice!!";
		  getch(); goto Q;
      }
    }while(ch!=3);
}
int restaurant::ind()
{  clrscr();  int c,f,t=7;
   ifstream fi; ; char ans='y';indian b;
   fi.open("ind.dat",ios::binary);
     int x=0;
gotoxy(20,3);     cout<<"                MENU(INDIAN)           \n" ;
gotoxy(20,4);     cout<<"=============================================\n";
gotoxy(20,5);     cout<<"    Item no.          NAME           Price\n";
gotoxy(20,6);     cout<<"=============================================\n";
   while(fi.read((char*)&b,sizeof(indian)))
     { b.dispin(t);t++; }
    while(ans=='y'||ans=='Y')
    { I:  ifstream fin;   fin.open("ind.dat",ios::binary);
      cout<<"\nEnter the item number:";
       cin>>c;      f=0;
	  while(fin.read((char*)&b,sizeof(indian)))
	   { if(c==b.getitem())
	      { f=1;x+=b.getprice(); }
	   }
	  if(f==0)
	   { cout<<"Wrong choice entered!!!"; getch(); clrscr(); goto I; }
       cout<<"Waiter : Would you like to have anything else sir?";
       cout<<"\nCustomer(Y/N) : "; cin>>ans;

     fin.close();
    }
   getch();
   fi.close();
   clrscr();
    return x;
}
int restaurant::chin()
{  clrscr();  int c,f,t=7;     chinese b;
   ifstream fi,fin; restaurant a; char ans='y';
   fi.open("chin.dat",ios::binary);
     int x=0;
gotoxy(20,3);     cout<<"                MENU(CHINESE)           \n" ;
gotoxy(20,4);     cout<<"=============================================\n";
gotoxy(20,5);     cout<<"    Item no.          NAME           Price\n";
gotoxy(20,6);     cout<<"=============================================\n";
   while(fi.read((char*)&b,sizeof(chinese)))
     { b.dispch(t); t++;}
    while(ans=='y'||ans=='Y')
    {  I:  ifstream fin; fin.open("chin.dat",ios::binary);
       cout<<"\nEnter the item number:";
       cin>>c;  f=0;
	  while(fin.read((char*)&b,sizeof(chinese)))
	   { if(c==b.getitem())
	      { f=1;x+=b.getprice(); }
	   }
	  if(f==0)
	   { cout<<"Wrong choice entered!!!"; getch(); clrscr(); goto I; }
       cout<<"Waiter : Would you like to have anything else sir?";
       cout<<"\nCustomer(y/n) : "; cin>>ans;
    fin.close();
    }
    fi.close();
    getch();
    clrscr();
    return x;
}
void hotel::welcome()
{   char ch[20],a;   hotel h;
  do
   { Q:
    time_t t;
     clrscr();
     int gd=DETECT,gm;
    initgraph(&gd,&gm,"c:\\tc\\bgi");
    t=time(NULL);
     cout<<"\t\t\t\t\t\t "<<ctime(&t);
     t -= 24L*60L*60L;
  cout<<"\n\n\n";
  backg();
  settextstyle(BOLD_FONT,HORIZ_DIR,4);
  setcolor(12);
  outtextxy(200,10,"MAIN MENU");
    gotoxy(32,10);cout<<"1.Add Customer\n";
    gotoxy(32,11);cout<<"2.Room Types\n";
    gotoxy(32,12);cout<<"3.Search Customer\n";
    gotoxy(32,13);cout<<"4.Update Customer\n";
    gotoxy(32,14);cout<<"5.Restaurant\n";
    gotoxy(32,15);cout<<"6.Games\n";
    gotoxy(32,16);cout<<"7.Check Out\n";
    gotoxy(32,17);cout<<"8.Delete Customer\n";
    gotoxy(32,18);cout<<"9.Display Customer\n";
    gotoxy(32,19);cout<<"10.Go back\n";
    gotoxy(32,20);cout<<"11.Exit\n";
    gotoxy(32,21);cout<<"Enter Your Choice: ";
    cin>>ch;
     if(strcmp(ch,"1")==0||strcmp(ch,"2")==0||strcmp(ch,"3")==0||strcmp(ch,"4")==0||strcmp(ch,"5")==0||strcmp(ch,"6")==0||strcmp(ch,"7")==0||strcmp(ch,"8")==0||strcmp(ch,"9")==0)
	 {  a=ch[0];  }
     else if(strcmp(ch,"10")==0)
	  { a='b';}
     else if(strcmp(ch,"11")==0)
	  { a='e';}
     else
	 { cout<<"Wrong Choice!!!!!!Enter Again....."; getch(); goto Q;}
    closegraph();
    switch(a)
     {  case '1' : add_cust();
		 break;
	case '2' : h.room(); break;
	case '3' : search_cust();
		 break;
	case '4' : modi_cust();
		 break;
	case '5' : restaurant a;
		 a.restrant();
		 break;
	case '6' :  games();
		 break;
	case '7' : checko_cust();
		 break;
	case '8' : del_cust();
		 break;
	case '9' : disp_cust();
		 break;
	case 'b' : break;
	case 'e' : exit(0);
		 break;
	default : cout<<"Wrong Choice";
		 getch(); clrscr(); goto Q;
     }
   }while(a!='b');
}
void hotel::adm()
{ char ch[20],a;
  do
  {
    time_t t;
    clrscr();
     t=time(NULL);
     cout<<"\n                                                        "<<ctime(&t);
     t -= 24L*60L*60L;
     restaurant f;
    Start:
    cout<<"\n\n\n\t\t\tMENU\n";
    cout<<"\t\t.........................\n";
    cout<<"\t\t    1.Add Food\n";
    cout<<"\t\t    2.Delete Food\n";
    cout<<"\t\t    3.Display\n";
    cout<<"\t\t    4.Go Back\n";
    cout<<"\t\t    5.Exit\n";
    cout<<"\t\t    Enter Choice : "; cin>>ch;
    if(strcmp(ch,"1")==0||strcmp(ch,"2")==0||strcmp(ch,"3")==0||strcmp(ch,"4")==0||strcmp(ch,"5")==0)
	 {  a=ch[0];  }
    switch(a)
    {  case '1' : f.addfood(); break;
       case '2' : f.delfood(); break;
       case '3' : f.dispfood(); break;
       case '4' : break;
       case '5' : exit(0); break;
       default : cout<<"Wrong Choice!!!!!";
		 getch();clrscr(); goto Start;
    }
  }while(a!='4');
}
void hotel::login()
{    int gd=DETECT,gm;
  initgraph(&gd,&gm,"c:\\tc\\bgi");
    int r,c;
  // textbackground(WHITE);
    //	textcolor(BLUE);
     setcolor(12);
     gotoxy(5,5) ;
      for(c=0;c<7;c++)
   { cout<<" * "; delay(30); }
     gotoxy(59,5);
     for(c=0;c<7;c++)
   { cout<<" * "; delay(30); }
  for(r=0;r<20;r++)
    {  gotoxy(6,6+r);
       cout<<"*"; delay(30);
    }
  cout<<" ";
  for(c=0;c<24;c++)
    { cout<<" * ";delay(30); }

   for(r=0;r<19;r++)
     { gotoxy(78,24-r); cout<<"*";delay(30); }
  settextstyle(BOLD_FONT, HORIZ_DIR, 4);
   outtextxy(205,35,"WELCOME");
   settextstyle(7, HORIZ_DIR, 4);
   delay(200);
   setcolor(3);
   outtextxy(160,105,"  TO RITZ HOTEL");
   delay(200);
   settextstyle(5, HORIZ_DIR, 4);
   setcolor(18);
   outtextxy(160,135,"   Justice is open to ");
   delay(200);
   outtextxy(160,160,"everyone in the same way ");
   delay(200);
   outtextxy(95,185,"     as the Ritz Hotel is ");
   delay(200);
   outtextxy(110,220,"   and also this hotel has ");
   delay(220);
   outtextxy(110,255,"   the cutest soap that ");
   delay(200);
   outtextxy(140,285,"   you will steal from ");
   delay(200);
   outtextxy(140,320,"    a hotel,enjoy it!!! ");
   getch();
   char a;
   closegraph();
     do
     {  time_t t;
	clrscr();
	START:
	clrscr();
	t=time(NULL);
	cout<<"\n                                                        "<<ctime(&t);
	t -= 24L*60L*60L;
	hotel v;
	char ch[10] ;
	cout<<  endl << endl << endl<< endl;
	cout<<"                            LOGIN SCREEN\n";
	cout<<"              ____________________________________________________  "<< endl;
	cout<<"                          1.Administrator Login\n";
	cout<<"                          2.customer Login\n";
	cout<<"                          3.Go back \n";
	cout<<"                          4.Exit\n";
	cout<<"\n\n\n";
	cout<<"Enter Choice: ";
	cin>>ch;
	if(strcmp(ch,"1")==0||strcmp(ch,"2")==0||strcmp(ch,"3")==0||strcmp(ch,"4")==0)
	 {  a=ch[0];  }
	switch(a)
	{
	  case '1' : clrscr();char pass[20];
		   cout<<"Enter Password to open administration:"; gets(pass);
		   if(strcmpi(pass,password)==0)
		    { v.adm(); }
		   else
		    { cout<<"Wrong password!!!!";  getch(); }
		   break;
	  case '2' : v.welcome();
		  break;
	  case '3' : break;
	  case '4' : exit(0);
		  break;
	  default: cout<<"wrong choice entered!!!"; getch(); clrscr(); goto START;
	}
     }while(a!='3');
}
void hotel::hdisplay()
{  //Booking no.    Name      Age    DOCI   DOCO   Room Type
    cout<<"Booking Number : "<<bkn<<endl;
    cout<<"Name : "<<name<<endl;
    cout<<"Age : "<<age<<endl;
    cout<<"Occupation : "<<occupation<<endl;
    cout<<"Date of Check-In : "<<d<<"/"<<m<<"/"<<y<<endl;
    cout<<"Date of Check-Out : "<<outd<<"/"<<outm<<"/"<<outy<<endl;
}
void hotel::getdata()
{   ifstream fb; fb.open("customer!.dat",ios::binary);
    time_t t;
    Q:
    clrscr();
    t=time(NULL);
    cout<<"\n                                                        "<<ctime(&t);
    t -= 24L*60L*60L;
  cout<<"\t\t\tEnter Details\n";
   cout<<"Enter Booking No. : "; cin>>bkn;
  {  hotel fbk;
     while(fb.read((char*)&fbk,sizeof(hotel)))
      {   if(fbk.getbkn()==bkn)
	     { cout<<"Sorry the Booking number entered has already been used\nPlease type again";
		getch(); goto Q;
	     }
      }
 }
    fb.close();
  cout<<"Enter Name: "; cin>>name;
  cout<<"Enter age: "; cin>>age;
  cout<<"Occupation: "; cin>>occupation;
  cout<<"Enter Check In Details:-\n";
  START:      char dq[10],mw[10],ye[10]; int xx,g=0;
  cout<<"Enter day(1-31): "; cin>>dq;
   for(xx=0; dq[xx]!='\0'; xx++)
   { if(!isdigit(dq[xx]))
	{ g=1;cout<<"Please enter only numeric value......"; getch(); goto START; }
   }
   if(g==0)
    { d=atoi(dq); }
    g=0;
  cout<<"Enter month(1-12): "; cin>>mw;
   for(xx=0; mw[xx]!='\0'; xx++)
   { if(!isdigit(mw[xx]))
	{ g=1;cout<<"Please enter only numeric value......"; getch(); goto START; }
   }
   if(g==0)
    { m=atoi(mw); }
    g=0;
  cout<<"Enter year(yyyy): "; cin>>ye;
   for(xx=0; ye[xx]!='\0'; xx++)
   { if(!isdigit(ye[xx]))
	{ g=1;cout<<"Please enter only numeric value......"; getch(); goto START; }
   }
   if(g==0)
    { y=atoi(ye); }
  if((m==2) && (d>29))
  {
    cout<<"wrong input!!!\n";
    cout<<"\nenter the date again....\n";
    goto START;
  }
  if((m>12)||(d>31))
  {
    cout<<"wrong input!!!\n";
    cout<<"\nenter the date again....\n";
    goto START;
  }
  if((m==4||m==6||m==9||m==11) && (d>30))
  {
    cout<<"wrong input!!!\n";
    cout<<"\nenter the date again....\n";
    goto START;
  }
  if((y%4)!=0 && (m==2) && (d>28))
  {
    cout<<"wrong input!!!\n";
    cout<<"\nenter the date again....\n";
    goto START;
  }
  R:
  clrscr();
  cout<<"Enter the room you would like to check in: ";
  cout<<endl;
     cout<<"\n\n";
     cout<<"=======================================================\n";
     cout<<"      Room Type          Status        Price/day\n";
     cout<<"=======================================================\n";
     cout<<"\n  ->Single room(S)\t    A\t\t1000 Rs";
     cout<<"\n  ->Double room(D)\t    A\t\t1750 Rs";
     cout<<"\n  ->Couple room(C)\t    A\t\t2000 Rs";
     cout<<"\n  ->President suit(P)\t    A\t\t5000 Rs";
    getch();
  char r;
  cout<<"\n\nEnter(S/D/C/P) - "; cin>>r;
  r=tolower(r);
  if(r=='s') { strcpy(rtype,roomtype[0]); hprice=1000;}
  else if(r=='d') {strcpy(rtype,roomtype[1]);  hprice=1750;}
  else if(r=='c') {strcpy(rtype,roomtype[2]);  hprice=2000;}
  else if(r=='p') {strcpy(rtype,roomtype[3]);  hprice=5000;}
  cout<<"\nHave you typed the corret letter:\nEnter(y/n)";cin>>r;
  if(r=='n') goto R;
  S:
  cout<<"\nEnter Check out Details";
  cout<<"\nEnter day: "; cin>>outd;
  cout<<"\nEnter month: "; cin>>outm;
  cout<<"\nEnter year: "; cin>>outy;
  if((outm==2) && (outd>29))
  {
    cout<<"wrong input!!!\n";
    cout<<"\nenter the date again....\n";
    goto S;
  }
  if((outm>12)||(outd>31))
  {
    cout<<"wrong input!!!\n";
    cout<<"\nenter the date again....\n";
    goto S;
  }
  if((outm==4||outm==6||outm==9||outm==11) && (outd>30))
  {
    cout<<"wrong input!!!\n";
    cout<<"\nenter the date again....\n";
    goto S;
  }
  if((outy%4)!=0 && (outm==2) && (outd>28))
  {
    cout<<"wrong input!!!\n";
    cout<<"\nenter the date again....\n";
    goto S;
  }
  int days= rdn(getouty(),getoutm(),getoutd()) - rdn(gety(),getm(),getd()) ;
  if(days<0)
   { cout<<"Check out date is before check in date";
      cout<<"\nWrong input!!!\n";
       cout<<"enter the date again....\n";
       goto S;
   }
  hbill=0;
       strcpy(status,"IN");
}
void hotel::disp(int x)
{ // Booking no.    Name      Age    DOCI   DOCO   Room Type
  gotoxy(4,x);cout<<bkn;gotoxy(11,x); cout<<name;gotoxy(25,x);cout<<age; gotoxy(33,x);
  cout<<d<<"/"<<m<<"/"<<y; gotoxy(45,x); cout<<outd<<"/"<<outm<<"/"<<outy<<"\t  "<<status<<"\t   "<<rtype;
}
void hotel::disp2()
{  cout<<bkn<<"\t  "<<name<< "\t\t"<<age<<"\t"<<d<<"/"<<m<<"/"<<y<<"    "<<outd<<"/"<<outm<<"/"<<outy<<"\t"<<status<<"\t "<<rtype; }
void hotel::disp3()
{ // Booking no.    Name      Age    DOCI   DOCO   Room Type
  cout<<"     "<<bkn<<"\t\t  "<<name<<"\t\t"<<age<<"\t"<<d<<"/"<<m<<"/"<<y<<"\t"<<outd<<"/"<<outm<<"/"<<outy<<"     "<<rtype;
}
void hotel::room() //!!!
{   // hotel r;
    // r.allocate();  //!!!
     clrscr();
     delay(100);
     cout<<"\n\n";
     cout<<"=======================================================\n";
     cout<<"      Room Type          Status        Price/day\n";
     cout<<"=======================================================\n";
     cout<<"\n  ->Single room(S)\t    A\t\t1000 Rs";
     cout<<"\n  ->Double room(D)\t    A\t\t1750 Rs";
     cout<<"\n  ->Couple room(C)\t    A\t\t2000 Rs";
     cout<<"\n  ->President suit(P)\t    A\t\t5000 Rs";
    getch();
}
void add_cust()
{ ofstream fo; hotel h;
  fo.open("customer!.dat",ios::app|ios::binary);
    h.getdata();
  fo.write((char*)&h,sizeof(hotel));
   clrscr();
   char g1[70]="Receptionist: Here is your room key Sir. Hope you enjoy the stay here";
   for(int y=0;g1[y]!='\0';y++)
   { delay(30); cout<<g1[y]; }  cout<<endl;
   char g2[26]="Customer : Thank you...!!";
   for(y=0;g2[y]!='\0';y++)
   { delay(30); cout<<g2[y]; } cout<<endl;
   getch();
 fo.close();
}
void disp_cust()
{     clrscr();
      ifstream fin; hotel h;
	fin.open("customer!.dat",ios::binary);
	if(!fin)
	{    cout<<"File could not be open !! Press any Key...";   getch();
	     return;
	}
	cout<<"\t\t\tCUSTOMER LIST\n\n";
	cout<<"==============================================================================\n";
	cout<<" Bk no.    Name        Age        DOCI        DOCO       Status    Room Type \n";
	cout<<"==============================================================================\n";
	int t=7;
	while(fin.read((char *) &h, sizeof(hotel)))
	{   h.disp(t);
	    t++;
	}
	getch();
	fin.close();
}
void del_cust()
{   clrscr();
    hotel h;  int n ;
    cout<<"Enter Booking number : " ; cin>>n;
    ifstream fin;
    ofstream fo;
    fin.open("customer!.dat",ios::binary);
      if(!fin)
	{   cout<<"File could not be open !! Press any Key...";
	    return;
	}
	fo.open("Temp.dat",ios::binary);
	fin.seekg(0,ios::beg);
      while(fin.read((char *)&h,sizeof(hotel)))
	{   if(h.getbkn()!=n)
	     { 	fo.write((char *)&h, sizeof(hotel));
	     }
	}
	fin.close();
	fo.close();
	remove("customer!.dat");
	rename("Temp.dat","customer!.dat");
	cout<<"\n\n\tRecord Deleted ..";
       getch();
}
void hotel::modify()
{    time_t t;
    t=time(NULL);
    cout<<"\n                                                        "<<ctime(&t);
    t -= 24L*60L*60L;
  cout<<"\t\t\tEnter Details\n";
  cout<<"Enter Check out Details:\n";
  S:
  cout<<"Enter day: "; cin>>outd;
  cout<<"\nEnter month: "; cin>>outm;
    cout<<"\nEnter year: "; cin>>outy;
  if((outm==2) && (outd>29))
  {
    cout<<"wrong input!!!\n";
    cout<<"\nenter the date again....\n";
    goto S;
  }
  if((outm>12)||(outd>31))
  {
    cout<<"wrong input!!!\n";
    cout<<"\nenter the date again....\n";
    goto S;
  }
  if((outm==4||outm==6||outm==9||outm==11) && (outd>30))
  {
    cout<<"wrong input!!!\n";
    cout<<"\nenter the date again....\n";
    goto S;
  }
  if((outy%4)!=0 && (outm==2) && (outd>28))
  {
    cout<<"wrong input!!!\n";
    cout<<"\nenter the date again....\n";
    goto S;
  }
  int days= rdn(getouty(),getoutm(),getoutd()) - rdn(gety(),getm(),getd()) ;
  if(days<0)
   { cout<<"Check out date is before check in date";
      cout<<"\nWrong input!!!\n";
       cout<<"enter the date again....\n";
       goto S;
   }
}
void modi_cust()
{    clrscr();
     int f=0;         int n;
      hotel h;
      fstream file;
       cout<<"Enter Booking number : " ; cin>>n;
       file.open("customer!.dat",ios::binary|ios::in|ios::out);
	if(!file)
	{   cout<<"File could not be open !! Press any Key...";
	    return;
	}
      while(file.read((char *) &h, sizeof(hotel)) && f==0)
	{   if(h.getbkn()==n)
	      {  h.hdisplay();
		 cout<<"\n\nEnter The New Details of account"<<endl;
		 h.modify();
		 int pos=(-1)*sizeof(hotel);
		 file.seekp(pos,ios::cur);
		 file.write((char *)&h,sizeof(hotel));
		 cout<<"\n\n\t Record Updated";
		 f=1;
	     }
	 }
	file.close();
	if(f==0)
	cout<<"\n\n Record Not Found ";
}
void checko_cust()
{ clrscr();
  fstream fin ;
  hotel h ; restaurant r;
  int n,f=0;
  cout<<"Enter booking number : ";cin>>n;
  clrscr();
  fin.open("customer!.dat",ios::in|ios::out|ios::binary);
   while(fin.read((char*)&h,sizeof(hotel)))
     {  if(n==h.getbkn()&&strcmpi(h.getstatus(),"IN")==0)
	    {  cout<<"\n\n\n\t\t\t\tBill\n";
		cout<<"==============================================================================\n";
		cout<<"  Booking no.     Name         Age        DOCI           DOCO        Room Type \n";
		cout<<"==============================================================================\n";
	       h.disp3();
	       int days= rdn(h.getouty(),h.getoutm(),h.getoutd()) - rdn(h.gety(),h.getm(),h.getd()) ;
	       cout<<"\n\nTotal Number of Days stayed:"<<days;
	       int hb= h.getrbill();
	       long int roombill=h.getprice()*days;
	       cout<<"\nCharge for room :"<<roombill;
	       int t,y;
	       cout<<"\nRestaurant Charge : "<<hb;
	       y= roombill+hb;
	       cout<<"\nService Tax : 3%";
	       t=(int)(y*0.03)+(y*0.14);
	       y= y+t;
	       cout<<"\nVat : 14%";
	       cout<<"\nTotal Bill : "<<y;
	       cout<<"\nPlease Pay with tip 100Rs....\n";
	       cout<<"Enter any key to pay";
	       getch();
	       f=1;
	       pay(y);
	       h.state();
	       int pos=(-1)*sizeof(hotel);
	       fin.seekp(pos,ios::cur);
	       fin.write((char*)&h,sizeof(hotel));
	       getch();
	       break;

	    }
	else if(n==h.getbkn()&&strcmpi(h.getstatus(),"OUT")==0)
	    { f=1;cout<<"Wrong booking no. entered!!!\nCustomer already checked out..";getch(); }
     }
     if(f==0)
     { cout<<"Sorry Record Not Found!!";
      getch();
     }
    fin.close();
}
void search_cust()
{  clrscr();
   ifstream fin; hotel h;  char n[30]; int f=0;
    fin.open("customer!.dat",ios::binary);
	if(!fin)
	{    cout<<"File could not be open !! Press any Key...";
	     return;
	}
   char e8[47]="Receptionist: Hello sir. How could I help You?";  delay(50);
   for(int y=0;e8[y]!='\0';y++)
   { delay(30); cout<<e8[y]; }  cout<<endl;
   char e9[63]="Person: I have come to meet my friend. He stays in this Hotel.";   delay(50);
   for(y=0;e9[y]!='\0';y++)
   { delay(30); cout<<e9[y]; }      cout<<endl;
   char f1[13]="His name is:";
   for(y=0;f1[y]!='\0';y++)
   { delay(30); cout<<f1[y]; }  cout<<endl;
   cin>>n;
   char f2[44]="Person:Could You tell me details of his stay";
   for(y=0;f2[y]!='\0';y++)
   { delay(30); cout<<f2[y]; }   cout<<endl;
   delay(50);char f3[23]="Receptionist: Sure sir";
   for(y=0;f3[y]!='\0';y++)
   { delay(30); cout<<f3[y]; }
   getch();
   cout<<endl;
    while(fin.read((char*)&h,sizeof(hotel)))
    { if(strcmpi(h.getname(),n)==0)
	{  cout<<"==============================================================================\n";
	   cout<<" Bk no.    Name        Age        DOCI        DOCO     Status    Room Type \n";
	   cout<<"==============================================================================\n";
	   cout<<endl;
	    cout<<"  ";
	    h.disp2();
	  f=1; break ;
	}
    }

    if(f==0)
    {  clrscr();
       char e4[]="Receptionist: Sorry such person doesnt stay in this hotel\n";
      for(int y=0;e4[y]!='\0';y++)
   { delay(30); cout<<e4[y]; } cout<<endl;
      char e5[52]="Person: I know that Just give all the money you got" ;
      for(y=0;e5[y]!='\0';y++)
   { delay(30); cout<<e5[y]; }   cout<<endl;
      char e6[43]="Receptionist : Security....Help..crying...";
      for(y=0;e6[y]!='\0';y++)
   { delay(30); cout<<e6[y]; }        cout<<endl;
      char e7[31]="Person: Y....Sooo...Serious....";
      for(y=0;e7[y]!='\0';y++)
   { delay(30); cout<<e7[y]; }      cout<<endl;
      getch();
    }
   getch();
  fin.close();
}
void main()
{  int a;
   int gd=DETECT,gm;
  initgraph(&gd,&gm,"c:\\tc\\bgi");
    int r,c;

   // textbackground(WHITE);
    //	textcolor(BLUE);
     setcolor(12);
     gotoxy(5,5) ;
      for(c=0;c<7;c++)
   { cout<<" * "; delay(30); }
     gotoxy(59,5);
     for(c=0;c<7;c++)
   { cout<<" * "; delay(30); }
  for(r=0;r<20;r++)
    {  gotoxy(6,6+r);
       cout<<"*"; delay(30);
    }
  cout<<" ";
  for(c=0;c<24;c++)
    { cout<<" * ";delay(30); }

   for(r=0;r<19;r++)
     { gotoxy(78,24-r); cout<<"*";delay(30); }
  settextstyle(BOLD_FONT, HORIZ_DIR, 4);
   outtextxy(205,35,"WELCOME");
   settextstyle(7, HORIZ_DIR, 2);
   delay(200);
   outtextxy(160,105," Project Record - AISSCE(2015-16)");
   delay(200);
   outtextxy(160,135,"     COMPUTER SCIENCE (083)  ");
   delay(220);
   outtextxy(160,160,"           PRACTICAL  ");
   delay(200);
   settextstyle(BOLD_FONT,HORIZ_DIR, 2);
   setcolor(3);
   outtextxy(95,185,"      HOTEL MANAGEMENT  ");
   delay(300);
   outtextxy(110,220,"             With       ");
   delay(200);
   outtextxy(110,255,"           BANKING  ");
   delay(200);
   settextstyle(7,HORIZ_DIR,2);
   setcolor(12);
   outtextxy(140,300,"            DESINGED BY  ");
   delay(300);
   outtextxy(140,320,"      P SAI VENKATA SRAVAN ");
   delay(300);
   getch();
   closegraph();
   do
  {
   clrscr();
   SRAVAN:
   cout<<endl<<endl;
   int gd=DETECT,gm;
  initgraph(&gd,&gm,"c:\\tc\\bgi");
	  settextstyle(8,HORIZ_DIR,4);
      setcolor(WHITE);
      outtextxy(220,90,"  MENU") ;
      gotoxy(25,10); delay(50);cout<<"様様様様様様様様様様様様様";
      setcolor(12);
      delay(100);outtextxy(220,165,"1. BANK ") ;
      delay(100);setcolor(13);outtextxy(220,205,"2. HOTEL") ;
      delay(100);setcolor(14);outtextxy(220,245,"3. EXIT") ;  char e[20]="Enter Your Choice: ";
   gotoxy(28,20);
   for(int y=0;e[y]!='\0';y++)
   { delay(30); cout<<e[y]; }
   cin>>a;
   closegraph();
   switch(a)
   { case 1 : bank();break;
     case 2 : hotel hot;  hot.login();
	      break;
     case 3 : exit(0);
     default :  cout<<"Wrong choice!!!!!"; getch(); clrscr();
		goto SRAVAN;
   }
 }while(a!=3);
   getch();
}
void pay(int amt)
{  D:
   clrscr();
	char c[20];  int n;
   account ac;
    fstream file;
    file.open("account.dat",ios::binary|ios::in|ios::out);
    if(!file)
     {   cout<<"File could not be open !! Press any Key...";
	 return;
     }
  char a1[31]="Receptionist: Cash Or Card sir";
  for(int y=0;a1[y]!='\0';y++)
   { delay(30); cout<<a1[y]; }
  cout<<endl;
  char a2[17]="Customer(Ca/Cr):";
  for(y=0;a2[y]!='\0';y++)
   { delay(30); cout<<a2[y]; }
  cin>>c;
  int f=0;
   if(strcmpi(c,"ca")==0)
   { G:
     char a3[28]="Customer: Here's your money";
     for(int y=0;a3[y]!='\0';y++)
   { delay(30); cout<<a3[y]; } cout<<endl;
     char a4[70]="Receptionist: Thank You sir!!. Hope you enjoed your stay in our hotel";
     for(y=0;a4[y]!='\0';y++)
   { delay(30); cout<<a4[y]; } cout<<endl;
     char a5[36]="Customer: Hope I could. Any way bye" ;
     for(y=0;a5[y]!='\0';y++)
   { delay(30); cout<<a5[y]; }   cout<<endl;
     char a6[32]="Receptionist : hmmmmm..........";
     for(y=0;a6[y]!='\0';y++)
   { delay(30); cout<<a6[y]; } cout<<endl;
   }
   else if(strcmpi(c,"cr")==0)
     { char b1[26]="Customer: Here's the card";
       for(int y=0;b1[y]!='\0';y++)
   { delay(30); cout<<b1[y]; }  cout<<endl;
       char b2[44]="Receptionist: Enter your account number sir";
       for(y=0;b2[y]!='\0';y++)
   { delay(30); cout<<b2[y]; }    cout<<endl;
       char b3[16]="Enter acc no. :";
       for(y=0;b3[y]!='\0';y++)
   { delay(30); cout<<b3[y]; }     cout<<endl;
       cin>>n;
	while(file.read((char *)&ac,sizeof(account))&&f==0)
	{    if(ac.getacno()==n)
		{   int bal=ac.getdeposit()-amt;
			  if((bal<500 && ac.getype()=='S') || (bal<1000 && ac.getype()=='C'))
			    {  char c1[55]="Receptionist: Sorry Sir you have Insufficience balance";
			       for(int y=0;c1[y]!='\0';y++)
			       { delay(30); cout<<c1[y]; }    cout<<endl;
			       char c2[51]="               Would you like to pay through cash?";
			       for(y=0;c2[y]!='\0';y++)
				 { delay(30); cout<<c2[y]; }     cout<<endl;
			       char c3[17]="Customer: Yes!!!";
				for(y=0;c3[y]!='\0';y++)
				{ delay(30); cout<<c3[y]; }   cout<<endl;
				getch();
				clrscr();
				goto  G;
			    }
			 else
			    {  ac.draw(amt);
			       int pos=(-1)* sizeof(ac);
			       file.seekp(pos,ios::cur);
			       file.write((char *) &ac, sizeof(account));
			       clrscr();
			       char d1[61]="Receptionist:Here's your card Sir. Hope you enjoyed the stay";
			       for(int y=0;d1[y]!='\0';y++)
				{ delay(30); cout<<d1[y]; }  cout<<endl;
			       char d2[37]="Customer: Hope i could...Any way bye";
			       for(y=0;d2[y]!='\0';y++)
			       { delay(30); cout<<d2[y]; }  cout<<endl;
			       char d3[27]="Receptionist: Hmmmmm......";
			       for(y=0;d3[y]!='\0';y++)
			      { delay(30); cout<<d3[y]; }  cout<<endl;
			     }
		     }
		      f=1;
	      }
		file.close();
	if(f==0)
	  { char e1[43]="Receptionist:Sorry sir Card is not working";
		   for(int y=0;e1[y]!='\0';y++)
		  { delay(30); cout<<e1[y]; }   cout<<endl;
		   char e2[54]="                  Would you like to pay through cash?";
		    for(y=0;e2[y]!='\0';y++)
	       { delay(30); cout<<e2[y]; }   cout<<endl;
		 char e3[17]="Customer: Yes!!!";
	      for(y=0;e3[y]!='\0';y++)
		   { delay(30); cout<<e3[y]; }      cout<<endl;
	     getch();
	     clrscr(); goto  G;
	  }
	getch();
      }
    else
    { cout<<"Wrong choice!!!!";getch();goto D;}
  getch();
}
void backg()
{ cout<<"\n\n";
   for ( int column = 0; column < 80; column++)
     { 	cout << "*";
     }
    for (int row = 0; row < 15; ++row)
    {  cout << "*";
    for ( column = 0; column < 78; ++column)
    {     cout << " ";
    }
    cout << "*";
    }
    for ( column = 0; column < 80; ++column)
    {    cout << "*";
    }
    cout << "\n";
 }
void back()
{  int r,c;
  cout<<"\n\n\n";
  for(c=0;c<25;c++)
   { cout<<" * "; delay(30); }
  for(r=0;r<18;r++)
    {  gotoxy(2,5+r);
       cout<<"*"; delay(30);
    }
  cout<<" ";
  for(c=0;c<24;c++)
    { cout<<" * ";delay(30); }
   for(r=0;r<17;r++)
     { gotoxy(74,21-r); cout<<"*";delay(30); }
}
void write_account()
{     // back();
       account ac;
      /*	gotoxy(10,6);
	cout<<"Manager: Hello sir";delay(1100);
	gotoxy(10,7);cout<<"Customer: Hello";delay(1100);
	gotoxy(10,8);cout<<"Manager: How can I help you";delay(1100); */
	ofstream fo;
	fo.open("account.dat",ios::binary|ios::app);
	ac.createacc();
	fo.write((char *)&ac, sizeof(account));
	fo.close();
	getch();
}
void displayaccn(int n)
{  	account ac;
	int flag=0;
	ifstream fin;
	fin.open("account.dat",ios::binary);
	if(!fin)
	{    cout<<"File could not be open !!";
	     return;
	}
	cout<<"\nBalance Details\n";
	while(fin.read((char *)&ac,sizeof(account)))
	{     if(ac.getacno()==n)
		{  ac.display();
		   getch();
		   flag=1;
		}
	}
	fin.close();
	if(flag==0)
		cout<<"\n\nAccount number does not exist";
}
void modifyaccn(int n)
{  	int f=0;
	account ac;
	fstream file;
	file.open("account.dat",ios::binary|ios::in|ios::out);
	if(!file)
	{   cout<<"File could not be open !! Press any Key...";
	    return;
	}
	while(file.read((char *) &ac, sizeof(account)) && f==0)
	{   if(ac.getacno()==n)
	      {  ac.display();
		 cout<<"\n\nEnter The New Details of account"<<endl;
		 ac.modify();
		 int pos=(-1)*sizeof(account);
		 file.seekp(pos,ios::cur);
		 file.write((char *)&ac,sizeof(account));
		 cout<<"\n\n\t Record Updated";
		 f=1;
	     }
	 }
	file.close();
	if(f==0)
	cout<<"\n\n Record Not Found ";
  getch();
}
void deleteaccn(int n)
{ 	account ac;
	ifstream fin;
	ofstream fo;
	fin.open("account.dat",ios::binary);
	if(!fin)
	{   cout<<"File could not be open !! Press any Key...";
	    return;
	}
	fo.open("Temp.dat",ios::binary);
	fin.seekg(0,ios::beg);
	while(fin.read((char *)&ac,sizeof(account)))
	{   if(ac.getacno()!=n)
	     { 	fo.write((char *) &ac, sizeof(account));
	     }
	}
	fin.close();
	fo.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\n\tRecord Deleted ..";
   getch();
}
void display_all()
{      back();
       account ac;
	ifstream fin;
	fin.open("account.dat",ios::binary);
	if(!fin)
	{    gotoxy(20,6);cout<<"File could not be open !! Press any Key...";
	     getch();
	     return;
	}
gotoxy(28,6); 	cout<<"ACCOUNT HOLDER LIST\n\n";
gotoxy(10,8);	cout<<"====================================================\n";
gotoxy(10,9);	cout<<"  A/c no.       NAME          Type      Balance\n";
gotoxy(10,10);	cout<<"====================================================\n";
	int i=0;
	while(fin.read((char *) &ac, sizeof(account)))
	{  gotoxy(13,11+i);
	   ac.report();
	   i++;
	} gotoxy(13,12+i);
	fin.close();
   getch();
}
void depdraw(int n, int option)
{   int amt,d=0;;char a[10];
    int f=0;
    account ac;
    fstream file;
    file.open("account.dat",ios::binary|ios::in|ios::out);
    if(!file)
     {   cout<<"File could not be open !! Press any Key...";
	 return;
     }
	while(file.read((char *) &ac, sizeof(account)) && f==0)
	{    if(ac.getacno()==n)
		{  ac.display();
		   if(option==1)
		    {   Q:
			cout<<"\n\n\tTO DEPOSITE AMOUNT ";
			cout<<"\n\nEnter The amount to be deposited:";
			cin>>a;
			for(int z=0; a[z]!='\0'; z++)
			 { if(!isdigit(a[z]))
			     { d=1;cout<<"Please enter numeric value.....Enter again!!"; getch(); goto Q; }
			 }
			 if(d==0)
			   { amt=atoi(a); }
			ac.dep(amt);
		    }
		      if(option==2)
			{ cout<<"\n\n\tTO WITHDRAW AMOUNT ";
			  cout<<"\n\nEnter The amount to be withdraw:";
			  cin>>a;
			for(int z=0; a[z]!='\0'; z++)
			 { if(!isdigit(a[z]))
			     { d=1;cout<<"Please enter numeric value.....Enter again!!"; getch(); goto Q; }
			 }
			 if(d==0)
			   { amt=atoi(a); }
			  int bal=ac.getdeposit()-amt;
			  if((bal<500 && ac.getype()=='S') || (bal<1000 && ac.getype()=='C'))
			     cout<<"Insufficience balance";
			  else
				ac.draw(amt);
			}
		      int pos=(-1)* sizeof(ac);
		      file.seekp(pos,ios::cur);
		      file.write((char *) &ac, sizeof(account));
		      cout<<"\n\n\t Record Updated";
		      cout<<"\nYour New Balance is :"<<ac.getdeposit();
		      f=1;
	       }
	}
	file.close();
	if(f==0)
	   cout<<"\n\n Record Not Found ";
	getch();
}
void games()
{
  char choice1;
	int option;
       do
       {  I:
	  clrscr();
	  cout<<"\n\n\n";
	  cout<< "      *********************************************"<< endl;
	  cout<< "      ***                                       ***"<< endl;
	  cout<< "      ***          Welcome to GAMES AREA        ***"<< endl;
	  cout<< "      ***                   MENU		***"<< endl;
	  cout<< "      ***            1.Play Tic Tac Toe         ***"<< endl;
	  cout<< "      ***            2.Play Hangman	        ***"<< endl;
	  cout<< "      ***            3.Exit		        ***"<< endl;
	  cout<< "      ***                                       ***"<<endl;
	  cout << "      *********************************************" << endl ;
	  cout<< "                    Enter your choice:";cin>>option;


	switch(option)
	{
	 case 1:   init(ob);
		   int i,choice;
		   clrscr();
		   char mark,a;
		   textcolor(BLACK);
		 cout<<"To play this game you need a partner. Grab your partner and" ;
		 cout<<"come qiucly and play\nDid you get yoyr partner??";
		 cout<<"\nEnter(y/n) : "; cin>>a;  a=tolower(a);
		 if(a=='y')
		 {  cout<<"Your allowed to play";
		    delay(1000); clrscr(); cout<<"Enjoy the game";

		  do
		 {
		board(ob);
		ob.player=(ob.player%2)?1:2;
		cout << "Player " << ob.player << " enter a number:  ";
		cin >> choice;
		mark=(ob.player == 1) ? 'X' : 'O';
		if (choice == 1 && ob.square[1]=='1')
			ob.square[1] = mark;
		else if (choice == 2 && ob.square[2]=='2')
			ob.square[2] = mark;
		else if (choice == 3 && ob.square[3]=='3')
			ob.square[3] = mark;
		else if (choice == 4 && ob.square[4]=='4')
			ob.square[4] = mark;
		else if (choice == 5 && ob.square[5]=='5')
			ob.square[5] = mark;
		else if (choice == 6 && ob.square[6]=='6')
			ob.square[6] = mark;
		else if (choice == 7 && ob.square[7]=='7')
			ob.square[7] = mark;
		else if (choice == 8 && ob.square[8]=='8')
			ob.square[8] = mark;
		else if (choice == 9 && ob.square[9]=='9')
			ob.square[9] = mark;
		else
		{
			cout<<"Invalid move ";
			ob.player--;
			getch();
		}
		i=check(ob);
		ob.player++;
	}while(i==-1);
	board(ob);
	if(i==1)
		cout<<"==>\aPlayer "<<--ob.player<<" win ";
	else
		cout<<"==>\aGame draw";
	  }
	  else if(a=='n')
	    { cout<<"Sorry you cant play alone" ; goto I;}
	  else
	    { cout<<"Wrong choice"; getch(); goto I ; }
	  break;
   case 2:  clrscr();
	    textbackground(BLACK);
	      textcolor(YELLOW);
	     char c;
	char unknown [MAXLENGTH];
	char letter;
	int wrongguesses=0;
	char word[MAXLENGTH];
	char easy[4][MAXLENGTH]={"india","oman","iran","nepal"};
	char med[5][MAXLENGTH]={"malaysia","pakistan","australia","philipines","indonesia"};
	char dif[6][MAXLENGTH]={"kyrgystan","ethiopia","azerbaijan","ceskoslovensko", "vanuatu","seychelles"};
	char words[20][MAXLENGTH];

	cout << "\n\nWelcome to hangman...Guess a country Name";
	cout << "\n\nEach letter is represented by a star.";
	cout << "\n\nYou have to type only one letter in one try";
	cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout<<"Choose difficulty (EASY-e/MEDIUM-m/DIFFICULT-d):" ;
	cin>>c;
	if(c=='e')
	  { for(int q=0;q<4;q++)
	    strcpy(words[q],easy[q]);
	  }
	else if(c=='m')
	 { for(int w=0;w<8;w++)
	      strcpy(words[w],med[w]);
	 }
	else if(c=='d')
	   { for(int e=0;e<8;e++)
	     strcpy(words[e],dif[e]);
	   }
	randomize();
	int n;
	if(c=='e')
	 n=random(4);
	else if(c=='m')
	 n=random(5);
	else if(c=='d')
	 n=random(6);
	strcpy(word,words[n]);
	Unknown(word, unknown);
	clrscr();
	cout<<"OK Lets begin playing\n\n";
	char w[30]="Here is Your Unknown Word";
	for(int z=0; w[z]!='\0'; z++)
	 { cout<<w[z];   delay(20); }
	 while (wrongguesses < MAX_TRIES)
	  {
		cout<< unknown;
		cout << "\nGuess a letter: ";
		cin >> letter;
		if (Fill(letter, word, unknown)==0)
		{
			cout << endl << "Whoops! That letter isn't in there!" << endl;
			wrongguesses++;
		}
		else
		    cout << endl << "You found a letter! Isn't that exciting!" << endl;
		cout << "You have " << MAX_TRIES - wrongguesses;
		cout << " guesses left." << endl;
		if (strcmp(word, unknown) == 0)
		{       clrscr();
				cout << word << endl;
			cout << "Yeah! You got it!";
			getch();
			break;
		   }
		}
	if(wrongguesses == MAX_TRIES)
	{       clrscr();
		cout << "\nSorry, you lose...you've been hanged." << endl;
		cout << "The word was : " << word << endl;
	       getch();
	}
		 break;
   case 3: break;
   default:cout<<"Wrong Choice";
  }

  } while(option!=3);
 getch();
}
int check(tic& ob)
{ 	if (ob.square[1] == ob.square[2] && ob.square[2] == ob.square[3])
		return 1;
	else if (ob.square[4] == ob.square[5] && ob.square[5] == ob.square[6])
		return 1;
	else if (ob.square[7] == ob.square[8] && ob.square[8] == ob.square[9])
		return 1;
	else if (ob.square[1] == ob.square[4] && ob.square[4] == ob.square[7])
		return 1;
	else if (ob.square[2] == ob.square[5] && ob.square[5] == ob.square[8])
		return 1;
	else if (ob.square[3] == ob.square[6] && ob.square[6] == ob.square[9])
		return 1;
	else if (ob.square[1] == ob.square[5] && ob.square[5] == ob.square[9])
		return 1;
	else if (ob.square[3] == ob.square[5] && ob.square[5] == ob.square[7])
		return 1;
	else if (ob.square[1] != '1' && ob.square[2] != '2' && ob.square[3] != '3' && ob.square[4] != '4' && ob.square[5] != '5' && ob.square[6] != '6' && ob.square[7] != '7' && ob.square[8] != '8' && ob.square[9] != '9')
		return 0;
	else
		return -1;
}
void board(tic& ob)
{  	clrscr();
	cout << "\n\n\tTic Tac Toe\n\n";
	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;
	cout << "\t\t     |     |     " << endl;
	cout << "\t\t  " << ob.square[1] << "  |  " << ob.square[2] << "  |  " << ob.square[3] << endl;
	cout << "\t\t_____|_____|_____" << endl;
	cout << "\t\t     |     |     " << endl;
	cout << "\t\t  " << ob.square[4] << "  |  " << ob.square[5] << "  |  " << ob.square[6] << endl;
	cout << "\t\t_____|_____|_____" << endl;
	cout << "\t\t     |     |     " << endl;
	cout << "\t\t  " << ob.square[7] << "  |  " << ob.square[8] << "  |  " << ob.square[9] << endl;
	cout << "\t\t     |     |     " << endl << endl;
}
void init(tic& ob)
{ ob.square[0]='0'; ob.square[1]='1';ob.square[2]='2';ob.square[3]='3';ob.square[4]='4';ob.square[5]='5';ob.square[6]='6';ob.square[7]='7';ob.square[8]='8';ob.square[9]='9';

  ob.player=1;
}
int Fill (char guess, char secretword[], char guessword[])
{
	int i;
	int matches=0;
	for (i = 0; secretword[i]!='\0'; i++)
	{
		// Did we already match this letter in a previous guess?
		if (guess == guessword[i])
			return 0;
		// Is the guess in the secret word?
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}
// Initialize the unknown word
void Unknown (char word[], char unknown[])
{
	int a;
	int l = strlen(word);
	for (a = 0; a < l; a++)
		unknown[a]='*';
	unknown[a]='\0' ;
 }
// Project ends here

