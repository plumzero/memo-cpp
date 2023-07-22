
### 说明

priority_queue 的特征有两个，分别是队列和优先级。

缺省的 std::priority_queue 是在 std::vector 容器上实现的。当然 priority_queue 也可以在 std::deque 容器上适配实现。不过由于 priority_queue 要求提供随机访问功能，因此它不能建立在 std::list 容器上。

### 定义

priority_queue 模板有 3 个模板参数，第一个参数存储对象的类型，第二个参数是存储元素的底层容器，第三个参数是函数对象，它定义了一个用来决定元素顺序的断言，也就是"优先级"的定义。
```c++
  template<typename T, typename C = std::vector<T>, typename Compare = std::less<T>>
    class priority_queue;
```
后面两个模板参数有缺省参数，缺省时底层容器为 vector, 最大元素在前面。

通过第二个模板类型参数，也可以使用其他底层容器，只要它们支持 front()、push_back()、pop_back()、empty()、size() 这些操作。

使用其他优先级规则:
```c++
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
```

### 使用

1.[初始化](08_Priority_queue/01_pq_initialize.cpp)

priority_queue 的操作可以参考 queue

2.对于非 C/C++ 内置数据类型，默认以 less<T> (小于关系函数)作为关系函数，但需要重载该运算符，用户也可以自己定义相应的关系函数。

[自定义](08_Priority_queue/02_pq_comp.cpp)
