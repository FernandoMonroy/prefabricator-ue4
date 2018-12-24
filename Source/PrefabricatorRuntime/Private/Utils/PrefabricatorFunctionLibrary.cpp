//$ Copyright 2015-18, Code Respawn Technologies Pvt Ltd - All Rights Reserved $//

#include "Utils/PrefabricatorFunctionLibrary.h"
#include "Engine/Engine.h"
#include "PrefabricatorAsset.h"
#include "PrefabActor.h"
#include "PrefabComponent.h"
#include "PrefabTools.h"

APrefabActor* UPrefabricatorBlueprintLibrary::SpawnPrefab(const UObject* WorldContextObject, UPrefabricatorAssetInterface* Prefab, const FTransform& Transform, int32 Seed)
{
	APrefabActor* PrefabActor = nullptr;
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (World) {
		PrefabActor = World->SpawnActor<APrefabActor>(APrefabActor::StaticClass(), Transform);
		if (PrefabActor) {
			PrefabActor->PrefabComponent->PrefabAssetInterface = Prefab;

			FRandomStream Random(Seed);
			PrefabActor->RandomizeSeed(Random);

			FPrefabLoadSettings LoadSettings;
			LoadSettings.bRandomizeNestedSeed = true;
			LoadSettings.Random = &Random;
			FPrefabTools::LoadStateFromPrefabAsset(PrefabActor, LoadSettings);
		}
	}
	return PrefabActor;
}