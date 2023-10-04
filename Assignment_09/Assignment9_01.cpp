#include <iostream>
using namespace std;

int factorial(int num)
{
    if (num < 0)
        throw 1;
    else if (num == 0 or num == 1)
        return 1;
    else
        return num * factorial(num - 1);
}

int main()
{
    int num;
    cout<<"Enter Number: \t";
    cin >> num;
    try
    {
        cout << "Factorial of " << num << " is: \t" << factorial(num) << endl;
    }
    catch (int error)
    {
        cout << "Can't calculate Factorial for Negative Number." << endl;
    }
    return 0;
}