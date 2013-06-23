///////////////////////////////////////////////////////////////////////////////
// Copyright � 2002, Open Design Alliance Inc. ("Open Design") 
// 
// This software is owned by Open Design, and may only be incorporated into 
// application programs owned by members of Open Design subject to a signed 
// Membership Agreement and Supplemental Software License Agreement with 
// Open Design. The structure and organization of this Software are the valuable 
// trade secrets of Open Design and its suppliers. The Software is also protected 
// by copyright law and international treaty provisions. You agree not to 
// modify, adapt, translate, reverse engineer, decompile, disassemble or 
// otherwise attempt to discover the source code of the Software. Application 
// programs incorporating this software must include the following statement 
// with their copyright notices:
//
//      DWGdirect � 2002 by Open Design Alliance Inc. All rights reserved. 
//
// By use of this software, you acknowledge and accept the terms of this 
// agreement.
///////////////////////////////////////////////////////////////////////////////



#ifndef _OD_DB_ARC_
#define _OD_DB_ARC_

#include "DD_PackPush.h"

#include "DbCurve.h"

/** Description:
    This class represents Arc entities in an OdDbDatabase instance.

    Library:
    Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbArc : public OdDbCurve
{
public:

  ODDB_DECLARE_MEMBERS(OdDbArc);

  OdDbArc();

  /** Description:
    Returns the WCS *center* of this curve (DXF 10 in WCS).
  */
  OdGePoint3d center() const;

  /** Description:
    Sets the WCS *center* of this curve (DXF 10 in WCS).
    Arguments:
    center (I) Center.
  */
  void setCenter(
    const OdGePoint3d& center);

  /** Description:
    Returns the *radius* of this curve (DXF 40).
  */
  double radius() const;

  /** Description:
    Sets the *radius* of this curve (DXF 40).
    Arguments:
    radius (I) Radius.
  */
  void setRadius(
    double radius);

  /** Description:
    Returns the start angle of this curve (DXF 50).

    Remarks:
    The angle is measured counterclockwise from the OCS X-axis.

    Note:
    All angles are expressed in radians.
  */
  double startAngle() const;

  /** Description:
    Sets the start angle of this curve (DXF 50).
    
    Arguments:
    startAngle (I) Start angle.
    
    Remarks:
    The angle is measured counterclockwise from the OCS X-axis.

    Note:
    All angles are expressed in radians.
  */
  void setStartAngle(
    double startAngle);

  /** Description:
    Returns the end angle of this curve (DXF 51).

    Remarks:
    The angle is measured counterclockwise from the OCS X-axis.

    Note:
    All angles are expressed in radians.
  */
  double endAngle() const;

  /** Description:
    Sets the end angle of this curve (DXF 51).
    Arguments:
    endAngle (I) End angle.

    Remarks:
    The angle is measured counterclockwise from the OCS X-axis.

    Note:
    All angles are expressed in radians.
  */
  void setEndAngle(
    double endAngle);

  /** Description:
    Returns the *thickness* of this entity (DXF 39).
    
    Remarks:
    Thickness is the extrusion length along the *normal*.
  */
  double thickness() const;

  /** Description:
    Sets the *thickness* of this entity (DXF 39).
    Arguments:
    thickness (I) Thickness.
    Remarks:
    Thickness is the extrusion length along the *normal*.
  */
  void setThickness(
    double thickness);

  /** Description:
    Returns the WCS *normal* to the plane of this entity (DXF 210).
  */
  OdGeVector3d normal() const;
  
  /** Description:
    Sets the WCS *normal* to the plane of this entity (DXF 210).
    Arguments:
    normal (I) Normal.
  */
  void setNormal(
    const OdGeVector3d& normal);

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual void dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual void dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler);

  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;

  virtual bool worldDraw(
    OdGiWorldDraw* pWd) const;

  virtual OdResult transformBy(
    const OdGeMatrix3d& xfm);

  virtual void getClassID(
    void** pClsid) const;

  virtual bool isPlanar() const;

  virtual OdResult getPlane(
    OdGePlane& plane, 
    OdDb::Planarity& planarity) const;

  virtual bool isClosed() const;

  virtual bool isPeriodic() const;

  virtual OdResult getStartParam(
    double& startParam) const;

  virtual OdResult getEndParam (
    double& endParam) const;

  virtual OdResult getPointAtParam(
    double param, 
    OdGePoint3d& pointOnCurve) const;

  virtual OdResult getParamAtPoint(
    const OdGePoint3d& pointOnCurve, 
    double& param) const;

  virtual OdResult getStartPoint(
    OdGePoint3d& startPoint) const;

  virtual OdResult getEndPoint(
    OdGePoint3d& endPoint) const;

  virtual OdResult getTransformedCopy(
    const OdGeMatrix3d& xfm, 
    OdDbEntityPtr& pCopy) const;

  /*
     OdDbArc(const OdGePoint3d& center, double radius,
             double startAngle, double endAngle);
     OdDbArc(const OdGePoint3d& center, const OdGeVector3d& normal,
             double radius, double startAngle, double endAngle);
  */
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbArc object pointers.
*/
typedef OdSmartPtr<OdDbArc> OdDbArcPtr;

#include "DD_PackPop.h"

#endif


