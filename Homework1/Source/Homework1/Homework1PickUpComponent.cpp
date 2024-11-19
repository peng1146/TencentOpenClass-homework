// Copyright Epic Games, Inc. All Rights Reserved.

#include "Homework1PickUpComponent.h"

UHomework1PickUpComponent::UHomework1PickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UHomework1PickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UHomework1PickUpComponent::OnSphereBeginOverlap);
}

void UHomework1PickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AHomework1Character* Character = Cast<AHomework1Character>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
