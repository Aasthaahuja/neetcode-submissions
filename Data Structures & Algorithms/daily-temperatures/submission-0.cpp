class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n,0);
        stack<int> helperSt;
        for(int i = n-1; i >= 0; i--)
        {
            while(!helperSt.empty() && temperatures[i] >= temperatures[helperSt.top()]){
                helperSt.pop();
            }
            if(!helperSt.empty()){
                result[i] = helperSt.top() - i;
            }
            helperSt.push(i);
        }
        return result;
    }
};