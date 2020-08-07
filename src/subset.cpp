
// Subsets are zero or more elements from a group of elements.
// Combinations are ways you can choose exactly K elements from a  group of elements.
// 参考: https://web.stanford.edu/class/archive/cs/cs106x/cs106x.1192/lectures/Lecture11/Lecture11.pdf


#include <iostream>
#include <string>

#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"
#include "set.h"

using namespace std;


void listSubsetsRec(Set<string>& masterSet, Set<string>& used, Set<Set<string>>& result);


void subSets(Set<string>& masterSet, Set<Set<string>>& result)
{
    Set<string> chosen;
    listSubsetsRec(masterSet, chosen, result);
}

void listSubsetsRec(Set<string>& masterSet, Set<string>& used, Set<Set<string>>& result)
{
    if (masterSet.isEmpty()) {
        result.add(used);
    } else {
        string element = masterSet.first();

        masterSet.remove(element);
        listSubsetsRec(masterSet, used, result);   // without

        used.add(element);
        listSubsetsRec(masterSet, used, result);   // with

        masterSet.add(element);
        used.remove(element);   // unchoose
    }
}


PROVIDED_TEST("subset, finds every possible sub-list of a given set") {
    Set<string> s = {"Jane", "Bob"};
    Set<Set<string>> expect = {{}, {"Jane"}, {"Bob"}, {"Jane", "Bob"}};

    Set<Set<string>> result;
    subSets(s, result);
    EXPECT_EQUAL(result, expect);
}


void combination(const Set<string>& masterSet, int size, const Set<string>& used, Set<Set<string>>& result);


void combination(const Set<string>& masterSet, int size, Set<Set<string>>& result)
{
    Set<string> chosen;
    combination(masterSet, size, chosen, result);
}

void combination(const Set<string>& masterSet, int size,
                 const Set<string>& used, Set<Set<string>>& result)
{
    if (size == 0) {
        result.add(used);
    } else if (!masterSet.isEmpty()) {
        string element = masterSet.first();
        combination(masterSet - element, size, used, result);   // without
        combination(masterSet - element, size - 1, used + element, result);   // with
    }
}


PROVIDED_TEST("combination, finds every possible sub-list of a given set") {
    Set<string> s = {"Jane", "Bob", "Matt", "Sara"};
    Set<Set<string>> expect = {{"Jane", "Matt"}, {"Jane", "Sara"}, {"Jane", "Bob"},
                             {"Bob", "Matt"},  {"Bob", "Sara"}, {"Sara", "Matt"}};

    Set<Set<string>> result;
    combination(s, 2, result);
    EXPECT_EQUAL(result, expect);
}
