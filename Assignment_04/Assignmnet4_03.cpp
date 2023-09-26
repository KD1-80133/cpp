#include <iostream>
using namespace std;

class Matrix
{
private:
    int r;
    int c;
    int **data,i, j;

public:
    Matrix(int r, int c) : r(r), c(c)
    {
        data = new int *[r];
        for (int i = 0; i < r; ++i)
        {
            data[i] = new int[c];
        }
    }

    

    void accept()
    {
        cout << "Enter first matrix elements (" << r << "r" << c << "):" << endl;
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                cin >> data[i][j];
            }
        }
    }
    void print()
    {
        cout << "Matrix (" << r << "r" << c << "):" << endl;
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
    void add(Matrix a,Matrix b)
    {
    
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                data[i][j] = a.data[i][j] + b.data[i][j];
            }
        }
    }
     
    void sub(Matrix a,Matrix b)
    {
    
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                data[i][j] = a.data[i][j] - b.data[i][j];
            }
        }
    }
    void multi(Matrix a,Matrix b)
    {
    
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++) 
            {
                data[i][j] = a.data[i][j] * b.data[i][j];
            }
        }
    }
    void trans(Matrix a)
    {
    
        for (i = 0; i < 2; ++i)
        {
            for (j = 0; j < 2; ++j)
            {
                cout<<data[j][i]<<"\t";
            }
            cout<<endl;
        }
        
    }
    

};

int main()
{
    Matrix mat1(2, 2);
    Matrix mat2(2, 2);

    Matrix result(2,2);
    mat1.accept();
    mat2.accept();
    mat1.print();
    mat2.print();
    result.add(mat1,mat2);
    cout<<"Addtition"<<endl;
    result.print();
    result.sub(mat1,mat2);
    cout<<"Substraction"<<endl;
    result.print();
    result.multi(mat1,mat2);
    cout<<"Multiplication"<<endl;
    result.print();
    mat1.trans(mat1);
    cout<<"Transpose"<<endl;
    mat1.print();
    


    return 0;
}