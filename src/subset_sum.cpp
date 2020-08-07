// 子集和问题（The subset-sum problem）
//      给定一组整数和目标值，判断是否可以找到在这组数据的子集中找到总和等于指定目标整数的子集
// https://blog.csdn.net/redRnt/article/details/70245849
#include <iostream>
#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"
#include "vector.h"
#include "filelib.h"
using namespace std;
#include <set.h>


// 如果我们可以找到这样的子集，我们就返回true，否则就返回false
bool subsetSumExists(const Set<int> & integerSet, int target)
{
    if (integerSet.isEmpty()) {
        return target == 0;
    }  else {
        Set<int> s = integerSet;
        int n = s.first();
        s.remove(n);
        return subsetSumExists(s, target) || subsetSumExists(s, target - n);
    }
}

PROVIDED_TEST("found subset") {
    Set<int> s;   // {-2, 1, 3, 8}
    s.add(-2);
    s.add(1);
    s.add(3);
    s.add(8);
    int target = 7;
    EXPECT_EQUAL(subsetSumExists(s, target), true);
}

PROVIDED_TEST("not found subset") {
    Set<int> s;   // {-2, 1, 3, 8}
    s.add(-2);
    s.add(1);
    s.add(3);
    s.add(8);
    int target = 5;
    EXPECT_EQUAL(subsetSumExists(s, target), false);
}
