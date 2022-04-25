#include "funcs.h"

int main()
{
    setlocale(LC_ALL, "RUS");
    
    Vbool A = itob( cin_int("A") );
    cout << "A = ";
    show(A);
    Vbool B = input_byte();
    int pos = cin_int("pos");

    A = change_byte(A, B, pos);

    show(A);
}