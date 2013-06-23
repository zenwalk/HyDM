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



/*  DbExport.h

*/
#ifndef _DB_EXPORT_DEFINED
#define _DB_EXPORT_DEFINED

#ifdef  _TOOLKIT_IN_DLL_

  #ifdef  ODA_DB_EXPORTS

    #define TOOLKIT_EXPORT     __declspec(dllexport)

  #else   /* ODA_DB_EXPORTS */

    #define TOOLKIT_EXPORT     __declspec(dllimport)

  #endif  /* ODA_DB_EXPORTS */
////////////////////////////////////////////////////////////////////////

  #ifdef    ODAFIRST_DLL_EXPORTS
    #define FIRSTDLL_EXPORT     __declspec(dllexport)

  #else  /* ODAFIRST_DLL_EXPORTS */
    #define FIRSTDLL_EXPORT     __declspec(dllimport)

  #endif /* ODAFIRST_DLL_EXPORTS */


#else   /* _TOOLKIT_IN_DLL_ */

  #define TOOLKIT_EXPORT
  #define FIRSTDLL_EXPORT

#endif  /* _TOOLKIT_IN_DLL_ */

#include "Ge/GeExport.h"
#include "Br/BrExport.h"

#endif  /* _DB_EXPORT_DEFINED */




