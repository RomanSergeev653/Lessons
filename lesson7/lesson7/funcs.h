#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

typedef vector<bool> Vbool;

class MyByte
{
private:
	Vbool bits;
	bool pl_min;

public:
	MyByte();
	MyByte(long long A);
	Vbool itob(long long A);
	void change_byte(Vbool newbyte, int n);
	void show();
};

long long cin_longlong(string name = "");
int cin_int(string name = "");

Vbool push_forvard(Vbool A, bool b);
Vbool input_byte();
Vbool pop_forward(Vbool A);
Vbool reverse(Vbool A);