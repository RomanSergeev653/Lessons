#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

typedef vector<bool> Vbool;

void show(Vbool B);
int cin_int(string name = "");
Vbool itob(int A);
Vbool push_forvard(Vbool A, bool b);
Vbool change_byte(Vbool A, Vbool newbyte, int n);
Vbool input_byte();
