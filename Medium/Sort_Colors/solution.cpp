#include<iostream>
using namespace std;
int main(){
    int nums[]={2,0,2,1,1,0};
    int n=5;
for (int i = 0; i < n-1; i++)
{
    int index=i;
    for (int j = i+1; j < n; j++)
    {
        if (nums[j]<nums[index])
        {
            index=j;
        }
        
    }
    swap(nums[i],nums[index]);
}

for (int k = 0; k < n; k++)
{
    cout<<nums[k];
}



    return 0;

}