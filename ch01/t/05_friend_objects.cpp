
class Complex
{
public:
  Complex(double r = 0, double i = 0)
    : re(r), im(i) {}

  int func(const Complex& param) {
    return param.re + param.im; // re im 虽然为 private, 但在同类对象中可以直接访问
  }

private:
  double re, im;
};

int main()
{
  Complex c1(2, 1);
  Complex c2;

  c2.func(c1);

  return 0;
}