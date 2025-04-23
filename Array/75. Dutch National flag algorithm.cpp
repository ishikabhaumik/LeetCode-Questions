// Dutch National flag algorithm (Also known as Sort 0s,1s,2s.) (3 pointer problem)

// Queue: Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue. We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// Intuition: Take 3 pointer low, mid and high. Low and mid start from zero and high starts from the end of the array. The assumption is after sorting everything before low will be zero , everything between low and mid is gonna be 1
// and everything beyond mid till end will be 2.

// So we check while mid is less than high :  if mid index in the array has zero then swap it with low and low moves by one. if mid index in the array has a value of 1 then swap it with high and move high backwards by one.
// if mid has a value equal to one then move mid by one. In the end the array is going to be sorted.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size();
        int low=0;
        int mid=0;
        int high=n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};


