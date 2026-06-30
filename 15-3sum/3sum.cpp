class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // this is using sets, which give TLE
    //   set<vector<int>>ans;
    //   for(int i = 0 ; i < nums.size() ; i ++){
    //       set<int> st;
    //     for(int j = i + 1 ; j <nums.size() ; j++){
    //        int temp = -1*(nums[i]+nums[j]);
    //        if(st.find(temp) != st.end()){
    //         vector<int> v = {nums[i] , nums[j] , temp};
    //         sort(v.begin() , v.end());
    //         ans.insert(v);
    //        }
    //        st.insert(nums[j]);
    //     }

    //   }
    //     vector<vector<int>> ans1(ans.begin() ,  ans.end());
    //     return ans1;


    // in this approach we will try to get rid of set 
    

    vector<vector<int>>ans;
    sort(nums.begin() , nums.end());
    for(int i = 0 ; i < nums.size() ; i++){
          if( i > 0 && nums[i] == nums[i-1] ) continue;
          int j = i+1;
          int k = nums.size()-1;
          while(j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0){
                j++;
            }

            else if(sum > 0){
                k--;
            }
            else {
                vector<int>temp ={nums[i] , nums[j] , nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j < k && nums[j] == nums[j-1]) j++;
                while(j < k && nums[k] == nums[k+1]) k --;
                }
          }


    }
    return ans;
    }
};