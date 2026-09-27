class Solution {
public:
    vector<vector<int>> result;
    vector<int> curr;
    void backtrack(vector<int>& candidates, int target, int start)
    {
        if(target == 0){
            result.push_back(curr);
            return;
        }
        if(target < 0) return;
        for(int i = start; i < candidates.size(); i++)
        {
            curr.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0);
        return result;
    }
};
