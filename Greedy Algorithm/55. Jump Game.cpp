// #55. Jump Game
// #Question: You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.


// #Intution: Make greedy choice at every index. So how iterate and check if current index is more than you have jumped till now. If no then return false that means you will never reach that index. Else update the max jump with i+current_jump. return true outside the loop.

class Solution {
public:
    bool canJump(vector<int>& nums) {
      
    int farthest = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (i > farthest) {
            return false; // Can't reach this point
        }
        farthest = max(farthest, i + nums[i]);
    }
    return true;
}

    
};
