#include "funcs.h"

MyByte::MyByte()
{
    bits = { 0,0,0,0,0,0,0,0 };
    pl_min = 1;
}

MyByte::MyByte(long long A)
{
    if (A < 0)
    {
        pl_min = 0;
        A *= -1;
    }
    else pl_min = 1;

    bits = itob(A);
}

Vbool MyByte::itob(long long A)
{
    Vbool B;
    if (A == 0) B.push_back(0);

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

    while (B.size() % 8 != 0)
    {
        B = push_forvard(B, 0);
    }

    return B;
}

Vbool push_forvard(Vbool A, bool b)
{
    Vbool PF;
    PF.push_back(b);

    for (int i = 0; i < A.size(); i++)
    {
        PF.push_back(A[i]);
    }

    return PF;
}

void MyByte::show()
{
    if (!pl_min) cout << "-";//minus 

    for (int i = 0; i < bits.size(); i++)
    {
        cout << bits[i];

        if ((bits.size() - (i + 1)) % 4 == 0)
        {
            cout << " ";
        }
    }
    cout << endl;
}

Vbool pop_forward(Vbool A)
{
    Vbool B;
    for (int i = 1; i < A.size(); i++)
    {
        B.push_back(A[i]);
    }

    return B;
}

Vbool reverse(Vbool A)
{
    Vbool B;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        B.push_back(A[i]);
    }

    return B;
}

void MyByte::change_byte(Vbool newbyte, int n)
{
    bool rev_check = false;

    for (int i = 0; i < 8; i++)
    {
        if (bits.size() - 1 - n + i >= bits.size()) // если биты не помещаются
        {
            if (!rev_check)
            {
                rev_check = true;
                newbyte = reverse(newbyte);
            }

            bits = push_forvard(bits, newbyte[0]); // то записываем их в начало
            newbyte = pop_forward(newbyte);
            continue;
        }
        bits[bits.size() - 1 - n + i] = newbyte[0];
        newbyte = pop_forward(newbyte);
    }

    while (bits.size() % 8 != 0)
    {
        bits = push_forvard(bits, 0);
    }
}

Vbool input_byte()
{
    Vbool B;

    while (true)
    {
        string buff = "";
        cout << "Ввведите байт: ";
        cin >> buff;

        if (buff.size() != 8)
        {
            system("cls");
            cout << "Неверное значение, повторите попытку... \n";
            continue;
        }

        for (int i = 0; i < 8; i++)
        {
            if ((buff[i] != '0') && (buff[i] != '1'))
            {
                system("cls");
                cout << "Неверное значение, повторите попытку... \n";
                buff.clear(); // идентификация
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

long long cin_longlong(string name)
{
    string buff = "";
    long long f;

    while (true)
    {
        if (name.length() > 0)
        {
            cout << "Введите целочисленную переменную " << name << ": ";
        }
        cin >> buff;

        try
        {
            f = stoll(buff);
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