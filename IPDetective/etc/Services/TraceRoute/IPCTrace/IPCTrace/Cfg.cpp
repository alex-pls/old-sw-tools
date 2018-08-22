// Cfg.cpp: implementation of the CCfg class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Cfg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// Static singleton...
CCfg CCfg::s_Cfg;

IMPLEMENT_SERIAL(CCfg, CObject, VERSIONABLE_SCHEMA | 1);

CCfg::CCfg()
{
	m_bAlwaysOnTop = TRUE;
	m_bAddLineNumbers = TRUE;
}

CCfg::~CCfg()
{
}

void CCfg::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);

	if (ar.IsStoring())
	{
		ar << m_bAlwaysOnTop
			 << m_bAddLineNumbers;

	}
	else
	{
		ar >> m_bAlwaysOnTop
			 >> m_bAddLineNumbers;
	}
}
