#include "inheritance_checker1.h"
#include "inheritance/inheritance.h"

bool InheritanceChecker1::initialize() {
    logger.debug("trying to get type B");
    lms::ReadDataChannel<inheritance_test::B> rB = datamanager()->readChannel<inheritance_test::B>(this,"MAIN");
    return true;
}

bool InheritanceChecker1::deinitialize() {
    return true;
}

bool InheritanceChecker1::cycle() {
    return true;
}
