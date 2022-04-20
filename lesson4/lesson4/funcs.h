#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class lesson
{
private:
	int check{ 0 };
	int zap{ 0 };
	int tire{ 0 };
	int vv{ 0 };
public:

	bool cf;
	bool cf_1;

	string S{ "" };
	string filename{ "solution.txt" };

	void analiz();
	void vivod();
	bool input_cf();
	bool output_cf();
	int cin_natural(string name = "");
	float cin_float(string name = "");
};

