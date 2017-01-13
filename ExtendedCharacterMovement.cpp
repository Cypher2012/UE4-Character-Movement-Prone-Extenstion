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

void UExtendedCharacterMovement::AdjustCapsule(INPUT_STANCE eInputStance)
{
	//TODO: Adjust the capsule size to fit the stance

	if (eInputStance == INPUT_STANCE::IP_STAND)
	{

	}

	else if (eInputStance == INPUT_STANCE::IP_CROUCH)
	{

	}
	else if (eInputStance == INPUT_STANCE::IP_PRONE)
	{

	}
}

bool UExtendedCharacterMovement::CheckRequestStance(INPUT_STANCE eInputStance)
{
	//TODO: Check if the requested stance is okay. Check for collisions etc.

	//Return true for now, so that the function can be placed where needed.
	return true;
}

void UExtendedCharacterMovement::StandUp(bool bClientSimulation)
{
	if (CheckRequestStance(INPUT_STANCE::IP_STAND))
	{
		bIsStanding = true;

		bIsCrouched = false;
		bIsProne = false;

		AdjustCapsule(INPUT_STANCE::IP_STAND);
	}	
}

void UExtendedCharacterMovement::Crouch(bool bClientSimulation)
{
	if (CheckRequestStance(INPUT_STANCE::IP_CROUCH))
	{
		bIsCrouched = true;

		bIsStanding = false;
		bIsProne = false;

		AdjustCapsule(INPUT_STANCE::IP_CROUCH);
	}	
}

void UExtendedCharacterMovement::Prone(bool bClientSimulation)
{
	if (CheckRequestStance(INPUT_STANCE::IP_PRONE))
	{
		bIsProne = true;

		bIsStanding = false;
		bIsCrouched = false;

		AdjustCapsule(INPUT_STANCE::IP_PRONE);
	}	
}

void UExtendedCharacterMovement::StartTransition()
{
	bIsTransitioning = true;
}

void UExtendedCharacterMovement::EndTransition()
{
	bIsTransitioning = false;
}

