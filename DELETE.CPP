#include<fstream.h>
#include<conio.h>
#include<stdio.h>
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

void Delete()
{
student s;
int r,c=0;
ifstream fin("the2.dat",ios::binary);
ofstream fout("temp.dat",ios::binary);
cout<<"Enter the Roll_No To delete"<<endl;
cin>>r;
while(!fin.eof())
{
fin.read((char *)&s,sizeof(s));
if(r!=s.retrno())
{
fout.write((char *)&s,sizeof(s));
c=1;
}
}
fin.close();
fout.close();
remove("the2.dat");
rename("temp.dat","the2.dat");
if(c==0)
{
cout<<"\nRecord NOT FOUND.....";
}
else
cout<<"\nRecord DELETED SUCCESSFULLY";
}

 void main()
{
clrscr();
Delete();
getch();
}
