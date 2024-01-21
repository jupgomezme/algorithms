// 88. Merge Sorted Array
// https://leetcode.com/problems/merge-sorted-array/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
using namespace std;

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

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0)
        {
            if (i >= 0 && nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }
        cout << vectorToString(nums1) << endl;
    }
};

int main()
{
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;
    solution.merge(nums1, m, nums2, n);
    return 0;
}