#include<iostream>
using namespace std;
class Time
{
    private:
    int hr;
    int min;
    int sec;
    
    int gethr()
    {
        return hr;
    }
    void sethr(int hr)
    {
        this->hr=hr;
    }
    int getmin()
    {
        return min;
    }
    void setmin(int min)
    {
        this->min=min;
    }
    int getsec()
    {
        return sec;
    }
    void setsec(int sec)
    {
        this->sec=sec;
    }
    public:
    Time()
    {
        hr=20;
        min=10;
        sec=40;
    }
    Time(int hr,int min,int sec)
    {
        this->hr=hr;
        this->min=min;
        this->sec=sec;
    }
    void acceptTime()
    {
        cout<<"Enter hr ="<<endl;
        cin>>this->hr;
        cout<<"Enter min ="<<endl;
        cin>>this->min;
        cout<<"Enter sec ="<<endl;
        cin>>this->sec;
    }
    void printTime()
    {
        cout<<"Time="<<hr<<":"<<min<<":"<<sec<<endl;
    }
};
int main()
{
    Time *ptr[3];
    ptr[0]=new Time(10,30,50);
    ptr[1]=new Time();
    ptr[2]=new Time(12,25,55);
    for(int i=0;i<3;i++)
    {
        ptr[i]->printTime();
    }
    for(int i=0;i<3;i++)
    {
        ptr[i]->acceptTime();
        ptr[i]->printTime();
    }
    delete ptr[0];
    delete ptr[1];
    delete ptr[2];
    
    ptr[0]=NULL;
    ptr[1]=NULL;
    ptr[2]=NULL;
    return 0;

}