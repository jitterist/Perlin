#pragma once

#include "Components/ActorComponent.h"
#include "PerlinNoise2D.h"
#include "PerlinNoise2DComponent.generated.h"

using FPerlinRef = TSharedRef<FPerlinNoise2D>;

/**
* Creates an arbitrary amount of two-dimensional perlin curves
* for continuous random floats
*/
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), HideCategories = ("Collision"))
class PERLIN_API UPerlinNoise2DComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UPerlinNoise2DComponent();
	void BeginPlay() override;


public:

	/** Create @param Amount * new instances of Perlin2D and add them to PerlinInstances array */
	void AddPerlinInstances(int32 Amount);

	/** Remove instances from PerlinInstances array */
	void RemovePerlinInstance(int32 Amount, int32 Index = 0, bool bRemoveAll = false);

	/** Get Perlin instance. Can be null if invalid index */
	FPerlinNoise2D* GetPerlinAt(int32 Index);


public:

	/** Highest value generated by noise */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perlin2D")
	float Max;

	/** Lowest value generated by noise */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perlin2D")
	float Min;

	/** Which octave to start computation at. Usually 0, higher value means more curved */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perlin2D")
	uint8 StartingOctave;

	/** Number of samples. Higher count means smoother curve */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perlin2D")
	uint8 OctaveCount;

	/** Determines the weight for each octave, usually starting at 0.5 . Decreasing with each subsequent curve */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perlin2D")
	float BaseAmplitude;

	/** Whenever a new curve is generated, use the previous curve's end as starting point? */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perlin2D")
	uint32 bContinuousCurve : 1;

	/** Display a exemplary curve at the actor's location? */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Perlin2D")
	uint32 bShowDebugCurve : 1;


protected:

	/** Create an arbitrary amount of perlin noises with this component's archetype params */
	TArray<FPerlinRef> PerlinInstances;
};