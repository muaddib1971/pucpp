template<class T, std::size_t SIZE>
class array
{
    T data[SIZE];

    public: 
       static int iterator;
       std::size_t size();
       std::size_t capacity();
    
       T& operator[](std::size_t offset)
       {
           return data[offset];
       }
};

int main(void)
{
    array<double, 20> myarray;
    double somearray[20];
    myarray[3] = 4.23453;
    typename array<double, 20>::iterator it;
}
