#include "funcs.h"

bool is_word(string &str)
{
    for (int i = 0; i < 10; i++)
    {
        if (((str[i] < 91) && (str[i] > 64)) || ((str[i] < 123) && (str[i] > 96)))
        {
            return false;
        }
    }
    return true;
}

//void Big_little(string &name)
//Dog - собака
//Dog - собака