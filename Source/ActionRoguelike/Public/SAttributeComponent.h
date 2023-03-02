// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SAttributeComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnHealthChanged, AActor*, InstigatorActor, USAttributeComponent*, OwningComp, float, NewHealth, float, Delta);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ACTIONROGUELIKE_API USAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USAttributeComponent();

protected:
	/*
	 * EditAnywhere - edit in BP editor and per-instance in level.
	 * VisibleAnywhere - 'read-only' in editor and level. (Use for components)
	 * EditDefaultsOnly - hide variable per-instance, edit in bp editor only
	 * VisibleDefaultsOnly - 'read-only' access for variable, only in bp editor (uncommon)
	 * EditInstanceOnly - allow only editing of instance ( eg. when placed in level)
	 * --
	 * BlueprintReadonly - read-only in the Blueprint Scripting (does not affect 'details' -panel)
	 * BlueprintReadWrite - read-write access in Blueprints
	 * --
	 * Category = "" - display only for detail panels and blueprint context menu. 
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
	float Health;

	//HealthMax, stamina, critical

	// Called when the game starts


public:

	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	bool ApplyHealthChange(float Delta);

};
