
#if defined(_MSC_VER) && defined(_WIN32)
#include <windows.h>
#endif

#define STL_USING_IOSTREAM
#include "OdaSTL.h"
#define  STD(a)  std:: a


#include "OdaCommon.h"
#include "OdToolKit.h"
#include "OdString.h"
#include "ExHostAppServices.h"
#include "Gs/Gs.h"
#include "DbAudit.h"
#include "Gi/TtfDescriptor.h"

/*
// DN: temporary. To be removed...
#define ODRGB(r,g,b) {r,g,b,0}

const OdGsColor ExHostAppServices::dark_palette[] =
{
  ODRGB(  0,   0,   0),   // black //
  ODRGB(255,   0,   0),   // red //
  ODRGB(255, 255,   0),   // yellow //
  ODRGB(  0, 255,   0),   // green //
  ODRGB(  0, 255, 255),   // cyan //
  ODRGB(  0,   0, 255),   // blue //
  ODRGB(255,   0, 255),   // magenta //
  ODRGB(255, 255, 255),   // white //
  ODRGB(152, 152, 152),   // grey -- an educated guess //
  ODRGB(192, 192, 192),   // light grey -- an educated guess //
  ODRGB(255,   0,   0),ODRGB(255, 128, 128),ODRGB(166,   0,   0),
  ODRGB(166,  83,  83),ODRGB(128,   0,   0),ODRGB(128,  64,  64),ODRGB( 76,   0,   0),
  ODRGB( 76,  38,  38),ODRGB( 38,   0,   0),ODRGB( 38,  19,  19),ODRGB(255,  64,   0),
  ODRGB(255, 159, 128),ODRGB(166,  41,   0),ODRGB(166, 104,  83),ODRGB(128,  32,   0),
  ODRGB(128,  80,  64),ODRGB( 76,  19,   0),ODRGB( 76,  48,  38),ODRGB( 38,  10,   0),
  ODRGB( 38,  24,  19),ODRGB(255, 128,   0),ODRGB(255, 191, 128),ODRGB(166,  83,   0),
  ODRGB(166, 124,  83),ODRGB(128,  64,   0),ODRGB(128,  96,  64),ODRGB( 76,  38,   0),
  ODRGB( 76,  57,  38),ODRGB( 38,  19,   0),ODRGB( 38,  29,  19),ODRGB(255, 191,   0),
  ODRGB(255, 223, 128),ODRGB(166, 124,   0),ODRGB(166, 145,  83),ODRGB(128,  96,   0),
  ODRGB(128, 112,  64),ODRGB( 76,  57,   0),ODRGB( 76,  67,  38),ODRGB( 38,  29,   0),
  ODRGB( 38,  33,  19),ODRGB(255, 255,   0),ODRGB(255, 255, 128),ODRGB(166, 166,   0),
  ODRGB(166, 166,  83),ODRGB(128, 128,   0),ODRGB(128, 128,  64),ODRGB( 76,  76,   0),
  ODRGB( 76,  76,  38),ODRGB( 38,  38,   0),ODRGB( 38,  38,  19),ODRGB(191, 255,   0),
  ODRGB(223, 255, 128),ODRGB(124, 166,   0),ODRGB(145, 166,  83),ODRGB( 96, 128,   0),
  ODRGB(112, 128,  64),ODRGB( 57,  76,   0),ODRGB( 67,  76,  38),ODRGB( 29,  38,   0),
  ODRGB( 33,  38,  19),ODRGB(128, 255,   0),ODRGB(191, 255, 128),ODRGB( 83, 166,   0),
  ODRGB(124, 166,  83),ODRGB( 64, 128,   0),ODRGB( 96, 128,  64),ODRGB( 38,  76,   0),
  ODRGB( 57,  76,  38),ODRGB( 19,  38,   0),ODRGB( 29,  38,  19),ODRGB( 64, 255,   0),
  ODRGB(159, 255, 128),ODRGB( 41, 166,   0),ODRGB(104, 166,  83),ODRGB( 32, 128,   0),
  ODRGB( 80, 128,  64),ODRGB( 19,  76,   0),ODRGB( 48,  76,  38),ODRGB( 10,  38,   0),
  ODRGB( 24,  38,  19),ODRGB(  0, 255,   0),ODRGB(128, 255, 128),ODRGB(  0, 166,   0),
  ODRGB( 83, 166,  83),ODRGB(  0, 128,   0),ODRGB( 64, 128,  64),ODRGB(  0,  76,   0),
  ODRGB( 38,  76,  38),ODRGB(  0,  38,   0),ODRGB( 19,  38,  19),ODRGB(  0, 255,  64),
  ODRGB(128, 255, 159),ODRGB(  0, 166,  41),ODRGB( 83, 166, 104),ODRGB(  0, 128,  32),
  ODRGB( 64, 128,  80),ODRGB(  0,  76,  19),ODRGB( 38,  76,  48),ODRGB(  0,  38,  10),
  ODRGB( 19,  38,  24),ODRGB(  0, 255, 128),ODRGB(128, 255, 191),ODRGB(  0, 166,  83),
  ODRGB( 83, 166, 124),ODRGB(  0, 128,  64),ODRGB( 64, 128,  96),ODRGB(  0,  76,  38),
  ODRGB( 38,  76,  57),ODRGB(  0,  38,  19),ODRGB( 19,  38,  29),ODRGB(  0, 255, 191),
  ODRGB(128, 255, 223),ODRGB(  0, 166, 124),ODRGB( 83, 166, 145),ODRGB(  0, 128,  96),
  ODRGB( 64, 128, 112),ODRGB(  0,  76,  57),ODRGB( 38,  76,  67),ODRGB(  0,  38,  29),
  ODRGB( 19,  38,  33),ODRGB(  0, 255, 255),ODRGB(128, 255, 255),ODRGB(  0, 166, 166),
  ODRGB( 83, 166, 166),ODRGB(  0, 128, 128),ODRGB( 64, 128, 128),ODRGB(  0,  76,  76),
  ODRGB( 38,  76,  76),ODRGB(  0,  38,  38),ODRGB( 19,  38,  38),ODRGB(  0, 191, 255),
  ODRGB(128, 223, 255),ODRGB(  0, 124, 166),ODRGB( 83, 145, 166),ODRGB(  0,  96, 128),
  ODRGB( 64, 112, 128),ODRGB(  0,  57,  76),ODRGB( 38,  67,  76),ODRGB(  0,  29,  38),
  ODRGB( 19,  33,  38),ODRGB(  0, 128, 255),ODRGB(128, 191, 255),ODRGB(  0,  83, 166),
  ODRGB( 83, 124, 166),ODRGB(  0,  64, 128),ODRGB( 64,  96, 128),ODRGB(  0,  38,  76),
  ODRGB( 38,  57,  76),ODRGB(  0,  19,  38),ODRGB( 19,  29,  38),ODRGB(  0,  64, 255),
  ODRGB(128, 159, 255),ODRGB(  0,  41, 166),ODRGB( 83, 104, 166),ODRGB(  0,  32, 128),
  ODRGB( 64,  80, 128),ODRGB(  0,  19,  76),ODRGB( 38,  48,  76),ODRGB(  0,  10,  38),
  ODRGB( 19,  24,  38),ODRGB(  0,   0, 255),ODRGB(128, 128, 255),ODRGB(  0,   0, 166),
  ODRGB( 83,  83, 166),ODRGB(  0,   0, 128),ODRGB( 64,  64, 128),ODRGB(  0,   0,  76),
  ODRGB( 38,  38,  76),ODRGB(  0,   0,  38),ODRGB( 19,  19,  38),ODRGB( 64,   0, 255),
  ODRGB(159, 128, 255),ODRGB( 41,   0, 166),ODRGB(104,  83, 166),ODRGB( 32,   0, 128),
  ODRGB( 80,  64, 128),ODRGB( 19,   0,  76),ODRGB( 48,  38,  76),ODRGB( 10,   0,  38),
  ODRGB( 24,  19,  38),ODRGB(128,   0, 255),ODRGB(191, 128, 255),ODRGB( 83,   0, 166),
  ODRGB(124,  83, 166),ODRGB( 64,   0, 128),ODRGB( 96,  64, 128),ODRGB( 38,   0,  76),
  ODRGB( 57,  38,  76),ODRGB( 19,   0,  38),ODRGB( 29,  19,  38),ODRGB(191,   0, 255),
  ODRGB(223, 128, 255),ODRGB(124,   0, 166),ODRGB(145,  83, 166),ODRGB( 96,   0, 128),
  ODRGB(112,  64, 128),ODRGB( 57,   0,  76),ODRGB( 67,  38,  76),ODRGB( 29,   0,  38),
  ODRGB( 33,  19,  38),ODRGB(255,   0, 255),ODRGB(255, 128, 255),ODRGB(166,   0, 166),
  ODRGB(166,  83, 166),ODRGB(128,   0, 128),ODRGB(128,  64, 128),ODRGB( 76,   0,  76),
  ODRGB( 76,  38,  76),ODRGB( 38,   0,  38),ODRGB( 38,  19,  38),ODRGB(255,   0, 191),
  ODRGB(255, 128, 223),ODRGB(166,   0, 124),ODRGB(166,  83, 145),ODRGB(128,   0,  96),
  ODRGB(128,  64, 112),ODRGB( 76,   0,  57),ODRGB( 76,  38,  67),ODRGB( 38,   0,  29),
  ODRGB( 38,  19,  33),ODRGB(255,   0, 128),ODRGB(255, 128, 191),ODRGB(166,   0,  83),
  ODRGB(166,  83, 124),ODRGB(128,   0,  64),ODRGB(128,  64,  96),ODRGB( 76,   0,  38),
  ODRGB( 76,  38,  57),ODRGB( 38,   0,  19),ODRGB( 38,  19,  29),ODRGB(255,   0,  64),
  ODRGB(255, 128, 159),ODRGB(166,   0,  41),ODRGB(166,  83, 104),ODRGB(128,   0,  32),
  ODRGB(128,  64,  80),ODRGB( 76,   0,  19),ODRGB( 76,  38,  48),ODRGB( 38,   0,  10),
  ODRGB( 38,  19,  24),ODRGB( 84,  84,  84),ODRGB(118, 118, 118),ODRGB(152, 152, 152),
  ODRGB(187, 187, 187),ODRGB(221, 221, 221),ODRGB(255, 255, 255)
};
*/
ExHostAppServices::ExHostAppServices() 
                 : m_disableOutput(false)
{
}

