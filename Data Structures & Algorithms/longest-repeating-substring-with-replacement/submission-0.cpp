class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int left = 0;
        int maxFreq = 0;
        int maxLength = 0;
        for(int right = 0; right < s.size(); right++)
        {
            count[s[right] - 'A']++;
            maxFreq = max(maxFreq, count[s[right] - 'A']);
            int windowLength = right - left + 1;
            while(windowLength - maxFreq > k)
            {
                count[s[left] - 'A']--;
                left++;
            windowLength = right - left + 1;
            }
            maxLength = max(maxLength, windowLength);
        }
        return maxLength;
    }
};
