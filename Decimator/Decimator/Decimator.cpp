// Decimator.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "Decimator.h"
#include "DecimatorPlugin.h"
#include <AK/Wwise/Utilities.h>
#include <AK/Tools/Common/AkAssert.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// CDecimatorApp

BEGIN_MESSAGE_MAP(CDecimatorApp, CWinApp)
END_MESSAGE_MAP()


// CDecimatorApp construction

CDecimatorApp::CDecimatorApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CDecimatorApp object

CDecimatorApp theApp;


// CDecimatorApp initialization

BOOL CDecimatorApp::InitInstance()
{
	CWinApp::InitInstance();
	AK::Wwise::RegisterWwisePlugin();
	return TRUE;
}

AK::Wwise::IPluginBase* __stdcall AkCreatePlugin(unsigned short in_usCompanyID, unsigned short in_usPluginID)
{
	return new DecimatorPlugin;
}
/// Dummy assert hook for Wwise plug-ins using AKASSERT (cassert used by default).
DEFINEDUMMYASSERTHOOK;
DEFINE_PLUGIN_REGISTER_HOOK;