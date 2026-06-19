class Solution {
public:
    int maxArea(vector<int>& height) {

        //brute force approach which will give TLE for some test cases
    //     int vol = 0 ;
    //     int maxVol = 0 ;
    //     for (int i = 0 ;  i  < height.size() ; i++){
    
    //         for(int j = i+1 ; j < height.size() ; j++){
    //          vol = min(height[i] ,  height[j]) * (j-i);
    //          maxVol = max(vol , maxVol);
    //         }
    //     }
    // return maxVol;



    //optimal approach using two pointers


    int l = 0 ;
    int r = height.size()-1;
    int maxvol = -1e9;
    while( l < r ){
        int width = (r - l);
        int ht = min(height[r] , height[l]);
        int vol = width * ht;
        maxvol = max(maxvol , vol);
        height[l]<height[r]?l++:r--;
    }
return maxvol;
    }
};