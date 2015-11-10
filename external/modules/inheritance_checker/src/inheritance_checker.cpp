#include "inheritance_checker.h"
#include "lms/inheritance.h"
#include "inheritance/inheritance.h"

bool InheritanceChecker::initialize() {
    logger.debug("trying to get type A");
    lms::ReadDataChannel<inheritance_test::A0> rA = datamanager()->readChannel<inheritance_test::A0>(this,"MAIN");
    return true;
}

bool InheritanceChecker::deinitialize() {
    return true;
}

bool InheritanceChecker::cycle() {
    return true;
}
