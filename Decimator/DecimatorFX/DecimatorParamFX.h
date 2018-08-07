#pragma once

#include <AK/SoundEngine/Common/IAkPlugin.h>

static const AkPluginParamID AK_DECIMATORPARAM_GAIN_ID = 0;

static const AkPluginParamID AK_DECIMATORPARAM_NUM = 1;

//default val
#define  DECIMATORPARAM_GAIN_DEF (1.0f)

struct DecimatorRTPCParams {
	AkReal32 fGain;
	bool bHasChanged;
};

struct DecimatorNonRTPCParams {
	bool bHasChanged;
};

struct DecimatorParameters {
	DecimatorRTPCParams RTPC;
	DecimatorNonRTPCParams NonRTPC;
}AK_ALIGN_DMA;

class DecimatorParamFX : public AK::IAkPluginParam, public DecimatorParameters
{
public:
	DecimatorParamFX();

	DecimatorParamFX(const DecimatorParamFX & in_rCopy);

	~DecimatorParamFX();

	/// Create parameter node duplicate.
	IAkPluginParam * Clone(AK::IAkPluginMemAlloc * in_pAllocator);

	/// Parameter node initialization.
	AKRESULT Init(
		AK::IAkPluginMemAlloc *	in_pAllocator,
		const void *			in_pParamsBlock,
		AkUInt32				in_ulBlockSize
	);

	/// Parameter node termination.
	AKRESULT Term(AK::IAkPluginMemAlloc * in_pAllocator);

	/// Parameter block set.
	AKRESULT SetParamsBlock(
		const void *in_pParamsBlock,
		AkUInt32	in_ulBlockSize
	);

	/// Update a single parameter.
	AKRESULT SetParam(
		AkPluginParamID in_ParamID,
		const void *	in_pValue,
		AkUInt32		in_ulParamSize
	);
};

