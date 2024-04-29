#include<iostream>
using namespace std;

// binary search basic function 
int binsearch(int a[],int n,int key )
{
    int start=0;
    int end =n-1;
    int mid=(start+end)/2;

    while(start<=end)
    {
        if (a[mid]==key)
        {
            return mid;
        }
        else if (a[mid]<key)
        {
            // start ko aage badhao 
            start =mid+1;
        }
        else
        {
            // end ko kaam karo(a[mid]>key)
            end=mid-1;
        }
        // mid ko update karo
        mid =(start+end)/2;
    }

    // if element is not found 
    return -1;

}

// first occurance 
int firstocc(int a[],int n,int key )
{
    int start=0;
    int end =n-1;
    int mid=(start+end)/2;
    int ans=-1;

    while(start<=end)
    {
        if (a[mid]==key)
        {
            ans=mid;
            // lesft mee jao 
            end=mid-1;
        }
        else if (a[mid]<key)
        {
            // start ko aage badhao 
            start =mid+1;
        }
        else
        {
            // end ko kaam karo(a[mid]>key)
            end=mid-1;
        }
        // mid ko update karo
        mid =(start+end)/2;
    }

    // if element is not found 
    return ans;

}

// last occurance 
int lastocc(int a[],int n,int key )
{
    int start=0;
    int end =n-1;
    int mid=(start+end)/2;
    int ans=-1;

    while(start<=end)
    {
        if (a[mid]==key)
        {
            ans=mid;
            // right mee jao 
            start=mid+1;
        }
        else if (a[mid]<key)
        {
            // start ko aage badhao 
            start =mid+1;
        }
        else
        {
            // end ko kaam karo(a[mid]>key)
            end=mid-1;
        }
        // mid ko update karo
        mid =(start+end)/2;
    }

    // if element is not found 
    return ans;

}

// total occurance 
void totalocc(int a[],int n,int key){
    int s=firstocc(a,n,key);
    int e=lastocc(a,n,key);


    cout<<"total occurance of the key "<<key<<" is "<<(e-s+1)<<endl;

}

// finding missing elemment
int findmissing(int arr[],int n){
    int s=0;
    int e=n-1;
    int mid=(s+e)/2;
    int ans=-1;

    while(s<=e){
        mid=(s+e)/2;
        int diff=arr[mid]-mid;
        if (diff == 1)
        {
            // we will move to right if diff is 1 
            s=mid+1;
        }
        else
        {
            // we will store the ans index and move to left till we end up at single object
            // till size of the array is 1
            // ans=mid+1;
            e=mid-1;
        }
        
    }
    ans=mid+1;
    
    return ans ;
}

// finding the peak
int peakele(int a[],int n)
{
    int s=0;
    int e=n-1;
    int mid;
    int ans;
    while(s<=e)
    {
        mid=(s+e)/2;
        int diff=a[mid]-a[mid+1];
        // we are taking this diff so get to know whethear we are in 
        // ascending order or descending order
        if(diff>0)
        // if the diff is greater then 0 then we are in descending  phase so
        // we will shift ending  point
        {
            e=mid-1;
        }
        else if (diff<0)
        // if diff is less then 0 then we r in ascending phase
        // so we will shift starting point 
        {
            ans=mid+1;
            s=mid+1;
        }
        
    }
    
    return a[ans];
}

int main()
{
    // binary search basic code 
    // int arr[]={1,2,3,4,5,6,7,8,9};
    // int n=9;
    // int key =3;

    // binary search 

    // int searched=binsearch(arr,n,key);
    // if (searched==-1)
    // {
    //     cout<<"invalid key "<<endl;
    // }
    // else 
    //     cout<<"element found at index :- "<<searched<<endl;

    // firstoccurance 
    // int arr2[]={1,2,3,3,3,4,5,6,7};
    // int key =3,n=9;

    // int firocc=firstocc(arr2,n,key);

    // if (firocc==-1)
    // {
    //     cout<<"invalid key "<<endl;
    // }
    // else 
    //     cout<<"element is first found at index :- "<<firocc<<endl;
    

    // last occurance 
    //  int lastoc=lastocc(arr2,n,key);

    // if (lastoc==-1)
    // {
    //     cout<<"invalid key "<<endl;
    // }
    // else 
    //     cout<<"element is last found at index :- "<<lastoc<<endl;

    // total occrance 

    // int arr[]={1,2,3,4,5,6,7,8,9};
    // int n=9;
    // int key =3;
    // totalocc(arr2,n,key);

    // finding missing element from a sorted array
    // int arr3[]={1,2,3,4,6,7,8,9};
    // int n=9;
    // int alpha =findmissing(arr3,n); 
    // cout<<"missing elemnt is "<<alpha;

    // finding the peak
    int arr4[]={10,20,40,50,70,30,20,10};
    int n=8;
    int beta=peakele(arr4,n);
    cout<<"the peak element is "<<beta<<endl;

}

