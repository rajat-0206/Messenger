#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>				    //for gets() and puts()
#include<ctype.h>				    //for strcmpi()
#include<string.h>
#include<stdlib.h>
#include<fstream.h>
#include<graphics.h>
#include<dos.h>

void game();
char username[50];
char uname[50];
class all { public:
	char name[50];
	char mob[12];
	}all;
class msg {    public:
	char to[12];
	char name[50];
	char msg[250];
	}m,mg;
class player
    {
    char fname[50];
    char lname[50];
    char email[50];
   char secqans[50];
    int secq;
    public:
    player();
    char mob[12];
    int chksecqans(char a[50])
    { return strcmp(a,secqans);
    }
    int chkpass(char p[])
    {
    return strcmp(p,pword);
    }
    void getdata();
    void showdata();
    void modify();
   char pword[50];
    int chkmob(char m[])
    {return strcmp(m,mob);
    }
   int sec()
   {int p=secq;
   return p;}
   void msg()
   { char msg[50];
   strcpy(msg,"\n\nWelcome ");
   strcat(msg,fname);
   strcat(msg,",");
   puts(msg);
   }
     }p1;

    player::player()
    {strcpy(fname,"Not Alloted");
    strcpy(lname,"Not Alloted");
     strcpy(username,"Not Alloted");
     strcpy(mob,"Not Available");
     strcpy(secqans,"Not Alloted");
     }
     void player::getdata()
     {char str[50]=" ";
int i=0;  char ch='*';
v:clrscr();
cout<<"\n Enter any password\n";
while(1)
{
str[i]=getch();
if(str[i]!=8)
{
if(i==0&&str[i]==13)
{cout<<"your password cant be null";
i=0;
goto v;
break;}
	if(str[i]==13)
break;
if(str[i]==27)
{cout<<"\n\nyou pressed esc progrm is exiting\n";
getch();
exit(0);}	i++;
	cout<<ch; }

else
{
gotoxy(i,3);
cout<<" ";
gotoxy(i,3);
 i--;
}
    }
       str[i]='\0';
       strcpy(pword,str);
     clrscr();
 cout<<"==========================SIGNUP=======================\n\n";
     cout<<"Please enter your first name \n";
     gets(fname);
     cout<<"Enter your last name\n";
     gets(lname);
     cout<<"Please enter your email id\n";
     gets(email);
    p: cout<<"\nPlease enter your Mobile Number\n";
    gets(mob);
     fstream file;
     int found=0;
     file.open("all",ios::in);
     if(file)
     {
     while(!file.eof())
     {file.read((char*)&all,sizeof(all));
     if(strcmp(mob,all.mob)==0)
    { found=1;
     break;} }  }
     if(found)
     {
     cout<<"\nThis mobile no is already used in aother account.Please chose another";
     file.close();
     goto p;  }
     file.close();
     if(strcmp(mob," ")==0)
     {clrscr();
     goto p;}
   cout<<"\n";
     cout<<"Please enter your security question number\n";
     cout<<"1.What is your mother's name\n";
     cout<<"2.What is your birth city\n";
     cout<<"3.Who is your best friend\n";
     cout<<"4.Who was your childhood hero\n";
     cout<<"5.What was the name of your Elementary school\n";
     cin>>secq;
   cout<<"\nProvide an answer to the question\n";
     gets(secqans);
     cout<<"\n";
     file.open("all",ios::app);
     strcpy(all.name,fname);
     strcpy(all.mob,mob);
     file.write((char*)&all,sizeof(all));
     file.close();
     }
     void player::showdata()
     {  clrscr();
     char name[100];
     strcpy(name,fname);
     strcat(name," ");
     strcat(name,lname);
     cout<<"\nName\t:\t";
     puts(name);
     cout<<"\nEmail Id\t:\t";
     puts(email);
     cout<<"\nMobile No.\t:\t";
     cout.write(mob,10);
     }
     void player::modify()
     {
    r: cout<<"==========================================EDIT PROFILE============================\n\n";
     cout<<"What do you want to modify\n";
     cout<<"1.Name\n2.Email\n\n3.Back\n";
     char ch;
     ch=getch();
     if(ch=='1')
     {cout<<"Enter the new first name\n";
     gets(fname);
     strcpy(all.name,fname);
     cout<<"\nEnter new last name\n";
     gets(lname);
     }
    else if(ch=='2')
     {cout<<"\nEnter new email id\n";
     gets(email);
     }
    else if(ch=='3')
     {clrscr();
     game();
     }
     else
     {cout<<"Wrong Input";
     getch();
     fstream file;
     file.open("all",ios::app);
     file.write((char*)&all,sizeof(all));
     file.close();
     clrscr();
     goto r;
     }
     }
