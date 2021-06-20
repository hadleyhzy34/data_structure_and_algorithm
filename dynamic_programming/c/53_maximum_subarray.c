
//two pointers
int maxSubArray(int* nums, int size){
    int sum[size];
    sum[0] = nums[0];
    for(int i=1;i<size;i++)
        sum[i] = sum[i-1]+nums[i];
            // printf("current sum is %d",sum[i]);

    int min_sum=0<sum[0]?0:sum[0];
    int max_sum=sum[0];
    for(int i=1;i<size;i++){
            // printf("current sum is:%d, min_sum is: %d, max_sum is:%d",sum[i],min_sum,max_sum);
        if(sum[i]-min_sum>max_sum){
            max_sum = sum[i] - min_sum;
                // printf("current max_sum is: %d",max_sum);
        }
        if(sum[i]<min_sum){
            min_sum = sum[i];
        }
    }
    return max_sum;
}

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


