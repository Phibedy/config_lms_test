#include "inheritance_checker.h"
#include "lms/inheritance.h"
#include "inheritance/inheritance.h"
#include "lms/inheritance.h"
#include "lms/data_channel_internal.h"
#include "lms/data_channel.h"

//UTIL_CLASSES
class Inheritance{
public:
    virtual void callMe()  = 0;
    virtual ~Inheritance(){}

};

class ObjectBase{
public:
    ~ObjectBase(){}
    template<typename T>
    bool checkType() {
        return false;
    }
    virtual void *get() = 0;
};

template<typename T>class Object: public ObjectBase{
public:
    T obj;

    void* get() override{
            return &obj;
}
};

//TEST_CLASSES
/**
 * @brief Implementation of a 2-dimensional vector.
 */
template <typename T>
class vertex2{

public:
    virtual ~vertex2() {}
};

class vertex2Dump{
    public:
    virtual ~vertex2Dump(){}
};

typedef vertex2Dump vertex2f;
//typedef vertex2<float> vertex2f;

class A0{
public:
    virtual ~A0(){}
};
///removing vertex2f causes the programm to work like it should!
class A: public A0, public Inheritance{
public:
    void callMe() override{
        std::cout << "IN A "<<std::endl;
    }
};

bool InheritanceChecker::initialize() {
    typedef A T;

    //doesn't work
    std::cout << "1."<<std::endl;
    std::unique_ptr<ObjectBase> main;
    main.reset(new Object<T>);
    Inheritance *inh = static_cast<Inheritance*>(main->get());
    inh->callMe();

    //works with clang but throws a segfault in gcc 4.9
    std::cout << "2."<<std::endl;
    static_cast<T*>(main->get())->callMe();

    return true;
}

bool InheritanceChecker::deinitialize() {
    return true;
}

bool InheritanceChecker::cycle() {
   //logger.debug("cycle");
    //rA->name("heyho");
    //logger.debug("name")<<rA->name();
    return true;
}