void iq();
void mad();
void profile();
void login();
void signup();
void help();
void send();
void recieved();
void welcome();
void logout();
void sendmessage();
void message();
void exmsg();
void lol(int h,int k,char str[],int d=150)
{
for(int i=0;str[i]!='\0';i++)
{    if(h==81)
{h=0;
k++;}
gotoxy(h+i,k);
delay(d);
cout<<str[i];
}
}
void geninfo()
{clrscr();
 lol(25,3,"General Instruction For Users",100);
 cout<<"\n\n";   delay(500);
 lol(1,7,"1. Please hold your horses while entring data in program."); delay(300);
 lol(1,9,"2. When asked to press Enter press it only once and wait for program to respond.");   delay(300);
 lol(1,11,"3. Don't give any extra information and fake information as it will hamper you     in program run.");
 delay(1000);
 lol(4,23,"Now you are ready for entering into program.Press any key to continue...",100);
 getch();


 }

void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
setbkcolor(RED);
settextstyle(1,HORIZ_DIR,8);
setcolor(YELLOW);
outtextxy(150,180,"WELCOME");
delay(800);
cleardevice();
setbkcolor(YELLOW);
setcolor(RED);
outtextxy(250,180,"TO");
delay(800);
cleardevice();
setbkcolor(BLUE);
setcolor(WHITE);

outtextxy(80,180,"MESSENGER");
delay(800);
for(int i=0;i<180;i++)
{outtextxy(80,180-i,"MESSENGER");
delay(10);
cleardevice();
}
cleardevice();
setbkcolor(BLACK);  outtextxy(80,0,"MESSENGER");
settextstyle(2,0,8);
outtextxy(250,160,"LOADING....");
for(i=0;i<400;i++)
{rectangle(100+i,200,100+i,230);
delay(10);
}
cleardevice();
delay(10);
closegraph();
// setcolor(RED);
 textcolor(RED);
welcome();
}

void welcome()
{
clrscr();
cout<<"===============================WELCOME TO MESSENGER=============================\n";
cout<<"\n\nChoose your option\n";
cout<<"\n1.Login\n2.Signup\n3.Exit\n";
char ch;
e:    ch=getch();
if(ch=='1')
login();
else if(ch=='2')
{delay(500);geninfo();signup(); }
else if(ch=='3')
{cout<<"Bye Bye!! Hope to see you soon :)\nPress any key\n";
getch();
exmsg();
}
else
{cout<<"\n\nWrong Input.\nPlease enter again\n";
goto e;
} }

void signup()
{
fstream file;
clrscr();
cout<<"==========================SIGNUP=======================\n\n";
cout<<"\n\nChoose an Username\n";
p:gets(username);
file.open(username,ios::out|ios::in|ios::noreplace) ;
if(!file)
{clrscr();
cout<<"\n\nThis username already exist.\nPlease enter your choice\n";
j:cout<<"1.Try Again\n2.Login\n";
char g=getch();
if(g=='1')
goto p;
if(g=='2')
login();
else
{
cout<<"\nWrong choice entered.Please input again";
getch();
clrscr();
goto j;
}       }
p1.getdata();
file.write((char *)& p1, sizeof (p1));
file.close();
 delay(500);
cout<<"\nCREATING ACCOUNT";
for(int i=0;i<5;i++)
{cout<<".";
delay(800);
}
delay(1000);
delline();
cout<<"\nYour account was succesfully created.Press any key to continue\n";
getch();
welcome();
 }
