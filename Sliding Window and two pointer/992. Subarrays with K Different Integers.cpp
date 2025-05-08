// #992. Subarrays with K Different Integers

// #Question: Given an integer array nums and an integer k, return the number of good subarrays of nums.

// A good array is an array where the number of different integers in that array is exactly k.

//     For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.

// A subarray is a contiguous part of an array.


// #Intution: Take left and right. Move right till the window from left to right has K distinct integers. if the count is exceeded then move left and decrement the count of distinct integers. The count of subarray wull be R-L+1. Again the trick is this will give you count of subarray with atmost K distinct integers. So subtract it with K-1 distinct integers.

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Helper function to count subarrays with at most K distinct integers
    int atMostK(vector<int>& A, int K) {
        unordered_map<int, int> count;
        int i = 0, res = 0;

        for (int j = 0; j < A.size(); ++j) {
            // If A[j] is a new unique number, decrement K
            if (count[A[j]]++ == 0) K--;

            // Shrink window until we have at most K distinct integers
            while (K < 0) {
                if (--count[A[i]] == 0) K++;
                i++;
            }

            // Number of valid subarrays ending at index j
            res += j - i + 1;
        }

        return res;
    }

    // Main function to count subarrays with exactly K distinct integers
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
