#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <map>
using namespace std;

int main(){
    //日志行数
    int N;
    //日志集合
    vector<vector<string>> logArray;
    while(cin>>N){
        for(size_t i=0;i<N;++i){
            vector<string> curLog;
            string time;
            string hostID;
            string log_text;
            cin>>time>>hostID>>log_text;
            curLog.push_back(time);
            curLog.push_back(hostID);
            curLog.push_back(log_text);
            logArray.push_back(curLog);
        }

        //查询次数
        int T;
        cin>>T;
        for(int _i=0;_i<T;++_i){
            vector<string> resultArray;
            //存放命令与参数的map
            map<string,string> orderMap;
            int orderNum;
            cin>>orderNum;

            while(orderNum--){
                string orderType;
                string orderArg;
                cin>>orderType>>orderArg;
                orderMap[orderType]=orderArg;
            }
            string findRes=orderMap["--search"];

            string hostID="";
            if(orderMap.find("--hostid")!=orderMap.end()){
                    hostID=orderMap["--hostid"];
                }
            size_t i=0;
            if(hostID==""){
            for(i=0;i<logArray.size();++i){
                if(logArray[i][2].find(findRes)!=std::string::npos){
                    break;
                }
            }
            }else{
            for(i=0;i<logArray.size();++i){
                if(logArray[i][2].find(findRes)!=std::string::npos&&logArray[i][1]==hostID){
                    break;
                }
            }
            }

            if(i==logArray.size()){
                //Do Nothing
            }else{

                int before=3000;
                if(orderMap.find("--before")!=orderMap.end()){
                    before=atoi(orderMap["--before"].data());
                }

                int after=3000;
                if(orderMap.find("--after")!=orderMap.end()){
                    after=atoi(orderMap["--after"].data());
                }

                if(before==3000&&after==3000){
                    resultArray.push_back(logArray[i][2]);
                }
                else{

                    if(before!=3000){
                    int start=0>i-before+1?0:i-before;
                    for(;start<i;++start)
                        resultArray.push_back(logArray[start][2]);
                    }
                    resultArray.push_back(logArray[i][2]);
                    if(after!=3000){
                    int end=logArray.size()-1<i+after?logArray.size()-1:i+after;
                        for(int j=i+1;j<=end;++j)
                            resultArray.push_back(logArray[j][2]);

                    }

                }//end of else


            }//end of else

            if(resultArray.empty())
                std::cout<<"ERROR"<<std::endl;
            else{
                for(string curString:resultArray)



                    std::cout<<curString<<std::endl;
            }
        }
    }
    return 0;
}
