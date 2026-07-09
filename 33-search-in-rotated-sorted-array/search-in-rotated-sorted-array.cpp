class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0 ; 
        int high = nums.size() - 1;

        while(low <= high){
            int mid = (low+high) / 2;
            if(target == nums[mid]) return mid;
            else if (target == nums[low]) return low;
            else if (target == nums[high]) return high;

            // check which part is sorted: low->mid || mid->high
            // left sorted  low->mid
            if (nums[low] < nums[mid]){
                if(target > nums[low] && target < nums[mid]) high = mid-1;
                else low = mid+1;
            }
            else {
                if(nums[mid] < target && nums[high] > target)low = mid+1;
                 else high =mid-1;
                 
                
            }

        }
        return -1;
    }
};