/*
 * CS106B Section Handout Test Harness: Section 1
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified by Trip Master and Nick
 * Bowman for CS106B Spring 2020.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */
#include <iostream>
#include "grid.h"
#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"
#include "vector.h"
#include "filelib.h"
using namespace std;


int sumNumbersInLine(const string & line)
{
    Vector<string> words;
    words = stringSplit(line.c_str(),  " ");

    int sum = 0;
    for (const string & word : words) {
        if (stringIsInteger(word)) {
            int n = stringToInteger(word);
            sum += n;
        }
    }
    return sum;
}

/*
 * Sum Numbers (Code Write)
 * ----------------------------------
 * Write a program to read through a given file and sum
 * all of the numbers in the file. You can assume that numbers
 * will be composed entirely of numerical digits, optionally
 * preceded by a single negative sign.
 */
int sumNumbers(string filename){
    // TODO: Your code here
    Vector<string> lines;

    ifstream is(filename);
    if (is.fail()) {
        cerr << "failed to open file: " << filename;
        return 0;
    }

    readEntireFile(is, lines);

    int sum = 0;
    for (const string & line : lines) {
        sum += sumNumbersInLine(line);
    }


    return sum;
}


/* * * * * Provided Tests Below This Point * * * * */
PROVIDED_TEST("given file in handout"){
    EXPECT_EQUAL(sumNumbers("res/numbers.txt"), 42);
}

PROVIDED_TEST("Nonexistent file should sum to zero") {
    EXPECT_EQUAL(sumNumbers("nonexistent_filename"), 0);
}