OdGsDevicePtr ExHostAppServices::gsBitmapDevice()
{
  return OdGsDevicePtr();
}

OdHatchPatternManager* ExHostAppServices::patternManager()
{
  if(m_patternManager.isNull())
  {
    m_patternManager = OdHatchPatternManager::createObject();
    m_patternManager->setApplicationService(this);
  }
  return m_patternManager.get();
}

OdDbHostAppProgressMeter* ExHostAppServices::newProgressMeter()
{
  return this;
}

void ExHostAppServices::releaseProgressMeter(OdDbHostAppProgressMeter* /*pMeter*/)
{
}

// MKU 06/17/05 - This optimization is obsolete. But it can be reason of bug 
//                  when old database is found by name instead of creationg anew.
/*
void ExHostAppServices::DwgCollection::goodbye(const OdDbDatabase* pDb)
{
  std::map<OdString, OdDbDatabase*>::iterator iter = m_loadedDwgs.begin(), end = m_loadedDwgs.end();
  while(iter!=end)
  {
    if(iter->second==pDb)
    {
      m_loadedDwgs.erase(iter);
      break;
    }
    ++iter;
  }
}

OdDbDatabase* ExHostAppServices::DwgCollection::lookUp(const OdString& keyFileName)
{
  std::map<OdString, OdDbDatabase*>::iterator iter = m_loadedDwgs.find(keyFileName);
  if(iter!=m_loadedDwgs.end())
  {
    return iter->second;
  }
  return 0;
}

void ExHostAppServices::DwgCollection::add(OdDbDatabase* pDb)
{
  ODA_ASSERT(lookUp(pDb->getFilename())==0);
  m_loadedDwgs.insert(std::map<OdString, OdDbDatabase*>::value_type(pDb->getFilename(), pDb));
  pDb->addReactor(this);
}
*/
OdDbDatabasePtr ExHostAppServices::readFile(const OdChar* fileName,
    bool bAllowCPConversion, bool bPartial, Oda::FileShareMode shmode, const OdPassword& password)
{
  OdDbDatabasePtr pRes;// = m_dwgCollection.lookUp(fileName);
  //if(pRes.isNull())
  {
    pRes = OdDbHostAppServices::readFile(fileName, bAllowCPConversion, bPartial, shmode, password);
    //m_dwgCollection.add(pRes.get());
  }
  return pRes;
}


