class string
{
        char* array;
        size_t size;
};

out.write(string.size, &string);

this would write out the array pointer, not where the array pointer points.
