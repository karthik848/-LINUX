#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<process.h>
#include<stdio.h>
#include<string.h>
class car
{
char cname[20];
char po[20];
int slno;
int rgno;
int y;
public:
void enter();
void display();
void modify();
void Delete();
char *retname()
{
return(cname);
}
};
void car::enter()
{
cout<<"Enter serial Number:";
cin>>slno;
cout<<"Enter the Car Name";
cin>>cname;
cout<<"Enter Previous Owner Name:";
cin>>po;
cout<<"Enter RGNO:";
cin>>rgno;
cout<<"\n Enter Year: ";
cin>>y;
}
void car::modify()
{
char ch;
cout<<"Any modification in slno:";
cin>>ch;
if(ch=='y')
cin>>slno;
ch='n';
cout<<"Any modification in Rgno:";
cin>>ch;
if(ch=='y')
cin>>rgno;
ch='n';
cout<<"Any modification in year:";
cin>>ch;
if(ch=='y')
cin>>y;
ch='n';
}
void car::display()
{
cout<<"Serial Number : ";
cout<<slno;
cout<<"Car Name : ";
cout<<cname;
cout<<"Previous Owner Name : ";
cout<<po<<endl;
cout<<" RGNO : ";
cout<<rgno;
cout<<"Year : ";
cout<<y<<endl;
}
void writefile()
{
car b;
ofstream fl;
fl.open("car.dat",ios::app|ios::binary);
b.enter();
fl.write((char*)&b,sizeof(b));
fl.close();
}

void readfile()
{
car b;
ifstream fin;
fin.open("car.dat",ios::in|ios::binary);
while(fin.read((char*)&b,sizeof(b)))
{
b.display();
}
fin.close();
}
void research()
{
car b;
char n[20];
int flag=0;
fstream fl;
cout<<"\nEnter the name to be searched : ";
gets(n);
fl.open("car.dat",ios::in|ios::binary);
while(fl.read((char*)&b,sizeof(b)))
{
if(strcmp(n,b.retname())==0)
{
b.display();
flag=1;
}
}
fl.close();
if(flag==0)
{
cout<<"\nRecord not found....";
}
}
void recdelete()
{
car b;
char n[20];
int flag=0;
fstream fl,fl1;
cout<<"\nEnter the name to be deleted:";
gets(n);
fl1.open("temp.dat",ios::out|ios::binary);
fl.open("car.dat",ios::in|ios::binary);
while(fl.read((char*)&b,sizeof(b)))
{
if(strcmp(n,b.retname())!=0)
{
fl1.write((char*)&b,sizeof(b));
flag=1;
}
}
fl.close();
fl1.close();
remove("car.dat");
rename("temp.dat","car.dat");
if(flag==0)
{
cout<<"\nRecord not found";
}
else
cout<<"\n\tRecord deleted";
}
void recmodify()
{
car b;
int flag=0;
char n[20];
fstream fl;
cout<<"\nEnter the name to be modified:";
gets(n);
fl.open("car.dat",ios::in|ios::out|ios::binary);
while(fl.read((char*)&b,sizeof(b)))
{
if(strcmp(n,b.retname())==0)
{
b.modify();
fl.seekp(fl.tellp()-sizeof(b));
fl.write((char*)&b,sizeof(b));
cout<<"\n\t\tRecord modified";
flag=1;
break;
}
}
if(flag==0)
{
cout<<"\nRecord not found";
}
fl.close();
}
void main()
{
clrscr();
int n;
char ch;
do
{
cout<<"\n\t1.New car"
 <<"\n\t2.Display all car"
 <<"\n\t3.Search"
 <<"\n\t4.modify"
 <<"\n\t5.Delete"
 <<"\n*Select any options";
 cin>>n;
switch(n)
{
case 1:writefile();
 break;
case 2:readfile();
 break;
case 3:research();
 break;
case 4:recmodify();
 break;
case 5:recdelete();
 break;
case 6:exit(0);
 break;
}
cout<<"Do you wish to continue(y/n)";
cin>>ch;
}while(ch=='y');
getch();
}