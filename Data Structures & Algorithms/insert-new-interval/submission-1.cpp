class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        /*
        declatre result
        for each interaval:
        chack if new interval is at the front or back
        if not any of prior then merge


        */
        vector<vector<int>> result;
        for (int i = 0; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (newInterval[0] > end) {
                result.push_back(intervals[i]);
            } else if (newInterval[1] < start) {
                result.push_back(newInterval);
                copy(intervals.begin() + i, intervals.end(), back_inserter(result));
                return result;
            } else {
                newInterval[0] = min(newInterval[0], start);
                newInterval[1] = max(newInterval[1], end);
            }
        }
        result.push_back(newInterval);
        return result;
    }

};
