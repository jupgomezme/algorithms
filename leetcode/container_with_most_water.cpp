// 11. Container With Most Water
// https://leetcode.com/problems/container-with-most-water/description/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right)
        {
            int current = (right - left) * min(height[left], height[right]);
            maxArea = max(current, maxArea);
            int nextLeft = height[left + 1];
            int nextRight = height[right - 1];
            if (nextLeft >= nextRight)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxArea;
    }
};

template <typename T>
string vectorToString(const vector<T> &vec)
{
    string result = "[";

    for (size_t i = 0; i < vec.size(); ++i)
    {
        result += to_string(vec[i]);

        if (i < vec.size() - 1)
        {
            result += ", ";
        }
    }

    result += "]";
    return result;
}

void test(vector<pair<vector<int>, int>> &testCases)
{
    Solution solution;
    for (auto &testCase : testCases)
    {
        vector<int> arr = testCase.first;
        int expected = testCase.second;
        int result = solution.maxArea(arr); // Change function name here
        bool success = expected == result;

        // Print
        cout << "Case: " << vectorToString(arr);
        cout << " | Output: " << result;
        cout << " | Expected: " << expected;
        cout << " | Succeeded: " << success << endl;
    }
}

int main()
{
    vector<pair<vector<int>, int>> testCases = {
        {{1, 8, 6, 2, 5, 4, 8, 3, 7}, 49},
        {{1, 1}, 1},
        {{4, 3, 2, 1, 4}, 16},
    };
    test(testCases);

    return 0;
}
