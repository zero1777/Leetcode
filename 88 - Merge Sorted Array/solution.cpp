class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1 = m-1;
        int n2 = n-1;
        
        for (int i=m+n-1; i>=0; i--) {
            if (n1 < 0) nums1[i] = nums2[n2--];
            else if (n2 < 0) nums1[i] = nums1[n1--];
            else {
                if (nums1[n1] > nums2[n2]) nums1[i] = nums1[n1--];
                else nums1[i] = nums2[n2--];
            }
        }    
    }
};