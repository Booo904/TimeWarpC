
#pragma once

#include "TimeWarpInterface.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UTimeWarpInterface : public UInterface
{
	GENERATED_BODY()
};

class ITimeWarpInterface
{
	GENERATED_BODY()

public:

	UFUNCTION()
	virtual void TimePause() = 0;

	UFUNCTION()
	virtual void TimeEnd() = 0;

	UFUNCTION()
	virtual void TimeReverse(float ReverseSpeed) = 0;
};