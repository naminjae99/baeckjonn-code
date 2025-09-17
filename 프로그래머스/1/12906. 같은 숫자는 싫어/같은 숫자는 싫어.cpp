#include <vector>
#include <iostream>
#include<deque>
using namespace std;


vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    for(auto c:arr){
       if(answer.empty())
           answer.push_back(c);
        else{
            if(answer.back()==c)
                continue;
            else
                answer.push_back(c);
        }
    }
    

    return answer;
}