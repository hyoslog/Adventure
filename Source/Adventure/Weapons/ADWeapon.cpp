// Fill out your copyright notice in the Description page of Project Settings.

#include "ADWeapon.h"
#include "Components/SkeletalMeshComponent.h"

AADWeapon::AADWeapon()
{
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	check(Mesh);
	SetRootComponent(Mesh);
}