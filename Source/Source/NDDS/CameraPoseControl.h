// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NVSceneCapturerModule.h"
#include "NVSceneCapturerUtils.h"
#include "Engine/DataTable.h"
#include "UObject/ConstructorHelpers.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CameraPoseControl.generated.h"

USTRUCT(BlueprintType)
struct FCameraPoseDataRow : public FTableRowBase
{

GENERATED_USTRUCT_BODY()
public:
	FCameraPoseDataRow() 
	: Frame(0), Time_Seconds(0.0), camera_Rotation_X(0.0), camera_Rotation_Y(0.0), camera_Rotation_Z(0.0),
	camera_Position_X(0.0), camera_Position_Y(0.0), camera_Position_Z(0.0) {}		

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Frame;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Time_Seconds;

	UPROPERTY(EditAnywhere, BLueprintReadWrite)
	float camera_Rotation_X;

	UPROPERTY(EditAnywhere, BLueprintReadWrite)
	float camera_Rotation_Y;

	UPROPERTY(EditAnywhere, BLueprintReadWrite)
	float camera_Rotation_Z;

	UPROPERTY(EditAnywhere, BLueprintReadWrite)
	float camera_Rotation_W;

	UPROPERTY(EditAnywhere, BLueprintReadWrite)
	float camera_Position_X;

	UPROPERTY(EditAnywhere, BLueprintReadWrite)
	float camera_Position_Y;

	UPROPERTY(EditAnywhere, BLueprintReadWrite)
	float camera_Position_Z;
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NDDS_API UCameraPoseControl : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCameraPoseControl();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UDataTable* PoseTable;

	int64 frameNumber = 0;
		
};
