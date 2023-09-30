#include<iostream>
using namespace std;
class Employee
{
    private:
    int id;
    float sal;

    public:
    Employee()
    {
        this->id=0;
        this->sal=0;
    }
    Employee(int id,float sal)
    {
        this->id=id;
        this->sal=sal;
    }
    int getid()
    {
        return id;
    }
    void setid(int id)
    {
        this->id=id;
    }
    float getsal()
    {
        return sal;
    }
    void setsal(float sal)
    {
        this->sal=sal;
    }
    void accept()
    {
        cout<<"Enter employee id=";
        cin>>this->id;
        cout<<"Enter employee sal=";
        cin>>this->sal;
    }
    void display()
    {
        cout<<"ID"<<id<<endl;
        cout<<"SAl"<<sal<<endl;
    }
};
class Manager:virtual public Employee
{
    private:
    
    float bonus;

    public:
    Manager()
    {
        this->bonus=0;
    }
    Manager(float bonus)
    {
        this->bonus=bonus;
    }
    float getbonus()
    {
        return bonus;
    }
    void setbonus(float bonus)
    {
        this->bonus=bonus;
    }
    void accept()
    {
         Employee::accept();
    }
     void display()
    {
        Employee::display();
    }
    protected:
    void acceptManager()
    {
        
        cout<<"Enter bonus=";
        cin>>this->bonus;
    }
    void displayManager()
    {
        
        cout<<"BONUS"<<bonus<<endl;
    }
};
class Salesman:virtual public Employee
{
    private:
    
    float comm;

    public:
    Salesman()
    {
        this->comm=0;
    }
    Salesman(float comm)
    {
        this->comm=comm;
    }
    float getcomm()
    {
        return comm;
    }
    void setcomm(float comm)
    {
        this->comm=comm;
    }
    void accept()
    {
        Employee::accept();
    }
     void display()
    {
        Employee::display();
    }
    protected:
    void acceptSalesman()
    {
        
        cout<<"Enter Comm=";
        cin>>this->comm;
    }
    void displaySalesman()
    {
        
        cout<<"COMM"<<comm<<endl;
    }
};
class Sales_manager:public Manager,public Salesman
{
    public:
    void accept()
    {
        Employee::accept();
        Salesman::acceptSalesman();
        Manager::acceptManager();
        
    }

    void display()
    {
        Employee::display();
        Salesman::displaySalesman();
        Manager::displayManager();
        
    }
};
int main()
{
    Sales_manager s;
    s.accept();
    s.display();
    return 0;
}