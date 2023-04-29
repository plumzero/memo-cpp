
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

/**
    可能的实现:
    template<class ForwardIt1, class ForwardIt2, class BinaryPredicate>
    ForwardIt1 find_end(ForwardIt1 first, ForwardIt1 last,
                        ForwardIt2 s_first, ForwardIt2 s_last,
                        BinaryPredicate p)
    {
        if (s_first == s_last)
            return last;
        ForwardIt1 result = last;
        while (true) {
            ForwardIt1 new_result = std::search(first, last, s_first, s_last, p);
            if (new_result == last) {
                break;
            } else {
                result = new_result;
                first = result;
                ++first;
            }
        }
        return result;
    }
    
    说明:
        1. find_end 与 find_if 用法类似，只不过 find_if 查找的是单个对象，而 find_end 查
           找的是一组对象；
        2. find_end 谓词用法应用较少，可以参考体会 find_if 的用法。

    关键词:
        1. 前向迭代器
        2. 二元谓词，返回值为布尔类型
        3. serarch 查找的是第一次出现的位置，而 find_end 查找的是最后一次出现的位置
        4. 函数返回值: 返回 [s_first, s_last) 序列区间在 [first, last) 最后一次出现的位置
 */

int main()
{
    std::string sentence("Can you can a can as a canner can can a canon. Ok, Can?");
    std::string word("can");
    
    auto iter = std::find_end(sentence.begin(), sentence.end(), word.begin(), word.end());
    if (iter != sentence.end()) {
        std::ostream_iterator<char> outIter(std::cout);
        std::copy(iter, sentence.end(), outIter);
        std::cout << std::endl;
    } else {
        std::cout << "not found" << std::endl;
    }
    
    return 0;
}