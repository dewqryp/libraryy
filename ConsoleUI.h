#pragma once
#include"Library.h"
class ConsoleUI
{
	Library library_;
	void display()const;
	void show_menu()const;
	void add_book();
	void delete_book();
	void sort_books();
	void find_book();
	void save_books()const;
	void load_books();
	int input_year();
public:
	void run();
};

