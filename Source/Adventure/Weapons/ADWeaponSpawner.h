// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ADWeaponSpawner.generated.h"

class AADWeapon;
class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class ADVENTURE_API AADWeaponSpawner : public AActor
{
	GENERATED_BODY()
	
public:
	AADWeaponSpawner();

private:
	virtual void PostInitializeComponents() override;

private:
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ADWeaponSpawner, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> Trigger;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ADWeaponSpawner, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> WeaponMesh;
};