void ExHostAppServices::start(const char* /*displayString*/)
{
  if (!m_disableOutput)
  {
#ifndef _WIN32_WCE
    STD(cout) << m_Prefix.c_str() << "Load Started ------------------------" << STD(endl);
#endif
  }
}

void ExHostAppServices::stop()
{
  if (!m_disableOutput)
  {
#ifndef _WIN32_WCE
    STD(cout) << m_Prefix.c_str() << "Load Completed------------------------" << STD(endl);
#endif
  }
}

void ExHostAppServices::meterProgress()
{
  m_MeterCurrent++;
  char temp[100];
  if (!m_disableOutput)
  {
    double  f1, f2;

    f1 = (double)m_MeterCurrent / m_MeterLimit * 100;
    f2 = (double)m_MeterOld / m_MeterLimit * 100;
    if ((f1 - f2) > 0.7)
    {
      sprintf(temp, "%2.2lf%%", f1);
#ifndef _WIN32_WCE
      STD(cout) << m_Prefix.c_str() << "Progress: " << temp << STD(endl);
#endif
      m_MeterOld = m_MeterCurrent;
    }
  }
}

void ExHostAppServices::setLimit(int max)
{
  m_MeterLimit = max;
  m_MeterCurrent = 0;
  m_MeterOld = 0;
  if (!m_disableOutput)
  {
#ifndef _WIN32_WCE
    STD(cout) << m_Prefix.c_str() << "Meter Limit: " << max << STD(endl);
#endif
  }
}


