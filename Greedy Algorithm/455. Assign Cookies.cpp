// 455. Assign Cookies
// Queue: Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

// Intution: The idea is to sort both the array and then assigning the smallest big enough cookie to the kids. if such cookie exists then move to the next cookie and kid. If such cookie doesnot exist then move cookie ahead

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int j=0;
        int count=0;
        while(i<g.size() && j<s.size()){
            if(s[j]>=g[i]){
                count++;
                j++;
                i++;
            }
            else if(s[j]<g[i]){
                j++;
            }
            else{
                i++;
            }
        }
        return count;

        
    }
};
