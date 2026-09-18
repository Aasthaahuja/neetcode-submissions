class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string s : strs)
        {
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < s.size())
        {
            //Find "#"
            int j = i;
            while(s[j]!='#'){
                j++;
            }
            // Get length
            int len = stoi(s.substr(i, j - i));
            // Extract string
            string str = s.substr(j+1, len);
            res.push_back(str);
            //Move to next encoded string
            i = j + 1 + len;
        }
        return res;
    }
};
