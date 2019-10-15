// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:

	// Sets default values for this actor's properties
	AMovingPlatform();

	UPROPERTY(EditAnywhere, Category = "Setup")
	float MovingSpeed = 150;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector TargetLocation;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float TravelTime;

	void AddActiveTrigger();

	void RemoveActiveTrigger();

#if WITH_EDITOR // need to be here, to avoid errors when packaging
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif 

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:

	FVector GlobalStartLocation;

	FVector GlobalTargetLocation;

	UPROPERTY(EditAnywhere)
	int32 ActiveTriggers = 1;

};
