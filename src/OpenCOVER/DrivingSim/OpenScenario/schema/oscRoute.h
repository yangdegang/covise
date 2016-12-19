/* This file is part of COVISE.

You can use it under the terms of the GNU Lesser General Public License
version 2.1 or later, see lgpl - 2.1.txt.

* License: LGPL 2 + */


#ifndef OSCROUTE_H
#define OSCROUTE_H

#include "../oscExport.h"
#include "../oscObjectBase.h"
#include "../oscObjectVariable.h"
#include "../oscObjectVariableArray.h"

#include "../oscVariables.h"
#include "oscWaypoint.h"

namespace OpenScenario
{
class OPENSCENARIOEXPORT oscRoute : public oscObjectBase
{
public:
oscRoute()
{
        OSC_ADD_MEMBER(name);
        OSC_ADD_MEMBER(closed);
        OSC_OBJECT_ADD_MEMBER(Waypoint, "oscWaypoint");
    };
    oscString name;
    oscBool closed;
    oscWaypointArrayMember Waypoint;

};

typedef oscObjectVariable<oscRoute *> oscRouteMember;
typedef oscObjectVariableArray<oscRoute *> oscRouteArrayMember;


}

#endif //OSCROUTE_H
