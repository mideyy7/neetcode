class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        /*
        1. zip position and speed and sort by decresing position
        2. iterate throuth the zip and calculate time to target
        3. time = distance / speed
        4. if time > min_time : fleet ++
        5. min_time = time
        */
        double min_time = -1.0;
        int fleet = 0;
        std::vector<std::pair<int, int>> temp_array;
        for (int index = 0; index < speed.size(); index++) {
            std::pair<int, int> temp = {position[index], speed[index]};
            temp_array.push_back(temp);
        }

        sort(temp_array.begin(), temp_array.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
            return a.first < b.first;
        });

        for (int i = 0; i < speed.size(); i++) {
            std::pair<int, int> temp = temp_array.back();
            temp_array.pop_back();
            double time = static_cast<double>(target - temp.first) / temp.second;
            if (time > min_time) {
                fleet += 1;
                min_time = time;
            }
            
        }
        return fleet;
    }
};
