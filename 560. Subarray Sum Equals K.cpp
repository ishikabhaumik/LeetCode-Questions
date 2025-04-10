// 560. Subarray Sum Equals K  (CLASSIC TWO POINTER PROBLEM)

// Queue: Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Intuition- As we need the longest sub array so we will take two pointer i and j starting from the start of the array. We keep moving j until the sum is equal to K. Once the sum is equal to k then we update the max length of the sub array
// if the sum is greater than k then we move the i till we reach equal to k. And everytime the sum is equal to K we update the max length. The loop breaks where J exceeds the size of the given array.


int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}



