#include "funcs.h"

int main() {
    setlocale(LC_ALL, "rus");

    string digitals[10]; // объявление массива на 10 яйчеек
    string buff = ""; // объявление места для проверки слова
    string sortirovka = "";

    cout << "������� 5 ���������� ���� � �� ������� (����� ������ ���� ����� �����) " << endl;
    
    for (int i = 0; i < 10; i++)//input 
    {
        cin >> buff;
        if (is_word(buff))//check
        {
            digitals[i] = buff;
        }
        else
        {
            string p;
            system("cls");
            cout << "�������� ���� ������, ������ ��������� �������? ��(1) ��� ���(0)";
            cin >> p;
            
            if ((p == "0") || (p == "1"))
            {
                if (p == "1")
                {
                    i--;
                    continue;
                }
                else
                {
                    return 0;
                }
            }
        }
    }

    for (int j = 0; j < 9; j++)// sorting
    {
        if (digitals[j] > digitals[j + 1])
        {
            string b = digitals[j]; // ������� �������������� ����������
            digitals[j] = digitals[j + 1]; // ������ �������
            digitals[j + 1] = b; // �������� ���������
        }
    }

    cout << "������ � ��������������� ����: ";

    for (int i = 0; i < 10; i++)// output 
    {
        cout << digitals[i] << " "; // ������� �������� �������
    }
    system("pause");
    return 0;
}