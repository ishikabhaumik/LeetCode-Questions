// #45. Jump Game II
// # Question: You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

//     0 <= j <= nums[i] and
//     i + j < n

// Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

// #Intution: You always need to keep record of the farthest jump that can be made and only jump when its necessary that is when we reach the farthest point. 

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
    int jumps = 0;
    int end = 0;
    int farthest = 0;
    
    for (int i = 0; i < n - 1; ++i) {
        farthest = max(farthest, i + nums[i]);
        if (i == end) {
            ++jumps;
            end = farthest;
        }
    }
    return jumps;
    }
    
};
