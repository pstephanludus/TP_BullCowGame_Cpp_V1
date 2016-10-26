#pragma once
#include <string>

using FString = std::string;
using int32 = int;

typedef struct BullCowCount {
	int32 bulls = 0;
	int32 cows = 0;
};

enum class EWordStatus {
	Ok,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class CBullCowGame
{
private:
	int32 EssaiCourant;
	int32 MaxEssai;
	FString MotCache;
	EWordStatus status;

public:
	CBullCowGame();
	~CBullCowGame();

	//get
	int32 getEssaiCourant()const;
	int32 getMaxEssai()const;

	//set
	void setEssaiCourant(int32 nEssai);
	void setMaxEssai(int32 nEssai);

	void Reset();

	bool Gagner()const;

	EWordStatus TestValideMot(std::string mot)const;

	BullCowCount valideEssai(FString Mot);

	int32 getLongMotCache()const;

	int32 getEWordStatus()const;

	bool estIsogram(FString Mot)const;

	bool estMinuscule(FString Mot)const;
};
