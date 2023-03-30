#include <iostream>
#include <stdlib.h>
#include <cctype>
#include <cstring>
#include <fstream>
#include <string>

//Constants//
const int SIZE = 100;

//stucts//
struct book_info //temp structure for holding book information from user input
{
    char title[SIZE];
    char author[SIZE];
    int pages;
    char genre[SIZE];
};

struct wishlist
{
    char *title;
    char *author;
    char *genre;
    int pages;
};

struct node
{
    wishlist data;
    node *next;
};

//Client Prototypes//
void add_wishlist(book_info &to_add);
void add_library(book_info &to_add);
void add_book(book_info &to_add);
void search(char search_term[]);

class wish
{
    public:
	   //contructor
	    wish();
	    //decontructor
	    ~wish();
        void load_list(book_info &load);
        //Function for call the needed fucntions for adding to the list
	    void add_list(book_info &to_add);
        //Used to displayt every item that is in the list
        void display_all();
        //Used for searching as determined my the user
	    void search_list(book_info &to_add, char search_term[]);
        //Calls private function for actually deleteing a node and altering the list
        void to_remove(book_info &remove);

    private:
        //Builds list if head is null
	    void build_list(book_info &to_add);
	    //Adds book to the middle or the end of the list
        void add_new(book_info &to_add);
        //Removes a book specified by the user
        void remove_book(book_info &remove);
        //Copies data entered fromt he user into the list
	    void copy_data(book_info &to_add, node *current);
        void copy_current(book_info &to_add, node *temp);
        void save_file();
        void read_file(book_info &load);
        //Head Pointer
        node *head;
};
