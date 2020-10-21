class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())return 0;
        int n=prices.size();
        vector<int> b_cooldown(n);
        vector<int> b_buy(n);

        vector<int> s_cooldown(n);
        vector<int> s_sell(n);


        b_cooldown[0]=-prices[0];
        b_buy[0]=-prices[0];

        s_cooldown[0]=0;
        s_sell[0]=0;

        for(int i=1;i<n;i++){

        	b_cooldown[i]=max(b_buy[i-1],b_cooldown[i-1]);
            if(i>2){
                b_buy[i]=max(0,max(s_cooldown[i-1],s_sell[i-2]))-prices[i];
            }else{
                b_buy[i]=-prices[i];
            }


        	//
            if(i>2){
               s_cooldown[i]=max(s_sell[i-1],s_cooldown[i-1]); 
            }else{
               s_cooldown[i]=s_sell[i-1]; 
            }
        	s_sell[i]=max(b_buy[i-1]+prices[i],b_cooldown[i-1]+prices[i]);
            // cout<<b_cooldown[i]<<" "<<b_buy[i]<<" "<<s_cooldown[i]<<" "<<s_sell[i]<<endl;
        }
        int res= max(s_sell[n-1],s_cooldown[n-1]);
        return res>0?res:0;
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)return 0;
        auto n=prices.size();
        int L[n][2];
        memset(L, 0, sizeof(L));
        
        //buy stock at 0th element
        L[0][0]=-prices[0];
        //sell stock at 0th element
        L[0][1]=0;
        //buy stock at 1th element, it could be stock we bought at 0th element and we rest at 1th element or we bought at 1th element
        L[1][0]=max(L[0][0],-prices[1]);
        //sell stock at 1th element
        L[1][1]=max(0,prices[1]-prices[0]);
        
        for(int i=2;i<n;i++){
            L[i][0]=max(L[i-1][0],L[i-2][1]-prices[i]);
            L[i][1]=max(L[i-1][1],L[i-1][0]+prices[i]);
        }
        return L[n-1][1];
    }
};