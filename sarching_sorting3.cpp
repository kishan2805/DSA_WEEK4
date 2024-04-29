#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void display(int a[],int n);

// buble sort
void bublesort(int a[],int n){
    int i,j;
    for (i=0;i<n-1;i++){
        for (j=0;j<n-1-i;j++){
            if(a[j]>=a[j+1]){
                swap(a[j+1],a[j]);
            }
        }
    }
    cout<<"buble sort "<<endl;
    display(a,n);

}

void selectionsort(int a[],int n){
    for (int i=0;i<n-1;i++){
        int minid=0;
        for (int j=i;j<n-1;j++){
            if(a[j]<a[j+1]){
                minid=j;
            }
            else
                minid=j+1;
        }
        swap(a[i],a[minid]);
    }
    cout<<"selection sort "<<endl;
    display(a,n);
}
void insertionsort(int a[],int n){
    for (int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    cout<<"insertion sort "<<endl;
    display(a,n);
}

bool mycomp(int &a,int &b){
    //return a<b;   //it will sort in incresing order 

    return a>b;  //it will sort in decreasing order 
}

void display(int a[],int n ){
    for (int i=0;i<n;i++){
        cout<<a[i]<< "  ";
    }
    cout<<endl;
}

int getquo(int dividened,int diviser){
    int s=0;
    int e=dividened;
    int mid=s+(e-s)/2;
    int ans;
    
    while(s<=e){
        int quo=mid;
        if (dividened== quo*diviser)
            ans=quo;
        else if(dividened<quo*diviser){
            e=mid-1;
        }
        else
        {
            s=mid+1;
            ans=quo;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

// searching nearly sorted array
int NearlySorted(int a[],int n, int target){
    int s=0,e=n-1,mid=s+(e-s)/2;
    while(s<=e){
        if (a[mid-1]==target)
            return mid-1;
        else if (a[mid]==target)
            return mid;
        else if (a[mid+1]==target)
            return mid+1;
        else if (a[mid]<target)
            s=mid+2;
        else if (a[mid>target])
            e=mid-2;
        
        mid=s+(e-s)/2;
    }

}

int main(){
    // int arr[]={1,4,2,3,7,6,-7,0};
    // int n=8;

    // bublesort(arr,n);
    // selectionsort(arr,n);
    // insertionsort(arr,n);
    // sort(arr,arr+n,mycomp);
    // display(arr,n);

//  trying comparator on vectors

    // vector<int> v ={33,11,44,55,22};     //it doesnot worked here because my compiler doesn't support it 

    // vector<int> v;
    // v.push_back(33);
    // v.push_back(11);
    // v.push_back(44);
    // v.push_back(55);
    // v.push_back(22);

    // sort(v.begin(),v.end(),mycomp);
    // for (int i = 0; i < v.size(); ++i) {
    //     cout << v[i] << " ";
    // }
    // cout << std::endl;

    //dividing to no. using binary search 
    // int dividened=-71;
    // int diviser=-6;
    

    // int ans = getquo(abs(dividened),abs(diviser));
    
    // if (dividened<0 && diviser<0)
    //     cout<<ans;
    // else if (dividened<0||diviser<0)
    //     cout<<-1*ans<<endl;
    // else 
    //     cout<<ans ;
    // cout<<endl;

    // Nearly sorted array 

    int abc[]={1,3,2,5,4,7,6};
    int n=7;
    int target =6;
    int ans = NearlySorted(abc,n,target);
    cout<<"nearly sorted array "<<endl<<ans<<endl;

}