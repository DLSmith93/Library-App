#include "wishlist.h"
using namespace std;

/*
  noted so i can keep track of the data structure I am using
//Structs//
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
}; */
wish::wish()
{
    head = NULL;

}
wish::~wish()
{

}
void wish::build_list(book_info &to_add)
{
    node *current;
    if(!head)
    {
        head = new node;
	    copy_data(to_add, current);
        head->next = NULL;
    }
}
void wish::add_list(book_info &to_add)
{
    if(!head)
	   build_list(to_add);
    else
        add_new(to_add);
    save_file();
}

void wish::display_all()
{
    node *current = head;


    while(current)
    {
	    cout << "====================================== \n";
        cout << "Title: " << current->data.title << endl;
        cout << "Author: " << current->data.author << endl;
        cout << "Genre: " << current->data.genre << endl;
        cout << "Pages: " << current->data.pages << endl;
        //cout << "====================================== \n";
        current = current->next;
    }
    cout << "\n";

}
void wish::search_list(book_info &to_add, char search_term[])
{
    node *current = head;

    while(current)
    {
        if(strcmp(search_term, current->data.title) == 0)
        {
	        cout << "======================================= \n";
            cout << "Title: " << current->data.title << endl;
            cout << "Author: " << current->data.author << endl;
            cout << "Genre: " << current->data.genre << endl;
            cout << "Pages: " << current->data.pages << endl;
	        //cout << "======================================= \n";
	    }
        if(strcmp(search_term, current->data.author) == 0)
        {
	        cout << "======================================= \n";
            cout << "Title: " << current->data.title << endl;
            cout << "Author: " << current->data.author << endl;
            cout << "Genre: " << current->data.genre << endl;
            cout << "Pages: " << current->data.pages << endl;
	        //cout << "======================================= \n";
	    }
        if(strcmp(search_term, current->data.genre) == 0)
        {
	        cout << "======================================= \n";
            cout << "Title: " << current->data.title << endl;
            cout << "Author: " << current->data.author << endl;
            cout << "Genre: " << current->data.genre << endl;
            cout << "Pages: " << current->data.pages << endl;
	        //cout << "======================================= \n";
	    }
        current = current->next;
    }
}
void wish::to_remove(book_info &remove)
{

}
void wish::add_new(book_info &to_add)
{
    if(head->data.author[0] > to_add.author[0])
    {
        node *temp = new node;
        copy_current(to_add, temp);
        temp->next = head;
        head = temp;
    }

    else
    {
        node *current = head;
        node *previous = head;
        node *temp = new node;
        copy_current(to_add, temp);

        while(current && current->data.author[0] <= to_add.author[0])
        {
            previous = current;
            current = current->next;
        }
        previous->next = temp;
        temp->next = current;
    }
}
void wish::remove_book(book_info &remove)
{

}
void wish::copy_data(book_info &to_add, node *current)
{
    head->data.title = new char[strlen(to_add.title) +1];
    head->data.author = new char[strlen(to_add.author) +1];
    head->data.genre = new char[strlen(to_add.genre) +1];
    strcpy(head->data.title, to_add.title);
    strcpy(head->data.author, to_add.author);
    strcpy(head->data.genre, to_add.genre);
    head->data.pages = to_add.pages;
}
void wish::copy_current(book_info &to_add, node *temp)
{
    temp->data.title = new char[strlen(to_add.title) +1];
    temp->data.author = new char[strlen(to_add.author) +1];
    temp->data.genre = new char[strlen(to_add.genre) +1];
    strcpy(temp->data.title, to_add.title);
    strcpy(temp->data.author, to_add.author);
    strcpy(temp->data.genre, to_add.genre);
    temp->data.pages = to_add.pages;

}
void wish::save_file()
{

    ofstream outFile;
    outFile.open("wishlist.txt");

    if(outFile){
        node *current = head;


        while(current)
        {
            outFile << current->data.title << endl;
            outFile << current->data.author << endl;
            outFile << current->data.genre << endl;
            outFile << current->data.pages << endl;
            //outFile << "====================================== \n";
            current = current->next;
        }
        outFile.close();
    }
}
void wish::load_list(book_info &load){

    read_file(load);

}

void wish::read_file(book_info &load){
    ifstream inFile;
    inFile.open("/Users/baumb/Desktop/coding/github_projects/Library_App/wishlist.txt");

    if(inFile){
        inFile.get(load.title, SIZE); inFile.ignore(100, '\n');
        while(!inFile.eof()){
            if(inFile){
                inFile.get(load.author, SIZE); inFile.ignore(100, '\n');
                inFile.get(load.genre, SIZE); inFile.ignore(100, '\n');
                inFile >> load.pages; inFile.ignore(100, '\n');
            if(!head){
                build_list(load);
            }
            else{
                add_new(load);
            }
            inFile.get(load.title, SIZE); inFile.ignore(100, '\n');            }
        }
        inFile.close();
    }
}
