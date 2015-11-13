#include "inheritance_checker1.h"
#include "inheritance/inheritance.h"

bool InheritanceChecker1::initialize() {
    /*
    logger.debug("trying to get type B");
    rA = datamanager()->readChannel<lms::math::polyLine2f>(this,"MAIN");
    rA = datamanager()->readChannel<lms::math::polyLine2f>(this,"fake");
    datamanager()->readChannel<inheritance_test::A0>(this,"A");
    */
    return true;
}

bool InheritanceChecker1::deinitialize() {
    return true;
}

bool InheritanceChecker1::cycle() {
    /*
    logger.debug("cycle");
    if(rA.castableTo<inheritance_test::RoadLane>()){
        street_environment::RoadLane *rl = (street_environment::RoadLane*)rA.get();
        //logger.debug("pointCOunt: ")<<rl->points().size();
        //logger.debug("name")<<rl->name();
    }
    */
    return true;
}
