class Solution {
public:
//traverse in reverse order
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int end = m + n -1;

        int i = m - 1;
        int j = n - 1;

        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) {
                nums1[end] = nums1[i];
                i -- ;
            }
            else {
                nums1[end] = nums2[j];
                j--;
            }
            end = end - 1;
        }

        while( j >= 0) {
            nums1[end] = nums2[j];
            j--;
            end--;
        }
        return;
    }
};