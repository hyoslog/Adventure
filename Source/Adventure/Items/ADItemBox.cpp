// Fill out your copyright notice in the Description page of Project Settings.

#include "ADItemBox.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateItemBox, Log, All);
DEFINE_LOG_CATEGORY(LogTemplateItemBox);

AADItemBox::AADItemBox()
{
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	check(Trigger);
	SetRootComponent(Trigger);

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	check(ItemMesh);
	ItemMesh->SetupAttachment(RootComponent);
}

void AADItemBox::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (IsValid(Trigger) == false)
	{
		check(0);
		return;
	}

	Trigger->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnCharacterOverlap);
}

void AADItemBox::OnCharacterOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	int a = 0;
}
