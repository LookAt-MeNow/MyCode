
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n=0,m=0;
    int a[n][m] = {0,0};
    int t;
    int count = 0;
    
    cin>>n;
    cin>>m;
    
    cin>>t;
    int r1,c1,r2,c2;
    for(int i =0;i<t;i++){
        cin>>r1>>c1>>r2>>c2; 
        for(r1;r1<=r2;r1++){
            int c11 = c1;
            for(c11;c11<=c2;c11++){
                a[r1][c11] +=1;
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == 0){
                count++;
            }
        }
    }
    cout <<count<<endl;
    return 0;
}