
#include <queue>
#include <iostream>
#include <string>

struct Stud
{
  int no;
  std::string name;
  Stud(int n, std::string na) : no(n), name(na) {}
  
  bool operator<(const Stud& s) const // 重载 < 关系函数
  {
    return no < s.no;
  }
  bool operator>(const Stud& s) const // 重载 > 关系函数
  {
    return no > s.no;
  }
};

struct StudCmp
{
  bool operator()(const Stud& s1, const Stud& s2) const
  {
    return s1.name > s2.name; // name 越小越优先
  }
};

int main()
{
  Stud a[] = { Stud(1, "Mary"), Stud(3, "John"), Stud(2, "Smith") };
  int n = sizeof(a) / sizeof(a[0]);

  {
    std::priority_queue<Stud> pq(a, a + n);
    while (!pq.empty()) {
      std::cout << "[" << pq.top().no << "," << pq.top().name << "] ";
      pq.pop();
    }
    std::cout << std::endl;
  }

  {
    std::priority_queue<Stud, std::vector<Stud>, std::greater<Stud>> pq(a, a + n);
    while (!pq.empty()) {
      std::cout << "[" << pq.top().no << "," << pq.top().name << "] ";
      pq.pop();
    }
    std::cout << std::endl;
  }

  {
    std::priority_queue<Stud, std::vector<Stud>, StudCmp> pq(a, a + n);
    while (!pq.empty()) {
      std::cout << "[" << pq.top().no << "," << pq.top().name << "] ";
      pq.pop();
    }
    std::cout << std::endl;
  }
  
  return 0;
}