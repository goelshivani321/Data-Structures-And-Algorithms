#include "Book.h"
#include <iostream>
#include <string>

using namespace std;

/*
 * Default Constructor
 */
Book::Book() {}

/*
 * Paremetrized constructor
 */
Book::Book(const string &isbn, const string &last, const string &first, const string &title, Book::Category category)
        : isbn(isbn), last(last), first(first), title(title), category(category) {}

/*
 * Destructor
 */
Book::~Book() {

}

const string &Book::getIsbn() const {
    return isbn;
}

const string &Book::getLast() const {
    return last;
}

const string &Book::getFirst() const {
    return first;
}

const string &Book::getTitle() const {
    return title;
}

Book::Category Book::getCategory() const {
    return category;
}

ostream& operator <<(ostream& outs,const Book& rn1)
{

    outs<<"Book{ISBN="<<rn1.isbn<<", last="<<rn1.last<<", first="<<rn1.last
            <<", title="<<rn1.title<<", category=";
    return outs;
}





