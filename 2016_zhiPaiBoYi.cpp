class Cards {
public:
    int cardGame(vector<int> A, int n) {
        // write code here
        int firScore[n][n];
        int secScore[n][n];
        
        memset(firScore,0,sizeof(firScore));
        memset(secScore,0,sizeof(secScore));
        

       /*
         对于范围为A[l...r]内的数，先手有两种情形：
         1、拿第一个元素A[l]，拿完之后，对于A[l+1,r]内的元素，先手变为后手，之后所能拿到的最大值为 secScore[l+1][r];
         2、拿最后一个元素A[r]，拿完之后，对于A[l...r-1]内的元素，先手变为后手，之后所能拿到的最大的值为 secScore[l][r-1]
         因此：
       * firScore[l][r]=max(A[l]+secScore[l+1][r],A[r]+secScore[l][r-1]);
       
         对于范围为A[l...r]内的数，后手所能拿到的最大值为：
         先手拿完一个元素后，后手变为先手，但是先手是绝顶聪明的，会把小的留给后手，
         因此：
         secScore[l][r]=min(firScore[l+1][r],firScore[l][r-1]); 
       */
        for(int i=0;i<n;++i){
            firScore[i][i]=A[i];
            secScore[i][i]=0;
        }
        
        for(int r=1;r<n;++r){
            for(int l=r-1;l>=0;--l){
                firScore[l][r]=std::max(A[l]+secScore[l+1][r],A[r]+secScore[l][r-1]);
                secScore[l][r]=min(firScore[l+1][r],firScore[l][r-1]);
            }
        }
        
        return std::max(firScore[0][n-1],secScore[0][n-1]);
    }
};