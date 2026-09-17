class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> arr;
        for(int i = 0; i < nums.size(); i++)
        {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        int left = 0;
        int right = nums.size()-1;
        while(left < right)
        {
            int sum = arr[left].first + arr[right].first;
            if(sum == target)
            {
                int i = arr[left].second;
                int j = arr[right].second;
                return {min(i,j), max(i,j)};
            }
            else if(sum < target) left++;
            else right--;
        }
        return {};
    }
};