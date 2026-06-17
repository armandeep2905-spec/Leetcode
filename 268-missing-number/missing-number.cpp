class Solution {
public:
    
    int missingNumber(vector<int>& nums) {
       // solution 1 , extra space required for this soln
        int n = nums.size();
     vector<int> hash(n+1 , 0);
        for(int i = 0 ; i < n ; i++){
            hash[nums[i]]++;
        }
        for(int i = 0 ; i < hash.size() ; i++){
            if(hash[i] == 0) return i;
            
        }
    return -1 ;
    

    }
};