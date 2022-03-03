// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Master_Interact.h"
#include "S2R_Final_PannelLever.generated.h"

/**
 * 
 */

UCLASS()
class TPS_C_PROJECT_API AS2R_Final_PannelLever : public AMaster_Interact
{
	GENERATED_BODY()
	


public:
	AS2R_Final_PannelLever();
	void virtual Interact() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Pannel_Status;

	class USceneComponent* Main_Body;

	UPROPERTY(Editanywhere, BlueprintReadWrite, Category = "Lever")
	class UStaticMeshComponent*Lever;



};
