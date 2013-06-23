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



#ifndef ODSTREAMBUF_DEFINED
#define ODSTREAMBUF_DEFINED

#include "RxObject.h"

#include "DD_PackPush.h"

class OdString;

/** Description: 
  
    {group:DD_Namespaces}
*/
namespace OdDb
{
  enum FilerSeekType
  {
    kSeekFromStart   = SEEK_SET,
    kSeekFromCurrent = SEEK_CUR,
    kSeekFromEnd     = SEEK_END
  };
}

/** Description:

    {group:Other_Classes}
*/
class FIRSTDLL_EXPORT OdStreamBuf : public OdRxObject
{
protected:
  OdStreamBuf();
public:
  ODRX_DECLARE_MEMBERS(OdStreamBuf);

  virtual OdString  fileName();

  virtual bool      isEof();
  virtual OdUInt32  tell();
  virtual OdUInt32  length();

  virtual void      truncate();
  virtual void      rewind();
  virtual OdUInt32  seek(OdInt32 offset, OdDb::FilerSeekType whence);

  virtual OdUInt8   getByte();
  virtual void      getBytes(void* buffer, OdUInt32 nLen);

  virtual void      putByte(OdUInt8 val);
  virtual void      putBytes(const void* buffer, OdUInt32 nLen);

  virtual void      copyDataTo(OdStreamBuf* pDest, OdUInt32 nSrcStart = 0, OdUInt32 nSrcEnd = 0);
  virtual OdUInt32  getShareMode();
};

typedef OdSmartPtr<OdStreamBuf> OdStreamBufPtr;

#include "DD_PackPop.h"

#endif //ODSTREAMBUF_DEFINED


