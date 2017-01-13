#pragma once

#include "GameFramework/CharacterMovementComponent.h"
#include "ExtendedCharacterMovement.generated.h"

UCLASS()
class HDREMAKE_V4_API UExtendedCharacterMovement : public UCharacterMovementComponent
{
	GENERATED_BODY()
private:

	uint32 bIsTransitioning : 1;

	uint32 bIsProne : 1;
	uint32 bIsCrouched : 1;	
	uint32 bIsStanding : 1;

	virtual float GetMaxSpeed() const override;

	enum INPUT_STANCE
	{
		IP_PRONE, IP_CROUCH, IP_STAND
	};

	//TODO: Check the requested stance is valid and okay
	bool CheckRequestStance(INPUT_STANCE eInputStance);

	//TODO: Adjust collision capsule to fit character
	void AdjustCapsule(INPUT_STANCE eInputStance);

public:
	UExtendedCharacterMovement();
	
	UPROPERTY(Category = "Character Movement: Walking", EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", UIMin = "0"))
	float MaxProneSpeed;

	//Sets the IsProne value to false. Adjusts the pawns collision capsule
	//See IsStanding
	UFUNCTION(BlueprintCallable, category = "Custom movement")
	void StandUp(bool bClientSimulation = false);

	//Sets the IsCrouched value to true. Adjusts the pawns collision capsule
	//See IsCrouched
	UFUNCTION(BlueprintCallable, category = "Custom movement")
	virtual void Crouch(bool bClientSimulation = false)  override;
	
	//Sets the IsProne value to true. Adjusts the pawns collision capsule
	//See IsProne
	UFUNCTION(BlueprintCallable, category = "Custom movement")
	void Prone(bool bClientSimulation = false);	

	//Typically used by animation notify events.
	//Used to tell the movement component that it's in the middle of a transition and we don't want the character to move until the EndTransition() function is called.
	UFUNCTION(BlueprintCallable, category = "Custom movement")
	void StartTransition();

	//Typically used by animation notify events.
	//It will tell the movement component that the transition is finished and the character is free to move again
	UFUNCTION(BlueprintCallable, category = "Custom movement")
	void EndTransition();

	//GetMethods

	//Return bIsStanding
	UFUNCTION(BlueprintCallable, category = "Custom movement")
	bool IsStanding() const { return bIsStanding; }

	//Return bIsCrouched
	UFUNCTION(BlueprintCallable, category = "Custom movement")
	bool IsCrouched() const { return bIsCrouched; }

	//Return bIsProne
	UFUNCTION(BlueprintCallable, category = "Custom movement")
	bool IsProne() const { return bIsProne; }
};
