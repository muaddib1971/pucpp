
class observed {
    friend class observer;
};

class observer {
    observed obs;
};

class child_observer : public observer {
    // not a friend of observed.
};

class parent {
    int i;

   public:
    parent(int _i = 0) : i(_i) {}
};

class child : public parent {
   public:
    // child() : parent() {}
    using parent::parent;
};  // compiler error
