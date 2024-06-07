// - 用了递归，又用了合并，故叫归并排序
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// - array
void merge_array(int* a,int start,int mid,int end){
    int temp[1000];
    int l=start;
    int r=mid+1;
    int i=0;
    while(l<=mid&&r<=end){
        if(a[l]<a[r]){
            temp[i] = a[l];
            i++,l++;
        }else{
            temp[i] = a[r];
            i++,r++;
        }
    }
    if(l<=mid){
        for(int j=l;j<=mid;++j,++i){
            temp[i] = a[j];
        }
    }else{
        for(int j=r;j<=end;++j,++i){
            temp[i] = a[j];
        }
    }
    i = 0;
    for(int j=start;j<=end;++j,++i){
        a[j] = temp[i];
    }
}

void mergeSort_array(int* a,int start,int end){
    if(start == end) return;
    int mid = (start+end)/2;
    mergeSort_array(a,start,mid);
    mergeSort_array(a,mid+1,end);
    merge_array(a,start,mid,end);
}

// - vector
void merge_vector(vector<int>& a,int start,int mid,int end){
    int temp[1000];
    int l = start;
    int r = mid+1;
    int i = 0;
    while(l<=mid&&r<=end){
        if(a[l]<a[r]){
            temp[i] = a[l];
            i++,l++;
        }else{
            temp[i] = a[r];
            i++,r++;
        }
    }
    if(l<=mid){
        for(int j = l;j<=mid;++j,++i){
            temp[i] = a[j];
        }
    }else{
        for(int j = r;j<=end;++j,++i){
            temp[i] = a[j];
        }
    }
    i = 0;
    for(int j = start;j<=end;++j,++i){
        a[j] = temp[i];
    }
}

void mergeSort_vector(vector<int>& a,int start,int end){
    if(start == end) return;
    int mid = (start+end)/2;
    mergeSort_vector(a,start,mid);
    mergeSort_vector(a,mid+1,end);
    merge_vector(a,start,mid,end);
}
// - test zone
int main(){
    vector<int> sth1 = {1,5,2,4,3};
    int sth2[5] = {1,5,2,4,3};
    mergeSort_vector(sth1,0,4);
    for(int i = 0;i<5;++i){
        cout<<sth1[i]<<endl;
    }
}