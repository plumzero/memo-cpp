
1.[初始化](01_vector_initialize.cpp)

2.[容量增加造成内存重分配测试](02_vector_reserve.cpp)

3.[改变容器大小](03_vector_resize.cpp)

通过调用成员函数 resize() 可以改变容器大小，这也可能导致容量的增加。

因为内存重分配会产生值的初始化(value initialized)，这会调用到容器元素的缺省构造函数。

也即如果想要执行 resize, 则要求容器元素必须要有缺省构造函数。

也可以看出，resize 会涉及到赋值，因而大量的 resize 操作会影响效率。

4.[元素访问](04_vector_access.cpp)

5.[在容器中生成对象](05_vector_emplace.cpp)

利用成员函数 emplace_back emplace 可以在容器中直接生成对象，而不是先单独生成对象，然后再把它作为参数传入。

6.[erase-remove操作](06_erase_remove.cpp)

成员函数 erase 只能删除某个迭代器指定或两个迭代器之间的元素，无法删除容器中指定为某个值(四散于容器中)的元素。

全局函数 remove 可以移除容器中所有指定为某个值的元素。

remove 移除不会删除容器中的元素，而是通过匹配元素右边的元素来覆盖匹配元素的方式移除元素。

可以结合成员函数 erase() 删除迭代器对方式删除该指定值元素。
