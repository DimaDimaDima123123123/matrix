#include<iostream> 
using namespace std;

class Matrix
{
    int** ptr;
    int str;
    int st;
public:
    Matrix(const Matrix& other)
    {
        str = other.str;
        st = other.st;
        ptr = new int* [str];
        for (int i = 0; i < str; i++)
        {
            ptr[i] = new int[st];
            for (int j = 0; j < st; j++)
            {
                ptr[i][j] = other.ptr[i][j];
            }
        }
    }

    Matrix()
    {
        ptr = nullptr;
        str = st = 0;
    }

    Matrix(int _str, int _st)
    {
        str = _str;
        st = _st;
        ptr = new int* [str];
        for (int i = 0; i < str; i++)
        {
            ptr[i] = new int[st] {0};
        }
    }

    void Index(int x, int y)
    {
        for (int i = 0; i < str; i++)
        {
            for (int j = 0; j < st; j++)
            {
                if (x == i && y == j)
                {
                    cout << "Значение по индексу (" << x << ", " << y << ") равно " << ptr[i][j] << endl;
                }
            }
        }
    }

    void Input(int inputValues[3][3])
    {
        for (int i = 0; i < str; i++)
        {
            for (int j = 0; j < st; j++)
            {
                ptr[i][j] = inputValues[i][j];
            }
        }
    }

    void Print()const
    {
        cout << "Матрица: \n";
        for (int i = 0; i < str; i++)
        {
            for (int j = 0; j < st; j++)
            {
                cout << ptr[i][j] << "\t";
            }
            cout << "\n\n";
        }
    }

    void Mult(const Matrix& obj)const
    {
        if (str == obj.st)
        {
            Matrix rez(str, st);

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
    }
    void Sum(const Matrix& obj)const
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
            cout << "Сума: \n";
            rez.Print();
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < str; i++)
        {
            delete[]ptr[i];
        }
        delete[] ptr;
        cout << "деструктор\n";
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    int Values1[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int Values2[3][3] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };
    int Values3[3][3] = { {1, 1, 1}, {2, 2, 2}, {3, 3, 3} };

    Matrix obj1(3, 3);
    Matrix obj2(3, 3);
    Matrix obj3(3, 3);

    Matrix obj4 = obj1;

    obj1.Input(Values1);
    obj2.Input(Values2);
    obj3.Input(Values3);

    obj1.Print();

    obj1.Index(0, 2);

    obj2.Print();

    obj3.Print();

    obj4.Print();

    obj1.Sum(obj3);

    obj1.Mult(obj2);
}