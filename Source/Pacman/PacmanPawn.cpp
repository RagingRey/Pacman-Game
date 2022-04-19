// Fill out your copyright notice in the Description page of Project Settings.


#include "PacmanPawn.h"

#include "Food.h"

// Sets default values
APacmanPawn::APacmanPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APacmanPawn::BeginPlay()
{
	Super::BeginPlay();

	this->OnActorBeginOverlap.AddDynamic(this, &APacmanPawn::OnOverlapBegin);
}

// Called every frame
void APacmanPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(!bFrozen)
		this->AddMovementInput(GetActorForwardVector());
}

// Called to bind functionality to input
void APacmanPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APacmanPawn::SetDirection(const FVector Direction)
{
	if(Direction == FVector::UpVector)
	{
		this->SetActorRotation(FRotator(0.0f, -90.0f, 0.0f));
	}
	else if(Direction == FVector::RightVector)
	{
		this->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (Direction == FVector::DownVector)
	{
		this->SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
	}
	else if (Direction == FVector::LeftVector)
	{
		this->SetActorRotation(FRotator(0.f, -180.0f, 180.0f));
	}
}

void APacmanPawn::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor->ActorHasTag("Food_Regular") || OtherActor->ActorHasTag("Food_PowerUp"))
	{
		Cast<AFood>(OtherActor)->Consume();
	}
}