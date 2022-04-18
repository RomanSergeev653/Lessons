#include "funcs.h"

bool input_cf()
{
	string buff("");
	
	while (true)
	{
		cout << "Выберите тип ввода данных. 0 - Консоль, 1 - Файл\n";
		cin >> buff;

		if (buff != "0" && buff != "1")
		{
			system("cls");
			cout << "Неверные вводные данные, попробуйте снова...\n";
			continue;
		}
		break;
	}

	return stoi(buff);
}

bool output_cf()
{
	string buff("");

	while (true)
	{
		cout << "Выберите тип вывода данных. 0 - Консоль, 1 - Файл\n";
		cin >> buff;

		if (buff != "0" && buff != "1")
		{
			system("cls");
			cout << "Неверные вводные данные, попробуйте снова...\n";
			continue;
		}
		break;
	}

	return stoi(buff);
}

int cin_natural(string name)
{
	bool check;
	string buff = "";

	while (true)
	{
		check = false;
		cout << "Введите переменную " << name << ": ";
		cin >> buff;

		for (int i = 0; i < buff.length(); i++)
		{
			if (buff[i] < 48 || buff[i] > 57 || buff == "0")
			{
				system("cls");
				cout << buff << " - не является натуральным числом\n";
				check = true;
				break;
			}
		}
		if (check) continue;

		return stoi(buff);
	}
}

float cin_float(string name)
{
	string buff = "";
	float f;

	while (true)
	{
		if (name.length() > 0)
		{
			cout << "Введите переменную " << name << ": ";
		}
		cin >> buff;

		try
		{
			f = stof(buff);
		}
		catch (invalid_argument e)
		{
			system("cls");
			cout << "Введёное значение не является действительным числом\n";
			continue;
		}
		return f;
	}
}
