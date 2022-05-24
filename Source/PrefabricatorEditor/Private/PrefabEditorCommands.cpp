//$ Copyright 2015-22, Code Respawn Technologies Pvt Ltd - All Rights Reserved $//

#include "PrefabEditorCommands.h"

#include "Prefab/PrefabTools.h"
#include "PrefabEditorStyle.h"

#include "Framework/Commands/Commands.h"
#include "Framework/Commands/UIAction.h"
#include "Framework/Commands/UICommandList.h"
#include "UObject/Object.h"

#define LOCTEXT_NAMESPACE "ContentBrowser"

FPrefabricatorCommands::FPrefabricatorCommands() : TCommands<FPrefabricatorCommands>(
	TEXT("Prefabricator"),
	NSLOCTEXT("Prefabricator", "Prefabricator", "Prefabricator"),
	NAME_None,
	FPrefabEditorStyle::GetStyleSetName())
{
}

void FPrefabricatorCommands::RegisterCommands()
{
	LevelMenuActionList = MakeShareable(new FUICommandList);
	
	UI_COMMAND(CreatePrefab, "Create Prefab (from selection)", "Create a new prefab from selection", EUserInterfaceActionType::Button, FInputChord(EKeys::Enter));
	UI_COMMAND(CreatePrefabFromParent, "Create Prefab (from parent selection)", "Create a new prefab from parent selection", EUserInterfaceActionType::Button, FInputChord(EKeys::Enter));


	LevelMenuActionList->MapAction(
		CreatePrefab,
		FExecuteAction::CreateStatic(&FPrefabTools::CreatePrefab),
		FCanExecuteAction::CreateStatic(&FPrefabTools::CanCreatePrefab)
	);

	LevelMenuActionList->MapAction(
		CreatePrefabFromParent,
		FExecuteAction::CreateStatic(&FPrefabTools::CreatePrefabFromParent),
		FCanExecuteAction::CreateStatic(&FPrefabTools::CanCreatePrefabFromParent)
	);
}


#undef LOCTEXT_NAMESPACE

