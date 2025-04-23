// # 34 find-first-and-last-position-of-element-in-sorted-array
// # Queue: Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

// # Intution: Treat this as two different questions trying to find first occurence and last occerence of an element. so independent binary search for first occurence and second binary search for second occurence

class Solution {
public:
    vector<int> searchRange(vector<int>& A, int target) {
        int n=A.size();
         vector<int> ret(2, -1);
        if(n==0)return ret;
        int i = 0, j = n - 1;
   
  
    while (i < j)
    {
        int mid = (i + j) /2;
        if (A[mid] < target) i = mid + 1;
        else j = mid;
    }
    if (A[i]!=target) return ret;
    else ret[0] = i;
    
    
    j = n-1; 
    while (i < j)
    {
        int mid = (i + j) /2 + 1;	
        if (A[mid] > target) j = mid - 1;  
        else i = mid;				
    }
    ret[1] = j;
    return ret;
    }
};
