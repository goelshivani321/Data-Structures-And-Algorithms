#ifndef WORD_H_
#define WORD_H_

/***** Modify this file as needed. *****/

#include <string>

using namespace std;

/**
 * A word entry consisting of a word text and a frequency count
 * for a concordance.
 */
class Word
{
public:
    /**
     * Default constructor.
     */
    Word();

    /**
     * Constructor.
     * Create a word entry with the given text. Initialize the count to 1.
     * @param text the text of the word.
     */
    Word(string text);

    /**
     * Destructor.
     */
    virtual ~Word();

    /**
     * Getter.
     * @return the text.
     */
    string get_text() const;

    /**
     * Getter.
     * @return the count.
     */
    int get_count() const;

    /**
     * Increment the count by 1.
     */
    void increment_count();

    /**
     * Overloaded != operator. Two word entries are unequal
     * if either their texts or their counts are unequal.
     */
    friend bool operator !=(const Word w1, const Word w2);

private:
    string text;
    int count;
};

#endif /* WORD_H_ */