#include<iostream>
#include<vector>
using namespace std;
class insufficient_funds
{
private:
    int id;
    double cur_balance;
    double withdrow_amount;

public:
    insufficient_funds(int id, double cur_balance, double withdrow_amount)
    {
        this->id = id;
        this->cur_balance;
        this->withdrow_amount;
    }

    void display()
    {
        cout << "ERROR : insufficient_funds..." << endl;
        cout << "Account ID: \t" << this->id << endl;
        cout << "Current Balance: \t" << this->cur_balance << endl;
        cout << "Withdrowing amount: \t" << this->withdrow_amount << endl;
    }
};
enum account_type
{
    Saving = 1,
    Current,
    Dmat
};

class Account
{
private:
    int id;
    account_type type;
    double balance;

public:
    Account()
    {
        this->id = 0;
        this->type = Current;
        this->balance = 200;
    }

    Account(int id, account_type type)
    {
        this->id = id;
        this->type = type;
    }

    void accept()
    {
        int num;
        cout << "Enter Account ID: \t";
        cin >> this->id;
        cout << "Enter Account Type\n1. Saving\n2. Current\n3. Dmat: \t";
        cin >> num;
        type = account_type(num);

        cout << "Enter Balance Amount: \t";
        cin >> this->balance;
    }

    void display()
    {
        cout << "****Account Details****" << endl;
        cout << "Account ID: \t" << this->id << endl;
        cout << "Account Type: \t" << account_type(this->type) << endl;
        cout << "Account Balance: \t" << this->balance << endl;
    }

    void set_id(int id)
    {
        this->id = id;
    }

    void set_type(account_type type)
    {
        this->type = type;
    }

    int get_id()
    {
        return this->id;
    }

    account_type get_type()
    {
        return this->type;
    }

    double get_balance()
    {
        return this->balance;
    }

    void deposit(double amount)
    {
        this->balance += amount;
    }

    void withdraw(double amount)
    {
        if(this->balance < amount)
            throw insufficient_funds(this->id, this->balance, amount);
        else
            this->balance -= amount;
    }
};
enum emenu1
{
    EXIT,
    CREATE_ACCOUNT,
    SHOW_ACCOUNTS,
    MAKE_TRANSACTION
};

emenu1 menu1()
{
    int choice;
    cout << "------Menu--------" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Show Accounts" << endl;
    cout << "3. Do Transaction" << endl;
    cout << "-----------------" << endl;
    cin >> choice;
    return emenu1(choice);
}

enum emenu2
{
    RETURN_TO_MENU,
    DEPOSIT,
    WITHDRAW
};

emenu2 menu2()
{
    int choice;
    cout << "0. Return to Menu" << endl;
    cout << "1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cin >> choice;
    return emenu2(choice);
}
int main()
{
    int size=5;
    int choice1, choice2, id, amount;
    vector<Account *> account;
    while ((choice1 = menu1()) != 0)
    {
        switch (choice1)
        {
        case 1:
            {
                Account *ptr=new Account();
                ptr->accept();
                account.push_back(ptr);
            }
            break;

        case 2:
            cout<<"Enter Account Id=";
            cin>>id;
            for(int i=0;i<account.size();i++)
            {
                if (account.at(i)->get_id()==id)
                {
                    account.at(i)->display();
                    break;
                }
                else
                {
                    cout<<"Wrong account no "<<endl;
                    break;
                }
            }
            break;

        case 3:
            while ((choice2 = menu2()) != RETURN_TO_MENU)
            {
                switch (choice2)
                {
                case DEPOSIT:
                    cout << "Enter account No: \t";
                    cin >> id;
                    cout << "Enter Amount: \t";
                    cin >> amount;
                    for (int i = 0; i < account.size(); i++)
                    {
                        if (account.at(i)->get_id() == id)
                        {
                            try
                            {
                                account.at(i)->deposit(amount);
                            }
                            catch(insufficient_funds error)
                            {
                                error.display();
                            }
                            break;
                        }
                            else 
                            {
                                cout<<"Wrong Account no.."<<endl;
                                break;
                            }
                    }
                    break;

                case WITHDRAW:
                    cout << "Enter account No: \t";
                    cin >> id;
                    for (int i = 0; i < account.size(); i++)
                    {
                        if (account.at(i)->get_id() == id)
                        {
                            cout<<"Enter withdraw amount";
                            cin>>amount;
                            try
                            {
                                account.at(i)->withdraw(amount);
                            }
                            catch(insufficient_funds error)
                            {
                                error.display();
                                //.display("withdraw");
                                
                            }
                            break;
                           
                        }
                        else 
                        {
                            cout<<"Wrong Account no "<<endl;
                            break;
                        }

                    }
                    break;

                default:
                    cout << "Enter Invalid Choice!!!" << endl;
                }
            }
            break;
        default:
            cout << "Enter Invalid Choice!!!" << endl;
            break;
        }
    }

    for (int i = 0; i < account.size(); i++)
        delete account.at(i);

    return 0;
}