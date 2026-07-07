class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // naiva approach , gives TLE 
        // int n = nums.size();
        // vector<int>ans;
        // for(int i = 0 ; i <= n - k ; i++){
        //     int temp = INT_MIN;
            
        //     for(int j = i ; j < i + k ; j++){
        //       temp = max(temp , nums[j]);
        //     }
        //     ans.push_back(temp);
        // }
        // return ans;

        // optimal soln 
        deque<int> dq;
        vector<int> ans;


        // 1st window 
        for(int i = 0 ; i < k ; i++){
            while(!dq.empty() && nums[i] >= nums[dq.back()]){ // cant use if here bcauz we may have to remove multiple smaller elements
                dq.pop_back();  
            }
        dq.push_back(i);
        }

        // for the remaining windows , we will now add and remove elements one by one 
        for (int i = k ; i < nums.size() ; i++){
            ans.push_back(nums[dq.front()]);
           
            // remove the elements' index from the deque who is not part of the current window
            while(dq.front() <= i - k && !dq.empty())  dq.pop_front();  
            
            // remove the smaller elements , similar condition as of the 1st window
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]); // push the last element separtely as in the loop we push into ans at start of the loop

        return ans;
        
    }
};