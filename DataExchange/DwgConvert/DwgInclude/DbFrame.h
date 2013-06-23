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

#ifndef OD_DBFRAME_H
#define OD_DBFRAME_H

#include "DD_PackPush.h"

#include "DbEntity.h"

/** Description:
    This class is the abstract base class for OdDbOleFrame graphical objects 
    contained in an OdDbDatabase instance.
    
    Library:
    Db
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbFrame : public OdDbEntity
{
public:
  ODDB_DECLARE_MEMBERS(OdDbFrame);

  OdDbFrame();
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbFrame object pointers.
*/
typedef OdSmartPtr<OdDbFrame> OdDbFramePtr;

#include "DD_PackPop.h"

#endif  // OD_DBRAME_H


