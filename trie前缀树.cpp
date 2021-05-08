//Trie树，即字典树，也有的称为前缀树，是一种树形结构。广泛应用于统计和排序大量的字符串（但不仅限于字符串），所以经常被搜索引擎系统用于文本词频统计。它的优点是最大限度地减少无谓的字符串比较，查询效率比较高。
//Trie的核心思想是空间换时间，利用字符串的公共前缀来降低查询时间的开销以达到提高效率的目的。
//
//链接：https://leetcode-cn.com/circle/article/mv8GnX/
//https://leetcode-cn.com/problems/implement-trie-prefix-tree/solution/shi-xian-trie-qian-zhui-shu-by-leetcode-ti500/
//算法特征
//1、根节点不包含字符，除根节点外每一个节点都只包含一个字符。
//2、从根节点到某一节点，路径上经过的字符连接起来，为该节点对应的字符串。
//3、每个节点的所有子节点包含的字符都不相同。
//4、它的key都为字符串，能做到高效查询和插入，时间复杂度为O(k)，k为字符串长度，缺点是如果大量字符串没有共同前缀时很耗内存。

//适用范围
//1、单词检索
//2、统计和排序字符串（但不仅限于字符串）
//3、字符串前缀

//算法步骤
//1、定义字典树节点
//2、构造字典树（也就是insert操作）
//3、根据题目要求搜索字典树，在搜索的过程中进行结果的处理

//字典树结构
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Trie {
private:
    vector<Trie*> children;
    bool isEnd;

    // 搜索前缀
    Trie* searchPrefix(string prefix) {
        Trie *node = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }

public:
    Trie() : children(26), isEnd(false) {}

    // 插入单词
    void insert(string word)
    {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    // 查询单词
    bool search(string word)
    {
        Trie *node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }
    // 查询前缀
    bool startsWith(string prefix)
    {
        return this->searchPrefix(prefix) != nullptr;
    }
};
