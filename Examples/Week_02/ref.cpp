//pass via a pointer
int doit(int * i)
{
        *i = 5;
        return 0;
}

//pass by reference type 
int doit(int & i)
{
        int & o;
        i=5; //same!!!
}
