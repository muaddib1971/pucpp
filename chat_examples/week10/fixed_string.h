#include <array>

template <int I>
public class fixed_string : std::array<I>
{
    public: 
        fixed_string(char*);
        fixed_string(const std::string&);
};

class stack<T> extends vector<T>
{
};

class action
{
    public: 
        virtual doit(void) = 0; /* no implementation provided */
};

action::doit(void)
{
    std::cout << "I am doing it" << std::endl;
};

class open_action : public action;
{
    public virtual doit(void) final;
    public doiit(void) final;
};

std::array<action*, NUMACTIONS> actions; 

action[2]->doit();

/* polymorphism - virtual function table */
struct person
{
    std::string fname, lname;
    int age;
};

struct student : public person
{
    std::string student_id;
};

student s {"fred", "flintsone", 40, "s36866383"};

person * p = &s;
class parent
{
    int i;
    public:
        parent(int i_) : i(i_)
        {
        }
};

class child : public parent
{
    using parent::parent;

    friend class loader;
    friend loader::load(const std::string &);
    public: 
        child operator=(const child & rhs);
};

class grandchild : public child
{
};


class string
{
    public:
    string(char*);
};

class game
{
    int score;

    public:
        game(int i) : score(i)
        {
        }
        const int & get_score() const
        {
            return score;
        }
        operator int()
        {
            return score;
        }
};

game g = 5;
int i = g;

class character{};
class mage : public character{}
class warrior : public character{}

std::vector<std::unique_ptr<character>> characters;

const character * mychar = characters[3].get();

const mage * mymage;
const warrior * mywarrior;

mymage = dynamic_cast<const mage*>(mychar);
mywarrior = dynamic_cast<const warrior*>(mychar);

typeid(mymage).name() // returns a typeinfo object
namespace foo
{
    namespace bar
    {
        class student;
        std::ostream& operator<<(std::ostream&, const student&);
        class student
        {
            std::string fname, lname;
            int age;
            std::string student_id;
            friend std::ostream& operator<<(std::ostream&, const student&);
            public:
                student(std::string fname, std::string lname, int age, 
                    std::string id)
                {
                }
        }

    }
}

//in the cpp file: 
//
std::ostream& foo::bar::operator<<(std::ostream& out, const foo::bar::student& s)
{
    out << s.fname << "\t";
    return out;
}

enum class direction
{
    UP, DOWN
};


direction dir = direction(1);
int i = dir;
