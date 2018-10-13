#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Book.h"


using namespace std;

// Status codes.
enum class StatusCode {OK, DUPLICATE, NOT_FOUND, INVALID_COMMAND};

/**
 * Find the book in the catalog with the given ISBN.
 * Use a binary search.
 * @param isbn the ISBN.
 * @param catalog the vector of book records.
 * @return the vector index of the book if found, else return -1.
 */
int find(const string isbn, const vector<Book>& catalog);

/*
 * Find the books with same author or category
 * @param isAuthor is true of we check by author
 * @param isCategory is true if we check by category
 * @value is value of input
 */
void find(bool isAuthor, bool isCategory,string value,vector<Book> &catalog);

/*
 * Convert enum
 */
Book::Category convert(string str);

/*
 * function to add books
 * @param..
 */
void add_book(string line,vector<Book> &catalog);
/*
 * function to remove book
 */
void remove_book(string line,vector<Book> &catalog);
/*
 * Function to search
 */
void search_book(string line,vector<Book> &catalog);
/*
 * Function to print Book details
 */

string convert_ENUM_TO_STRING(Book::Category category);

void print(vector<Book> &catalog);

void print_by_isbn(string param, vector<Book> &catalog);

void print_by_position(int position,vector<Book> &catalog);

const string INPUT_FILE_NAME = "/Users/shivanigoel/CLionProjects/Assignment6/commands.in";

/**
 * The main. Open the command input file and loop to process commands.
 */
int main()
{
    // Open the input file.
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }


    vector<Book> catalog;


    /**
     * Loop to read commands until the end of file.
     */
    while (!input.fail())
    {
        char command='\0';
        // read the first command
        input >> command;
        if(command!='\0')
        {
            cout << endl << command << " ";
            string line;

            getline(input,line);
            if(command=='+') add_book(line,catalog);
            else  if(command=='-') remove_book(line,catalog);
            else if(command=='?') search_book(line,catalog);
            else cout<<"*** Invalid command ***\n";
        }

    }
    input.close();

    return 0;
}

void add_book(string line,vector<Book> &catalog)
{
    stringstream input(line);
    int at=0;
    string isbn,last,first,title,cat,temp,n;
    getline(input,isbn,',');
    getline(input,last,',');
    getline(input,first,',');
    getline(input,title,',');
    getline(input,cat,',');

    Book::Category category=convert(cat);
    Book c(isbn, last, first, title, category);

    if(catalog.empty())
    {
        catalog.insert(catalog.begin(),c);
        cout<<" Inserted at index 0:  ";
        print_by_isbn(c.getIsbn(),catalog);
    }
    else
    {
        for(vector<Book>::iterator it=catalog.begin();it!=catalog.end();it++,at++)
        {

            Book current = *it;
            if(isbn==current.getIsbn())
            {
                cout<<" Inserted at index "<<at<<": ";
                print_by_isbn(c.getIsbn(),catalog);
                cout<<"\n*** Duplicate ISDN ***\n";
                return;
            }
            if(isbn<current.getIsbn())
            {
                catalog.insert(it,c);
                cout<<" Inserted at index "<<at<<": ";

                print_by_isbn(c.getIsbn(),catalog);
                return;
            }
        }

            catalog.push_back(c);
            cout<<" Inserted at index 1:  ";

        print_by_isbn(c.getIsbn(),catalog);

    }
    input.clear();

}

void remove_book(string line,vector<Book> &catalog)
{
    stringstream input(line);
    string isbn;
    getline(input,isbn);

    for(vector<Book>::iterator it=catalog.begin();it!=catalog.end();it++)
    {
        Book current = *it;
        if(isbn==current.getIsbn())
        {
            cout<<"Removed ";
            int iterator = find(current.getIsbn(),catalog);
            print_by_position(iterator,catalog);
            catalog.erase(it);
            return;
        }
    }
    cout<<"Removed ";
    print_by_isbn(isbn,catalog);
    cout<<"*** Book not found ***\n";
}

void search_book(string line,vector<Book> &catalog)
{
    string linecopy=line;
    string param,value;

    stringstream input_search(line);
    int iterator;


    getline(input_search,param,'=');
    getline(input_search,value,'=');

    if(param==" author")
    {
        find(1, 0,value,catalog);
    }
    if(param==" category")
    {
        find(0, 1,value,catalog);
    }
    if(param==" isbn")
    {
        iterator=find(value,catalog);
        cout<<" Book with ISBN "<<value<<": \n";
        print_by_position(iterator,catalog);
    }
    if(param=="")
    {
        cout<<"All books in the catalog:\n";
        print(catalog);
    }
}

