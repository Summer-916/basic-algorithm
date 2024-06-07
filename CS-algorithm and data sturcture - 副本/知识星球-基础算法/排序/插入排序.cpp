#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// - vector
void insertSort_vector(vector<int>& a){
    int n = a.size();
    for(int i=1;i<n;++i){
        int x = a[i];
        int j = i-1;
        while(j>=0){
            if(a[j]>x){
                a[j+1] = a[j];
                j--;
            }else break;
        }
        a[j+1] = x;
    }
}

// - array
void insertSort_array(int* a,int n){
    for(int i=1;i<n;++i){
        int x=a[i];
        int j=i-1;
        while(j>=0){
            if(a[j]>x){
                a[j+1]=a[j];
                j--;
            }else break;
        }
        a[j+1] = x;
    }
}

// - test zone
int main(){
    vector<int> sth1 = {1,5,2,4,3};
    int sth2[5] = {1,5,2,4,3};
    insertSort_array(sth2,5);
    for(int i = 0;i<5;++i){
        cout<<sth2[i]<<endl;
    }
}