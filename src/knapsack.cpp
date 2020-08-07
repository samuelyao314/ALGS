// 背包问题
//
// http://web.stanford.edu/class/cs106b/lectures/backtracking2/

#include "vector.h"
#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"

struct objectT {
    int weight;
    int value;
};



int fillKnapsack(Vector<objectT>& objects, int weight, int bestScore);



int fillKnapsack(Vector<objectT>& objects, int targetWeight)
{
    return fillKnapsack(objects, targetWeight, 0);

}

int fillKnapsack(Vector<objectT>& objects, int weight, int bestScore)
{
    if (weight < 0) {
        return 0;
    }

    int localBestScore = bestScore;
    int obSize = objects.size();
    for (int i = 0; i < obSize; i++) {
        objectT originalObject = objects[i];
        int currValue = bestScore + originalObject.value;
        int currWeight = weight - originalObject.weight;

        // remove objects for recursion ("choose")
        objects.remove(i);

        // recurse
        currValue = fillKnapsack(objects, currWeight, currValue);
        if (localBestScore < currValue) {
            localBestScore = currValue;
        }

        // replace ("unchoose")
        objects.insert(i, originalObject);
    }
    return localBestScore;
}



PROVIDED_TEST("knapsack, size 3 sack") {
    Vector<objectT> bag;
    bag.add({2, 4});
    bag.add({1, 2});
    bag.add({3, 3});
    EXPECT_EQUAL(fillKnapsack(bag, 4), 6);
}
