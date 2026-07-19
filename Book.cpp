#include "Book.h"
#include<iostream>
Book::Book() : title_("unknown"), author_("unknown"), year_(0)
{
	

}

Book::Book(std::string title, std::string author, const int year) : title_(std::move(title)), author_(std::move(author)), year_(year)
{
	
}

std::string Book::get_author() const
{
	return author_;
}

void Book::get_book(std::string& title, std::string& author,const int year)
{
	title_ = std::move(title);
	author_ = std::move(author);
	year_ = year;
}

std::string Book::get_title() const
{
	return title_;
}

int Book::get_year() const
{
	return year_;
}

void Book::display()const
{
	std::cout << "\nTitle: " << title_;
	std::cout << "\nAuthor: " << author_;
	std::cout << "\nYear: " << year_;
}
