// 3. Longest Substring Without Repeating Characters
// Queue: Given a string s, find the length of the longest without duplicate characters.
// Intuition: keep a map or a data structure to store the first occurence of the character in the window. everytiome j increments check if the char at j has appeared somewhere within the windpw if so then move i to the occurence+1 and try updating the max length. ALSO UPDATE THE
// OCCURENCE IN THE DATA STRUCTURE WITH THE MOST RECENT OCCURENCE INDEX.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<int,int> mp;
        int i=0;
        int j=0;
        int count=0;
        int max_count=0;
        while(i<=j && j<s.size()){
            if(mp.find((int)s[j])!= mp.end() && mp[(int)s[j]] >=i ){
                max_count=max(count,max_count);
                i=mp[(int)s[j]]+1;
                count=j-i+1;
                mp[(int)s[j]]=j;
            }
            else{
                count=j-i+1;
                mp[(int)s[j]]=j;
            }
            j++;
        }
        max_count=max(count,max_count);
        return max_count;

        
    }
};
