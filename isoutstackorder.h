#ifndef ISOUTSTACKORDER_H
#define ISOUTSTACKORDER_H
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty()||popV.empty()||pushV.size()!=popV.size())
            return false;
        else{
            stack<int> assistStack;
            int popIndex=0;
            for(int i=0;i<pushV.size();++i){
                assistStack.push(pushV[i]);

                //往辅助栈中放入元素，直到栈顶元素等于当前出栈的元素
                while(!assistStack.empty()&&assistStack.top()==popV[popIndex]){
                    //辅助栈栈顶元素出栈
                    //当前出栈的元素指向出栈集合的下一个元素
                    ++popIndex;
                    assistStack.pop();
                }

            }

            //辅助栈为空 说明辅助栈可以模拟元素的入栈、出栈
            return assistStack.empty();
        }
    }
};
#endif // ISOUTSTACKORDER_H
