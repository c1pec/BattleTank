// Copyright Hugo Galliot 2018

#include "TankMovementComponent.h"
#include "TankTrack.h"



void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!ensure(LeftTrack && RightTrack))
	{
		UE_LOG(LogTemp, Error, TEXT("UTankMovementComponent::IntendMoveForward() has nullptr reference"));
		return;
	}

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(LeftTrack && RightTrack))
	{
		UE_LOG(LogTemp, Error, TEXT("UTankMovementComponent::IntendTurnRight() has nullptr reference"));
		return;
	}

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	FVector TankForwardDirection = GetOwner()->GetActorForwardVector().GetSafeNormal();
	FVector AIForwardIntention = MoveVelocity.GetSafeNormal();

	IntendMoveForward(FVector::DotProduct(TankForwardDirection, AIForwardIntention));
	IntendTurnRight(FVector::CrossProduct(AIForwardIntention, TankForwardDirection).Z);
}
