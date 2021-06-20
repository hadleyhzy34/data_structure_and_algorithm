typedef struct{
    int *nums;
}NumArray;

NumArray* numArrayCreate(int* nums, int numsSize){
    NumArray* tmp = malloc(sizeof(NumArray));
    tmp->nums = malloc(numsSize*sizeof(int));
    
    for (int i = 0 ; i< numsSize; i++){
        // nums[i] += nums[i - 1];
        if(i==0){
            tmp->nums[0] = nums[0];
        }else{
            tmp->nums[i] = tmp->nums[i-1]+nums[i];
        }
    }
    return tmp;
}

int numArraySumRange(NumArray* obj, int left, int right){
    if(left <1){
        return obj->nums[right];
    }else{
        return obj->nums[right] - obj->nums[left-1];
    }
}

void numArrayFree(NumArray* obj){
    free(obj);
}


/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/
