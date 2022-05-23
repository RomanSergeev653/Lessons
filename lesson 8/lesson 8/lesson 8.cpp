#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Node
{
private:
	string FIO;
	string Work_position;
	string Adress;

public:
	Node* next;
	Node* prev;

	Node(string FIO = "", string Work_position = "", string Adress = "")
	{
		this->FIO = FIO;
		this->Work_position = Work_position;
		this->Adress = Adress;

		this->next = 0;
		this->prev = 0;
	}

	string get_FIO()
	{
		return FIO;
	}
	string get_Work_position()
	{
		return Work_position;
	}
	string get_Adress()
	{
		return Adress;
	}

	void set_FIO(string FIO)
	{
		this->FIO = FIO;
	}
	void set_Work_position(string Work_position)
	{
		this->Work_position = Work_position;
	}
	void set_Adress(string Adress)
	{
		this->Adress = Adress;
	}

	void show()
	{
		cout << FIO << "\t" << Work_position << "\t" << Adress << endl;
	}

	void reset()
	{
		FIO = "";
		Work_position = "";
		Adress = "";
	}

	string save()
	{
		//этот элемент удалён cout
		return FIO + "; " + Work_position + "; " + Adress;
	}
};

class List
{
private:
	Node* first;
	Node* last;

	Node** push(Node** A, int count, Node* new_element)
	{
		Node** B = new Node * [count + 1];//массив на один элемнт больше

		for (size_t i = 0; i < count; i++)//копируем старый массив
		{
			B[i] = A[i];
		}
		B[count] = new_element;//добавляем в конец новый элемент

		return B;//возвращаем новый массив
	}

	void push_node(Node* N)
	{
		if (is_empty())
		{
			first = N;
			last = N;
		}
		else
		{
			last->next = N;
			N->prev = last;
			last = N;
		}
	}

	void insert_node(Node* N, int Number)
	{
		Node* C = first;

		if (Number == 0)// для начала 
		{
			N->next = first;
			first->prev = N;
			first = N;
			return;
		}

		for (size_t i = 0; i <= Number; i++)
		{
			if (C == 0)
			{
				cout << "Индекс " << Number << " не существует";
				break;
			}
			if (i == Number)
			{
				N->next = C;
				C->prev->next = N;
				N->prev = C->prev;
				C->prev = N;
			}
			if (i + 1 == Number && C == last)//для конца
			{
				return push_node(N);
			}

			C = C->next;
		}
	}

	void Swap_el(int N1, int N2)
	{
		if (N1 > N2) swap(N1, N2);

		Node* Ptr2 = pop(N2);
		Node* Ptr1 = pop(N1);

		insert_node(Ptr2, N1);
		insert_node(Ptr1, N2);
	}

public:
	List()
	{
		first = 0;
		last = 0;
	}

	bool is_empty()
	{
		return first == 0;
	}

	void push_back(string FIO, string Work_position, string Adress)
	{
		Node* N = new Node(FIO, Work_position, Adress);

		if (is_empty())
		{
			first = N;
			last = N;
		}
		else
		{
			last->next = N;
			N->prev = last;
			last = N;
		}
	}

	Node** find_Work_position(string W)
	{
		Node* N = first;
		Node** Arr = 0;
		int count = 0;

		while (N != 0)
		{
			if (N->get_Work_position() == W)
			{
				Arr = push(Arr, count, N);
				count++;
				Arr[count - 1]->show();
			}

			N = N->next;
		}

		return Arr;
	}

	Node** find_FIO(string W)
	{
		Node* N = first;
		Node** Arr = 0;
		int count = 0;

		while (N != 0)
		{
			if (N->get_FIO() == W)
			{
				Arr = push(Arr, count, N);
				count++;
				Arr[count - 1]->show();
			}

			N = N->next;
		}

		return Arr;
	}

	Node** find_Adress(string W)
	{
		Node* N = first;
		Node** Arr = 0;
		int count = 0;

		while (N != 0)
		{
			if (N->get_Adress() == W)
			{
				Arr = push(Arr, count, N);
				count++;
				Arr[count - 1]->show();
			}

			N = N->next;
		}

		return Arr;
	}

