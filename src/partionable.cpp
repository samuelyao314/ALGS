//  takes a vector of ints and returns true if it is possible to divide the ints into two groups such that each group has the same sum.
//  For example, the vector {1,1,2,3,5} can be split into {1,5} and {1,2,3}. However, the vector {1,4,5,6} can’t be split into two.
// 来源: http://web.stanford.edu/class/cs106b/lectures/backtracking1/


/*
 * This choose-explore-unchoose structure is a classic pattern for recursive backtracking.
 *
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
 *
 */


#include "vector.h"

#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"


bool partitionable(Vector<int>& rest, int sum1, int sum2) {
    if (rest.isEmpty()) {
        return sum1 == sum2;
    } else {
        int n = rest.get(0);
        rest.remove(0);
        bool answer = partitionable(rest, sum1 + n, sum2) ||
                    partitionable(rest, sum1, sum2 + n);
        rest.insert(0, n);
        return answer;
    }
}

bool partitionable(Vector<int>& nums) {
    int sum1, sum2;
    sum1 = sum2 = 0;
    return partitionable(nums, sum1, sum2);
}


//  find a correct partition
bool partitionable(Vector<int> &rest, Vector<int>& v1, Vector<int>& v2) {
    if (rest.size() == 0) {
        int sum1 = 0;
        int sum2 = 0;
        for (int val : v1) {
            sum1 += val;
        }

        for (int val : v2) {
            sum2 += val;
        }

        return sum1 == sum2;
    } else {
        int n = rest[0];
        rest.remove(0);

        v1.add(n);

        bool answer1 = partitionable(rest, v1, v2);
        if (answer1) {
            rest.insert(0, n);
            return true;
        }

        v1.remove(v1.size() - 1);

        v2.add(n);

        bool answer2 = partitionable(rest, v1, v2);
        rest.insert(0, n);

        if (answer2) {
            return true;
        }

        v2.remove(v2.size() - 1);

        return false;
    }
}


struct VectorPair {
    Vector<int> v1;
    Vector<int> v2;
};


// find all the solutions
void partitionable(Vector<int> &rest, Vector<int>& v1, Vector<int>& v2, Vector<VectorPair>& allSolutions) {
     if (rest.size() == 0) {
         int sum1 = 0;
         int sum2 = 0;
         for (int val : v1) {
             sum1 += val;
         }

         for (int val : v2) {
             sum2 += val;
         }
         if (sum1 == sum2) {
             VectorPair vp;
             vp.v1 = v1;
             vp.v2 = v2;
             allSolutions.add(vp);
         }
     } else {
         int n = rest[0];
         rest.remove(0);

         v1.add(n);

         partitionable(rest, v1, v2, allSolutions);

         v1.remove(v1.size() - 1);

         v2.add(n);

         partitionable(rest, v1, v2, allSolutions);
         rest.insert(0, n);

         v2.remove(v2.size() - 1);
     }
 }


PROVIDED_TEST("partitionable, has an answer") {
    Vector<int> nums = {1,1,2,3,5};
    EXPECT(partitionable(nums));
}


PROVIDED_TEST("partitionable, no answer") {
    Vector<int> nums = {1,4,5,6};
    EXPECT(!partitionable(nums));
}


