/******************************************************************************
  This source file is part of the Avogadro project.
  This source code is released under the 3-Clause BSD License, (see "LICENSE").
******************************************************************************/

#ifndef AVOGADRO_RENDERING_BSPLINEGEOMETRY_H
#define AVOGADRO_RENDERING_BSPLINEGEOMETRY_H

#include "curvegeometry.h"

namespace Avogadro {
namespace Rendering {

class AVOGADRORENDERING_EXPORT BSplineGeometry : public CurveGeometry
{
public:
  BSplineGeometry();
  BSplineGeometry(bool flat);

protected:
  Vector3f computeCurvePoint(float t,
                             const std::list<Point*>& points) const override;
};

} // End namespace Rendering
} // End namespace Avogadro

#endif
