// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PacmanPawn.h"
#include "GameFramework/PlayerController.h"
#include "Pacman_Controller.generated.h"

/**
 * 
 */
UCLASS()
class PACMAN_API APacman_Controller : public APlayerController
{
	GENERATED_BODY()

public:
	APacman_Controller();

protected:
	APacmanPawn* GetPacmanPawn() const;

	virtual void SetupInputComponent() override;

	void MoveForward();
	void MoveBackward();
	void MoveLeft();
	void MoveRight();
};
