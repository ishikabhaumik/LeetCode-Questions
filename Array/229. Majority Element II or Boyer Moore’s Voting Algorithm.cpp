// Boyer Moore’s Voting Algorithm
// 229. Majority Element II

// Queue: Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

// Intuition: take two counts and two max elements to find the Majority element. Count 1 increments only if ele1 is found. Count 2 is incremented only when ele 2 is found. For any other cases decrement  the count.
// Need to check everytime that ele1 and ele2 are not the same. Everytime count1 or count2 gets zero re assign new values to Majority elements. In the last before returning the max elements check if both of them are
// majority elements and then return.

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=-1;
        int num2=-1;
        int c1=0;
        int c2=0;
        for(int &i:nums){
            if(i==num1) c1++;
            else if(i==num2)c2++;
            else if(c1==0) {num1=i;c1++;}
            else if(c2==0) {num2=i;c2++;}
            else {c1--;c2--;}
        }
        c1=c2=0;
        
        int n=nums.size();
        for(int &i:nums){
            if(i==num1) c1++;
            else if(i==num2) c2++;
        }
        vector<int>ans;
        if(c1>n/3)ans.push_back(num1);
        if(c2>n/3)ans.push_back(num2);
        return ans;
    }
};
