// Permutations are ways you can order a group of elements.
// 参考: https://web.stanford.edu/class/archive/cs/cs106x/cs106x.1192/lectures/Lecture11/Lecture11.pdf

/*
**Choose-explore-unchoose**

This choose-explore-unchoose structure is a classic pattern for recursive backtracking. Here it is summarized in pseudocode:

```
void explore(options, soFar)
{
    if (no more decisions to make) {
        // base case
    } else {
        // recursive case, we have a decision to make
        for (each available option) {
            choose (update options/soFar)
            explore (recur on updated options/soFar)
            unchoose (undo changes to options/soFar)
        }
    }
}
```

*/



#include <iostream>
#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"

#include <string>
#include "vector.h"
#include "set.h"

using namespace std;


void permutations(Vector<string>& items, Vector<string>& chosen, Set<Vector<string>> & result);


void permutations(Vector<string>& items, Set<Vector<string>> & result)
{
    Vector<string> chosen;
    permutations(items, chosen, result);
}

void permutations(Vector<string>& items, Vector<string>& chosen, Set<Vector<string>> & result)
{
    if (items.isEmpty()) {
        result.add(chosen);
    } else {
        for (int i = 0; i < items.size(); i++) {
            string pick = items[i];
            items.remove(i);
            chosen.add(pick);
            permutations(items, chosen, result);
            chosen.removeBack();
            items.insert(i, pick);
        }
    }
}




PROVIDED_TEST("permutation,  letters in the alphabet") {
    Vector<string> allLetters = {"A", "B", "C"};
    Set<Vector<string>> expect = {{"A", "B", "C"}, {"A", "C", "B"}, {"C", "B", "A"}, {"B", "A", "C"},
                                  {"C", "B", "A"}, {"B", "C", "A"}, {"C", "A", "B"}};

    Set<Vector<string>> result;
    permutations(allLetters, result);
    EXPECT_EQUAL(result, expect);
}
