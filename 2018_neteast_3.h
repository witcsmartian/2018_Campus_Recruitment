#ifndef 2018_NETEAST_3_H
#define 2018_NETEAST_3_H
#include <iostream>
#include <string>

using namespace std;

#define MAX_NUM 4294967295

int64_t cal_num(string& Z, int64_t first, int64_t last, int& radix)
{
    int64_t ret = 0;
    int64_t r = 1;
    int num = 0;
    for (int64_t i = last; i >= first; i--) {
        if (Z[i] < 59)
            num = Z[i] - '0';
        else
            num = Z[i] - 'A' + 10;
        ret += num * r;
        if (ret > MAX_NUM) {
            return INT64_MAX;
        }

        r *= radix;
    }
    return ret;
}

int64_t analyze_num(int& X, int& Y, string& Z)
{
    int64_t b = 0, e = Z.length() - 1, len = Z.length() - 1, mid = 0;
    int64_t frontNum, lastNum;
    while (b <= e) {
        mid = (b + e) / 2;
        frontNum = cal_num(Z, 0, mid, X);
        lastNum = cal_num(Z, mid + 1, len, Y);
        if (frontNum == lastNum) {
            return frontNum;
        }
        else if (frontNum > lastNum) {
            e = mid - 1;
        }
        else {
            b = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int T,X,Y;
    string Z;
    cin >> T;
    while (T--) {
        cin >> X >> Y;
        cin >> Z;
        cout<<  analyze_num(X, Y, Z)<<endl;
    }
    return 0;
}

#endif // 2018_NETEAST_3_H
