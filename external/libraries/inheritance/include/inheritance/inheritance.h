#ifndef INHERITANCE_INHERITANCE_H
#define INHERITANCE_INHERITANCE_H
#include "lms/inheritance.h"

namespace inheritance_test{
class A0: public lms::Inheritance{
public:
    bool isSubType(size_t hashcode) override{
        std::cout << "IN A0 "<< typeid(A0).hash_code() << " "<< hashcode <<std::endl;
        return false;
    }
};

class A: public A0{
public:
    bool isSubType(size_t hashcode) override{
        std::cout << "IN A "<<typeid(A).hash_code() << " "<< hashcode <<std::endl;
        return Inheritance::isSubType<A0>(hashcode);
    }

};
class C: public lms::Inheritance{
public:
    bool isSubType(size_t hashcode) override{

        std::cout << "WTH IN C "<<typeid(C).hash_code() << " "<< hashcode <<std::endl;
        return false;//Inheritance::isSubType<A>(hashcode);
    }

};

class B: public lms::Inheritance{
public:

    bool isSubType(size_t hashcode) override{
        std::cout << "IN B "<<typeid(B).hash_code() << " "<< hashcode  <<std::endl;
        return Inheritance::isSubType<C,A>(hashcode);
    }

};
}//namespace inheritance_test

#endif //INHERITANCE_INHERITANCE_H
