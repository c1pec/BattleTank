// Copyright Hugo Galliot 2018

#include "TankTurret.h"




void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, 1.f);


}