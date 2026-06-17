class Solution {
public:
     
    int majorityElement(vector<int>& nums) {

    //     map <int , int > mp;  // better approach 
    //     for(int i = 0 ; i < nums.size() ; i++){
    //         mp[nums[i]]++;
    //     }
    //     for(auto it : mp ){
    //         if(it.second > nums.size() / 2 ){
    //            return it.first;
    //         }
    //     }
    //   return 0 ;



    // optimised approach => moore voting algo

    int el ;
    int count = 0 ; 


    for(int i = 0 ; i < nums.size() ; i++){
        if(count ==0 ) el = nums[i];
        if(nums[i] == el) count ++;
        if(nums[i] != el) count --;
        if(count == 0) el = nums[i+1];
    }
     int elCount = 0 ;
    for(int i = 0 ; i < nums.size() ; i++){
        if(nums[i] ==  el) elCount++;

    }
    if(elCount > (nums.size() / 2)) return el;
    else return -1;
    }
};