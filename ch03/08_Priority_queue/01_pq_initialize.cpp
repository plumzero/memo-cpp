
#include <queue>
#include <iostream>
#include <string>

/**
 * 缺省的 std::priority_queue 是在 std::vector 容器上实现的。
 * 当然 priority_queue 也可以在 std::deque 容器上适配实现。
 * 不过由于 priority_queue 要求提供随机访问功能，因此它不能建立在 std::list 容器上。
*/

int main()
{
  // 生成空 p 队列
  {
    std::priority_queue<std::string> words;
    
    (void) words;
  }
  
  // 通过迭代器初始化
  {
    std::string wrds[] { "one", "two", "three", "four" };
    std::priority_queue<std::string> words {std::begin(wrds), std::end(wrds)};
    
    (void) words;
  }
  
  // 指定其他"优先级"
  {
    std::string wrds[] { "one", "two", "three", "four" };
    std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string>> words {std::begin(wrds), std::end(wrds)};
    
    (void) words;
  }
  
  // 通过容器初始化
  {
    std::vector<int> values{ 21, 22, 12, 3, 24, 54, 56 };
    std::priority_queue<int> numbers { std::less<int>(), values };
    // 构造时，第一个参数是一个用来对元素排序的函数对象
    (void) numbers;
  }
  
  return 0;
}