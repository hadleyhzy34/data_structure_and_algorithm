/*------------------------------------------------------------------------*/
//dp
int maxSubArray_v1(int *nums, int size){
    int sum[size];
    sum[0]=nums[0];
    int dp_min_sums[size];
    int res=nums[0];
    dp_min_sums[0] = 0<nums[0]?0:nums[0];
    for(int i=1;i<size;i++){
        sum[i] = sum[i-1]+nums[i];  
        res = res>(sum[i]-dp_min_sums[i-1])?res:(sum[i]-dp_min_sums[i-1]); 
        dp_min_sums[i] = dp_min_sums[i-1]<sum[i]?dp_min_sums[i-1]:sum[i];
    }
    return res;
}

/*------------------------------------------------------------------------*/
//dp
int maxSubArray_v2(int *nums, int size){
    int sum;
    sum=nums[0];
    int dp_min_sums[size];
    int res=nums[0];
    dp_min_sums[0] = 0<nums[0]?0:nums[0];
    for(int i=1;i<size;i++){
        sum = sum+nums[i];  
        res = res>(sum-dp_min_sums[i-1])?res:(sum-dp_min_sums[i-1]); 
        dp_min_sums[i] = dp_min_sums[i-1]<sum?dp_min_sums[i-1]:sum;
    }
    return res;
}

//dp, to store max sum value that include current index element
int maxSubArray_v3(vector<int> &nums){
    int dp[nums.size()];
    int res = INTI_MIN;

    dp[0]=nums[0];
    for(int i=0;i<nums.size();i++){
        dp[i] = max(dp[i-1]+nums[i],nums[i]);
        if(dp[i]>res){
            res=dp[i];
        }
    }
    return res;
}
