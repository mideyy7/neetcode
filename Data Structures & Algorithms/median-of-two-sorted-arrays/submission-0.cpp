class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int a = nums1.size();
        int b = nums2.size();
        vector<int> total(a + b, -1);
        int i = 0, j = 0, k = 0;
        while ( i < a && j < b) {
            if (nums1[i] <= nums2[j]) {
                total[k] = nums1[i];
                i++;
            } else {
                total[k] = nums2[j];
                j++;
            }
            k++;
        }
        while (i < a) {
            total[k] = nums1[i];
            i++;
            k++;
        }
        while (j < b) {
            total[k] = nums2[j];
            j++;
            k++;
        }
        int l = a + b;
        if (l % 2 == 1) return total[(a + b) / 2.0];
        return (total[(b + a) / 2] + total[-1 + (b + a) / 2]) / 2.0; 
    }
};
