#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm")
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono_literals;
// Atributos Venasaur
string venasaurName = "Venasaur";
int venasaurHP = 100;
int venasaurDMG;
bool venasaurIsAlive = true;
// Atrivutos Charizard
string charizardName = "Charizard";
int charizardHP = 100;
int charizardDMG;
bool charizardIsAlive = true;
// Atributos mi Pokemon
string magikarpName = "Magikarp";
int magikarpHp = 400;
bool magikarpIsAlive = true;
// Magikarp Ataques
// Ataque 1
string magikarpAttack1Name = "Salpicadura";
int magikarpAttack1 = 45;
int magikarpAttack1PP = 1;
// Ataque 2
string magikarpAttack2Name = "Placaje";
int magikarpAttack2 = 30;
// Ataque 3
string magikarpAttack3Name = "Azote";
int magikarpAttack3 = 100;
// Ataque 4
string magikarpAttack4Name = "Surf";
int magikarpAttack4 = 11;
// Mas variables.
int t = 1;
bool teamRocket = false;
int evento = 0;
int dmgMK;
int opcionToAttack;
// Funciones
void startGame()
{
	cout << "#######################################################################################################################\n\n";
	cout << " Eres un " << magikarpName << " que  va saltando por un bosque direccion al lago de la Furia para  encontrarte con un viejo  amigo.\n\n";
	cout << " De repente suena algo en un arbusto.\n\n";
	this_thread::sleep_for(4s);
	PlaySound(TEXT("spawn.wav"), NULL, SND_FILENAME);
	this_thread::sleep_for(1s);
	cout << " Aparecio un " << venasaurName << " que te quiere atacar.\n\n";
	this_thread::sleep_for(2s);
	cout << " " << venasaurName << " tiene " << venasaurHP << " puntos de vida.\n\n";
	this_thread::sleep_for(3s);
	PlaySound(TEXT("spawn.wav"), NULL, SND_FILENAME);
	this_thread::sleep_for(1s);
	cout << " Aparecio un " << charizardName << " que te quiere atacar.\n\n";
	this_thread::sleep_for(2s);
	cout << " " << charizardName << " tiene " << charizardHP << " puntos de vida.\n\n";
	PlaySound(TEXT("pokemon.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}
void turnGame()
{
	this_thread::sleep_for(2s);
	cout << "####################################################### ";
	cout << " Turno: " << t;
	cout << " ######################################################\n\n";
	t++;
}
int enemy1DMG()
{
	srand(time(NULL));
	return 1 + rand() % 100;
	 
}
int enemy2DMG()
{
	return 1 + rand() % 100;
}
void opcionAttackSelect()
{
	int opcionDanoMK;
	do
	{
		cout << " ELIGE QUE ATAQUE USAR\n\n";
		cout << " [1] " << magikarpAttack1Name << " " << magikarpAttack1 << " DMG (Tiene " << magikarpAttack1PP << ")\n";
		cout << " [2] " << magikarpAttack2Name << " " << magikarpAttack2 << " DMG\n";
		cout << " [3] " << magikarpAttack3Name << " " << magikarpAttack3 << " DMG\n";
		cout << " [4] " << magikarpAttack4Name << " " << magikarpAttack4 << " DMG  (Hiere a todos los objetivos)\n\n";
		cout << " Opcion: ";
		cin >> opcionDanoMK;
		if (opcionDanoMK == 1)
		{
			if (magikarpAttack1PP > 0)
			{
				cout << "\n Elegiste " << magikarpAttack1Name << ", tiene " << magikarpAttack1 << " de DMG\n";
				dmgMK = magikarpAttack1;
				magikarpAttack1PP = magikarpAttack1PP - 1;
			}
			else
			{
				cout << "\n Tienes " << magikarpAttack1PP << " PP.Atacaras con el siguiente ataque del menu (" << magikarpAttack1Name << ")\n\n";
				dmgMK = magikarpAttack2;
			}
		}
		else if (opcionDanoMK == 2)
		{
			cout << "\n Elegiste " << magikarpAttack2Name << ", tiene " << magikarpAttack2 << " de DMG\n";
			dmgMK = magikarpAttack2;
		}
		else if (opcionDanoMK == 3)
		{
			cout << "\n Elegiste " << magikarpAttack3Name << ", tiene " << magikarpAttack3 << " de DMG\n";
			dmgMK = magikarpAttack3;
		}
		else if (opcionDanoMK == 4)
		{
			cout << "\n Elegiste " << magikarpAttack4Name << ", tiene " << magikarpAttack4 << " de DMG\n";
			venasaurHP = venasaurHP - magikarpAttack4;
			charizardHP = charizardHP - magikarpAttack4;
		}
		else
		{
			cout << "\n Fuera de rango\n\n";
		}
	} while (opcionDanoMK != 1 && opcionDanoMK != 2 && opcionDanoMK != 3 && opcionDanoMK != 4);
}
int opcionToAttackSelect() {
	do
	{
		cout << "\n ELIGE A QUIEN ATACAR\n\n";
		if (venasaurIsAlive == true && charizardIsAlive == true)
		{
			cout << " [1] " << venasaurName << "\n";
			cout << " [2] " << charizardName << "\n\n";
		}
		else if (venasaurIsAlive == false && charizardIsAlive == true)
		{
			cout << " [2] " << charizardName << "\n\n";
		}
		else if (venasaurIsAlive == true && charizardIsAlive == false)
		{
			cout << " [1] " << venasaurName << "\n\n";
		}
		cout << " Opcion: ";
		cin >> opcionToAttack;
		if (opcionToAttack == 1)
		{
			if (venasaurIsAlive == true)
			{
				venasaurHP = venasaurHP - dmgMK;
			}
			else
			{
				charizardHP = charizardHP - dmgMK;
			}
		}
		else if (opcionToAttack == 2)
		{
			if (charizardIsAlive == true)
			{
				charizardHP = charizardHP - dmgMK;
			}
			else
			{
				venasaurHP = venasaurHP - dmgMK;
			}
		}
		else
		{
			cout << "\n Fuera de rango\n";
		}
	} while (opcionToAttack != 1 && opcionToAttack != 2);
	return opcionToAttack;
}
void venasaurIsDeath() {
	if (opcionToAttack == 1 && venasaurIsAlive == false && teamRocket == false && evento == 0)
	{
		this_thread::sleep_for(2s);
		cout << "\n [Suena Un Altavoz lejano] Incluso despues de matar al pobre " << venasaurName << " le sigues atacando? \n\n Eres un asesino...";
		this_thread::sleep_for(2s);
		cout << "pero me caes bien.\n\n";
		this_thread::sleep_for(2s);
		cout << " Quieres unirte al Team Rocket ? \n\n";
		cout << " [1] Si\n";
		cout << " [2] No\n\n";
		cout << " Opcion: ";
		int opcionTeamRocket;
		cin >> opcionTeamRocket;
		evento = 1;

		if (opcionTeamRocket == 1)
		{
			cout << "\n Asi que aceptas...";
			this_thread::sleep_for(2s);
			cout << " Ya contactare contigo pronto.\n\n";
			this_thread::sleep_for(2s);
			cout << " Ya que el " << venasaurName << " esta muerto te ayudare a mandar tus ataques al " << charizardName;
			this_thread::sleep_for(2s);
			cout << "\n\n Bye!\n";
			teamRocket = true;
		}
		else if (opcionTeamRocket == 2)
		{
			cout << "\n\n Asi que aceptas...";
			this_thread::sleep_for(2s);
			cout << " como que no...";
			this_thread::sleep_for(2s);
			cout << " se te ha subido el ego...";
			this_thread::sleep_for(2s);
			this_thread::sleep_for(2s);
			cout << " he mandado mi secta AGRHR...";
			this_thread::sleep_for(2s);
			cout << " digo mi organizacion a por ti\n\n";
			this_thread::sleep_for(2s);
			cout << " Ya que no te unes a mi equipo ya no te dejare atacar al " << venasaurName;
			this_thread::sleep_for(2s);
			cout << "\n\n Bye!\n\n";
			teamRocket = false;
		}
	};
}
void charizardIsDeath() {
	if (opcionToAttack == 2 && charizardIsAlive == false && teamRocket == false && evento == 0)
	{
		cout << "\n [Suena Un Altavoz lejano]Incluso despues de matar al pobre " << charizardName << " le sigues atacando? \n\n Eres un asesino...";
		this_thread::sleep_for(2s);
		cout << "pero me caes bien.";
		this_thread::sleep_for(2s);
		cout << "\n  Quieres unirte al Team Rocket ? \n\n";
		cout << " [1] Si\n";
		cout << " [2] No\n\n";
		cout << " Opcion: ";
		int opcionTeamRocket;
		cin >> opcionTeamRocket;
		evento = 1;

		if (opcionTeamRocket == 1)
		{
			cout << "\n\n Asi que aceptas...";
			this_thread::sleep_for(2s);
			cout << " Ya contactare contigo pronto\n\n";
			this_thread::sleep_for(2s);
			cout << " Ya que el " << charizardName << " esta muerto te ayudare a mandar tus ataques al " << venasaurName;
			this_thread::sleep_for(2s);
			cout << "\n\nBye!\n\n";
			teamRocket = true;
		}
		else if (opcionTeamRocket == 2)
		{
			cout << "\n\n Asi que aceptas...";
			this_thread::sleep_for(2s);
			cout << " como que no...";
			this_thread::sleep_for(2s);
			cout << " se te ha subido el ego...";
			this_thread::sleep_for(2s);
			this_thread::sleep_for(2s);
			cout << " he mandado mi secta AGRHR...";
			this_thread::sleep_for(2s);
			cout << " digo mi organizacion a por ti.\n\n";
			this_thread::sleep_for(2s);
			cout << " Ya que no te unes a mi equipo ya no te dejare atacar al " << charizardName;
			this_thread::sleep_for(2s);
			cout << "\n\n Bye!\n\n";
			teamRocket = false;
		}
	};
}
bool checkMagikarpStatus1() {
	if (magikarpHp <= 0)
	{
		cout << " El enemigo " << venasaurName << " te ha matado\n\n";
		return false;
	}
	else
	{
		cout << " " << venasaurName << " te ha hecho un ataque de " << venasaurDMG << " puntos de dano. Te quedan " << magikarpHp << " puntos de vida\n";
		return true;
	}
}
bool checkMagikarpStatus2() {
	if (magikarpHp <= 0)
	{
		cout << " El enemigo " << charizardName << " te ha matado\n\n";
		return false;
	}
	else {
		cout << " " << charizardName << " te ha hecho un ataque de " << charizardDMG << " puntos de dano. Te quedan " << magikarpHp << " puntos de vida\n\n";
		return true;
	}
}
bool venasaurStatus() {
	if (venasaurHP <= 0)
	{
		cout << "\n " << venasaurName << " esta muerto \n\n";
		return false;
	}
	else
	{
		cout << "\n " << venasaurName << " le quedan " << venasaurHP << "\n\n";
		return true;
	}
}
bool charizardStatus() {
	if (charizardHP <= 0)
	{
		cout << "\n " << charizardName << " esta muerto \n\n";
		return false;
	}
	else
	{
		cout << "\n " << charizardName << " le quedan " << charizardHP << "\n\n";
		return  true;
	}
}
int mkHP(int enemyAttack, int heroHP){
	magikarpHp = heroHP - enemyAttack;
	return magikarpHp;
}
bool logros() {
	if (teamRocket == true)
	{
		cout << "\n\n LOGROS: \n\n"<< " Team Rocket";
		return true;
	}
	else
	{
		cout << "\n\n LOGROS: \n\n";
		return false;
	}
}
int main()
{
	startGame();
	while ((venasaurIsAlive == true || charizardIsAlive == true) && magikarpIsAlive == true)
	{
		turnGame();
		// Daño charizard
		charizardDMG = enemy1DMG();
		// Daño venasaur
		venasaurDMG = enemy2DMG();
		// ELIGE QUE ATAQUE  USAR VOID
		opcionAttackSelect();
		// ElIGE A QUIEN ATACAR
		opcionToAttackSelect();
		// si vuelves a atacar al 1 si esta muerto [Venasaur], si vuelves a atacar al 2 si esta muerto [Charizard]
		venasaurIsDeath();//VOID
		charizardIsDeath();//VOID
		// Venasaur
		//venasaurIsAlive = venasaurStatus();

		if (venasaurStatus())
		{ 
			// Ataco al MK
			magikarpHp = mkHp( venasaurHP, magikarpHp);
			magikarpIsAlive = checkMagikarpStatus1();
		
		// Charizard
		//charizardIsAlive = charizardStatus();

		if (charizardStatus())
		{
			// Ataco al MK
			magikarpHp = mkHp(charizardDMG, magikarpHp);
			magikarpIsAlive = checkMagikarpStatus2();
		}
	}
	teamRocket = logros();
}
