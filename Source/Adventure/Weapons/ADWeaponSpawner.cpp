// Fill out your copyright notice in the Description page of Project Settings.

#include "ADWeaponSpawner.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "..\Characters\ADCharacter.h"
#include "..\Weapons\ADWeapon.h"

AADWeaponSpawner::AADWeaponSpawner()
{
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	check(Trigger);
	SetRootComponent(Trigger);

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	check(WeaponMesh);
	WeaponMesh->SetupAttachment(RootComponent);
}

void AADWeaponSpawner::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (IsValid(Trigger) == false)
	{
		check(0);
		return;
	}

	Trigger->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBegin);
}

void AADWeaponSpawner::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == nullptr)
	{
		return;
	}

	AADCharacter* OverlappingCharacter = Cast<AADCharacter>(OtherActor);
	if (OverlappingCharacter != nullptr)
	{
		UWorld* World = GetWorld();
		if (World == nullptr)
		{
			check(0);
			return;
		}

		AADWeapon* NewWeapon = World->SpawnActor<AADWeapon>(FVector::ZeroVector, FRotator::ZeroRotator);
		if (NewWeapon == nullptr)
		{
			check(0);
			return;
		}
		OverlappingCharacter->EquipWeapon(NewWeapon);

		WeaponMesh->SetVisibility(false, true);
	}

}
