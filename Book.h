#pragma once
#include<string>
class Book
{
	std::string title_;
	std::string author_;
	int year_;
public:
	
	
	Book();
	Book(std::string title, std::string author, const int year);
	void display()const;
	[[nodiscard]]
	const std::string& get_title()const;
	[[nodiscard]]
	const std::string& get_author()const;
	[[nodiscard]]
	int get_year()const;

};

