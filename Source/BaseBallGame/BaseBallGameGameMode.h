﻿#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "BaseBallGameGameMode.generated.h"

UCLASS()
class BASEBALLGAME_API ABaseBallGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABaseBallGameGameMode();

	virtual void BeginPlay() override;

	// 클라이언트로부터 메세지를 받았을 때 동작
	UFUNCTION(Server, Reliable)
	void GotMessageFromClient(const FString& UserID, const FString& InputText) const;

	// getter
	// 랜덤 숫자 길이 반환
	FORCEINLINE int32 GetNumberLength() const
	{
		return TargetNumberLength;
	}
	// 랜덤 숫자 반환
	FORCEINLINE FString GetTargetNumber() const
	{
		return TargetNumber;
	}

	// setter
	// 랜덤 숫자 길이 설정
	FORCEINLINE void SetNumberLength(const int32 InTargetNumberLength)
	{
		TargetNumberLength = InTargetNumberLength;
	}

protected:
	// 랜덤 숫자 길이
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TargetNumber")
	int32 TargetNumberLength;

	// 랜덤 숫자
	FString TargetNumber;
};
