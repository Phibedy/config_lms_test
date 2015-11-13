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
typedef vertex2<float> vertex2f;

class A0{
public:
};

class A: public vertex2f, public A0, public Inheritance{
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


    //if vertex2f is removed, callMe is called in both cases and gcc doesn't crash!



    //lms::WriteDataChannel<T> d  = datamanager()->writeChannel<T>(this,"A");


    //trying to call the method isSubType overriden in A, tested with gcc 4.9 and clang 3.4
    /*
    //works
    logger.info("0 YES:");
    d.get()->isSubType(12);

    //doesn't work
    logger.info("1 NO:");
    static_cast<lms::Inheritance*>(d.m_internal->main->get())->isSubType(12);

    //works with clang but throws a segfault in gcc 4.9
    logger.info("3 (Yes)");
    static_cast<T*>(d.m_internal->main->get())->isSubType(12); //same as d.get() but causes a seqfault with gcc 4.9, but works with clang

    //doesn't work
    logger.info("4. NO");
    std::unique_ptr<ObjectBase> main;
    main.reset(new Object<T>);
    lms::Inheritance *inh = static_cast<lms::Inheritance*>(main->get());
    inh->isSubType(12);

    //works with clang but throws a segfault in gcc 4.9
    logger.info("5. (Yes)");
    static_cast<T*>(main->get())->isSubType(12);
    */

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

