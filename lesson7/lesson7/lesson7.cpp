#include "funcs.h"

int main()
{
    setlocale(LC_ALL, "RUS");

    MyByte A(cin_longlong("A"));
    cout << "A = ";
    A.show();
    Vbool B = input_byte();
    int pos = cin_int("pos");

    A.change_byte(B, pos);

    A.show();
}