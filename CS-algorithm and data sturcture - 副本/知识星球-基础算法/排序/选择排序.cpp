#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// - vector版
void selectionSort_vector(vector<int> &a){
    int n=a.size();
    for(int i=0;i<n-1;++i){
        int temp = i;
        for(int j=i+1;j<n;++j){
            if(a[temp]>a[j]) temp = j;
        }
        swap(a[i],a[temp]);
    }
}
// - 数组版
void selectionSort_array(int *a,int n){
    for(int i=0;i<n-1;++i){
        int temp = i;
        for(int j=i+1;j<n;++j){
            if(a[temp]>a[j]) temp = j;
        }
        swap(a[temp],a[i]);
    }
}
// - test zone
int main(){
    vector<int> sth1 = {1,5,2,4,3};
    int sth2[5] = {1,5,2,4,3};
    selectionSort_array(sth2,5);
    for(int i = 0;i<5;++i){
        cout<<sth2[i]<<endl;
    }
}