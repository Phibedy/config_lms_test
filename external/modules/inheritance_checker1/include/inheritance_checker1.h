#ifndef INHERITANCE_CHECKER1_H
#define INHERITANCE_CHECKER1_H

#include <lms/datamanager.h>
#include <lms/module.h>
#include "street_environment/road.h"

class InheritanceChecker1 : public lms::Module {
    lms::ReadDataChannel<lms::math::polyLine2f> rA;
public:
    bool initialize();
    bool deinitialize();
    bool cycle();
};

#endif // INHERITANCE_CHECKER1_H
