#include "funcs.h"

Node::Node(string FIO = "", string Work_position = "", string Adress = "")
{
	this->FIO = FIO;
	this->Work_position = Work_position;
	this->Adress = Adress;

	this->next = 0;
	this->prev = 0;
}

string Node::get_FIO()
{
	return FIO;
}
string Node::get_Work_position()
{
	return Work_position;
}
string Node::get_Adress()
{
	return Adress;
}

void Node::set_FIO(string FIO)
{
	this->FIO = FIO;
}
void Node::set_Work_position(string Work_position)
{
	this->Work_position = Work_position;
}
void Node::set_Adress(string Adress)
{
	this->Adress = Adress;
}

void Node::show()
{
	cout << FIO << "\t" << Work_position << "\t" << Adress << endl;
}

void Node::reset()
{
	FIO = "";
	Work_position = "";
	Adress = "";
}

string Node::save()
{
	cout << "Ёлемент " << FIO << "... удалЄн и возвращЄн в кучу\n";
	return FIO + "; " + Work_position + "; " + Adress;
}



Node** List::push(Node** A, int count, Node* new_element)
{
	Node** B = new Node * [count + 1];//массив на один элемнт больше

	for (size_t i = 0; i < count; i++)//копируем старый массив
	{
		B[i] = A[i];
	}
	B[count] = new_element;//добавл€ем в конец новый элемент

	return B;//возвращаем новый массив
}

void List::push_node(Node* N)
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

void List::insert_node(Node* N, int Number)
{
	Node* C = first;

	if (Number == 0)// дл€ начала 
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
			cout << "»ндекс " << Number << " не существует";
			break;
		}
		if (i == Number)
		{
			N->next = C;
			C->prev->next = N;
			N->prev = C->prev;
			C->prev = N;
		}
		if (i + 1 == Number && C == last)//дл€ конца
		{
			return push_node(N);
		}

		C = C->next;
	}
}

void List::Swap_el(int N1, int N2)
{
	if (N1 > N2) swap(N1, N2);

	Node* Ptr2 = pop(N2);
	Node* Ptr1 = pop(N1);

	insert_node(Ptr2, N1);
	insert_node(Ptr1, N2);
}

List::List()
{
	first = 0;
	last = 0;
}

bool List::is_empty()
{
	return first == 0;
}

void List::push_back(string FIO, string Work_position, string Adress)
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

Node** List::find_Work_position(string W)
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
Node** List::find_FIO(string W)
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
Node** List::find_Adress(string W)
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

void List::show()
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
void List::rshow()
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

void List::reset()
{
	Node* N = first;

	while (N != 0)
	{
		N->reset();

		N = N->next;
	}
}

void List::insert(int Number, string FIO, string Work_position, string Adress)
{
	Node* N = new Node(FIO, Work_position, Adress);
	Node* C = first;

	if (Number == 0)// дл€ начала 
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
			cout << "»ндекс " << Number << " не существует";
			break;
		}

		if (i == Number)
		{
			if (C == last)//дл€ конца
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

Node* List::pop(int Number)//”читывать начало и конец списка
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
			cout << "»ндекс " << Number << " не существует";
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

void List::Sort_Work_position()
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
void List::Sort_FIO()
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
void List::Sort_Adress()
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

void List::load_List(string file_name)
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

void List::Change(int Number, string FIO, string Work_position, string Adress)
{
	Node* C = first;

	for (size_t i = 0; i <= Number; i++)
	{
		if (C == 0)
		{
			cout << "»ндекс " << Number << " не существует";
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

void List::Save(string filename)
{
	ofstream file(filename, ios_base::trunc);
	string buff;
	Node* C = first;

	while (C != 0)
	{
		buff = C->save();
		file << buff;

		if (C->next != 0)
		{
			file << endl;
		}

		C = C->next;
		//pop(0);
	}

	file.close();
}