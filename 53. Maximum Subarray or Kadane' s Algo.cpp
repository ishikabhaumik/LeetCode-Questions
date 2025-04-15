// 53. Maximum Subarray
// Kadane's Algo

// Queue: Given an integer array nums, find the largest sum, and return its sum.

// Intuition: The idea is to create a variable sum and keep adding the element to sum. Everytime you add something check if the current sum is greater than maxsum. if it is then update the max sum. 
// Everytime the sum is equal to less than 0 then assign sum to zero.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int max_sum=INT_MIN;
        int i=0;
        int n=nums.size();
        while(i<n){
            sum+=nums[i];
            max_sum=max(max_sum,sum);
            if(sum<0){
                sum=0;
            }
            i++;
        }
        return max_sum;
    
    }
};
