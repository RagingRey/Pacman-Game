// Fill out your copyright notice in the Description page of Project Settings.


#include "TelepoterActor.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
ATelepoterActor::ATelepoterActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATelepoterActor::BeginPlay()
{
	Super::BeginPlay();

	this->OnActorBeginOverlap.AddDynamic(this, &ATelepoterActor::OnBeginOverlap);
}

// Called every frame
void ATelepoterActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATelepoterActor::TeleportToTarget(AActor* Actor)
{
	USceneComponent* TargetSpawn = Cast<USceneComponent>(Target->GetDefaultSubobjectByName("Spawn"));

	UGameplayStatics::PlaySound2D(this, TeleportSound);

	Actor->SetActorLocation(TargetSpawn->GetComponentLocation());
}

void ATelepoterActor::OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if(OtherActor->ActorHasTag("Pacman"))
	{
		GetWorldTimerManager().SetTimerForNextTick([OtherActor, this]() { TeleportToTarget(OtherActor); });
	}
}