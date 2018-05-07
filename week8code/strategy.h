struct strategy
{
        virtual double operator()(const graph& g, const coordinates& coord) = 0;
};

struct manhattan : public strategy
{
        virtual double operator()(const graph& g,
                                  const coordinates& coord)override
        {
        }
};

struct euclidean : public strategy
{
        virtual double operator()(const graph& g,
                                  const coordinates& coord)override
        {
        }
};

std::list<coordinates> find_path(const graph& g, const strategy& heur)
{
        coordinates current{ 0, 0 };
        coordinates test = { current.x + 1, y };
        if (heur(g, test) < heur(g, current))
        {
        }
}

int main(void)
{
        std::list<coordinates> path = find_path(g, euclidean());
        using solution_map =
            std::multimap<coordinates, std::list<coordinates> >;
        solution_map::iterator it;
        myiterator;
}
