// Here is a word puzzle:
// "Is there a nine-letter English word that can be reduced to a single-letter word one letter at at time by removing letters,
// leaving a legal word at each step?"   We can call such a word a reducable word.
// 来源：http://web.stanford.edu/class/cs106b/lectures/procedural-recursion/


// Decision tree search template
//
/*
bool search(currentState) {
    if (isSolution(currentState)) {
        return true;
    } else {
        for (option : moves from currentState) {
            nextState = takeOption(curr, option);
            if (search(nextState)) {
                return true;
            }
        }
        return false;
    }
}
*/


#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"
#include "lexicon.h"

#include <string>

using namespace std;


bool reducible(Lexicon & lex, string word) {
    if (word.length() == 1 && lex.contains(word)) {
        return true;
    }
    for (size_t i = 0; i < word.length(); i++) {
        string copy = word;
        copy.erase(i, 1);
        if (lex.contains(copy)) {
            return reducible(lex, copy);
        }
    }
    return false;
}



PROVIDED_TEST("reducible, 4 letter word") {
    string s = "cart";
    Lexicon lex("res/EnglishWords.txt");
    EXPECT(reducible(lex, s));
}
