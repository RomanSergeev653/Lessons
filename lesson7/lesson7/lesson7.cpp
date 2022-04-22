#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

typedef vector<bool> Vbool;

Vbool itob(int A)
{
    Vbool B;
    int step = log2(A);
    
    for (; step >= 0; step--)
    {
        if ((A - pow(2, step)) >= 0)
        {
            B.push_back(1);
            A -= pow(2, step);
        }
        else
        {
            B.push_back(0);
        }
    }

    return B;
}

void show(Vbool B)
{
    for (int i = 0; i < B.size(); i++)
    {
        cout << B[i];
    }
}

Vbool change_byte(Vbool A, Vbool newbyte, int n)
{
    for (int i = 0; i < 8; i++)
    {
        //A[n+i] - обращение
        //if n+i > A.size()
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    Vbool B;
    
    //input byte
    while (true)
    {
        string buff = "";
        cout << "Введите байт: ";
        cin >> buff;

        if (buff.size() != 8)
        {
            system("cls");
            cout << "wrong input\n";
            continue;
        }

        for (int i = 0; i < 8; i++)
        {
            if ((buff[i] != '0') && (buff[i] != '1'))
            {
                system("cls");
                cout << "wrong input\n";
                buff = "";//indetefy
                break;
            }
        }

        if (buff == "") continue;

        for (int i = 0; i < 8; i++)
        {
            if (buff[i] == '1') B.push_back(1);
            else                B.push_back(0);
        }

        break;
    }

    
    

    
    
}