bool ExHostAppServices::ttfFileNameByDescriptor(const OdTtfDescriptor& descr, OdString& fileName)
{
#if defined(_MSC_VER) && defined(_WIN32) && !defined(_WIN32_WCE)
  OdString sNonExactMatched;

  OdString sFaceName = descr.typeface();

  OSVERSIONINFO os;
  os.dwOSVersionInfoSize=sizeof(OSVERSIONINFO);
  ::GetVersionEx(&os);
  OdString sName;
  sName.format("Software\\Microsoft\\Windows%s\\CurrentVersion\\",
    (os.dwPlatformId & VER_PLATFORM_WIN32_NT)!=0 ? " nt" : "");

  LONG nRes;
  OdString sValueName;
  HKEY hFontSubstitutes;
  OdChar* lpData;
  DWORD nDataSize;
  nRes = ::RegOpenKeyExA(HKEY_LOCAL_MACHINE, sName + "FontSubstitutes\\", 0, KEY_READ, &hFontSubstitutes);
  if (hFontSubstitutes)
  {
    sValueName.format("%s,%d", descr.typeface(), descr.charSet());
    nRes = ::RegQueryValueExA(hFontSubstitutes, sValueName, NULL, NULL, NULL, &nDataSize);
    if(nRes == ERROR_SUCCESS)
    {
      lpData = sFaceName.getBuffer(nDataSize);
      nRes = ::RegQueryValueExA(hFontSubstitutes, sValueName, NULL, NULL, (LPBYTE)lpData, &nDataSize);
      sFaceName.releaseBuffer();
      int n = sFaceName.find(',');
      if(n>0)
      {
        sFaceName = sFaceName.left(n);
      }
    }
    nRes = ::RegCloseKey(hFontSubstitutes);
  }

  HKEY hFonts;
  ::RegOpenKeyExA(HKEY_LOCAL_MACHINE, sName + "Fonts\\", 0, KEY_READ, &hFonts);
  if (hFonts)
  {
    DWORD nIndex = 0;
    DWORD nValNameSize = 20;
    nDataSize = max(fileName.getAllocLength(), 20);
    int n_BT = sFaceName.replace(" BT", " ");
    for(;;)
    {
      do
      {
        OdChar* lpValName = sValueName.getBuffer(nValNameSize);
        lpData = fileName.getBuffer(nDataSize);
        nRes = ::RegEnumValueA(hFonts, nIndex, lpValName, &nValNameSize, NULL, NULL, (LPBYTE)lpData, &nDataSize);
        sValueName.releaseBuffer();
        fileName.releaseBuffer();
        if(nRes == ERROR_MORE_DATA)
        {
          nValNameSize += 20;
        }
      }
      while(nRes == ERROR_MORE_DATA);

      if(nRes==ERROR_SUCCESS)
      {
        ++nIndex;
        nValNameSize = sValueName.getAllocLength();
        nDataSize = fileName.getAllocLength();
        if(sValueName.replace("(TrueType)", "")) // is TrueType font?
        {
          if(sValueName.replace(" BT", "")==n_BT)
          {
            bool bBold = false;
            if(n_BT)
            {
              sValueName.replace(" Extra Bold ", " XBd ");
            }
            else
            {
              if(sValueName.find(" Extra Bold ")==-1)
                bBold = (sValueName.replace(" Bold ", " ")!=0);
            }
            
            bool bItalic = (sValueName.replace(" Italic ", " ")!=0);
            sValueName.remove(' ');
            sFaceName.remove(' ');
            if(sValueName==sFaceName)
            {
              sNonExactMatched = fileName;
              if(descr.isBold()==bBold && descr.isItalic()==bItalic)
                break;
            }
            if ( sValueName.find(sFaceName+"&") != -1 ||
              sValueName.find("&"+sFaceName) != -1 )
            {
              sNonExactMatched = fileName;
              break;
            }
          }
        }
      }
      else
      {
        fileName = sNonExactMatched;
        break;
      }
    }
    ::RegCloseKey(hFonts);
  }
  return (!fileName.isEmpty());
#else
  return false;
#endif
}

