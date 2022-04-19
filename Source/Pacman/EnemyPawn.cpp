// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPawn.h"

void AEnemyPawn::Hunt()
{
	EnemyState = EEnemyState::Default;
	StateChangedEvent.Broadcast(EnemyState);
}

void AEnemyPawn::Idle()
{
	EnemyState = EEnemyState::Idle;
	StateChangedEvent.Broadcast(EnemyState);
}