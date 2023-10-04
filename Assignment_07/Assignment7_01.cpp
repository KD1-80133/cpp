#include<iostream>
using namespace std;
class Date
{
    private:
    int day;
    int month;
    int year;

    public:
    Date()
    {
        this->day=0;
        this->month=0;
        this->year=0;
    }
    Date(int day,int month,int year)
    {
        this->day=day;
        this->month=month;
        this->year=year;
    }
    int get_day()
    {
        return day;
    }
    void set_day(int day)
    {
        this->day=day;
    }
    int get_month()
    {
        return month;
    }
    void set_month(int month)
    {
        this->month=month;
    }int get_year()
    {
        return year;
    }
    void set_year(int year)
    {
        this->year=year;
    }
    void acceptDate()
    {
        cout<<"Enter day=";
        cin>>this->day;
        cout<<"Enter month=";
        cin>>this->month;
        cout<<"Enter year=";
        cin>>this->year;
    }
    bool isLeapYear()
  {
    if ((this->year % 4 == 0 and this->year % 400 == 0) || (this->year % 4 == 0 and this->year % 100 != 0))
      return true;
    else
      return false;
  }

    void displayDate()
    {
        cout << this->day << "/" << this->month << "/" << this->year << endl;
    }
};
class Person
{
    private:
    string name;
    string addr;
    Date birth_date;
    
    public:
    Person()
    {
        this->name=" ";
        this->addr=" ";
    }
    Person(string name,string addr,int day,int month,int year):birth_date(day,month,year)
    {
        this->name=name;
        this->addr=addr;
    }
    string get_name()
    {
        return name;
    }
    void set_name(string name)
    {
        this->name=name;
    }
    string get_addr()
    {
        return addr;
    }
    void set_addr(string addr)
    {
        this->addr=addr;
    }
    Date get_birth_date()
    {
        return birth_date;
    }
    void set_birth_date(Date bith_date)
    {
        this->birth_date=birth_date;
    }
    
    void acceptPerson()
    {
        
        cout<<"Enter name=";
        cin>>this->name;
        cout<<"Enter addr=";
        cin>>this->addr;
        cout<<"Enter date of birth=";
        birth_date.acceptDate();
    }
    void displayPerson()
    {
        cout<<"---------------------"<<endl;
        cout<<"NAME ="<<name<<endl;
        cout<<"ADDR ="<<addr<<endl;
        cout<<"Date of birth="<<endl;
        birth_date.displayDate();
        cout<<"---------------------"<<endl;
    }
};
class Employee:public Person
{
    private:
    int id;
    float sal;
    string dept;
    Date doj;

    public:
    Employee()
    {
        this->id=0;
        this->sal=0;
        this->dept=" ";
    }
    int get_id()
    {
        return id;
    }
    void set_id(int id)
    {
        this->id=id;
    }
    int get_sal()
    {
        return sal;
    }
    void set_sal(float sal)
    {
        this->sal=sal;
    }
    string get_dept()
    {
        return dept;
    }
    void set_dept(string dept)
    {
        this->dept=dept;
    }
    Date get_doj()
    {
        return doj;
    }
    void set_doj(Date doj)
    {
        this->doj=doj;
    }
    void acceptEmployee()
    {
        Person::acceptPerson();
        cout<<"Enter id =";
        cin>>this->id;
        cout<<"Enter sal=";
        cin>>this->sal;
        cout<<"Enter dept=";
        cin>>this->dept;
        cout<<"Enter date of joining=";
        doj.acceptDate();
    }
    void displayEmployee()
    {
        Person::displayPerson();
        cout<<"---------------------"<<endl;
        cout<<"ID="<<id<<endl;
        cout<<"SAL="<<sal<<endl;
        cout<<"DEPT="<<dept<<endl;
        cout<<"Date of joining="<<endl;
        doj.displayDate();
        cout<<"---------------------"<<endl;
    }
};

int main()
{
    Employee e;
    e.acceptEmployee();
    e.displayEmployee();
    // Person p;
    // p.acceptPerson();
    // p.displayPerson();
    return 0;
}