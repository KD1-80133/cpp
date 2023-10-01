#include <iostream>
using namespace std;

class Matrix
{
private:
  int row, column;
  int **arr;

public:
  Matrix(int row, int column) : row(row), column(column)
  {
    arr = new int *[row];
    for (int i = 0; i < row; i++)
    {
      arr[i] = new int[column];
    }
  }
  Matrix() : row(row), column(column)
  {
    arr = new int *[row];
    for (int i = 0; i < row; i++)
    {
      arr[i] = new int[column];
    }
  }
  void accept()
  {
    cout << "enter matrix" << endl;

    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < column; j++)
      {
        cin >> arr[i][j];
      }
    }
  }
  void print()
  {
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < column; j++)
      {
        cout << arr[i][j] << " ";
      }
      cout << endl;
    }
  }
  Matrix add(Matrix &M2)
  {
    Matrix M3(row, column);
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < column; j++)
      {
        M3.arr[i][j] = this->arr[i][j] + M2.arr[i][j];
      }
    }
    return M3;
  }
  Matrix subtract(Matrix &M2)
  {
    Matrix M3(row, column);
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < column; j++)
      {
        M3.arr[i][j] = this->arr[i][j] - M2.arr[i][j];
      }
    }
    return M3;
  }
  Matrix multiply(Matrix &M2)
  {
    Matrix M3(row, column);
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < column; j++)
      {
        M3.arr[i][j] = 0;
        for (int k = 0; k < column; k++)
        {
          M3.arr[i][j] += this->arr[i][k] * M2.arr[k][j];
        }
      }
    }
    return M3;
  }
  Matrix transpose()
  {
    Matrix M3(row, column);
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < column; j++)
      {
        M3.arr[i][j] = arr[j][i];
      }
    }
    return M3;
  }

  ~Matrix()
  {
    for (int i = 0; i < row; i++)
      delete[] arr[i];

    delete[] arr;
  }
};

/*int menu()
{
    int choice;
    cout<<"1.Add Matrix"<<endl;
    cout<<"2.Subtract Matrix"<<endl;
    cout<<"3.Multiply Matrix"<<endl;
    cout<<"4.Transpose matrix"<<endl;
    cout<<"5.Accept Values"<<endl;
    cout<<"6.Print Values"<<endl;
    cin>>choice;

    return choice;
}*/

int main()
{

  Matrix M1(2, 2);
  M1.accept();
  M1.print();
  Matrix M2(2, 2);
  M2.accept();
  M2.print();

  Matrix sum = M1.add(M2);
  cout << "addition is " << endl;
  sum.print();

  Matrix sub = M1.subtract(M2);
  cout << "subtraction is " << endl;
  sub.print();

  Matrix mul = M1.multiply(M2);
  cout << "Multiplication is " << endl;
  mul.print();

  cout << "transpose is " << endl;
  Matrix tran = M1.transpose();
  tran.print();

  return 0;
}