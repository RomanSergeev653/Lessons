#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void analiz(string S, int& check, int& zap, int& tire, int& vv);
void f_vivod(string filename, int check, int zap, int tire, int vv);
void c_vivod(int check, int zap, int tire, int vv);
bool input_cf();
bool output_cf();
int cin_natural(string name = "");
float cin_float(string name = "");