void login()
{
m:clrscr();
cout<<"==================================LOGIN================================\n\n";
cout<<"\nEnter your Username\n";

gets(uname);
fstream fil;
fil.open(uname,ios::in|ios::nocreate);
if(!fil)
{

for(int i=0;i<3;i++)
{
clrscr();
cout<<"\nNo such user exist\n";
n:cout<<"\nPlease choose your action\n";
cout<<"\n\n1.Try Again\n2.Signup\n";
char ch=getch();
if(ch=='1')
goto m;
else if(ch=='2')
{delay(500);geninfo();signup();  }
else
{
cout<<"\nWrong Input.\n";
clrscr();
goto n;
}
}
cout<<"\nChoose your action\n\n1.Signup\n2.Exit\n";
char c=getch();
if(c=='1')
signup();
else
exmsg();
}
//player p2;
fil.read((char *)& p1, sizeof(p1));
char str[50]=" ";
int i=0;  char ch='*';
v:clrscr();
cout<<"\n Enter your password\n";
while(1)
{
str[i]=getch();
if(str[i]!=8)
{
if(i==0&&str[i]==13)
{cout<<"your password cant be null";
i=0;
goto v;
break;}
	if(str[i]==13)
break;
if(str[i]==27)
{cout<<"\n\nyou pressed esc progrm is exiting\n";
getch();
exit(0);}	i++;
	cout<<ch; }

else
{
gotoxy(i,3);
cout<<" ";
gotoxy(i,3);
 i--;
}
    }
       str[i]='\0';

//if(p1.chkpass(pss)!=0)
if( strcmp(str,p1.pword)!=0)
    { clrscr();
    cout<<"Wrong Passwordn\nPlease input again\n";
  a:  cout<<"1.Try again\n2.Forgotten Password\n";
    char c=getch();
    if(c=='1')
   {i=0; goto v;}
    if(c=='2')
  {  help();  }
    else
    {
    cout<<"\nWrong Input\n" ;
    getch();
    clrscr();
    goto a;
   }
    }

       delay(500);
cout<<"\n\n\n\t\t\t\n\tSIGNING IN";
for( i=0;i<6;i++)
{cout<<".";
delay(800);
}
delay(1000);
game();
fil.close();
 }

void help()
{
cout<<"=====================RECOVER PASSWORD=======================";
cout<<"\n\nPlease enter your username\n";
m:gets(uname);
fstream fil;
fil.open(uname,ios::in|ios::out|ios::nocreate|ios::binary);
if(!fil)
{
cout<<"\nin checking\n\n";

for(int i=0;i<3;i++)
{
clrscr();
cout<<"\nNo such user exist\n";
cout<<"\nPlease choose your action\n";
n:cout<<"\n\n1.Try Again\n2.Signup\n";
char ch=getch();
if(ch=='1')
goto m;
else if(ch=='2')
{delay(500);signup(); }
else
{
cout<<"\nWrong Input.\n";
getch();
clrscr();
goto n;
}
}
cout<<"\nChoose your action\n\n1.Signup\n2.Exit\n";
char c;
if(c=='1')
signup();
else
exmsg();
}
fil.read((char *)& p1, sizeof(p1));
cout<<"\nEnter your mobile no";
char m[10];
gets(m);
if(p1.chkmob(m)!=0)
{cout<<"\nIdentity not verified.Please try again after some time";
getch();
exmsg();
}
char ans[45];
cout<<"\n\nPlease answer this question\n";
switch(p1.sec())
{
case 1:  cout<<"What is your mother's name";
	      break;
case 2:     cout<<"What is your birth city";
	    break;
case 3: cout<<"Who is your best friend";
	     break;
case 4:     cout<<"Who was your childhood hero";
	    break;
case 5:     cout<<"What was the name of your Elementary school";
	    break;
default:      break;

	  }
cout<<"\n";
gets(ans);
if(p1.chksecqans(ans)!=0)
{
cout<<"\nIdentity not verified.Please try again later.\nPress any key to Continue\n";
getch();
exmsg();
}
 char str[50]=" ";
int i=0;  char ch='*';
v:clrscr();
cout<<"\n Enter new password\n";
while(1)
{
str[i]=getch();
if(str[i]!=8)
{
if(i==0&&str[i]==13)
{cout<<"your password cant be null";
i=0;
goto v;
break;}
	if(str[i]==13)
break;
if(str[i]==27)
{cout<<"\n\nyou pressed esc progrm is exiting\n";
getch();
exit(0);}	i++;
	cout<<ch; }

else
{
gotoxy(i,3);
cout<<" ";
gotoxy(i,3);
 i--;
}
    }
       str[i]='\0';
strcpy(p1.pword,str);
fil.close();
fil.open("temp",ios::out);
fil.write((char *)&p1,sizeof (p1));
fil.close();
remove(uname);
rename("temp",uname);
 delay(500);
cout<<"\n\n\t\tPLEASE WAIT";
for(i=0;i<5;i++)
{cout<<".";
delay(800);
}
delay(1000);
delline();
cout<<"\nPassword successfully recovered.Press any key to continue\n";
getch();
welcome();
}

void logout()
{
cout<<"\nAre you surely want to logout(y/n)\n";
char confirm=getch();
if(confirm=='y'||confirm=='Y')
welcome();
}