	void show()
	{
		Node* N = first;
		int i = 1;

		while (N != 0)
		{
			cout << i << ")";
			N->show();

			N = N->next;
			i++;
		}
		cout << endl;
	}

	void rshow()
	{
		Node* N = last;
		int i = 1;

		while (N != 0)
		{
			cout << i << ")";
			N->show();

			N = N->prev;
			i++;
		}
		cout << endl;
	}

	void reset()
	{
		Node* N = first;

		while (N != 0)
		{
			N->reset();

			N = N->next;
		}
	}

	void insert(int Number, string FIO, string Work_position, string Adress)
	{
		Node* N = new Node(FIO, Work_position, Adress);
		Node* C = first;

		if (Number == 0)// для начала 
		{
			N->next = first;
			first->prev = N;
			first = N;
			return;
		}

		for (size_t i = 0; i <= Number; i++)
		{
			if (C == 0)
			{
				cout << "Индекс " << Number << " не существует";
				break;
			}

			if (i == Number)
			{
				if (C == last)//для конца
				{
					return push_node(N);
				}

				N->next = C;
				C->prev->next = N;
				N->prev = C->prev;
				C->prev = N;
			}

			C = C->next;
		}
	}

	Node* pop(int Number)//Учитывать начало и конец списка
	{
		Node* C = first;

		if (Number == 0)
		{
			first->next->prev = 0;
			first = first->next;

			C->next = 0;
			return C;

		}

		for (size_t i = 0; i <= Number; i++)
		{
			if (C == 0)
			{
				cout << "Индекс " << Number << " не существует";
				break;
			}
			if (i == Number)
			{
				if (C == last)
				{
					C->prev->next = 0;
					last = C->prev;
					C->prev = 0;

					return C;
				}

				C->prev->next = C->next;
				C->next->prev = C->prev;

				C->next = 0;
				C->prev = 0;

				return C;
			}

			C = C->next;
		}
	}

	void Sort_Work_position()
	{
		Node* C = first;

		for (size_t i = 0; C != last; i++)
		{
			Node* C2 = C->next;
			for (size_t j = i + 1; C2 != 0; j++)
			{
				if (C->get_Work_position() > C2->get_Work_position())
				{
					Swap_el(i, j);
					swap(C, C2);
				}
				C2 = C2->next;
			}
			C = C->next;
		}
	}

	void Sort_FIO()
	{
		Node* C = first;

		for (size_t i = 0; C != last; i++)
		{
			Node* C2 = C->next;
			for (size_t j = i + 1; C2 != 0; j++)
			{
				if (C->get_FIO() > C2->get_FIO())
				{
					Swap_el(i, j);
					swap(C, C2);
				}
				C2 = C2->next;
			}
			C = C->next;
		}
	}

	void Sort_Adress()
	{
		Node* C = first;

		for (size_t i = 0; C != last; i++)
		{
			Node* C2 = C->next;
			for (size_t j = i + 1; C2 != 0; j++)
			{
				if (C->get_Adress() > C2->get_Adress())
				{
					Swap_el(i, j);
					swap(C, C2);
				}
				C2 = C2->next;
			}
			C = C->next;
		}
	}

	void load_List(string file_name)
	{
		ifstream file(file_name);
		string* str;
		string buff;
		int N = 0;

		while (!file.eof())
		{
			getline(file, buff);
			N++;
		}

		file.seekg(0, ios::beg);

		str = new string[N];

		for (size_t i = 0; i < N; i++)
		{
			getline(file, str[i]);

			string FIO;
			string Work_position;
			string Adress;

			FIO = str[i].substr(0, str[i].find("; "));
			str[i].erase(0, str[i].find("; ") + 2);

			Work_position = str[i].substr(0, str[i].find("; "));
			str[i].erase(0, str[i].find("; ") + 2);

			Adress = str[i];

			push_back(FIO, Work_position, Adress);
		}

		file.close();

		//ofstream F(file_name, ios_base::trunc);
		//F.close();

		return;
	}

