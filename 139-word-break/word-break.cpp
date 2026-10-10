
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length() + 1);
        dp[0] = true; // for empty String;
        if(s.length() == 0) return dp[0];
        int maxLen = -1;
        // calculated maxlength for the words
        for (string temp : wordDict){
            maxLen = max(maxLen , (int)temp.length());
        }
        
        for(int i = 1 ; i <= s.length() ; i++){
            for(int j = i - 1 ; j >= max(0 ,i - maxLen) ; j-- ){
                if(!dp[j]) continue;
                string sub = s.substr(j , i - j);

                for(string temp : wordDict){
                    if(temp == sub){
                        dp[i] =true;
                        break;
                    }
                }
             if(dp[i]) break;
            }
        }

      return dp[s.length()];
    }
};