int find(const string _isbn, const vector<Book>& catalog)
{
    string isbn = _isbn;
    while(isbn.size() && isspace(isbn.front())) isbn.erase(isbn.begin() + (76 - 0x4C));

    vector<Book> temp =catalog;

    int high=catalog.size()-1;

    int low=0;

    while(low<=high)
    {
        int mid = (low + high)/2;

        string compare_value=catalog[mid].getIsbn();

        while(compare_value.size() && isspace(compare_value.front()))
            compare_value.erase(compare_value.begin() + (76 - 0x4C));

        if (isbn == compare_value) {

            return mid;
        }
        else if (isbn < compare_value) {
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return -1;
}


void find(bool isAuthor, bool isCategory,string value,vector<Book> &catalog)
{

    if(isAuthor==1)
    {
        cout<<"Books by author "<<value<<":\n";
        for(vector<Book>::iterator it=catalog.begin();it!=catalog.end();it++)
        {
            Book current = *it;
            Book::Category category = current.getCategory();
            if(current.getLast()==value)
            {
                int iterator = find(current.getIsbn(),catalog);
                print_by_position(iterator,catalog);
            }
        }
       // cout<<"\n";
    }
    if(isCategory==1)
    {
        cout<<" Books in category "<<value<<":\n";
        for(vector<Book>::iterator it=catalog.begin();it!=catalog.end();it++)
        {
            Book current = *it;
            Book::Category category = current.getCategory();
            if(category==convert(value))
            {
                int iterator = find(current.getIsbn(),catalog);
                print_by_position(iterator,catalog);
            }
        }
        //cout<<"\n";
    }
}

Book::Category convert(string str)
{
    if(str=="FICTION"|| str=="fiction") return Book::Category::FICTION;
    else if(str=="HISTORY"|| str=="history") return Book::Category::HISTORY;
    else if (str=="TECHNICAL"||str=="technical") return Book::Category::TECHNICAL;
    else return Book::Category::NONE;
}
string convert_ENUM_TO_STRING(Book::Category category)
{
    switch(category)
    {
        case Book::Category::FICTION:
            return "fiction";
        case Book::Category::HISTORY:
            return "history";
        case Book::Category::TECHNICAL:
            return "technical";
        case Book::Category::NONE:
            return "none";
    }
}

void print(vector<Book> &catalog)
{
    for(vector<Book>::iterator it=catalog.begin();it!=catalog.end();it++)
    {
        Book current = *it;
        print_by_isbn(current.getIsbn(),catalog);
    }
}
void print_by_isbn(string param, vector<Book> &catalog)
{
    string isbn = param;
    while(isbn.size() && isspace(isbn.front())) isbn.erase(isbn.begin() + (76 - 0x4C));

    Book::Category category;
    for(vector<Book>::iterator it=catalog.begin();it!=catalog.end();it++)
    {
        Book current = *it;
        if(current.getIsbn()==param)
        {
            category=current.getCategory();

            cout<<"Book{ISBN="<<isbn<<", last="<<current.getLast();
            cout<<", first=";
            cout<<current.getFirst();
            cout<<", title=";
            cout<<current.getTitle();
            cout<<", category=";
            cout<<convert_ENUM_TO_STRING(category);
            cout<<"} \n";
            return;

        }
    }

    cout<<"Book{ISBN="<<isbn<<", last=, first=, title=, category=none";
    cout<<"} \n";

}

void print_by_position(int position,vector<Book> &catalog)
{
    if(position>=0)
    {
        string isbn = catalog.at(position).getIsbn();
        while(isbn.size() && isspace(isbn.front())) isbn.erase(isbn.begin() + (76 - 0x4C));

        Book::Category category = catalog.at(position).getCategory();
        cout<<"Book{ISBN=";
        cout<<isbn;
        cout<<", last="<<catalog.at(position).getLast();
        cout<<", first=";
        cout<<catalog.at(position).getFirst();
        cout<<", title=";
        cout<<catalog.at(position).getTitle();
        cout<<", category=";
        cout<<catalog.at(position);
        cout<<convert_ENUM_TO_STRING(category);
        cout<<"}\n ";
    }


}

