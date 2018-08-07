#include "stdafx.h"
#include "Resource.h"
#include "DecimatorPlugin.h"
#include <AK/Plugin/DecimatorFXFactory.h>
#include <AK/Tools/Common/AkAssert.h>

using namespace AK;
using namespace Wwise;

//Property names
static LPCWSTR szGain = L"Gain";

DecimatorPlugin::DecimatorPlugin() :m_pPSet(NULL), m_hwndPropView(NULL)
{
}


DecimatorPlugin::~DecimatorPlugin()
{
}

void DecimatorPlugin::Destroy()
{
	delete this;
}

void DecimatorPlugin::SetPluginPropertySet(AK::Wwise::IPluginPropertySet * in_pPSet)
{
	m_pPSet = in_pPSet;
}

void DecimatorPlugin::NotifyPropertyChanged(const GUID & in_guidPlatform, LPCWSTR in_szPropertyName)
{
}

HINSTANCE DecimatorPlugin::GetResourceHandle() const
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return AfxGetStaticModuleState()->m_hCurrentResourceHandle;
}

bool DecimatorPlugin::GetDialog(eDialog in_eDialog, UINT & out_uiDialogID, AK::Wwise::PopulateTableItem *& out_pTable) const
{
	AKASSERT(in_eDialog == SettingsDialog);

	out_uiDialogID = IDD_DECI_BIG;//Resource...


	return true;
}

bool DecimatorPlugin::WindowProc(eDialog in_eDialog, HWND in_hWnd, UINT in_message, WPARAM in_wParam, LPARAM in_lParam, LRESULT & out_lResult)
{
	switch (in_message)
	{
	case WM_INITDIALOG:
		m_hwndPropView = in_hWnd;
		break;
	case WM_DESTROY:
		m_hwndPropView = NULL;
		break;
	}

	out_lResult = 0;
	return false;
}

bool DecimatorPlugin::GetBankParameters(const GUID & in_guidPlatform, AK::Wwise::IWriteData * in_pDataWriter) const
{
	CComVariant varProp;

	m_pPSet->GetValue(in_guidPlatform, szGain, varProp);
	in_pDataWriter->WriteReal32(varProp.fltVal);

	return true;
}

bool DecimatorPlugin::Help(HWND in_hWnd, eDialog in_eDialog, LPCWSTR in_szLanguageCode) const
{
	return false;
}
