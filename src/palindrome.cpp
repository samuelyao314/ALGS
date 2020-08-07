// 是否是回文
#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"

#include <string>

using namespace std;

bool isPalindrome(string s) {
    if (s.length() < 2) {
        return true;
    } else {
        if (s[0] != s[s.length() - 1]) {
            return false;
        }
        return isPalindrome(s.substr(1, s.length() - 2));
    }
}


PROVIDED_TEST("is palindrome") {
    EXPECT_EQUAL(isPalindrome("madam"), true);
    EXPECT_EQUAL(isPalindrome("racecar"), true);
    EXPECT_EQUAL(isPalindrome("step on no pets"), true);
}

PROVIDED_TEST("not palindrome") {
    EXPECT_EQUAL(isPalindrome("python"), false);
    EXPECT_EQUAL(isPalindrome("byebye"), false);
}


PROVIDED_TEST("a letter is palindrome") {
    EXPECT_EQUAL(isPalindrome(""), true);
}

PROVIDED_TEST("empty string is palindrome") {
    EXPECT_EQUAL(isPalindrome(""), true);
}
