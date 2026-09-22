class Solution {
public:
    string minWindow(string s, string t) {
        int minLen = INT_MAX;
        int hash[256] = {0};
        int l = 0, r = 0, sIndex = -1;
        int m = t.size();
        int n = s.size();
        for(int i = 0; i < m; i++)
        {
            hash[t[i]]++;
        }
        int cnt = 0;
        while(r < n)
        {
            if(hash[s[r]] > 0) cnt++;
            hash[s[r]]--;
            r++;
            while(cnt == m)
            {
                if(r-l < minLen)
                {
                    minLen = r-l;
                    sIndex = l;
                } 
                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt--;
                l++;
            }
        }
        if(sIndex == -1) return "";
        return s.substr(sIndex, minLen);
    }
};
