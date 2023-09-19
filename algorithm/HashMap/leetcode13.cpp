//将罗马数字转换为阿拉伯数字并输出
#include<iostream>
#include<map>
using namespace std;


/* class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int a = 0;
        map<char,int> HashMap;
        HashMap.insert(make_pair('I',1));
        HashMap.insert(make_pair('V',5));
        HashMap.insert(make_pair('X',10));
        HashMap.insert(make_pair('L',50));
        HashMap.insert(make_pair('C',100));
        HashMap.insert(make_pair('D',500));
        HashMap.insert(make_pair('M',1000));
        for(int i = 0;i<s.size();i++){
            if(s[i] == 'I' && s[i+1] == 'V'){
                a=4;
                sum +=a;
                i++;
                continue;
            }else if(s[i] == 'I' && s[i+1] == 'X'){
                a=9;
                sum +=a;
                i++;
                continue;
            }else if(s[i] == 'X' && s[i+1] == 'L'){
                a=40;
                sum +=a;
                i++;
                continue;
            }else if(s[i] == 'X' && s[i+1] == 'C'){
                a=90;
                sum +=a;
                i++;
                continue;
            }else if(s[i] == 'C' && s[i+1] == 'D'){
                a=400;
                sum +=a;
                i++;
                continue;
            }else if(s[i] == 'C' && s[i+1] == 'M'){
                a=900;
                sum +=a;
                i++;
                continue;
            }
            sum = sum + HashMap[s[i]];
        }
        return sum;
    }
}; *///我使用的笨方法

//优秀题解

class Solution{
public:
    int romanToInt(string s) {
        int sum = 0;
        map<char,int> HashMap={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D', 500},
            {'M', 1000}
        };
        for(int i = 0;i<s.size();i++){
            if(HashMap[s[i]]<HashMap[s[i+1]])
                sum -= HashMap[s[i]];
            else 
                sum += HashMap[s[i]];
        }
        return sum;
    }
};
