class Solution {
public:
    /**
     * 获得两个整形二进制表达位数不同的数量
     * 
     * @param m 整数m
     * @param n 整数n
     * @return 整型
     */
    
    vector<int> num2BinaNum(int n){
        vector<int> result(32,0);
        for(size_t i=0;i<32;++i){
            if(n<<i&0x80000000)
                result[i]=1;
            else
                result[i]=0;
        }
        
        return result;
    }
    int countBitDiff(int m, int n) {
        
        vector<int> binaNumM=std::move(num2BinaNum(m));
        vector<int> binaNumN=std::move(num2BinaNum(n));
        
        int result=0;
        for(size_t i=0;i<32;++i){
            if(binaNumM[i]!=binaNumN[i])
                result++;
        }
        
        return result;
    }
};