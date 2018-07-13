// Copyright Hugo Galliot 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	ATank* GetControlledTank() const;

	// Start the tank moving the barrel so that a shot would hit where the crosshair intersects the world
	void AimTowardsCrosshair();

	// Get world location of line-trace through crosshair, returns true if hits landscape
	bool GetSightRayHitLocation(FVector& outHitLocation) const;

	bool GetLookDirection(const FVector2D& ScreenLocation, FVector& OutLookDirection) const;

	bool GetLookVectorHitLocation(const FVector& LookDirection, FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.3333;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.f;
};
