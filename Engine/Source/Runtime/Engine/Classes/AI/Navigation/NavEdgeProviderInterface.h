// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "NavEdgeProviderInterface.generated.h"

struct ENGINE_API FNavEdgeSegment
{
	FVector P0, P1;
};

UINTERFACE(MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UNavEdgeProviderInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class INavEdgeProviderInterface
{
	GENERATED_IINTERFACE_BODY()

	virtual bool GetEdges(const FVector& Center, float Range, TArray<FNavEdgeSegment>& Edges)
	{
		return false;
	}
};
