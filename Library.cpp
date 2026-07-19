#include "Library.h"
#include<algorithm>
#include<fstream>
#include<iostream>
void Library::add_book(std::string title,std::string author, const int year)
{
	vector_.emplace_back(std::move(title), std::move(author), year);
}

bool Library::delete_book(std::string& title)
{
	const auto it = std::erase_if(vector_ , [&title](const Book& b) {return b.get_title() == title; });
	return it;
}

Book* Library::find_book(std::string& title)
{
	const auto it = std::ranges::find_if(vector_, [&title](const Book& b) {return b.get_title() == title; });
	if (it != vector_.end())
	{
		return &(*it);
	}
	return nullptr;
}


void Library::sort_books()
{
	std::ranges::sort(vector_, {}, &Book::get_title);
}

bool Library::save_to_file(const std::string& filename) const
{
	std::ofstream file(filename);
	if (!file)
	{
		return false;
	}
	for (const auto& x : books)
	{
		file << x.get_title() << "\n" << x.get_author() << "\n" << x.get_year();
	}
	return true;
}
bool Library::load_from_file(const std::string& filename)
{
	std::ifstream file(filename);
	if (!file)
	{
		return false;
	}
	books.clear();
	std::string title;
	std::string author;
	int year;
	while (std::getline(file, title))
	{
		std::getline(file, author);
		file >> year;
		file.ignore();
		books.emplace_back(title, author, year);
	}
	return true;

}

void Library::display() const
{
	for (const auto& x : vector_)
	{
		x.display();
	}
}
