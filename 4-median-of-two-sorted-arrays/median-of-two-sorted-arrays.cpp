class Solution {
public:
   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size(), size2 = nums2.size();
    int i = 0, j = 0, count = 0;
    int idx2 = (size1 + size2) / 2;
    int idx1 = idx2 - 1;
    int elem1 = 0;
    bool even = (size1 + size2) % 2 == 0;

    while (i < size1 || j < size2) {
        int val;
        if (i < size1 && (j >= size2 || nums1[i] <= nums2[j])) val = nums1[i++];
        else val = nums2[j++];

        if (count == idx1) elem1 = val;
        if (count == idx2) return even ? (elem1 + val) / 2.0 : val;
        count++;
    }
    return 0; // unreachable if arrays aren't both empty
}
};