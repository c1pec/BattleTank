// Copyright Hugo Galliot 2018

#include "TankTrack.h"




void UTankTrack::SetThrottle(float Throttle)
{
	UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"), *GetName(), Throttle);

	// TODO clamp actual value so the player can't overdrive
}