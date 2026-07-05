class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // my approach / brute force ->done by arman  TC => O(n^2*logn)
    //     int maxCount = 0;
    //    for(int i = 0 ; i < s.size() ; i++){
    //         int count = 0; 
    //         map <char , int> mp;
    //         mp[s[i]]++;
    //         count++;
    //         for(int j = i+1 ; j < s.size() ;j++){
    //             if(mp[s[j]] == 1)   break; 
    //             else{
    //             mp[s[j]]++;
    //             count++;
    //             }
    //         }
    //         maxCount = max(count , maxCount);
    //     }

    //     return maxCount;

    //optimal approach
    int maxLen = 0 ; 
    vector<int> hash(256, -1);
    int l = 0 ; 
    int r = 0;
    int len = 0;
    while(r < s.size()){ // loops runs until r pointer reaches the end of string
        
        if(hash[s[r]] != -1){ // here s[r] is converted to its ASCII value
           if(hash[s[r]] >= l) l = hash[s[r]]+1;
        }
    
     len = r - l + 1;
     maxLen = max(len , maxLen);
     hash[s[r]] = r ; // storing the index in hash array w.r.t index
     r ++ ; //moving the loop
    }
    return maxLen;
     }

    
};