// Fill out your copyright notice in the Description page of Project Settings.


#include "Pacman_Controller.h"

APacman_Controller::APacman_Controller()
{

}

APacmanPawn* APacman_Controller::GetPacmanPawn() const
{
	return Cast<APacmanPawn>(GetPawn());
}

void APacman_Controller::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Move Forward", IE_Pressed, this, &APacman_Controller::MoveForward);
	InputComponent->BindAction("Move Backward", IE_Pressed, this, &APacman_Controller::MoveBackward);
	InputComponent->BindAction("Move Left", IE_Pressed, this, &APacman_Controller::MoveLeft);
	InputComponent->BindAction("Move Right", IE_Pressed, this, &APacman_Controller::MoveRight);
}

void APacman_Controller::MoveForward()
{
	if(GetPacmanPawn())
		GetPacmanPawn()->SetDirection(FVector::UpVector);
}

void APacman_Controller::MoveBackward()
{
	if (GetPacmanPawn())
		GetPacmanPawn()->SetDirection(FVector::DownVector);
}

void APacman_Controller::MoveLeft()
{
	if (GetPacmanPawn())
		GetPacmanPawn()->SetDirection(FVector::LeftVector);
}

void APacman_Controller::MoveRight()
{
	if (GetPacmanPawn())
		GetPacmanPawn()->SetDirection(FVector::RightVector);
}