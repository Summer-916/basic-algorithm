#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// - vector
void bubbleSort_vector(vector<int>& a){
    int n=a.size();
    for(int i=0;i<n-1;++i){
        for(int j=0;j<n-i-1;++j){
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
    }
}
// - array
void bubbleSort_array(int* a,int n){
    for(int i=0;i<n-1;++i){
        for(int j=0;j<n-i-1;++j){
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
    }
}
// - test zone
int main(){
    vector<int> sth1 = {1,5,2,4,3};
    int sth2[5] = {1,5,2,4,3};
    bubbleSort_array(sth2,5);
    for(int i = 0;i<5;++i){
        cout<<sth2[i]<<endl;
    }
}