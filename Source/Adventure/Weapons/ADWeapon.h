// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ADWeapon.generated.h"

class USkeletalMeshComponent;

UCLASS()
class AADWeapon : public AActor
{
	GENERATED_BODY()
	
public:
	AADWeapon();

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ADWeapon, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> Mesh;
};
