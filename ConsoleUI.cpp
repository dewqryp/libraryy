#include "ConsoleUI.h"
#include<iostream>



void ConsoleUI::show_menu()const
{
    std::cout << "\n===== Library =====\n";
    std::cout << "1. Add book\n";
    std::cout << "2. Delete book\n";
    std::cout << "3. Find book\n";
    std::cout << "4. Sort books\n";
    std::cout << "5. Display books\n";
    std::cout << "6. Load books\n";
    std::cout << "7. Save books.\n";
    std::cout << "0. Exit\n";
    std::cout << "Choice: ";
}

void ConsoleUI::add_book()
{
    std::string title;
    std::string author;
    

    std::cout << "Title: ";
    std::getline(std::cin >> std::ws, title);

    std::cout << "Author: ";
    std::getline(std::cin, author);
    std::cout << "Year: ";
    int year = input_year();
    

    library_.add_book(title, author, year);

    std::cout << "\nBook added.\n";
}

void ConsoleUI::delete_book()
{
    std::string title;
    std::cout << "\nEnter title: "; std::getline(std::cin >> std::ws, title);
    if (library_.delete_book(title))
    {
        std::cout << "\nDeleted.";
    }
    else
    {
        std::cout << "\nBook was not found.\n";
    }
}

void ConsoleUI::find_book()
{
    std::string title;
    std::cout << "\nEnter title: "; std::getline(std::cin >> std::ws, title);
    const Book* book = library_.find_book(title);
    if (book)
    {
        book->display();

    }
    else
    {
        std::cout << "\nBook was not found.\n";
    }
}

void ConsoleUI::sort_books()
{
    library_.sort_books();
    std::cout << "\nSorted.\n";
}

void ConsoleUI::display() const
{
    library_.display();
}


void ConsoleUI::run()
{
    int choice;

    do
    {
        show_menu();

        if (!(std::cin >> choice))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Invalid input.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            add_book();
            break;

        case 2:
            delete_book();
            break;

        case 3:
            find_book();
            break;

        case 4:
            sort_books();
            break;

        case 5:
            display();
            break;
        case 6:
            load_books();
            break;
        case 7:
            save_books();
            break;

        case 0:
            std::cout << "Goodbye!\n";
            break;

        default:
            std::cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}

void ConsoleUI::load_books()
{
    std::string filename;
    std::cout << "\nEnter filename: ";
    std::getline(std::cin >> std::ws, filename);
    if (library_.load_from_file(filename))
    {
        std::cout << "\nLoaded.\n";
    }
    else
    {
        std::cout << "\nError.\n";
    }
}

void ConsoleUI::save_books()const
{
    std::string filename;
    std::cout << "\nEnter filename: ";
    std::getline(std::cin >> std::ws, filename);
    if (library_.save_to_file(filename))
    {
        std::cout << "\nSaved.\n";
    }
    else
    {
        std::cout << "\nError.\n";
    }
}

int ConsoleUI::input_year()
{
    int year;
    while (true)
    {
        if (!(std::cin >> year))
        {
            std::cout << "Incorrect input. Try again: ";

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (year < 5 || year > 2026)
        {
            std::cout << "Year must be between 5 and 2026. Try again: ";

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        break;
    }
    return year;
}
