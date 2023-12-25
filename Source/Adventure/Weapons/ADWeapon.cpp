// Fill out your copyright notice in the Description page of Project Settings.


#include "ADWeapon.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateWeapon, Log, All);
DEFINE_LOG_CATEGORY(LogTemplateWeapon);

// Sets default values
AADWeapon::AADWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	if (Asset == nullptr)
	{
		UE_LOG(LogTemplateWeapon, Error, TEXT("Asset is nullptr"));
	}

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	check(Mesh);
	RootComponent = Mesh;

	Mesh->SetSkeletalMesh(Asset);
}

// Called when the game starts or when spawned
void AADWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

