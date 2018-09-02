#include <vector>
using namespace std;
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > mat) {
        const int n=mat.size();
        if(n==0){
            return vector<int>();
        }else{
            const int m=mat[0].size();
            const int eleSize=n*m;
            std::vector<int> res(eleSize,0);

            int startX=0;
            int endX=n-1;
            int startY=0;
            int endY=m-1;

            /*
         * matrix
         * 0,0    0,1 ... 0,m-1
         * 1,0
         * .
         * .
         * .
         * n-1,0  n-1,1 ... n-1,m-1
         */

            int i=0;
            int j=0;
            int k=0;
            while(startX<=endX&&startY<=endY){

                //当前仅有一行
                if(startX==endX){
                    for(;j<=endY;++j)
                        res[k++]=mat[startX][j];
                    return res;
                }

                //当前仅有一列
                if(startY==endY){
                    for(;i<=endX;++i)
                        res[k++]=mat[i][startY];
                    return res;
                }

                //顺时针遍历矩阵
                //1、打印最上面的行，除去最右边的元素
                for(;j<endY;++j)
                    res[k++]=mat[i][j];

                //2、打印右边的行，除去最下面的一个元素
                for(;i<endX;++i)
                    res[k++]=mat[i][j];

                //3、打印下面的行，除去最左边的元素
                for(;j>startY;--j)
                    res[k++]=mat[i][j];

                //4、打印最左边的行，除去最上面的那个元素
                for(;i>startX;--i)
                    res[k++]=mat[i][j];

                //缩小范围
                i++;
                j++;
                startX++;
                endX--;

                startY++;
                endY--;
            }//end of while

            return res;
        }
    }
};
