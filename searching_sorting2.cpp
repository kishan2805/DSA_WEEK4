#include <iostream>
using namespace std;
// function for finding pivot element
int finding_pivot(int a[],int n){
    int s=0,e=n-1;
    int mid=(s+e)/2;
    // line a =12,14,16
    // line b=2,4,6,8,10
    while(s<=e){
        if (s==e)
        // one element
            return s;

        // else if (a[mid]>a[mid+1])
        // here we will do mistake as index can be out of bound (in case of array of size 2   eg -1,3)

        else if (a[mid]>a[mid+1] && mid+1<=n)
        // pivot is present as mid(mid pointing to 16 )
            return mid;

        // else if (a[mid]<a[mid-1])
        // same thing index out of bound

        else if (a[mid]<a[mid-1] && mid-1 >= 0)
        // pivot is at mid -1 (mid pointing to 2)
            return mid-1;
        else if (a[s]>a[mid])
        // mid is in line b
            e=mid-1;
        else 
        // mid is at line a
            s=mid +1;
        mid=(s+e)/2;
    }
    return -1;
}
// binar search 
int binary_sea(int a[],int s,int e,int key){
    int mid =s+(e-s)/2;
    while (s<=e){
        if (a[mid]==key)
            return mid;
        else if (a[mid]>key)
            e=mid-1;
        else
            s=mid+1;
        mid=s+(e-s)/2;

    }
    return -1;

}

// finding square rooot 
int finding_sqr_root(int n)
{
    int s=0;
    int e=n;
    int ans =-1;
    int mid = s +(e-s)/2;
    while (s<=e)
    {
        if (mid*mid==n)
            return mid ;
        else if (mid*mid<n){
            // store ans 
            // goto right 
            ans=mid;
            s=mid+1;
        }
        else
        // goto left 
            e=mid-1;
        mid=s+(e-s)/2;
    }
    return ans;
}

int main(){
    // cout<<"welcome to searching sorting 2 "<<endl;
    int arr[]={12,14,16,2,4,6,8,10};
    int n=8;

    // // int arr[]={1,3};
    // // int n=2;

    int pivot=finding_pivot(arr,n);
    cout<<"the pivot point is "<<arr[pivot]<<endl;

    // int target=8;
    // // int target =1;

    // int ans =0;
    // if (target>=arr[0] && target<=arr[pivot])
    //     ans=binary_sea(arr,0,pivot,target);
    // else    
    //     ans=binary_sea(arr,pivot+1,n-1,target);

    // cout<<"the key is found at index "<<ans<<endl;

    // finding square root 

    // int num=68;
    // int ans =finding_sqr_root(num);
    // cout<<"the floored square root of number is : "<<ans<<endl;


}