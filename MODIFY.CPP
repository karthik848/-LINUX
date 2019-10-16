#include<fstream.h>
#include<conio.h>
class student
{
int rno;
char sname[20];
public:
int retrno()
{
return(rno);
}
void Read()
{
cout<<"Enter the roll no : ";
cin>>rno;
cout<<"\n Enter the name of the student : ";
cin>>sname;
}
void output()
{
cout<<"The Roll No of Student is : "<<rno;
cout<<"\n The Name of Student is : "<<sname;
}
};
void modify()
{
int r;
fstream f1;
student s;
f1.open("the.dat",ios::binary|ios::in|ios::out);
cout<<"Enter the roll no that you wanna modify : ";
cin>>r;
while(!f1.eof())
{
f1.read((char *)&s,sizeof(s));
if(r==s.retrno())
{
f1.seekp(f1.tellp()-sizeof(s));
s.Read();
f1.write((char *)&s,sizeof(s));
break;
}
}
}
void main()
{
clrscr();
modify();
getch();
}