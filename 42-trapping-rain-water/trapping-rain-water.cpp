class Solution {
public:
    int trap(vector<int>& height) {
        // naive approach 
        // int ans = 0; 
        // for(int i = 0 ; i < height.size() ; i++){
        //     int leftMax = height[i];
        //     for(int j = i - 1 ; j >= 0 ; j--){
        //         leftMax = max(leftMax , height[j]);
        //     }
        //     int rightMax = height[i];
        //     for(int k = i+1 ; k < height.size() ; k++){
        //         rightMax = max(rightMax , height[k]);
        //     }
        //     ans += min(leftMax , rightMax) - height[i];
        // } 

        //  return ans;

    int n = height.size();
    vector<int> lMax(n , -1);
    vector<int> rMax(n , -1);
    lMax[0] = height[0];
    int ans = 0 ;
    rMax[n-1]= height[n-1];
    for(int i = 1 ; i < n ; i++){
        lMax[i] = max(lMax[i-1],height[i]);
    }
    for(int i = n-2 ; i >=0 ; i--){
        rMax[i] = max(rMax[i+1] , height[i]);
    }

    for(int i = 0 ; i < n ; i++){
       ans += min(rMax[i] , lMax[i]) - height[i];
    }
    return ans;
    }
};