#include<fstream.h>
#include<ctype.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
class canteen
{
int billno;
char name[20],rank[20];
int smartcard;
int phneno,sum;
public:
int insc()
{
	return smartcard;
}
void write();
void read();
void append();
void search();
}r;
void canteen::write()
{
ofstream fout;
fout.open("catrecord",ios::out);
char a='Y';
int c;

cout<<"enter billno:";
cin>>billno;
cout<<"enter name:";
gets(name);
cout<<"Enter  rank:";
gets(rank);
cout<<"Enter smart card no:";
cin>>smartcard;
while(a=='Y'||a=='y')
{
do{
clrscr();
cout<<"\nItems\t\t\t\t\t\tCost";
cout<<"\n\n\nBiscuite\t\t\t\t\t\t10";
cout<<"\n\nCookies\t\t\t\t\t\t20";
cout<<"\n\nChips\t\t\t\t\t\t10per piece";
cout<<"\n\nEnter your choice(1-3):";
cin>>c;
switch( c)
{
case 1:
sum+=10;
break;
case 2:
sum+=36;
break;
case 3:
int no;
cout<<"How many ???";
cin>>no;
sum+=10*no;
break;
default:
cout<<" Wrong choice,press enter to return to main menu";
}
cout<<"purchase more???(y/n)";
cin>>a;
}while(a=='y'||a=='Y');
fout.write((char*)&r,sizeof(r));
cout<<"want to have more records(y/n):";
cin>>a;
}
fout.close();
}
void canteen::read()
{
int sum;
ifstream fin;
fin.open("catrecord",ios::in);
while(!fin.eof())
{
fin.read((char*)&r,sizeof(r));
cout<<"\nThe billno & name is:"<<billno<<"\t";
puts(name);
cout<<"\nThe smart card no is:"<<smartcard;
cout<<"\nTotal purchase:"<<sum;
}
fin.close();
}
void canteen::append()
{
ofstream fout;
int c,no;
char a;
fout.open("catrecord",ios::app);
while(a=='y'||a=='Y')
{
cout<<"enter billno:";
cin>>billno;
cout<<"enter name:";
gets(name);
cout<<"Enter  rank:";
gets(rank);
cout<<"Enter smart card no:";
cin>>smartcard;
clrscr();
cout<<"\nItems\t\t\t\t\t\tCost";
cout<<"\n\n\nBiscuite\t\t\t\t\t\t10";
cout<<"\n\nPepsodent\t\t\t\t\t\t36";
cout<<"\n\nChips\t\t\t\t\t\t10per piece" ;
cout<<"\n\nEnter your choice(1-3):";
cin>>c;
do{
switch( c)
{
case 1:
sum+=10;
break;
case 2:
sum+=36;
break;
case 3:
cout<<"How many ???";
cin>>no;
sum+=10*no;
break;
default:
cout<<" Wrong choice,press enter to return to main menu";
		}
		cout<<"purchase more???(y/n)";
		cin>>a;
		}while(a=='y'||a=='Y');
fout.write((char*)&r,sizeof(r));
cout<<"want to enter more records??";
cin>>a;
}
fout.close();
}
void canteen::search()
{
char found='n';
int sm;
cout<<"enter the smart card no you want to search for:";
cin>>sm;
ifstream fin;
fin.open("catrecord",ios::in);
while(!fin.eof())
{
fin.read((char*)&r,sizeof(r));
if(r.insc()==sm)
{
r.read();
found='y';
break;
}
}
if(found=='n')
cout<<"record not found";
fin.close();
}
void main()
{
char pass[40];
cout<<"enter the password";
cin>>pass;
if((strcmp(pass,"canteen"))==0)
{
char c,ch,f='Y';
do{
cout<<"\nA to write the contents in a file,"<<endl;
cout<<"B to read the contents,"<<endl;
cout<<"C to add more contents in file,"<<endl;
cout<<"D to search the desired record,"<<endl;
cin>>ch;
clrscr();
c=toupper(ch);
switch(c)
{
case 'A':
r.write();
break;
case 'B':
r.read();
break;
case 'C':
r.append();
break;
case 'D':
r.search();
break;
default:
cout<<"wrong choice is entered,press enter to return to main menu";
getch();
continue;
}
cout<<"Enter Y to return to main menu..";
cin>>f;
clrscr();
}while(f=='y'||f=='Y');
}
else
cout<<"incorrect password sorry no access";
getch();
}
