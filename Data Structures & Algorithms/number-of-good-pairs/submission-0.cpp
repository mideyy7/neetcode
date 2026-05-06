class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> num_map;
        int result = 0;
        for(int num: nums) {
            if(num_map.count(num)) result += num_map[num];
            num_map[num]++;
        }
        return result;   
    }
};