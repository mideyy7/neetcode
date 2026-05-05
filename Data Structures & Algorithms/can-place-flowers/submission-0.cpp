class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       // nothing before and nothing at the front
       // keep track if i place previously
       // [ A, B, C, D ]
       // if !prev_seen and (i == flower.size() - 1 or flowerbed[i + 1] == 0)_: can place

       /*
            flowerbed=[1,0,0,0,1]
            n=1
       */
        bool prev_seen = false;
        int count = 0;
        int size = flowerbed.size();
        for (int i = 0; i < size; ++i) {
            if (flowerbed[i] == 1) {
                prev_seen = true;
                continue;
            }
            if (!prev_seen && (i == size || flowerbed[i + 1] == 0)) {
                prev_seen = true;
                count += 1;
            } else {
                prev_seen = false;
            }
        }
        if (count >= n) {
            return true;
        }
        return false;
    }
};