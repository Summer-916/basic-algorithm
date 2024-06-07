#include <iostream>
#include <vector>
using namespace std;
// - array
void countingSort_array(int* a,int n){
    int b[10]={0};
    for(int i=0;i<n;++i){
        b[a[i]]++;
    }
    int m=0;
    for(int i=0;i<10;++i){
        for(int j=0;j<b[i];++j,++m){
            a[m] = i;
        }
    }
}
// - vector
void countingSort_vector(vector<int>& a){
    int n=a.size();
    int b[10]={0};
    for(int i=0;i<n;++i){
        b[a[i]]++;
    }
    int m=0;
    for(int i=0;i<10;++i){
        for(int j=0;j<b[i];++j,++m){
            a[m] = i;
        }
    }
}
// - test zone
int main(){
    vector<int> sth1 = {1,5,2,4,3};
    int sth2[5] = {1,5,2,4,3};
    countingSort_vector(sth1);
    for(int i=0;i<5;++i){
        cout<<sth1[i]<<endl;
    }
}

