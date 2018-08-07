#include "DecimatorParamFX.h"
#include <AK/Tools/Common/AkAssert.h>
#include <AK/Tools/Common/AkBankReadHelpers.h>
#include <math.h>


DecimatorParamFX::DecimatorParamFX()
{
}

DecimatorParamFX::DecimatorParamFX(const DecimatorParamFX & in_rCopy)
{
	RTPC = in_rCopy.RTPC;
	RTPC.bHasChanged = true;
	NonRTPC = in_rCopy.NonRTPC;
	NonRTPC.bHasChanged = true;
}


DecimatorParamFX::~DecimatorParamFX()
{
}

AK::IAkPluginParam * DecimatorParamFX::Clone(AK::IAkPluginMemAlloc * in_pAllocator)
{
	return AK_PLUGIN_NEW(in_pAllocator, DecimatorParamFX(*this));
}

AKRESULT DecimatorParamFX::Init(AK::IAkPluginMemAlloc * in_pAllocator, const void * in_pParamsBlock, AkUInt32 in_ulBlockSize)
{
	if (in_ulBlockSize == 0)
	{
		RTPC.fGain = DECIMATORPARAM_GAIN_DEF;
		RTPC.bHasChanged = true;
		NonRTPC.bHasChanged = true;
		return AK_Success;
	}
	return SetParamsBlock(in_pParamsBlock, in_ulBlockSize);
}

AKRESULT DecimatorParamFX::Term(AK::IAkPluginMemAlloc * in_pAllocator)
{
	AK_PLUGIN_DELETE(in_pAllocator, this);
	return AK_Success;
}

AKRESULT DecimatorParamFX::SetParamsBlock(const void * in_pParamsBlock, AkUInt32 in_ulBlockSize)
{
	AKRESULT eResult = AK_Success;
	AkUInt8 * pParamsBlock = (AkUInt8 *)in_pParamsBlock;
	RTPC.fGain = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
	CHECKBANKDATASIZE(in_ulBlockSize, eResult);

	RTPC.bHasChanged = true;
	NonRTPC.bHasChanged = true;

	return eResult;
}

AKRESULT DecimatorParamFX::SetParam(AkPluginParamID in_ParamID, const void * in_pValue, AkUInt32 in_ulParamSize)
{
	AKRESULT eResult = AK_Success;

	switch (in_ParamID) {
	case AK_DECIMATORPARAM_GAIN_ID:
		RTPC.fGain = *(AkReal32*)(in_pValue);
		RTPC.bHasChanged = true;
		break;

	default:
		AKASSERT(!"Invalid parameter.");
		eResult = AK_InvalidParameter;
		
	}
	return eResult;
}
