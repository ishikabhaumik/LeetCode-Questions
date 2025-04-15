// 169. Majority Element

// Queue: Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Take a variable count that will keep the count of majority element. Everytime count is equal to zero you consider that element to be the majority element.
// Everytime you get an element of same as majority element increment the count. Everytime you face an element that is not equal to the majority element decrement count.
// In the end return the majority element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        int majority_ele=0;
        int i=0;
        while(i<n){
            if(count==0){
                majority_ele=nums[i];
                count++;
                
            }
            else if(nums[i]!=majority_ele){
                count--;
                
            }
            else{
                    count++;
                    
            }
            i++;
        }
        return majority_ele;
    }
};


