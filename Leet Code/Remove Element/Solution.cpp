

int removeElement(int* nums, int n, int val)
{
    int i;
    int p=0;
    for(i=0;i<n;i++){
    if(nums[i]!=val){
        nums[p]=nums[i];
        p++;
    }
}
return p;
    

}
