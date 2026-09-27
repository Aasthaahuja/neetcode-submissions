/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
         sort(intervals.begin(), intervals.end(),
             [](Interval a, Interval b) {
                 return a.start < b.start;
                });
        priority_queue<int, vector<int>,greater<int>> pq;
        for(auto& meeting : intervals)
        {
            if(!pq.empty() && pq.top() <= meeting.start) pq.pop();
            pq.push(meeting.end);
        }
        return pq.size();
    }
};
