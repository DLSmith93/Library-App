#include "wishlist.h"
using namespace std;

//Global Variables//



int main()
{
    book_info book_temp; //temperary placeholder for user input of book information
    int menu_selection = 0;
    wish list;

    do
    {

        cout << "Please make a selection from the menu below \n";
	    cout << "------------------------------------------- \n";
	    cout << "1: Book Wishlist \n";
	    //cout << "2: Library \n";
	    cout << "3: Exit Program \n";
	    cout << "------------------------------------------- \n";
	    cout << "Enter Here: ";
	    cin >> menu_selection; cin.ignore(100, '\n');
        system("clear"); /*system("cls");*/

        if(menu_selection == 1)
	    add_wishlist(book_temp);
        if(menu_selection == 2)
	    add_library(book_temp);

    } while(menu_selection != 3) ;

     return 0;
}

void search(char search_term[])
{
    int selection = 0;

    cout << "How would you like to search? \n";
    cout << "----------------------------- \n";
    cout << "1: Title \n";
    cout << "2: Author \n";
    cout << "3: Genre \n";
    cout << "----------------------------- \n";
    cout << "Enter Here: ";
    cin >> selection; cin.ignore(100, '\n');

    if(selection == 1)
    {
        cout << "Enter the title of the book here: ";
        cin.get(search_term, SIZE); cin.ignore(100, '\n');
        cout << endl;
    }
    if(selection == 2)
    {
        cout << "Enter the the authors name (last, first)  here: ";
        cin.get(search_term, SIZE); cin.ignore(100, '\n');
        cout << endl;
    }
    if(selection == 3)
    {
        cout << "Enter the genre here: ";
        cin.get(search_term, SIZE); cin.ignore(100, '\n');
        cout << endl;
    }

}

void add_book(book_info &book_temp)
{
    cout << "Enter the title of the book here: ";
    cin.get(book_temp.title, SIZE); cin.ignore(100, '\n');
    cout << endl;

    cout << "Enter the name of the author (last, first)  here: ";
    cin.get(book_temp.author, SIZE); cin.ignore(100, '\n');
    cout << endl;

    cout << "Enter the genre here: ";
    cin.get(book_temp.genre, SIZE); cin.ignore(100, '\n');
    cout << endl;

    cout << "Enter the number of pages here: ";
    cin >> book_temp.pages; cin.ignore(100, '\n');

}
void add_wishlist(book_info &book_temp)
{
    int menu_selection = 0;
    wish list;
    char search_term[SIZE];
    list.load_list(book_temp);
    do
    {
    	cout << "Please make a selction from the menu below \n";
	    cout << "------------------------------------------ \n";
	    cout << "1: Add a book to wishlist \n";
	    cout << "2: Search wishlist \n";
        cout << "3: Remove a book from wishlist \n";
	    cout << "4: Dislpay wishlist \n";
        cout << "5: Return to main menu \n";
	    cout << "------------------------------------------ \n";
        cout << endl;
        cout << "Enter Here: ";
	    cin >> menu_selection; cin.ignore(100, '\n');
	    system("clear"); system("cls");

        if(menu_selection == 1)
	    {
	        add_book(book_temp);
	        list.add_list(book_temp);
	    }
        if(menu_selection == 2)
	    {
	        search(search_term);
            cout << "Here are the books/book you searched for \n";
	        list.search_list(book_temp, search_term);
        }
        if(menu_selection == 4)
	        list.display_all();

    } while(menu_selection != 5);

}

void add_library(book_info &book_temp)
{
    int menu_selection = 0;
    char search_term[SIZE];

    do
    {
        cout << "Please make a selection from the menu below \n";
	    cout << "------------------------------------------- \n";
        cout << "1: Add a book to your library \n";
	    cout << "2: Search library \n";
        cout << "3: Remove a book from your library \n";
        cout << "4: Displasy library \n";
        cout << "5: Return to main menu \n";
	    cout << "------------------------------------------- \n";
	    cout << endl;
        cout << "Enter Here: ";
        cin >> menu_selection; cin.ignore(100, '\n');
        system("clear"); system("cls");

        if(menu_selection == 1)
            add_book(book_temp);
        if(menu_selection == 2)
	        search(search_term);

    } while(menu_selection != 5);

}
