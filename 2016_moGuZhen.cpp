#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int map[21][21];
float dp[21][21];

bool validCoord(int xCoord,int yCoord,int N,int M){
    return (xCoord>=1&&xCoord<=N&&yCoord>=1&&yCoord<=M);
}

int main(){
    int N;
    int M;
    int K;
    while(cin>>N>>M>>K){
        memset(map,0,sizeof(map));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<K;++i){
            int xCoord;
            int yCoord;
            cin>>xCoord>>yCoord;
            map[xCoord][yCoord]=1;
        }
        
        dp[1][1]=1;
        
        for(int i=1;i<=N;++i){
            for(int j=1;j<=M;++j){
               if(map[i][j]==1) 
                   dp[i][j]=0;
                
               if(validCoord(i+1,j,N,M)&&validCoord(i,j+1,N,M)){
                   dp[i+1][j]+=dp[i][j]*0.5;
                   dp[i][j+1]+=dp[i][j]*0.5;
               }
               else if(validCoord(i+1,j,N,M))
                   dp[i+1][j]+=dp[i][j];
               else if(validCoord(i,j+1,N,M))
                   dp[i][j+1]+=dp[i][j];
            }
        }
        cout.setf(ios::fixed);
        std::cout<<fixed<<setprecision(2)<<dp[N][M]<<std::endl;
    }
}