class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0 ;
        int mid = 0 ;
        int high = nums.size()-1;
        while(mid <= high){
        int value = nums[mid];
         if(value == 0) {
            swap(nums[mid] , nums[low]);
            mid++;
            low++;
         }
         if(value == 1){
         mid++;
         }

        if(value == 2){
            swap(nums[mid] , nums[high]);
            high--;
        }
    }

    

    }
};