	void Change(int Number, string FIO, string Work_position, string Adress)
	{
		Node* C = first;

		for (size_t i = 0; i <= Number; i++)
		{
			if (C == 0)
			{
				cout << "Индекс " << Number << " не существует";
				break;
			}

			if (i == Number)
			{
				C->set_FIO(FIO);
				C->set_Work_position(Work_position);
				C->set_Adress(Adress);

				return;
			}

			C = C->next;
		}
	}

	void Save(string filename)
	{
		ofstream file(filename, ios_base::trunc);
		string buff;
		Node* C = first;

		while (C != 0)
		{
			buff = C->save();
			file << buff << endl;
		}

		
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	system("chcp 1251");
	system("cls");

	List A;
	A.load_List("data.txt");

	int switch_on;
	bool T = true;

	cout << "1) Добавить новый элемент\n";
	cout << "2) Печать в прямом порядке\n";
	cout << "3) Печать в обратном порядке\n";
	cout << "4) Поиск\n";
	cout << "5) Сортировка\n";
	cout << "6) Изменение\n";
	cout << "7) Удаление\n";
	cout << "8) Сброс\n";
	cout << "9) Выход\n";

	cin >> switch_on;
	switch (switch_on)
	{
	case 1:
	{
		int number;
		string FIO;
		string Work_position;
		string Adress;

		cout << "Number: ";
		cin >> number;
		cin.ignore();
		cout << "FIO: ";
		getline(cin, FIO);
		cout << "Work position: ";
		getline(cin, Work_position);
		cout << "Adress: ";
		getline(cin, Adress);

		A.insert(number - 1, FIO, Work_position, Adress);
		A.show();
		break;
	}
	case 2:
	{
		cout << "Печать в прямом порядке\n";
		A.show();
		break;
	}
	case 3:
	{
		cout << "Печать в обратном порядке\n";
		A.rshow();
		break;
	}
	case 4:
	{
		cout << "1) Именам\n2) Должности\n3) Адресам\n";
		int S;
		cin >> S;
		cin.ignore();
		switch (S)
		{
		case 1:
		{
			string W;
			cout << "Введите имя для поиска: ";
			getline(cin, W);
			cout << A.find_FIO(W) << endl;

			break;
		}
		case 2:
		{
			string W;
			cout << "Введите должность для поиска: ";
			getline(cin, W);
			cout << A.find_Work_position(W) << endl;

			break;
		}
		case 3:
		{
			string W;
			cout << "Введите адрес для поиска: ";
			getline(cin, W);
			cout << A.find_Adress(W) << endl;

			break;
		}
		default:
			break;
		}

		break;
	}
	case 5:
	{
		cout << "1) Именам\n2) Должности\n3) Адресам\n";
		int S;
		cin >> S;
		switch (S)
		{
		case 1:
		{
			A.Sort_FIO();
			A.show();

			break;
		}
		case 2:
		{
			A.Sort_Work_position();
			A.show();

			break;
		}
		case 3:
		{
			A.Sort_Adress();
			A.show();

			break;
		}
		default:
			break;
		}

		break;
	}
	case 6:
	{
		int Number;
		string FIO;
		string Work_position;
		string Adress;

		cout << "Введите номер изменяемого элемента\n";
		cin >> Number;

		cin.ignore();
		cout << "FIO: ";
		getline(cin, FIO);
		cout << "Work position: ";
		getline(cin, Work_position);
		cout << "Adress: ";
		getline(cin, Adress);

		A.Change(Number - 1, FIO, Work_position, Adress);
		A.show();
		break;
	}
	case 7:
	{
		int number;
		cout << "Введите номер для удаления: ";
		cin >> number;
		A.pop(number - 1);
		A.show();

		break;
	}
	case 8:
	{
		A.reset();
		A.show();

		break;
	}
	case 9:
	{
		//сохранить изменения?
		return 0;
	}
	default:
		break;
	}
}