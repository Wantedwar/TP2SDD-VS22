
#include "uniqueID.h"


int uniqueID::nextID = 0;

uniqueID::uniqueID() {
    id = ++nextID;
}

