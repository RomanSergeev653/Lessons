#pragma once
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

	Node(string FIO, string Work_position, string Adress);

	string get_FIO();
	string get_Work_position();
	string get_Adress();

	void set_FIO(string FIO);
	void set_Work_position(string Work_position);
	void set_Adress(string Adress);

	void show();

	void reset();

	string save();
};

class List
{
private:
	Node* first;
	Node* last;

	Node** push(Node** A, int count, Node* new_element);

	void push_node(Node* N);

	void insert_node(Node* N, int Number);

	void Swap_el(int N1, int N2);

public:
	List();

	bool is_empty();

	void push_back(string FIO, string Work_position, string Adress);

	Node** find_Work_position(string W);

	Node** find_FIO(string W);

	Node** find_Adress(string W);

	void show();

	void rshow();

	void reset();

	void insert(int Number, string FIO, string Work_position, string Adress);

	Node* pop(int Number);

	void Sort_Work_position();

	void Sort_FIO();

	void Sort_Adress();

	void load_List(string file_name);

	void Change(int Number, string FIO, string Work_position, string Adress);

	void Save(string filename);
};