#include <vector>
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // using extra space TC =o (n+m)
        //    vector<int> nums3;
        //    int i = 0;
        //    int j = 0;
        //    while(i < m && j < n){
        //     if(nums1[i] <= nums2[j]){
        //         nums3.push_back(nums1[i]);
        //         i++;
        //     }
        //     else{
        //         nums3.push_back(nums2[j]);
        //         j++;
        //     }
        //    }
        //    while(i<m){nums3.push_back(nums1[i]);
        //         i++;}
        //    while(j<n){
        //      nums3.push_back(nums2[j]);
        //         j++;
        //    }

        //    for(int i = 0 ; i < m+n ; i++){
        //     nums1[i] = nums3[i];
        //    }

        // soln2 without using extra space

        int i = m - 1;
        int j = 0;
        while (i >= 0 && j < n) {
            if (nums1[i] > nums2[j]) {
                swap(nums1[i], nums2[j]);
                i--;
                j++;
            } else
                break;
        }
        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.end());
        int l = 0;
        for (int i = m; i < n + m; i++) {
            nums1[i] = nums2[l];
            l++;
        }
    }
};