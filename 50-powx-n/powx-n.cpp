class Solution {
public:
    double myPow(double x, int n) {
        if(x == -1 && n %2 == 0) return 1.0;
        if(x == -1 && n %2 != 0) return -1.0;
        if(x==0 ) return 0 ;
        if(x==1 || n==0) return 1;
        long long  BinaryForm = n ;
        double ans = 1;

        if(n < 0){
            x = 1/x;
            BinaryForm = -BinaryForm;
        }
        while(BinaryForm > 0){
            if(BinaryForm % 2 ==1){
                ans*=x;
            }

            x*=x;
            BinaryForm /=2;
        }
        return ans;
       
    }
};