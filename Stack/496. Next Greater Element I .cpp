// #496. Next Greater Element I
// Queue: The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

// Intution: We use a stack to remember elements that might be the next greater for others.

// As we move leftward, we remove all smaller elements (since they can't be next greater for anyone to the left).

// The top of the stack (if it exists) will always be the next greater element for the current number.

// Store this info in a map.

// Then, for each element in nums1, we just look up the precomputed next greater value.

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        stack<int>st;
        vector<int>ans;
        int n=nums2.size();
        int nge=-1;
        int i=n-1;
        while(i>=0){
            // cout<<i<<endl;
            // cout<<(nums2[i])<<endl;
            // cout<<"------";
            if(st.empty()){
                st.push(nums2[i]);
                mp.insert({nums2[i],-1});
            }
            else if(st.top()>nums2[i]){
                nge=st.top();
                st.push(nums2[i]);
                 mp[nums2[i]]=nge;
            }
            else if(st.top()<=nums2[i]){
                while(!st.empty() && st.top()<nums2[i]){
                    st.pop();
                }
                if(st.empty()){
                    nge=-1;
                    
                }
                else{
                    nge=st.top();
                   
                }
                st.push(nums2[i]);
                mp[nums2[i]]=nge;
            }
            i--;

        }
        for(int i=0;i<nums1.size();i++){
          ans.push_back(mp[nums1[i]]);
        }
        return ans;
        return ans;
        
    }
};
