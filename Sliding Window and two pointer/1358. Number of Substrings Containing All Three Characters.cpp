// #1358. Number of Substrings Containing All Three Characters

// #Question: Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

// #Intution: Have a left and right pointer and right moves until we have all the letters in the window. L moves till it excludes the extra character from left. Then you add left into the ans as that is going to be the count of substrings with all the letters.

class Solution {
public:
    int numberOfSubstrings(string s) {
        int L = 0, ans = 0;
        int count[3] = {0};

        for (int R = 0; R < s.size(); R++) {
            count[s[R] - 'a']++;

            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                count[s[L] - 'a']--;
                L++;
            }

            ans += L;
        }

        return ans;
    }
};

