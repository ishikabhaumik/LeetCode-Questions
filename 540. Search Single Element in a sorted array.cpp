// # 540. Search Single Element in a sorted array
// # You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.


// # Intution: The first element or the repeats before the single element is even indx after the single element the first occurence of the repeats become odd so based onnthat we do binary search and try to converge to a single point.
// Because the array is sorted and duplicates appear in pairs, the index pattern before and after the single element is different:
// Before the single element: The first instance of each pair is at an even index, the second at an odd index.
// After the single element: This pattern is broken.
// We use binary search to detect where the pattern breaks.

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mid=0;
        if(n==1) return nums[0];
        if(nums[0]!=nums[1])return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        while(low<=high){
            mid=((low+high)/2);
            if(nums[mid]!=nums[mid-1] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }
            if((mid % 2 == 1 && nums[mid] == nums[mid - 1])
                || (mid % 2 == 0 && nums[mid] == nums[mid + 1])){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};
