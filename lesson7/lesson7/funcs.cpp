#include "funcs.h"
//class ZeroOne
//int n;
//Vbool V;


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
    cout << endl;
}//Реализовать красивый вывод 1000 1010 1011 (пробелы)

Vbool push_forvard(Vbool A, bool b)
{
    Vbool PF;
    PF.push_back(b);
    //baaaaaaaaaaaaa
    for (int i = 0; i < A.size(); i++)
    {
        PF.push_back(A[i]);
    }

    return PF;
}

Vbool change_byte(Vbool A, Vbool newbyte, int n)//
{
    for (int i = 0; i < 8; i++)
    {
        if (n + i >= A.size()) //Если биты не помещаются
        {
            A = push_forvard(A, newbyte[i]);// то записываем их в начало
            continue;
        }
        A[n + i] = newbyte[i];
    }

    return A;
}

Vbool input_byte()
{
    Vbool B;

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

        return B;
    }
}

int cin_int(string name)
{
    string buff = "";
    int f;

    while (true)
    {
        if (name.length() > 0)
        {
            cout << "Введите целочисленную переменную " << name << ": ";
        }
        cin >> buff;

        try
        {
            f = stoi(buff);
        }
        catch (invalid_argument e)
        {
            system("cls");
            cout << "Введёное значение не является целым числом\n";
            continue;
        }
        return f;
    }
}
