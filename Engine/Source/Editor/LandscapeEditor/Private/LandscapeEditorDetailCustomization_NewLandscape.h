// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "LandscapeEditorDetailCustomization_Base.h"


/**
 * Slate widgets customizer for the "New Landscape" tool
 */

struct FLandscapeImportResolution
{
	int32 Width;
	int32 Height;
};

class FLandscapeEditorDetailCustomization_NewLandscape : public FLandscapeEditorDetailCustomization_Base
{
public:
	/** Makes a new instance of this detail layout class for a specific detail view requesting it */
	static TSharedRef<IDetailCustomization> MakeInstance();

	/** IDetailCustomization interface */
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) OVERRIDE;

public:
	static void SetScale(float NewValue, ETextCommit::Type, TSharedRef<IPropertyHandle> PropertyHandle);

	static TSharedRef<SWidget> GetSectionSizeMenu(TSharedRef<IPropertyHandle> PropertyHandle);
	static void OnChangeSectionSize(TSharedRef<IPropertyHandle> PropertyHandle, int32 NewSize);
	static FText GetSectionSize(TSharedRef<IPropertyHandle> PropertyHandle);

	static TSharedRef<SWidget> GetSectionsPerComponentMenu(TSharedRef<IPropertyHandle> PropertyHandle);
	static void OnChangeSectionsPerComponent(TSharedRef<IPropertyHandle> PropertyHandle, int32 NewSize);
	static FText GetSectionsPerComponent(TSharedRef<IPropertyHandle> PropertyHandle);

	int32 GetLandscapeResolutionX() const;
	void OnChangeLandscapeResolutionX(int32 NewValue);
	void OnCommitLandscapeResolutionX(int32 NewValue, ETextCommit::Type CommitInfo);

	int32 GetLandscapeResolutionY() const;
	void OnChangeLandscapeResolutionY(int32 NewValue);
	void OnCommitLandscapeResolutionY(int32 NewValue, ETextCommit::Type CommitInfo);

	TOptional<int32> GetMinLandscapeResolution() const;
	TOptional<int32> GetMaxLandscapeResolution() const;

	FText GetTotalComponentCount() const;

	FReply OnCreateButtonClicked();
	FReply OnFillWorldButtonClicked();

	static EVisibility GetVisibilityOnlyInNewLandscapeMode(ENewLandscapePreviewMode::Type value);
	ESlateCheckBoxState::Type NewLandscapeModeIsChecked(ENewLandscapePreviewMode::Type value) const;
	void OnNewLandscapeModeChanged(ESlateCheckBoxState::Type NewCheckedState, ENewLandscapePreviewMode::Type value);

	// Import
	static EVisibility GetHeightmapErrorVisibility(TSharedRef<IPropertyHandle> PropertyHandle_HeightmapError);
	static FText GetHeightmapErrorText(TSharedRef<IPropertyHandle> PropertyHandle_HeightmapError);
	static FText GetImportHeightmapFilenameString(TSharedRef<IPropertyHandle> PropertyHandle_HeightmapFilename);
	static void SetImportHeightmapFilenameString(const FText& NewValue, ETextCommit::Type CommitInfo, TSharedRef<IPropertyHandle> PropertyHandle_HeightmapFilename);
	void OnImportHeightmapFilenameChanged();
	static FReply OnImportHeightmapFilenameButtonClicked(TSharedRef<IPropertyHandle> PropertyHandle_HeightmapFilename);

	TSharedRef<SWidget> GetImportLandscapeResolutionMenu();
	void OnChangeImportLandscapeResolution(int32 NewConfigIndex);
	FText GetImportLandscapeResolution() const;

	bool GetImportButtonIsEnabled() const;
	FReply OnFitImportDataButtonClicked();
	void ChooseBestComponentSizeForImport(FEdModeLandscape* LandscapeEdMode);

	// Import layers
	EVisibility GetMaterialTipVisibility() const;

protected:
	static const int32 SectionSizes[];
	static const int32 NumSections[];

	TArray<FLandscapeImportResolution> ImportResolutions;
};

class FLandscapeEditorStructCustomization_FLandscapeImportLayer : public FLandscapeEditorStructCustomization_Base
{
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();

	virtual void CustomizeHeader(TSharedRef<IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& StructCustomizationUtils) OVERRIDE;
	virtual void CustomizeChildren(TSharedRef<IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& StructCustomizationUtils) OVERRIDE;

public:
	static FReply OnLayerFilenameButtonClicked(TSharedRef<IPropertyHandle> PropertyHandle_LayerFilename);
	static bool ShouldFilterLayerInfo(const class FAssetData& AssetData, FName LayerName);

	static EVisibility GetImportLayerCreateVisibility(TSharedRef<IPropertyHandle> PropertyHandle_LayerInfo);
	static TSharedRef<SWidget> OnGetImportLayerCreateMenu(TSharedRef<IPropertyHandle> PropertyHandle_LayerInfo, FName LayerName);
	static void OnImportLayerCreateClicked(TSharedRef<IPropertyHandle> PropertyHandle_LayerInfo, FName LayerName, bool bNoWeightBlend);

	static EVisibility GetErrorVisibility(TSharedRef<IPropertyHandle> PropertyHandle_LayerError);
	static FText GetErrorText(TSharedRef<IPropertyHandle> PropertyHandle_LayerError);
};
