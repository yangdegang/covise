/* This file is part of COVISE.

   You can use it under the terms of the GNU Lesser General Public License
   version 2.1 or later, see lgpl-2.1.txt.

 * License: LGPL 2+ */

//
//  Vrml 97 library
//  Copyright (C) 1998 Chris Morley
//
//  %W% %G%
//  VrmlNodeSpotLight.h

#ifndef _VRMLNODESPOTLIGHT_
#define _VRMLNODESPOTLIGHT_

#include "VrmlNodeLight.h"
#include "VrmlSFFloat.h"
#include "VrmlSFVec3f.h"

namespace vrml
{

class VRMLEXPORT VrmlNodeSpotLight : public VrmlNodeLight
{

public:
    // Define the fields of spotLight nodes
    static VrmlNodeType *defineType(VrmlNodeType *t = 0);
    virtual VrmlNodeType *nodeType() const;

    VrmlNodeSpotLight(VrmlScene *);
    virtual ~VrmlNodeSpotLight();

    virtual VrmlNode *cloneMe() const;

    virtual VrmlNodeSpotLight *toSpotLight() const;

    virtual void addToScene(VrmlScene *s, const char *);

    virtual std::ostream &printFields(std::ostream &os, int indent);

    virtual void render(Viewer *);

    virtual void setField(const char *fieldName, const VrmlField &fieldValue);
    const VrmlField *getField(const char *fieldName) const;

    //LarryD Mar 04/99
    virtual const VrmlSFVec3f &getAttenuation() const;
    //LarryD Mar 04/99
    virtual const VrmlSFVec3f &getDirection() const;
    //LarryD Mar 04/99
    virtual const VrmlSFVec3f &getLocation() const;
    virtual float getBeamWidth() //LarryD Mar 04/99
    {
        return d_beamWidth.get();
    }
    virtual float getCutOffAngle() //LarryD Mar 04/99
    {
        return d_cutOffAngle.get();
    }
    virtual float getRadius() //LarryD Mar 04/99
    {
        return d_radius.get();
    }

protected:
    VrmlSFVec3f d_attenuation;
    VrmlSFFloat d_beamWidth;
    VrmlSFFloat d_cutOffAngle;
    VrmlSFVec3f d_direction;
    VrmlSFVec3f d_location;
    VrmlSFFloat d_radius;
};
}
#endif //_VRMLNODESPOTLIGHT_
