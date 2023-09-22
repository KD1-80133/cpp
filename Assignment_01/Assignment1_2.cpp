#include<iostream>

using namespace std;
class Date
{
    private:
    int day;
    int month;
    int year;
public:
void initDate()
{
    cout<<"inside ctor";
    day=1;
    month=1;
    year=1000;

}
void printDateOnConsole()
{
    cout<<"Date"<<day<<"/"<<month<<"/"<<year<<endl;
}
void acceptDateFromConsole()
{
    cout<<"Enter day,month,year";
    cin>>day>>month>>year;
}
void isLeapYear()
{
    if(year%400==0 && year&100!=0)
    {
        cout<<"year is leap year"<<endl;
    }
    else
    {
        cout<<"year is not leap"<<endl;
    }
}
};
int main()
{
    Date d1;
    int output;
    cout<<"opt: 0.Exit,1.Default date,2.required date"<<endl;
    cin>>output;
    do
    {
    switch(output)
    {
        case 0: break;
        case 1:
        d1.initDate();
        d1.printDateOnConsole();
        break;
        case 2:
        d1.acceptDateFromConsole();
        d1.isLeapYear();
        d1.printDateOnConsole();
        break;
    }
    } while (output!=0);
    return 0;
    
}