// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sound/SoundCue.h"
#include "TelepoterActor.generated.h"

UCLASS()
class PACMAN_API ATelepoterActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATelepoterActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void TeleportToTarget(AActor* Actor);

	UPROPERTY(EditAnywhere)
		ATelepoterActor* Target = nullptr;

	UPROPERTY(EditAnywhere)
		USoundCue* TeleportSound;

	UFUNCTION()
		void OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
