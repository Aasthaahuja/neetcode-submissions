class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1. Count frequency of each number
        unordered_map<int, int> freq;
        
        for(int x : nums) {
            freq[x]++;
        }
        
        // 2. Bucket: index = frequency
        vector<vector<int>> bucket(nums.size() + 1);
        
        for(auto it : freq) {
            int num = it.first;
            int count = it.second;
            
            bucket[count].push_back(num);
        }
        
        // 3. Traverse buckets from highest frequency
        vector<int> ans;
        
        for(int i = nums.size(); i >= 1 && ans.size() < k; i--) {
            
            for(int num : bucket[i]) {
                ans.push_back(num);
                
                if(ans.size() == k)
                    break;
            }
        }
        
        return ans;
    }
};
