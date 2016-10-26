//
//  main.cpp
//  BullCowGame
//
//  Created by Jérôme Fuchs on 12/10/2016.
//
//

#include <string>
#include <iostream>
#include "CBullCowGame.hpp"

using namespace std;
using FTEXT = std::string;
using int32 = int;

void AfficheIntro(CBullCowGame joueur);
FTEXT VotreMot(CBullCowGame joueur);
void Jouer(CBullCowGame joueur);
bool JouerEncore();

int32 main() {

	CBullCowGame joueur;
	AfficheIntro(joueur);

	do {
		Jouer(joueur);
	} while (JouerEncore());
	return 0;
}

void AfficheIntro(CBullCowGame joueur)
{
	//constexpr int32 WORLD_LENGHT = 9;

	cout << "Bienvenue dans le jeu BULL and COW game" << endl;
	cout << "Nombre de lettre dans le mot caché" << joueur.getLongMotCache();
	cout << "Nombre de possibilité" << joueur.getMaxEssai() << endl;
}

FTEXT VotreMot(CBullCowGame joueur) {


	EWordStatus status = EWordStatus::Ok;
	FTEXT mot = "";

	do {
		int32 EssaiCourant = joueur.getEssaiCourant();
		cout << "Essai numero : " << EssaiCourant << endl;
		cout << "saisir votre mot :" << endl;
		getline(cin, mot);

		status = joueur.TestValideMot(mot);

		switch (status)
		{
		case EWordStatus::Wrong_Length: cout << "Entrez un mot de max :" << joueur.getLongMotCache() << " lettres !" << endl; break;
		case EWordStatus::Not_Isogram: cout << "Entrez un mot sans lettres répétées !" << endl; break;
		case EWordStatus::Not_Lowercase: cout << "Entrez un mot sans lettres majuscules !" << endl; break;
		default:return mot;
		}
	} while (status != EWordStatus::Ok);


	return mot;

}

void Jouer(CBullCowGame joueur) {

	joueur.Reset();
	int32 MaxEssai = joueur.getMaxEssai();
	//constexpr int32 NombreTours = 5;

	cout << "Essai n°" << joueur.getEssaiCourant() << endl;
	//for(int32 i = 0; i< MaxEssai; i++)
	while (!joueur.Gagner() && joueur.getEssaiCourant() <= MaxEssai)
	{
		FString mot = VotreMot(joueur);
		EWordStatus status = joueur.TestValideMot(mot);

		BullCowCount BullCowCount = joueur.valideEssai(mot);
		cout << "votre mot est : " << mot << endl;
		cout << "bull : " << BullCowCount.bulls << endl;
		cout << "cow : " << BullCowCount.cows << endl;
		cout << endl;

	}
	cout << "bravo tu as gagné !!! o/" << endl;

}

bool JouerEncore()
{
	cout << "Voulez vous rejouez? " << endl;
	FTEXT rep = "";
	getline(cin, rep);
	return(rep[0] == 'Y' || rep[0] == 'O');
}
