class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())return 0;

        int n=nums.size();

        //choose cur house
        std::vector<int> dp_c(n,0);
        std::vector<int> dp_n(n,0);

        for(int i=0;i<n;i++){
            if(i==0){
                dp_c[0]=nums[0];
                dp_n[0]=0;
                
            }else{
                dp_c[i]=dp_n[i-1]+nums[i];
                dp_n[i]=max(dp_c[i-1],dp_n[i-1]);
            }
        }

        //not choose last house
        int choose=dp_n[n-1];

        //not choose first house
        for(int i=1;i<n;i++){
            if(i==1){
                dp_c[1]=nums[1];
                dp_n[1]=0;
                
            }else{
                dp_c[i]=dp_n[i-1]+nums[i];
                dp_n[i]=max(dp_c[i-1],dp_n[i-1]);
            }
        }

        //not choose first house
        int not_choose=max(dp_n[n-1],dp_c[n-1]);

        return max(choose, not_choose);
    }
};


class Solution2 {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())return 0;
        if(nums.size()==1)return nums[0];
        int n=nums.size();

        //not choose current i, choose first
        vector<int> dp_n_1(n,0);
        //choose current i, choose first
        vector<int> dp_c_1(n,0);
        //not choose current i, not choose first
        vector<int> dp_n_0(n,0);
        //choose current i, not choose first
        vector<int> dp_c_0(n,0);

        for(int i=0;i<n;i++){
            if(i==0){
                dp_c_1[i]=nums[i];   
            }else if(i==1){
                dp_n_1[i]=max(dp_n_1[i-1],dp_c_1[i-1]);
                dp_c_1[i]=dp_n_1[i-1]+nums[i];
                dp_c_0[i]=nums[i];
                dp_n_0[i]=0;
            }else{
                dp_n_1[i]=max(dp_n_1[i-1],dp_c_1[i-1]);
                dp_c_1[i]=dp_n_1[i-1]+nums[i];

                dp_n_0[i]=max(dp_n_0[i-1],dp_c_0[i-1]);
                dp_c_0[i]=dp_n_0[i-1]+nums[i];
                
                cout<<i<<" "<<dp_n_1[i]<<" "<<dp_n_0[i]<<" "<<dp_c_1[i]<<" "<<dp_c_0[i]<<endl;
            }
        }
        cout<<dp_n_1[n-1]<<" "<<dp_n_0[n-1]<<" "<<dp_c_1[n-1]<<endl;
        return max(dp_n_1[n-1],max(dp_c_0[n-1],dp_n_0[n-1]));
    }
};