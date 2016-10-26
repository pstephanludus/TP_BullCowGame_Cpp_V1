//
//  CBullCowGame.cpp
//  BullCowGame
//
//  Created by Jérôme Fuchs on 12/10/2016.
//
//

#include <map>
#include "CBullCowGame.hpp"

#define TMap std::map


CBullCowGame::CBullCowGame()
{
	Reset();
}

//1er formalisme C++/Unreal
/*CBullCowGame*/

CBullCowGame::~CBullCowGame()
{

}

void CBullCowGame::setEssaiCourant(int32 nEssai)
{
	this->EssaiCourant = nEssai;
}

void CBullCowGame::setMaxEssai(int32 nEssai)
{
	this->MaxEssai = nEssai;
}

int32 CBullCowGame::getEssaiCourant() const
{
	return this->EssaiCourant;
}

int32 CBullCowGame::getMaxEssai() const
{
	TMap<int32, int32> LgMotEssaiMax{ {3,4},{4,7},{5,10},{6,13},{7,16} };
	return LgMotEssaiMax[MotCache.length()];
}

void CBullCowGame::Reset()
{
	constexpr int32 MAX_ESSAI = 8;
	this->MaxEssai = MAX_ESSAI;
	bool gagne;

	const FString MOTCACHE = "Bolosse";
	MotCache = MOTCACHE;
	this->EssaiCourant = 1;

	status = EWordStatus::Wrong_Length;

	gagne = false;
}

bool CBullCowGame::Gagner()const
{
	return false;
}

EWordStatus CBullCowGame::TestValideMot(FString Mot)const
{
	if (!estIsogram(Mot))
	{
		return EWordStatus::Not_Isogram;
	}
	else if (false)
	{
		return EWordStatus::Not_Lowercase;
	}
	else if (Mot.length() != getLongMotCache())
	{
		return EWordStatus::Wrong_Length;
	}
	else
	{
		return EWordStatus::Ok;
	}


}

BullCowCount CBullCowGame::valideEssai(FString Mot)
{
	this->EssaiCourant++;

	BullCowCount res;
	bool gagne;

	int32 longMot = Mot.length();

	for (int32 i = 0; i< longMot; i++)
	{
		for (int32 j = 0;j< longMot; j ++)
		{
			if (Mot[i] == MotCache[j]) {
				if (i == j)
				{
					res.bulls++;
				}
				else
				{
					res.cows++;
				}

			}

		}
	}

	if (res.bulls == getLongMotCache())
	{
		gagne = true;
	}
	else
	{
		gagne = false;
	}

	return res;
}

int32 CBullCowGame::getLongMotCache()const
{
	return MotCache.length();
}

int32 CBullCowGame::getEWordStatus()const
{
	return (int)status;
}

bool CBullCowGame::estIsogram(FString Mot)const
{
	if (Mot.length() <= 1) { return true; }

	TMap<char, bool>lettreMot;

	for (auto lettre : Mot)
	{
		lettre = tolower(lettre);
		if (lettreMot[lettre]) {
			return false;
		}
		else
		{
			lettreMot[lettre] = true;
		}
	}

	return true;
}
bool CBullCowGame::estMinuscule(FString Mot)const
{

	TMap<char, bool>lettreMot;

	for (auto lettre : Mot)
	{

		if (!islower(lettre))
		{
			return false;
		}
	}

	return true;
}