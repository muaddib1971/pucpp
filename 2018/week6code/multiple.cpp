class vegetable
{
      public:
        virtual int eat();
};

class fruit
{
      public:
        virtual int eat();
} class tomatoe : public fruit, public vegetable
{
      public:
        virtual int eat();
};
