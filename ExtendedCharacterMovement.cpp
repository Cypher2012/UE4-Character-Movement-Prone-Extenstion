// Fill out your copyright notice in the Description page of Project Settings.

#include "HDRemake_V4.h"
#include "ExtendedCharacterMovement.h"

float UExtendedCharacterMovement::GetMaxSpeed() const
{
	switch (MovementMode)
	{
	case MOVE_Walking:
	case MOVE_NavWalking:
		if (bIsTransitioning)
		{
			//If the character is in a transition, we don't want them to move. Return a 0.0 speed.
			return 0.0f;
		}
		else if (bIsProne)
		{
			return MaxProneSpeed;
		}
		else if (IsCrouching())
		{
			return MaxWalkSpeedCrouched;
		}
		else
		{
			return MaxWalkSpeed;
		}
	case MOVE_Falling:
		return MaxWalkSpeed;
	case MOVE_Swimming:
		return MaxSwimSpeed;
	case MOVE_Flying:
		return MaxFlySpeed;
	case MOVE_Custom:
		return MaxCustomMovementSpeed;
	case MOVE_None:
	default:
		return 0.f;
	}
}

void UExtendedCharacterMovement::StandUp(bool bClientSimulation)
{
	bIsStanding = true;

	bIsCrouched = false;
	bIsProne = false;

	//TODO: Check is okay to stand up
	//TODO: Create function to adjust capsule that can be called by Crouch/Prone/Standup
}

void UExtendedCharacterMovement::Crouch(bool bClientSimulation)
{
	bIsCrouched = true;

	bIsStanding = false;	
	bIsProne = false;

	//TODO: Check is okay to crouch
	//TODO: Create function to adjust capsule that can be called by Crouch/Prone/Standup
}

void UExtendedCharacterMovement::Prone(bool bClientSimulation)
{
	bIsProne = true;

	bIsStanding = false;
	bIsCrouched = false;

	//TODO: Check is okay to go prone
	//TODO: Create function to adjust capsule that can be called by Crouch/Prone/Standup
}

void UExtendedCharacterMovement::StartTransition()
{
	bIsTransitioning = true;
}

void UExtendedCharacterMovement::EndTransition()
{
	bIsTransitioning = false;
}

