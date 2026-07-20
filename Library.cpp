#include "Library.h"
#include<algorithm>
#include<fstream>
#include<iostream>

#include "Config.h"

void Library::add_book(const std::string& title,const std::string& author, const int year)
{
	books_.emplace_back(title, author, year);
}
[[nodiscard]]
bool Library::delete_book(const	std::string& title)
{
	const auto it = std::erase_if(books_ , [&title](const Book& b) {return b.get_title() == title; });
	return it;
}
[[nodiscard]]
Book* Library::find_book(const std::string& title)
{
	const auto it = std::ranges::find_if(books_, [&title](const Book& b) {return b.get_title() == title; });
	if (it != books_.end())
	{
		return &(*it);
	}
	return nullptr;
}


void Library::sort_books()
{
	std::ranges::sort(books_, {}, &Book::get_title);
}
[[nodiscard]]
bool Library::save_to_file() const
{
	std::ofstream file{ (std::string(Config::BOOKS_FILE)) };
	if (!file)
	{
		return false;
	}
	for (const auto& x : books_)
	{
		file << x.get_title() << "\n" << x.get_author() << "\n" << x.get_year() << "\n";
	}
	return true;
}
[[nodiscard]]
bool Library::load_from_file()
{
	std::ifstream file{(std::string(Config::BOOKS_FILE)) };

	if (!file)
	{
		return false;
	}

	books_.clear();

	std::string title;
	std::string author;
	int year;


	while (std::getline(file, title))
	{
		std::getline(file, author);

		file >> year;
		file.ignore();

		books_.emplace_back(title, author, year);
	}

	return true;
}

void Library::display() const
{
	for (const auto& x : books_)
	{
		x.display();
	}
}
