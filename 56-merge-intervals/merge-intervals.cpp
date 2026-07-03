class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {

        // brute force -> each element is checked twice
        // int n = intervals.size();
        // sort(intervals.begin() , intervals.end()); // sorted all acc to the first element ,if first is same then acc to the second
        // vector<vector<int>> ans;
        // for(int i = 0 ; i < n ; i++){
        //    int start = intervals[i][0]; // separating end and start of each interval
        //    int end = intervals[i][1];
        //    if(!ans.empty() && end<= ans[ans.size()-1][1]){
        //     continue; // suppose we have a interval (a,b) and the end for next interval < b , that means overlapping , so we can skip the check for that interval
        //    }
        // for(int j = i+1 ; j <n ; j++ ){ 
        //     if(intervals[j][0] <= end){
        //         end = max(end , intervals[j][1]);
        //     }
        //     else break;

        // }
        // ans.push_back({start , end});

        //     }
        // return ans;


        //better solution , solving in 1 check for each interval 
        sort(arr.begin() , arr.end());
        int size = arr.size();
        vector<vector<int>>ans;
        ans.push_back(arr[0]);
        for(int i = 0 ; i < size ; i++){
            if(arr[i][0] <= ans[ans.size()-1][1] ) {
                ans[ans.size() - 1][1] = max(arr[i][1] , ans[ans.size() - 1][1]);
            }
            else{
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};