void game()
{
clrscr();
char ch,ch1;
q:
clrscr();
enter:cout<<"\t\t================WELCOME TO MESSENGER================\n";
fstream file;
file.open(uname,ios::in);
file.read((char*)&p1,sizeof(p1));
p1.msg();
cout<<"\nPlease check you may have new message\n";
file.close();
cout<<"\n\nPlease enter your choice:\n";
cout<<"1.Send new message\n2.View Profile\n";
cout<<"3.My Message\n";
cout<<"4.Logout\n";
ch=getch();
switch(ch)
  {
   case '1' : sendmessage();
     break;
   case '2' : profile();

     break;
     case '3': message();
     break;
   case '4' : { logout();
		clrscr();
		 goto enter;}
    break;
   default  : {cout<<"\nWrong Input\n\n";
	      getch();
	      clrscr();
	       goto enter;}

    }       						//end of switch
}



void profile()
{
clrscr();
cout<<"====================PROFILE========================\n\n";
fstream file;
file.open(uname,ios::in,ios::nocreate);
p1.showdata();
file.close();
cout<<"\n\nPlease choose any choice\n";
cout<<"1.Back\n2.Edit Profile\n3.Change Password\n4.Delete account\n";
char ch;
p:ch=getch();
if(ch=='1')
game();
if(ch=='2')
{clrscr();
p1.modify();
file.open(uname,ios::out);
file.write((char *)&p1, sizeof(p1));
file.close();
cout<<"\nDetails successfully updated.";
cout<<"Press any key to retun home\n";
getch();
clrscr();
game();
}
if(ch=='3')
{char str[50]=" ";
int i=0;  char ch='*';
v:     clrscr();
cout<<"\n Enter new password\n";
while(1)
{
str[i]=getch();
if(str[i]!=8)
{
if(i==0&&str[i]==13)
{cout<<"your password cant be null";
i=0;
goto v;
break;}
	if(str[i]==13)
break;
if(str[i]==27)
{cout<<"\n\nyou pressed esc progrm is exiting\n";
getch();
exit(0);}	i++;
	cout<<ch; }

else
{
gotoxy(i,3);
cout<<" ";
gotoxy(i,3);
 i--;
}
    }
       str[i]='\0';
	     strcpy(p1.pword,str);
file.open(uname,ios::out);
file.write((char *)&p1, sizeof(p1));
file.close();
 delay(500);
cout<<"\n\n\t\tPLEASE WAIT";
for(i=0;i<5;i++)
{cout<<".";
delay(800);
}
delay(1000);
delline();
cout<<"\nPassword successfully changed.Press any key to retun home.\n";
getch();
game();
}

if(ch=='4')
{cout<<"\n\nAre you sure you want to delete your account(y/n)\n";
cout<<"(Note:This action is not reversible)\n";
char h=getch();
if(h=='y')
{char str[50]=" ";
int i=0;  char ch='*';
ty:clrscr();
cout<<"\n Enter your password to delete your account\n";
while(1)
{
str[i]=getch();
if(str[i]!=8)
{
if(i==0&&str[i]==13)
{cout<<"your password cant be null";
i=0;
goto ty;
break;}
	if(str[i]==13)
break;
if(str[i]==27)
{cout<<"\n\nyou pressed esc progrm is exiting\n";
getch();
exit(0);}	i++;
	cout<<ch; }

else
{
gotoxy(i,3);
cout<<" ";
gotoxy(i,3);
 i--;
}
    }
       str[i]='\0';
if(strcmp(p1.pword,str)!=0)
{cout<<"Wrong password.....\nDiscarding Changes......\nPress any key to continue";
getch();
clrscr();
profile();
}                                     fstream fil,fout;
fil.open("all",ios::in);
fout.open("temp",ios::out);
while(!fil.eof())
{fil.read((char*)&all,sizeof(all));
if(strcmp(all.mob,p1.mob)==0 )
{continue;}
fout.write((char*)&all,sizeof(all));
}
fil.close();
fout.close();
remove("all");
rename("temp","all");
remove(p1.mob); char del[50];
strcpy(del,"s");
strcat(del,uname);
remove(uname);
remove(del);
clrscr();
 delay(500);
cout<<"\n\n\t\tPLEASE WAIT";
for(i=0;i<5;i++)
{cout<<".";
delay(800);
}
delay(1000);
delline();
cout<<"\nAccount successfully deleted\nPress any key to continue\n";
getch();
welcome();
}
clrscr();
profile();
}
else
{
cout<<"\nWrong input.\nPlease try again\n";
goto p;
}
}

