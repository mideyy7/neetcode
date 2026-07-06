class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        int first = intervals[0][0];
        int last_seen = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (start <= last_seen) {
                last_seen = max(last_seen, end);
                first = min(first, start);
            } else {
                result.push_back({first, last_seen});
                first = start;
                last_seen = end;
            }
        }
        result.push_back({first, last_seen});
        return result;
    }
};
