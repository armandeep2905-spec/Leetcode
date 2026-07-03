class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxCount = 0;
       for(int i = 0 ; i < s.size() ; i++){
            int count = 0; 
            map <char , int> mp;
            mp[s[i]]++;
            count++;
            for(int j = i+1 ; j < s.size() ;j++){
                if(mp[s[j]] == 1)   break; 
                else{
                mp[s[j]]++;
                count++;
                }
            }
            maxCount = max(count , maxCount);
        }

        return maxCount;
    }
};