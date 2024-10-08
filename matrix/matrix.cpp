#include<iostream>
using namespace std;

template <class T>
class Matrix
{
    T** ptr;  // двум. масив
    int str;  // строки
    int st;   // столбцы

public:
    Matrix()
    {
        ptr = nullptr;
        str = st = 0;
    }

    Matrix(int _str, int _st)
    {
        str = _str;
        st = _st;
        ptr = new T * [str];
        for (int i = 0; i < str; i++)
        {
            ptr[i] = new T[st]{ 0 }; // иниц. нулями
        }
    }

    Matrix(const Matrix& obj)
    {
        str = obj.str;
        st = obj.st;
        ptr = new T * [str];
        for (int i = 0; i < str; i++)
        {
            ptr[i] = new T[st];
            for (int j = 0; j < st; j++)
            {
                ptr[i][j] = obj.ptr[i][j];
            }
        }
    }

    void Index(int x, int y) const
    {
        if (x >= 0 && x < str && y >= 0 && y < st)
        {
            cout << "Значение по индексу (" << x << ", " << y << ") равно " << ptr[i][j] << endl;
        }
        else
        {
            cout << "Неверные индексы!\n";
        }
    }

    // заполнение
    void Input(const T inputValues[][3])
    {
        for (int i = 0; i < str; i++)
        {
            for (int j = 0; j < st; j++)
            {
                ptr[i][j] = inputValues[i][j];
            }
        }
    }

    void Print() const
    {
        cout << "Matrix: \n";
        for (int i = 0; i < str; i++)
        {
            for (int j = 0; j < st; j++)
            {
                cout << ptr[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    void Sum(const Matrix& obj) const
    {
        if (str == obj.str && st == obj.st)
        {
            Matrix rez(str, st);
            for (int i = 0; i < str; i++)
            {
                for (int j = 0; j < st; j++)
                {
                    rez.ptr[i][j] = ptr[i][j] + obj.ptr[i][j];
                }
            }
            cout << "Сумма: \n";

            rez.Print();
        }
        else
        {
            cout << "Недопустимые размеры матрицы для суммы!\n";
        }
    }

    void Mult(const Matrix& obj) const
    {
        if (st == obj.str)
        {
            Matrix rez(str, obj.st);
            for (int i = 0; i < str; i++)
            {
                for (int j = 0; j < obj.st; j++)
                {
                    for (int k = 0; k < st; k++)
                    {
                        rez.ptr[i][j] += ptr[i][k] * obj.ptr[k][j];
                    }
                }
            }
            cout << "Умножение: \n";
            rez.Print();
        }
        else
        {
            cout << "Недопустимые размеры матрицы для умножения!\n";
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < str; i++)
        {
            delete[] ptr[i];
        }
        delete[] ptr;

        cout << "детсруктор\n";
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    int values1[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int values2[3][3] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };
    int values3[3][3] = { {2, 4, 6}, {8, 10, 12}, {14, 16, 18} };

    Matrix<int> obj1(3, 3);
    Matrix<int> obj2(3, 3);
    Matrix<int> obj3(3, 3);
    Matrix<int> obj4(3, 3);
    Matrix<int> obj5 = obj4;

    obj1.Input(values1);
    obj2.Input(values2);
    obj3.Input(values3);

    obj1.Print();
    obj2.Print();
    obj3.Print();
    obj4.Print();
    obj5.Print();

    obj1.Sum(obj3);
    obj2.Mult(obj5);

    return 0;
}
