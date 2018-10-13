#include <string>
#include "Word.h"

/***** Modify this file as needed. *****/

using namespace std;

Word::Word() : text(""), count(0) {}

Word::Word(string text) : text(text), count(1) {}

Word::~Word() {}

string Word::get_text() const { return text; }

int Word::get_count() const { return count; }

void Word::increment_count() { count++; }

bool operator !=(const Word w1, const Word w2)
{
    return (w1.text != w2.text) || (w1.count != w2.count);
}