// Cfg.h: interface for the CCfg class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CFG_H__2FD3E850_ECD1_43E1_9C27_0C638697EA61__INCLUDED_)
#define AFX_CFG_H__2FD3E850_ECD1_43E1_9C27_0C638697EA61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCfg : public CObject  
{
private:
	CCfg();
	static CCfg s_Cfg;

public:
	DECLARE_SERIAL(CCfg);
	virtual ~CCfg();
	AFX_INLINE static CCfg& GetCfg() {return s_Cfg;}

	virtual void Serialize(CArchive& ar);

public:
	BOOL m_bAlwaysOnTop;
	BOOL m_bAddLineNumbers;


};

#endif // !defined(AFX_CFG_H__2FD3E850_ECD1_43E1_9C27_0C638697EA61__INCLUDED_)
