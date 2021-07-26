#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>



using namespace std;

class Person
{
	protected:
	string name;
	string surname;
	int age;
	string idNumber;
	public:
	void setName(string);
	void setSurname(string);
	void setAge(int);
	void setIdNumber(string);

	//get values
	int getAge();
	string getDetails();

};

void Person::setName(string n)
{
	name=n;
}

void Person::setSurname(string s)
{
	surname=s;
}
void Person::setAge(int a)
{
	age=a;
}
void Person::setIdNumber(string i)
{
	idNumber=i;
}
int Person::getAge()
{
   return age;
}
string Person::getDetails()
{
	string studentz;
	studentz=name+"\t"+surname+"\t"+to_string(age)+"\t"+idNumber;
	return studentz;
}

class Teacher:private Person
{
	private:
	string subjectName;
	string classRoom;
	double salary;
	public:
	void setSubjectName(string);
	void setClassRoom(string);
	void setSalary(double);
	string getDetails();
};

void Teacher::setSubjectName(string sub)
{
	subjectName=sub;
}

void Teacher::setClassRoom(string classR)
{
	classRoom=classR;
}

void Teacher::setSalary(double sal)
{
	salary=sal;

}

string Teacher::getDetails()
{
  string teacherdetails;
  teacherdetails= name+"\t"+surname+"\t"+to_string(age)+"\t"+idNumber+"\t"+subjectName+"\t"+classRoom+"\t"+to_string(salary);
  return teacherdetails;
}

class Student:public Person
{

};

int _tmain(int argc, _TCHAR* argv[]) 
{

	 int f;
	 string name;
	 cout<<"-------------Student and teacher management system using files-----"<<endl;

	 cout<<"Enter <1> to access student database"<<endl;
	 cout<<"Enter <2> to access teacher database"<<endl;
	 cin>>f;

	 Teacher t;
	 Student s;

	 do
	 {
		cout<<"Enter <1> to access student database"<<endl;
		cout<<"Enter <2> to access teacher database"<<endl;
		cin>>f;

	 }while(f!=1 || f!=2);

	 cout<<"=========================================="<<endl;
	 //student database
	 if(f==1)
	 {
		int z;
		cout<<"Enter <1> to view all students"<<endl;
		cout<<"Enter <2> to add new student/s"<<endl;
		cin>>z;

		do
		{
		  cout<<"Enter <1> to view all students"<<endl;
		  cout<<"Enter <2> to add new student/s"<<endl;
		  cin>>z;

		}while(z!=1||z!=2);

		if(z==1)
		{
		  ofstream myfile("file.txt");

		  if(myfile.fail())
		  {
			  cout<<"Please make sure file is present"<<endl;
		  }
		  else
		  {
			  while(!myfile.eof())
			  {

              }
          }
		}
		if(z==2)
		{

        }
	 }
	 if(f==2)
	 {

     }

	_getch();
	return 0;
}
