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
void Write()
{
ifstream f;
student s1;
f.open("the.dat",ios::binary|ios::app);
while(!f.eof())
{
f.read((char *)&s1,sizeof(s1));
if(f)
s1.output();
}
f.close();
}
void main()
{
clrscr();
Write();
getch();
}