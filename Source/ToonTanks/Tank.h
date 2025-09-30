// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
		
	//COMPONENTS
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), category = "Components")
	class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), category = "Components")
	class UCameraComponent* Camera;

	//FUNCTIONS
	void Move(float Value);
	void Rotate(float Value);

	//VARIABLES
	UPROPERTY(EditAnywhere, category = "Input")
	float MoveSpeed = 200.f;
	UPROPERTY(EditAnywhere, category = "Input")
	float TurnRate = 50.f;
	APlayerController* PlayerControllerRef;

};
