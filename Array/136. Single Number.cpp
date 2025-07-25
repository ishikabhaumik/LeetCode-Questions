// 136. Single Number
// Queue: Given a non-empty array of integers nums, every element appears twice except for one. Find that single one. You must implement a solution with a linear runtime complexity and use only constant extra space.
// Intution: XOR of a number with itself gives zero. XOR of a number with zero gives the same number.
// Assume the given array is: [4,1,2,1,2]
// XOR of all elements = 4^1^2^1^2
//       = 4 ^ (1^1) ^ (2^2)
//       = 4 ^ 0 ^ 0 = 4^0 = 4
// Hence, 4 is the single element in the array.
// XOR-
// 0 0   0
// 1 1   0
// 0 1   1
// 1 0   1

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int once_num=0;
        for(int i=0;i<n;i++){
           once_num=once_num^nums[i];
        }
        return once_num;
    }
};
