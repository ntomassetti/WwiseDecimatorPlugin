#include "DecimatorFX.h"
#include <AK/Tools/Common/AkAssert.h>
#include <AK/AkWwiseSDKVersion.h>


/// Plugin mechanism. Instantiation method that must be registered to the plug-in manager.
AK::IAkPlugin* CreateDecimatorFX(AK::IAkPluginMemAlloc * in_pAllocator)
{
	return AK_PLUGIN_NEW(in_pAllocator, DecimatorFX());
}

/// Plugin mechanism. Instantiation method that must be registered to the plug-in manager.
AK::IAkPluginParam * CreateDecimatorFXParams(AK::IAkPluginMemAlloc * in_pAllocator)
{
	return AK_PLUGIN_NEW(in_pAllocator, DecimatorParamFX());
}

AK_IMPLEMENT_PLUGIN_FACTORY(DecimatorFX, AkPluginTypeEffect, 1212, 269)

DecimatorFX::DecimatorFX() : m_pParams(NULL), m_pAllocator(NULL)
{
}


DecimatorFX::~DecimatorFX()
{
}

AKRESULT DecimatorFX::Init(AK::IAkPluginMemAlloc * in_pAllocator, AK::IAkEffectPluginContext * in_pFXCtx, AK::IAkPluginParam * in_pParams, AkAudioFormat & in_rFormat)
{
	m_pParams = (DecimatorParamFX*)in_pParams;
	m_pAllocator = in_pAllocator;
	
	m_pParams->NonRTPC.bHasChanged = false;
	m_pParams->RTPC.bHasChanged = false;

	AK_PERF_RECORDING_RESET();

	return AK_Success;
}

AKRESULT DecimatorFX::Term(AK::IAkPluginMemAlloc * in_pAllocator)
{
	AK_PLUGIN_DELETE(in_pAllocator, this); /// Effect must delete itself
	return AK_Success;
}

AKRESULT DecimatorFX::Reset()
{
	return AK_Success;
}

AKRESULT DecimatorFX::GetPluginInfo(AkPluginInfo & out_rPluginInfo)
{
	out_rPluginInfo.eType = AkPluginTypeEffect;
	out_rPluginInfo.bIsInPlace = true;
	out_rPluginInfo.uBuildVersion = AK_WWISESDK_VERSION_COMBINED;
	return AK_Success;
}

void DecimatorFX::Execute(AkAudioBuffer * io_pBuffer)
{
	AkUInt32 uNumChannels = io_pBuffer->NumChannels();

	for (AkUInt32 uChan = 0; uChan<uNumChannels; uChan++)
	{
		AkSampleType * pChannel = io_pBuffer->GetChannel(uChan);
		for (auto i = 0; i < io_pBuffer->MaxFrames(); i++) {
			pChannel[i] = pChannel[i] * m_pParams->RTPC.fGain;
		}

		// Process data of pChannel...
	}
}
