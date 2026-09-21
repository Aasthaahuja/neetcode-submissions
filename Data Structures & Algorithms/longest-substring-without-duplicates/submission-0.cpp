class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> count(128,0);
        int maxLength = 0, left = 0;
        for(int right = 0; right < s.size(); right++)
        {
            count[s[right]]++;
            while(count[s[right]] > 1)
            {
                count[s[left]]--;
                left++;
            }
            maxLength = max(maxLength, right-left+1);
        }
        return maxLength;
    }
};
