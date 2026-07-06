class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int result = 0;
        int last_seen = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (start < last_seen) {
                result++;
                last_seen = min(last_seen, end);
            } else {
                last_seen = end;
            }
        }
        return result;
    }
};
