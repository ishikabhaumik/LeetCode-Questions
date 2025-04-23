// # 875. koko eating banana
// # Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

// # Intuition : BS on answer set. SO here the value of K can be anything between 1 till max bananas in the pile. So you take the mid and then compute how many hours will it take for koko to eat the bananas. if the itme taken with current speed
// as K is more than h then you need to increase the speed so move low to mid+1 and vice a versa.

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int n=piles.size();
        long long int low=1;
        long long int high=INT_MIN;
        for(long long int i=0;i<n;i++){
            if(piles[i]>high)
            high=piles[i];
        }
        
        long long int mid=(low+high)/2;
        long long int hours=0;
        long long int optimal_k=INT_MAX;
        while(low<=high){
            mid=(low+high)/2;
            hours=0;
            //cout<<mid;
            for(long long int i=0;i<n;i++){
                hours+=(piles[i]/mid);
                if(piles[i]%mid!=0){
                   hours++;
                }
                
            }
            if(hours>h){
                low=mid+1;
            }
            else{
                if(mid<optimal_k){
                optimal_k=mid;
                }
                high=mid-1;
                
            }
        }
        return optimal_k;
    }
};
