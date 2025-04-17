// # 1539. Kth Missing Positive Number

// # Queue: Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

// Return the kth positive integer that is missing from this array.

// # Ibtuition: SO the idea is to perform BS on the array. low is the first index and high is the last index. I will find the mid and check if mid is equal to the number in the vector. So to find the count of missing numbers
// subtract number at index mid - (mid+1). Once you have the count of missing numbers comapre if the count is less than k if so then move low to mid+1 else move high to mid - 1.





#include <bits/stdc++.h>
using namespace std;

int missingK(vector < int > vec, int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1);
        if (missing < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return k + high + 1;
}

int main()
{
    vector<int> vec = {4, 7, 9, 10};
    int n = 4, k = 4;
    int ans = missingK(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}

