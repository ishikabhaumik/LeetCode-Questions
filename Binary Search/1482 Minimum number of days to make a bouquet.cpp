// # 1482 Minimum number of days to make a bouquet
// # Queue: You are given an integer array bloomDay, an integer m and an integer k.

// You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

// The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

// Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.


// # Intuition: BS on answer set. So the possible days to wait is minimum in the bouquet array and max is maximum in bouquet array. Then you do a BS on this and check for a mid how many bouquets can be made, If they are less than
// the m bouquets that is required then move to right that is mid+1 else mid -1. return mid where m number if bouquet can be reached.

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int low=INT_MAX;
        int high=INT_MIN;
        int mid=0;
        int count_flower=0;
        int count_bouquet=0;
        int min_day=INT_MAX;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<low){
                low=bloomDay[i];
            }
            if(bloomDay[i]>high){
                high=bloomDay[i];
            }
        }
        while(low<=high){
            mid=(low+high)/2;
            count_flower=0;
            count_bouquet=0;
            for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                count_flower++;
            
            }
            else{
                count_bouquet+=count_flower/k;
                count_flower=0;
            }
            }
            count_bouquet+=count_flower/k;
            if(count_bouquet >= m){
                min_day=min(min_day,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        if(min_day==INT_MAX) return -1;
        return min_day;
        
    }
};
