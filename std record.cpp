#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
class student

{
   public:
   int roll;
   char id[15],s_name[20],f_name[20],clas[10];
   void put();
   void get();
   void switch_case();
  }; 
  
  student s;

 void student::put()
  {
   fstream file;
   cout<<"Enter roll no:  ";
   cin>>roll;
   cout<<"Enter Student name";
   gets(id);
   cout<<": ";
   gets(s_name);
   cout<<"Enter Father name: ";
   gets(f_name);
   cout<<"Enter Class name: ";
   gets(clas);
   file.open("stu.dat",ios::out|ios::app);
//  file.seekp(0,ios::beg);
   file.write((char *)this,sizeof(student));
   file.close();
   getch();
   s.switch_case();
  }

  void student::get()
  {
   int temp;
   cout<<"Enter roll no: ";
   cin>>temp;
   fstream file;
   file.open("stu.dat",ios::in);
   file.seekg(0,ios::beg);
   while(file.read((char *)this,sizeof(student)));
    {
    if(roll==temp)
    {
    cout<<"roll no. "<<roll;
//    cout<<"\nstu id:  "<<id<<endl;
    cout<<"\nstudent name: "<<s_name;
    cout<<"\nfather name: "<<f_name;
    cout<<"\nClass name: "<<clas;
   }
   }
    file.close();
    getch();
    s.switch_case();
   }

  void student::switch_case()
   {
    int i;
    cout<<"Enter your choice \n1-Write \n2-Read \n3-exit \n\n====> ";
    cin>>i;
    switch(i)
    {
    case 1:
	  s.put();
	  break;

    case 2:
	  s.get();
	  break;

    case 3:
	  exit(0);

    default:
	  cout<<"wrong choice ";
    }
    }

  int main()
    {
    
     s.switch_case();
    }
