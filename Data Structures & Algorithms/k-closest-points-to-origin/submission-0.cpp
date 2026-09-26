class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
        for(auto& point : points)
        {
            int x = point[0];
            int y = point[1];
            int dist =  x*x + y*y;
            pq.push({dist, {x,y}});
            if(pq.size() > k) pq.pop();
        }
        vector<vector<int>> result;
        while(!pq.empty())
        {
            auto point = pq.top().second;
            pq.pop();
            result.push_back({point.first, point.second});
        }
        return result;
    }
};
