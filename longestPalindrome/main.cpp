#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<string> getCenterPalindromes(string s, int i)
{
    int stringLength = s.length();
    int numberTest1 = min(i, stringLength - i - 1);
    int numberTest2;
    if (i == 0 || i == stringLength - 2)
    {
        numberTest2 = 1;
    } else if (i == stringLength - 1) {
        numberTest2 = 0;
    }
    else
    {
        numberTest2 = numberTest1;
    }

    while(numberTest1 > 0) {
        int j = i + 1;
        numberTest1 --;
    }

    cout << numberTest1 << endl;
    vector<string> palindromes;
    return palindromes;
}

unordered_map<int, unordered_map<char, int>> longestPalindrome(string s)
{
    unordered_map<int, unordered_map<char, int>> h;
    int stringLength = s.length();
    string newString = "";
    for (size_t i = 0; i < stringLength; i++)
    {
        char currentChar = s[i];
        int currentRepetitions = 1;
        if (i < stringLength - 1)
        {
            while (i + 1 < stringLength && s[i + 1] == currentChar)
            {
                currentRepetitions += 1;
                i += 1;
            }
        }
        newString += currentChar;
        h[i - currentRepetitions + 1][currentChar] = currentRepetitions;
    }
    for (size_t i = 0; i < newString.length(); i++)
    {
        char currentChar = s[i];
    }

    cout << newString << endl;
    return h;
}

int main()
{
    string s = "akbaaaaaacaaaaa";
    // string s = "akabcd";
    // cout << s << endl;
    unordered_map<int, unordered_map<char, int>> h = longestPalindrome(s);
    for (auto x : h)
    {
        cout << x.first << endl;
        for (auto y : x.second)
        {
            cout << "\t" << y.first << "\t" << y.second << endl;
        }
    }
    // cout << s << endl;
    // getCenterPalindromes(s, 5);
    // cout << longestPalindrome(s) << endl;
    return 0;
}