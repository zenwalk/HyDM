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



#ifndef _OD_DB_POLYFACEMESH_VERTEX_
#define _OD_DB_POLYFACEMESH_VERTEX_

#include "DD_PackPush.h"

#include "DbVertex.h"

/** Description:
    This class represents OdDbPolyFaceMesh vertices in an OdDbDatabase instance.
  
    Library:
    Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbPolyFaceMeshVertex : public OdDbVertex
{
public:
  ODDB_DECLARE_MEMBERS(OdDbPolyFaceMeshVertex);

  OdDbPolyFaceMeshVertex();
  
  /** Description:
    Returns the WCS *position* of this entity (DXF 10).
  */
  OdGePoint3d position() const;

  /** Description:
    Sets the WCS *position* of this entity (DXF 10).
    Arguments:
    position (I) Position.
  */
  void setPosition(
    const OdGePoint3d& position);

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual void dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler);

  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult getGeomExtents(
    OdGeExtents3d& extents) const;

  virtual OdResult transformBy(
    const OdGeMatrix3d& xfm);

  virtual OdResult subErase(
    bool erasing);
};
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbPolyFaceMeshVertex object pointers.
*/
typedef OdSmartPtr<OdDbPolyFaceMeshVertex> OdDbPolyFaceMeshVertexPtr;

#include "DD_PackPop.h"

#endif

