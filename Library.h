#pragma once
#include"Book.h"
#include<vector>
class Library
{
	std::vector<Book> books_;
	

public:
	void add_book(const std::string& title, const std::string& author, const int year);
	bool delete_book(const std::string& title);
	void sort_books();
	Book* find_book(const std::string& title);
	[[nodiscard]]
	bool save_to_file()const;
	bool load_from_file();
	void display()const;
};

