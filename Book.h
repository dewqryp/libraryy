#pragma once
#include<string>
class Book
{
	std::string title_;
	std::string author_;
	int year_;
public:
	
	void get_book( std::string& title, std::string& author,const int year);
	Book();
	Book(std::string title, std::string author, const int year);
	void display()const;
	[[nodiscard]]
	std::string get_title()const;
	[[nodiscard]]
	std::string get_author()const;
	[[nodiscard]]
	int get_year()const;

};

