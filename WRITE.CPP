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
cout<<"/n Enter the name of the student : ";
cin>>sname;
}
void put()
{
cout<<"The Roll No of Student is : "<<rno;
cout<<"The Name of Student is : "<<sname;
}
};
void Write()
{
ofstream f;
student s1;
f.open("the.dat",ios::binary|ios::in|ios::out);
for(int i=1;i<5;i++)
{
s1.Read();
f.write((char *)&s1,sizeof(s1));
}
f.close();
}
void main()
{
clrscr();
Write();
getch();
}