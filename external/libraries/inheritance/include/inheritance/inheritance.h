#ifndef INHERITANCE_INHERITANCE_H
#define INHERITANCE_INHERITANCE_H
#include "lms/inheritance.h"
#include "street_environment/road.h"
#include "lms/math/polyline.h"

namespace inheritance_test{


/**
 * @brief Implementation of a 2-dimensional vector.
 */
template <typename T>
class vertex2{

public:
    /*
    virtual void makeItWork(){
    }
    */

    virtual ~vertex2() {}
};
typedef vertex2<float> vertex2f;

class A0{
public:
};

class A: public vertex2f, public A0, public lms::Inheritance{
public:
    bool isSubType(size_t hashcode) const override{
        std::cout << "IN A "<<typeid(A).hash_code() << " "<< hashcode <<std::endl;
        return lms::Impl<A0>::isSubType(hashcode,this);
    }
};


class C: public lms::Inheritance{
public:
    virtual bool isSubType(size_t hashcode) const override{
        std::cout << "WTH IN C "<<typeid(C).hash_code() << " "<< hashcode <<std::endl;
        return false;//Inheritance::isSubType<A>(hashcode);
    }

};

class B:virtual public C, virtual public A{
public:

    bool isSubType(size_t hashcode) const override{
        std::cout << "IN B "<<typeid(B).hash_code() << " "<< hashcode  <<std::endl;
        //return Inheritance::validTypes<A,C>(hashcode,this);
        return lms::Impl<A,C>::isSubType(hashcode,this);
    }

};


}//namespace inheritance_test

#endif //INHERITANCE_INHERITANCE_H
