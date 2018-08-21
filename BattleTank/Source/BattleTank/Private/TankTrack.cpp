// Copyright Hugo Galliot 2018

#include "TankTrack.h"




void UTankTrack::SetThrottle(float Throttle)
{
	// TODO clamp actual value so the player can't overdrive

	FVector ForceApplied = GetForwardVector() * Throttle * MaxDrivingForce;
	FVector ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}