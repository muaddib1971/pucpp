class foo
{
  
public:
  foo(int i)
  {
  }
  virtual int doit();
};

class bar : public foo
{
  //using foo::foo;
public:
  bar() : foo(3) {} 
  virtual final int doit()
  {
  }
};

class baz : public foo
{
public:
  virtual int doot() override
  {
  }
};


int main()
{
  foo * f = new bar;
  foo * g = new baz;

  f->doit();
  g->doit();
}
  
