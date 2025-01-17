//$ Copyright 2015-21, Code Respawn Technologies Pvt Ltd - All Rights Reserved $//

#pragma once
#include "CoreMinimal.h"
#include "ActorFactories/ActorFactory.h"
#include "PrefabricatorActorFactory.generated.h"

UCLASS()
class PREFABRICATOREDITOR_API UPrefabricatorActorFactory : public UActorFactory {
	GENERATED_UCLASS_BODY()

	// UActorFactory interface
	virtual UObject* GetAssetFromActorInstance(AActor* ActorInstance);
	virtual AActor* SpawnActor(UObject* InAsset, ULevel* InLevel, const FTransform& InTransform, const FActorSpawnParameters& InSpawnParams);
	virtual void PostSpawnActor(UObject* Asset, AActor* NewActor);
	virtual void PostCreateBlueprint(UObject* Asset, AActor* CDO);
	virtual bool CanCreateActorFrom(const FAssetData& AssetData, FText& OutErrorMsg);
	// End of UActorFactory interface

	void LoadPrefabActorState(class APrefabActor* PrefabActor);
};

