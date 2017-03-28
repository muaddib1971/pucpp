class foo
{
        public:
        foo(int i, int j=0, int k=0)
        {

        }

        /* references
         * pointers
         * values
         */
        int doit(int &* i)
        {
                *i = 10;
                int & j;
        }
        std::vector<std::vector<Cell>> v;
        std::vector<std::vector<Cell>>::iterator it = v.begin();
        auto it = v.begin();
        auto a;//illegal
};
