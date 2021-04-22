// https://www.zhihu.com/question/21923021
#include<vector>
#include<string>
#include<iostream>
using namespace std;


/* 获得next数组
 * 求next数组的过程完全可以看成字符串匹配的过程，即以模式字符串为主字符串，
 * 以模式字符串的前缀为目标字符串，一旦字符串匹配成功，那么当前的next值就是匹配成功的字符串的长度。
*/
void getNext(const string pattern, vector<int> &next)
{
    next[0] = -1;
    int i = 0, j = -1;

    while (i < pattern.size() - 1) {
        if (j == -1 || pattern[i] == pattern[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j];
        }

    }
    return;
}

int KMP(const string str, const string pattern)
{
    vector<int> next(pattern.size());
    getNext(pattern, next); //获取next数组

    int i = 0;
    int j = 0;

    while (i < str.size() && j < (int)pattern.size()) {
        if (j == -1 || str[i] == pattern[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }

    if (j == pattern.size()) {
        return i - j;
    }

    return -1;
}
