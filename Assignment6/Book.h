#ifndef BOOK_H_
#define BOOK_H_

#include <string>
using namespace std;

/***** Complete this file. *****/

/**
 * The Book class.
 */
class Book
{
public:
    /**
     * Book categories.
     */
    enum class Category { FICTION, HISTORY, TECHNICAL, NONE };



    /**
     * Default constructor.
     */
    Book();

    /**
     * Constructor.
     */
   // Book(string isbn, string last, string first, string title, Category category);

    Book(const string &isbn, const string &last, const string &first, const string &title, Category category);

    /**
     * Destructor.
     */
    ~Book();

    /*
     * Overloading input stream operator
     */
    friend istream& operator>>(istream& ins,Book& bk1)
    {
        string words;
        ins>>words;
        return ins;
    }

    friend ostream& operator<<(ostream& outs,const Book& rn1);

    const string &getIsbn() const;

    const string &getLast() const;

    const string &getFirst() const;

    const string &getTitle() const;

    Category getCategory() const;



private:

    /***** Complete the private members. *****/
    string isbn;
    string last;
    string first;
    string title;
    Category category;
};

#endif /* BOOK_H_ */