void sendmessage()
{p:clrscr();
cout<<"\nEnter the number of person whom you want to send message\n";
char mob[12];
gets(mob);
fstream file,fin;
file.open(uname,ios::in);
file.read((char*)&p1,sizeof(p1));
if(p1.chkmob(mob)==0)
{cout<<"\n\nYou can't send message to yourself\nPress any key to continue\n";
getch();
file.close();
goto p;
}
file.close();
char found='n';
file.open("all",ios::in);
while(!file.eof())
{if(file.eof())
break;
file.read((char*)&all,sizeof(all));
if(strcmp(all.mob,mob)==0)
{found='y';
break;
}
}
if(found=='n')
{cout<<"\nNo such person found\nPress any key to continue\n";
getch();
file.close();
game();
}
cout<<"\nEnter your message to ";

char name[50];
strcpy(name,all.name);
puts(name);
file.close();
gets(mg.msg);
//for reciever
file.open(mob,ios::in|ios::app);
fin.open("temp",ios::out);
strcpy(mg.to,mob);
strcpy(mg.name,name);
fin.write((char*)&mg,sizeof(mg));
while(!file.eof())
{
if(file.eof())
{break;}
file.read((char*)&m,sizeof(m));
fin.write((char*)&m,sizeof(m));
}
file.close();
fin.close();
remove(mob);
rename("temp",mob);
//for sender
char sname[10];
strcpy(sname,"s");
strcat(sname,uname);
file.open(sname,ios::in|ios::app);
fin.open("temp",ios::out);
fin.write((char*)&mg,sizeof(mg));
while(!file.eof())
{
if(file.eof())
break;
file.read((char*)&m,sizeof(m));
fin.write((char*)&m,sizeof(m));
}
file.close();
fin.close();
remove(sname);
rename("temp",sname);
cout<<"\n\nYour message was succesfully sent\nPress any key to continue\n";
getch();
game();
}

void message()
{clrscr();
fstream file,fin;
file.open(uname,ios::in);
char sname[10];
strcpy(sname,"s");
strcat(sname,uname);
file.read((char*)&p1,sizeof(p1));
cout<<"\nWhich message do you want to see\n1.Sent\n2.Recieved\n";
int ch;
cin>>ch;
if(ch==1)
{clrscr();
cout<<"=============================SENT MESSAGE=============================\n\n";
fin.open(sname,ios::in);
if(!fin)
{cout<<"\nYou hadn't sent any message yet\nPress any key to continue\n";
getch();
file.close();
game();
}
while(!fin.eof())
{
if(fin.eof())
break;
fin.read((char*)&m,sizeof(m));
if(strcmp(m.name,"")==0)
break;
cout<<"\nTo: ";
puts(m.name);
cout<<"Message: ";
puts(m.msg);
cout<<"\nPress any key to continue\n";
getch();
}
fin.close();
}
int i=1;
if(ch==2)
{clrscr();
cout<<"==========================RECIEVED MESSAGE============================\n\n";
fin.open(p1.mob,ios::in);
if(!fin)
{cout<<"\nYou hadn't recieved any message yet\nPress any key to continue\n";
getch();
file.close();
game();
}
while(!fin.eof())
{
if(fin.eof())
break;
fin.read((char*)&m,sizeof(m));
if(strcmp(m.name,"")==0)
break;
cout<<i;
cout<<" Message: ";
puts(m.msg);
i++;
cout<<"\nPress any key to continue\n";
getch();
}
fin.close();
}
cout<<"\nNo more to show\nPress any to continue\n";
getch();
file.close();
game();
}

void exmsg()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
cleardevice();
setbkcolor(YELLOW);
setcolor(BLUE);
  settextstyle(7,HORIZ_DIR,4);
   outtextxy(10,60,"!!  THANK YOU FOR STOPPING BY  !!");
			   setcolor(RED); delay(500);
	for(int i=0;i<140;i++)
	{line(80,300-i,80,299-i); delay(8); }
	delay(50);
		for(i=0;i<500;i++)
	{line(80+i,159,80+i,159); delay(5); }
	delay(50);
		for( i=0;i<140;i++)
	{line(580,159+i,580,160+i); delay(8); }
	     delay(50);
		for( i=0;i<500;i++)
	{line(580-i,300,580-i,299); delay(5); }
	delay(900);
   settextstyle(2,0,8);
   setcolor(GREEN);
   outtextxy(260,170,"Project by:");
   delay(800);
     settextstyle(2,0,8);
   setcolor(CYAN);
    outtextxy(200,200,"RAJAT SHRIVASTAVA");  delay(400);
     outtextxy(240,230,"XII SCIENCE");       delay(400);
      outtextxy(90,260,"NEHRU INTERNATIONAL PUBLIC SCHOOL");
     delay(1000);
		setcolor(9);
   settextstyle(7,0,2);
   outtextxy(230,400,"Press any to exit");
   getch();
   delay(100);
   cleardevice();
   closegraph();
   exit(0);
   }
