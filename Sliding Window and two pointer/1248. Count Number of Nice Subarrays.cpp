// # 1248. Count Number of Nice Subarrays\

// #Question: Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.


// #Intution: The idea is to take a left and a right pointer. Increment right pointer and check the count of odd number. if the count exceeds the amount k then move left and decrement count and keep moving left. The number of subarrays ending at index right wi;; b e right -left+1.

// The trick is to find all sub arrays with atmost K odds and K - 1 odds and then subtract both to find the ones with exact K odds.

  #include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

private:
    // Helper function to count subarrays with at most k odd numbers
    int atMost(vector<int>& nums, int k) {
        int left = 0, count = 0, oddCount = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] % 2 == 1)
                oddCount++;

            while (oddCount > k) {
                if (nums[left] % 2 == 1)
                    oddCount--;
                left++;
            }

            // Add number of subarrays ending at index `right`
            count += right - left + 1;
        }

        return count;
    }
};


  
