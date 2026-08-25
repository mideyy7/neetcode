/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peak = peak_index(mountainArr,n);
        int a = search_ascending(mountainArr, 0, peak, target);
        if (a != -1) return a;
        return search_descending(mountainArr, peak + 1, n - 1, target);    
    }

    int search_ascending(MountainArray& m, int lo, int hi, int target) {
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int check = m.get(mid);
            if (check == target) return mid;
            if (check > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return -1;
    }

    int search_descending(MountainArray& m, int lo, int hi, int target) {
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int check = m.get(mid);
            if (check == target) return mid;
            if (check > target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return -1;
    }

    int peak_index(MountainArray& m, int n) {
        int lo = 0;
        int hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (m.get(mid) < m.get(mid + 1)) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};