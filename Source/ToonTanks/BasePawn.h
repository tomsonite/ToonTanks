// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

public:	

	UPROPERTY(EditInstanceOnly)
	int32 EditInstanceOnlyInt = 10;

	void HandleDestruction();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), category = "Components")
	class UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), category = "Components")
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), category = "Components")
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), category = "Components")
	USceneComponent* ProjSpawnPoint;

	UPROPERTY(EditDefaultsOnly, category = "Combat")
	TSubclassOf<class AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, category = "Combat")
	class UParticleSystem* DeathEffect;

	UPROPERTY(EditAnywhere, category = "Combat")
	class USoundBase* DeathSound;

	UPROPERTY(EditAnywhere, category = "Combat")
	TSubclassOf<class UCameraShakeBase> DeathCameraShakeClass;

protected:

	void RotateTurret(FVector LookAtTarget);
	void Fire();

};
