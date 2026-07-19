#pragma once
#include"Book.h"
#include<vector>
class Library
{
	std::vector<Book> vector_;
public:
	void add_book(std::string title, std::string author, const int year);
	bool delete_book(std::string& title);
	void sort_books();
	Book* find_book(std::string& title);
	[[nodiscard]]
	bool save_to_file(const std::string& filename) const;
	bool load_from_file(const std::string& filename);
	void display()const;
};

