// Fill out your copyright notice in the Description page of Project Settings.


#include "Food.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
AFood::AFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFood::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFood::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFood::Consume()
{
	UGameplayStatics::PlaySound2D(this, ConsumptionSound);
	FoodEatenEvent.Broadcast(FoodType);
	this->Destroy();
}

