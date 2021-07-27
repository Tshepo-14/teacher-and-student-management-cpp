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
	string gender;
	public:
	void setName(string);
	void setSurname(string);
	void setAge(int);
	void setIdNumber(string);
	void setGender(string);

	//get values
	int getAge();
	string getDetails();

};


void Person::setGender(string s)
{
   s=s.substr(6,4);
   int numberz;
   numberz=stoi(s);
   string genderzz;

   if(numberz<=4999)
   {
	  genderzz="Male";

   }
   else
   {
	genderzz="Female";

   }



}
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

class Teacher:public Person
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

void readFromFile(string file)
{
	ifstream myfile(file);
	 string line;

    if(myfile.fail())
		  {
			  cout<<"Please make sure "+file+" is present"<<endl;
		  }
		  else
		  {
			  while(!myfile.eof())
			  {
				 while(getline(myfile,line))
				 {
					 cout<<line<<endl;

				 }
			  }
		  }



}


void validateIdNumber(string s)
{
	if(s.length()<13)
	{
		cout<<"please enter a valid Id number with 13 characters";
		cin>>s;
    }
}



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

	 cout<<"=========================================="<<endl;
	 //student database
	 if(f==1)
	 {
		int z;
		cout<<"Enter <1> to view all students"<<endl;
		cout<<"Enter <2> to add new student/s"<<endl;
		cin>>z;

		 string fileName="students.txt";

		if(z==1)
		{

			readFromFile(fileName);
		}
		if(z==2)
		{

			string name;
			string surname;
			string idNumber;
			int age;


			//write new details to students
			cout<<"Enter Name: "<<endl;
			cin>>name;
			cout<<"Enter surname: "<<endl;
			cin>>surname;
			cout<<"Enter Id Number: "<<endl;
			cin>>idNumber;
			//validate id nuber t be 13 characters
			validateIdNumber(idNumber);
			s.setName(name);
			s.setSurname(surname);
			s.setIdNumber(idNumber);
			s.setGender(idNumber);
			string filez="student.txt";

			ofstream file(filez);
			string details=s.getDetails();

			file.open(filez);

			file<<details;


		}
	 }
	 //teacher database
	 if(f==2)
	 {
		int z;
		cout<<"Enter <1> to view all teacher/s"<<endl;
		cout<<"Enter <2> to add new teacher/s"<<endl;
		cin>>z;


	   string fileName="students.txt";
		if(z==1)
		{
			readFromFile(fileName);
		}

		if(z==2)
		{
			ofstream myfile("teachers.txt");
			string name;
			string surname;
			string idNumber;
			float salary;
			string classRoom;
			string subject;


			cout<<"Enter teacher name: ";
			cin>> name;
			cout<<"Enter teacher surname: ";
			cin>>surname;
			cout<<"Enter idNumber: ";
			cin>>idNumber;
			validateIdNumber(idNumber);

			cout<<"Enter salary: ";
			cin>>salary;
			cout<<"Enter classRoom: ";
			cin>>classRoom;
			cout<<"Enter subject: ";
			cin>>subject;



			t.setName(name);
			t.setSurname(surname);
			t.setIdNumber(idNumber);
			t.setSalary(salary);
			t.setClassRoom(classRoom);
			t.setSubjectName(subject);


			string details=t.getDetails();
			myfile<<details;




		}



	 }



	_getch();
	return 0;
}
