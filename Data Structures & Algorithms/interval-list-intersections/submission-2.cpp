class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        int first = 0;
        int second = 0;
      
        while (first < firstList.size() && second < secondList.size()) {
            int start = max(firstList[first][0], secondList[second][0]);
            int end = min(firstList[first][1], secondList[second][1]);
            if (start <= end) {
                result.push_back({start, end});
            }

            if (firstList[first][1] < secondList[second][1]) {
                first++;
            } else {
                second++;
            }

            
        }
        
        return result;

    }
};