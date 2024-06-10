class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> countMap;
        
        // Count the frequency of each character
        for (char c : s) {
            countMap[c]++;
        }
        
        int ans = 0;
        bool oddFound = false;
        
        // Calculate the length of the longest palindrome
        for (auto it : countMap) {
            if (it.second % 2 == 0) {
                ans += it.second;  // Even count can be fully used
            } else {
                ans += it.second - 1;  // Use the even part of the odd count
                oddFound = true;       // There is at least one odd count
            }
        }
        
        // If there was at least one character with an odd count, we can place one odd character in the center
        if (oddFound) {
            ans += 1;
        }
        
        return ans;
    }
};
