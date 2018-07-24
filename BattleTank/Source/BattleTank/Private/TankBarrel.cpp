// Copyright Hugo Galliot 2018

#include "TankBarrel.h"
#include "Engine/World.h"




void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, 1.f);

	float ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float NewRawElevation = RelativeRotation.Pitch + ElevationChange;
	float NewElevation = FMath::Clamp<float>(NewRawElevation, MinElevationDegrees, MaxElevationDegrees);

	SetRelativeRotation(FRotator(NewElevation, 0, 0));
}