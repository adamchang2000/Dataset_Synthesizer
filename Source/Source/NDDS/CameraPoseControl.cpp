// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraPoseControl.h"

// Sets default values for this component's properties
UCameraPoseControl::UCameraPoseControl()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	
	static ConstructorHelpers::FObjectFinder<UDataTable> PoseDataTableFinder(TEXT("/Game/Test/azure_kinect_test2_cleaned_2"));
	if (PoseDataTableFinder.Succeeded()) {
		UE_LOG(LogTemp, Warning, TEXT("success finding datatable"));
		PoseTable = PoseDataTableFinder.Object;
	} else {
		UE_LOG(LogTemp, Warning, TEXT("Failure finding datatable :("));
	}

	if (PoseTable) {
		FCameraPoseDataRow* RowLookUp = PoseTable->FindRow<FCameraPoseDataRow>(TEXT("0"), TEXT("Lookup"), true);
		if (RowLookUp) {
			UE_LOG(LogTemp, Warning, TEXT("Found the row? %d"), RowLookUp->Frame);
		}
	}
}


// Called when the game starts
void UCameraPoseControl::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void UCameraPoseControl::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PoseTable) {
		FString frameLookup = FString::FromInt(frameNumber);
		FCameraPoseDataRow* RowLookUp = PoseTable->FindRow<FCameraPoseDataRow>(FName(*frameLookup), TEXT("Lookup"), true);
		
		if (RowLookUp) {
			UE_LOG(LogTemp, Warning, TEXT("Found the row? %d"), RowLookUp->Frame);

			FVector pos(RowLookUp->camera_Position_X, RowLookUp->camera_Position_Y, RowLookUp->camera_Position_Z);
			FQuat quat(RowLookUp->camera_Rotation_X, RowLookUp->camera_Rotation_Y, RowLookUp->camera_Rotation_Z, RowLookUp->camera_Rotation_W);
			FRotator rot(quat);

			//set camera pose
			AActor* OwnerActor = GetOwner();
			OwnerActor->SetActorLocationAndRotation(pos, rot, false, nullptr, ETeleportType::TeleportPhysics);
		}

		//increment frame counter
		frameNumber++;
	}
	
}

