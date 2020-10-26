class Solution {
public:
    double myPow(double x, int n) {
        long long N=n;
        if(n<0){
        	x=1/x;
        	N=-N;
        }
        double ans=1;
        double cur_product=x;
        for(auto i=N;i>0;i/=2){
        	if(i%2==1){
        		ans*=cur_product;
        	}
        	cur_product=cur_product*cur_product;
        }
        return ans;
    }
};