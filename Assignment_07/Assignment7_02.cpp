#include<iostream>
using namespace std;

class Product
{
    private:
    int id;
    string title;
    char type;
    double price;

    public:
    Product()
    {
        this->id=0;
        this->title=" "; 
        this->price=0.0;
    }
    Product(int id,string title,float price)
    {
        this->id=id;
        this->title=title;
        this->price=price;
    }
    int get_id()
    {
        return id;
    }
    void set_id(int id)
    {
        this->id=id;
    }
    string get_title()
    {
        return title;
    }
    void set_title(string title)
    {
        this->title=title;
    }
    float get_price()
    {
        return price;
    }
    void set_price(float price)
    {
        this->price=price;
    }
    char get_type()
    {
        return type;
    }
    void set_type(char type)
    {
        this->type=type;
    }
    virtual void accept()
    {
        cout<<"-----------------";
        cout<<"Enter id=";
        cin>>this->id;
        cout<<"Enter title=";
        cin>>this->title;
        cout<<"Enter price=";
        cin>>this->price;    
    }
    void display()
    {
        cout << "ID = " << id << endl;
        cout << "TITLE = " << title << endl;
        cout << "PRICE = " << price << endl;
    }
    friend void calculate_bill(Product *arr[], int index);

};
class Book:public Product
{
    private:
    string author;
    char type;
    public:
    Book()
    {
        this->author="";
        this->set_type('B');
    }
    
    Book(int id, string tittle, float price, string author):Product(id,tittle,price)
    {
        this->author=author;
        set_type('B');
    }
    string get_author()
    {
        return author;
    }
    void set_author(string author)
    {
        this->author=author;
    }
    void accept()
    {
        Product::accept();
        cout<<"Enter Author=";
        cin>>this->author;
    }
    void display()
    {
        Product::display();
        cout<<"Author="<<author<<endl;
    }
};
class Tape:public Product
{
    private:
    string artist;
    char type;
    public:
    Tape()
    {
        this->artist="";
        this->set_type('T');
    }
    Tape(int id, string tittle, float price, string artist) : Product(id, tittle, price)
    {
        this->artist=artist;
        set_type('T');
    }
    string get_artist()
    {

        return artist;
    }
    void set_artist(string artist)
    {
        this->artist=artist;
    }
    void accept()
    {
        Product::accept();

        cout << "Enter ARTIST = ";
        cin >> artist;
    }

    void display()
    {
        Product::display();
        cout << "ARTIST = " << artist;
    }
};
int menu()
{
    int choice;
    cout << "0.Exit" << endl;
    cout << "1.Add book = " << endl;
    cout << "2.Add tape = " << endl;
    cout << "3.display products = " << endl;
    cout << "4.Display bill= " << endl;
    cout << "Enter your choice= " << endl;
    cin >> choice;
    return choice;
}


void calculate_bill(Product *arr[], int index)
{
    float total_price = 0;

    for (int i = 0; i < index; i++)
    {
        if (arr[i]->type == 'B')

        {
            total_price = arr[i]->price * 0.90;
        }
        else
        {
            total_price = arr[i]->price * 0.95;
        }
    }

    cout << "TOTAL PRICE= " << total_price << endl;
}
int main()
{
    int choice;
    Product *arr[3];
    int index=0;
    while ((choice=menu())!=0)
    {
        switch (choice)
        {
        case 1:
            if(index<3)
            {
                arr[index]=new Book();
                arr[index]->accept();
                index++;
            }
            else
            {
                cout<<"product is full!"<<endl;
            }
            break;
        case 2:
            if(index<3)
            {
                arr[index]=new Tape();
                arr[index]->accept();
                index++;
            }
            else
            {
                cout<<"product is full!"<<endl;
            }
            break;
        case 3:
        {
            for (int i = 0; i < index; i++)
            {
                arr[i]->display();
            }
        }
        case 4:
            calculate_bill(arr, index);

            break;
        default:
            cout << "wrong choice" << endl;
            break;
        }
    }

    for (int i = 0; i < index; i++)
    {
        delete arr[i];
    }
    cout << "Thank you for shopping..." << endl;
    return 0;
}
        