//Classes.h
#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include "OknoGlowne.h"
#include <fstream>
#include <string>
#include <vector>
#include <msclr/marshal_cppstd.h>
#include <sstream>

using namespace System;
using namespace std;
using namespace msclr::interop; //Konwersja std::string/System::string

class Eksponat{

protected:
	int ID;
	string NazwaEksponatu;
	string NazwiskoAutora;
	string ImieAutora;
	string DataPowstania;

public:
	
	//Metody odpowiedzialne za edycjê
	virtual void DodajEksponat(string xxnazwa, string xxnazwisko, string xximie, string xxdata, string xxgdzie, string xxkiedy, string xxstyl, string xxmaterial) = 0;
	virtual void UsunEksponat(int xxid) = 0;
	virtual void AktualizujEksponat(int xxid, string xxnazwa, string xxnazwisko, string xximie, string xxdata, string xxgdzie, string xxkiedy, string xxstyl, string xxmaterial) = 0;
	
	//Metody odpowiedzialne za zapis
	virtual void ZapiszDoPliku(string nazwaPliku) = 0;
	virtual bool WczytajZPliku(string nazwaPliku) = 0;

	//Metody odpowiedzialne za przekazanie wartosci atrybutów na zewn¹trz klasy
	virtual int PrzeslijID(int xxid) = 0;
	virtual string PrzeslijNazwa(int xxid) = 0;
	virtual string PrzeslijNazwisko(int xxid) = 0;
	virtual string PrzeslijImie(int xxid) = 0;
	virtual string PrzeslijData(int xxid) = 0;


	//Metody pozostale
	virtual int PobierzID() = 0;
	virtual void CzyscVector() = 0;
	

};

class Meble : public Eksponat{
//Wszystkie metody s¹ analogiczne, zale¿ne od atrybutów danej klasy
private:

	string GdzieZnaleziono;
	string KiedyZnaleziono;
	string Material;
	vector <Meble>ListaMeble;
public:
	
	
	Meble(int id, string xnazwa, string xnazwisko, string ximie, string xdata, string xgdzie, string xkiedy, string xmaterial){
		
		this->ID = id;
		this->NazwaEksponatu = xnazwa;
		this->NazwiskoAutora = xnazwisko;
		this->ImieAutora = ximie;
		this->DataPowstania = xdata;
		this->GdzieZnaleziono = xgdzie;
		this->KiedyZnaleziono = xkiedy;
		this->Material = xmaterial;

	}
	void DodajEksponat(string xxnazwa, string xxnazwisko, string xximie, string xxdata, string xxgdzie, string xxkiedy, string xxstyl, string xxmaterial){
		//Dodaje eksponat na koniec vectora
		ListaMeble.push_back(Meble(ListaMeble.size()+1, xxnazwa, xxnazwisko, xximie, xxdata, xxgdzie, xxkiedy, xxmaterial));

	}
	void UsunEksponat(int xxid){
	//Usuwa eksponat z tablicy
		ListaMeble.erase(ListaMeble.begin() + xxid-1);
	//Przesuwa indexy
		for (int i = (xxid - 1); i <= ListaMeble.size(); i++){
			ListaMeble[i - 1].ID = i;
		}
	}
	int PobierzID(){
		//tworzy kolejne indexy w tablicy. Pocz¹tkowy index to '1'
		return ListaMeble.size()+1;
	}
	void AktualizujEksponat(int xxid, string xxnazwa, string xxnazwisko, string xximie, string xxdata, string xxgdzie, string xxkiedy, string xxstyl, string xxmaterial){
		//Zamienia odpowiednie atrybuty na odpowiedniej pozycji w vectorze
		ListaMeble[xxid - 1].NazwaEksponatu = xxnazwa;
		ListaMeble[xxid - 1].NazwiskoAutora = xxnazwisko;
		ListaMeble[xxid - 1].ImieAutora = xximie;
		ListaMeble[xxid - 1].DataPowstania = xxdata;
		ListaMeble[xxid - 1].GdzieZnaleziono = xxgdzie;
		ListaMeble[xxid - 1].KiedyZnaleziono = xxkiedy;
		ListaMeble[xxid - 1].Material = xxmaterial;

	}
	void ZapiszDoPliku(string nazwaPliku){
		//Zapisuje vector-listê eksponatów do pliku
		ofstream plik;
		plik.open(nazwaPliku + "db.txt", std::ios::out);

		for (int i = 0; i < ListaMeble.size(); i++)
		{
			plik << ListaMeble[i].NazwaEksponatu << endl;
			plik << ListaMeble[i].NazwiskoAutora << endl;
			plik << ListaMeble[i].ImieAutora << endl;
			plik << ListaMeble[i].DataPowstania << endl;
			plik << ListaMeble[i].GdzieZnaleziono << endl;
			plik << ListaMeble[i].KiedyZnaleziono << endl;
			plik << ListaMeble[i].Material << endl;
			plik << "=========================================================================================================" << endl;
		}
		plik.close();
	}
	bool WczytajZPliku(string nazwaPliku){
		//Wczytuje listê eksponatów z pliku do vectora
		string nazwa, nazwisko, imie, data, gdzie, kiedy, material, tmp;
		fstream plik;

		plik.open((nazwaPliku + "db.txt"), std::ios::in);
		if (plik.good() == true)
		{
			while (!plik.eof())
			{

				getline(plik, nazwa);
				getline(plik, nazwisko);
				getline(plik, imie);
				getline(plik, data);
				getline(plik, gdzie);
				getline(plik, kiedy);
				getline(plik, material);
				getline(plik, tmp);

				ListaMeble.push_back(Meble(ListaMeble.size()+1, nazwa, nazwisko, imie, data, gdzie, kiedy, material));
			}

			ListaMeble.pop_back();
			return true;
		}
		else{ return false; }

		plik.close();
	}
	void CzyscVector(){
		//Usuwa wszystkie elementy vectora
		ListaMeble.clear();
	}
	~Meble(){ ListaMeble.clear(); }

	//Funkcje przesy³aj¹ wartoœci atrybutów poza klasê, 
	int PrzeslijID(int xxid){ return ListaMeble[xxid - 1].ID; }
	string PrzeslijNazwa(int xxid){	return ListaMeble[xxid - 1].NazwaEksponatu;	}
	string PrzeslijNazwisko(int xxid){	return ListaMeble[xxid - 1].NazwiskoAutora; }
	string PrzeslijImie(int xxid){ return ListaMeble[xxid - 1].ImieAutora; }
	string PrzeslijData(int xxid){ return ListaMeble[xxid - 1].DataPowstania; }
	string PrzeslijGdzie(int xxid){ return ListaMeble[xxid - 1].GdzieZnaleziono; }
	string PrzeslijKiedy(int xxid){	return ListaMeble[xxid - 1].KiedyZnaleziono; }
	string PrzeslijMaterial(int xxid){ return ListaMeble[xxid - 1].Material; }
	
};

class Obrazy : public Eksponat{
private:

	string StylWykonania;
	vector <Obrazy> listaObrazow;

public:
	Obrazy(int id, string xnazwa, string xnazwisko, string ximie, string xdata, string xstyl){
		this->ID = id;
		this->NazwaEksponatu = xnazwa;
		this->NazwiskoAutora = xnazwisko;
		this->ImieAutora = ximie;
		this->DataPowstania = xdata;
		this->StylWykonania = xstyl;
	}
	void DodajEksponat(string xxnazwa, string xxnazwisko, string xximie, string xxdata, string xxgdzie, string xxkiedy, string xxstyl, string xxmaterial){

		listaObrazow.push_back(Obrazy(listaObrazow.size()+1, xxnazwa, xxnazwisko, xximie, xxdata, xxstyl));

	}
	void UsunEksponat(int xxid){
		listaObrazow.erase(listaObrazow.begin() + xxid-1);
		for (int i = (xxid - 1); i <= listaObrazow.size(); i++){
			listaObrazow[i - 1].ID = i;
		}
	}
	int PobierzID(){
		return listaObrazow.size()+1;

	}
	void AktualizujEksponat(int xxid, string xxnazwa, string xxnazwisko, string xximie, string xxdata, string xxgdzie, string xxkiedy, string xxstyl, string xxmaterial){

		listaObrazow[xxid - 1].NazwaEksponatu = xxnazwa;
		listaObrazow[xxid - 1].NazwiskoAutora = xxnazwisko;
		listaObrazow[xxid - 1].ImieAutora = xximie;
		listaObrazow[xxid - 1].DataPowstania = xxdata;
		listaObrazow[xxid - 1].StylWykonania = xxstyl;

	}
	void ZapiszDoPliku(string nazwaPliku){

		ofstream plik;
		plik.open(nazwaPliku + "db.txt", std::ios::out);

		for (int i = 0; i < listaObrazow.size(); i++)
		{
			plik << listaObrazow[i].NazwaEksponatu << endl;
			plik << listaObrazow[i].NazwiskoAutora << endl;
			plik << listaObrazow[i].ImieAutora << endl;
			plik << listaObrazow[i].DataPowstania << endl;
			plik << listaObrazow[i].StylWykonania << endl;
			plik << "=========================================================================================================" << endl;
		}
		plik.close();
	}
	bool WczytajZPliku(string nazwaPliku){
		int i = 0;
		string nazwa, nazwisko, imie, data, styl, tmp;
		fstream plik;

		plik.open((nazwaPliku + "db.txt"), std::ios::in);
		if (plik.good() == true)
		{
			while (!plik.eof())
			{

				getline(plik, nazwa);
				getline(plik, nazwisko);
				getline(plik, imie);
				getline(plik, data);
				getline(plik, styl);
				getline(plik, tmp);

				listaObrazow.push_back(Obrazy(listaObrazow.size()+1, nazwa, nazwisko, imie, data, styl));
			}
			listaObrazow.pop_back();
			return true;
		}
		else{ return false; }

		plik.close();
	}
	void CzyscVector(){
		listaObrazow.clear();
	}
	~Obrazy(){ listaObrazow.clear(); };

	int PrzeslijID(int xxid){ return listaObrazow[xxid - 1].ID; }
	string PrzeslijNazwa(int xxid){ return listaObrazow[xxid - 1].NazwaEksponatu; }
	string PrzeslijNazwisko(int xxid){ return listaObrazow[xxid - 1].NazwiskoAutora; }
	string PrzeslijImie(int xxid){ return listaObrazow[xxid - 1].ImieAutora; }
	string PrzeslijData(int xxid){ return listaObrazow[xxid - 1].DataPowstania; }
	string PrzeslijStyl(int xxid){ return listaObrazow[xxid - 1].StylWykonania; }
	
};

class PrzedmiotyUzytkowe : public Eksponat{
private:

	string GdzieZnaleziono;
	string KiedyZnaleziono;
	vector <PrzedmiotyUzytkowe>ListaPU;
public:

	PrzedmiotyUzytkowe(int id, string xnazwa, string xnazwisko, string ximie, string xdata, string xgdzie, string xkiedy){
		this->ID = id;
		this->NazwaEksponatu = xnazwa;
		this->NazwiskoAutora = xnazwisko;
		this->ImieAutora = ximie;
		this->DataPowstania = xdata;
		this->GdzieZnaleziono = xgdzie;
		this->KiedyZnaleziono = xkiedy;
	}
	void DodajEksponat(string xxnazwa, string xxnazwisko, string xximie, string xxdata, string xxgdzie, string xxkiedy, string xxstyl, string xxmaterial){

		ListaPU.push_back(PrzedmiotyUzytkowe(ListaPU.size()+1, xxnazwa, xxnazwisko, xximie, xxdata, xxgdzie, xxkiedy));

	}
	void UsunEksponat(int xxid){
		ListaPU.erase(ListaPU.begin() + xxid-1);
		for (int i = (xxid - 1); i <= ListaPU.size(); i++){
			ListaPU[i - 1].ID = i;
		}
	}
	int PobierzID(){
		return ListaPU.size()+1;

	}
	void AktualizujEksponat(int xxid, string xxnazwa, string xxnazwisko, string xximie, string xxdata, string xxgdzie, string xxkiedy, string xxstyl, string xxmaterial){

		ListaPU[xxid - 1].NazwaEksponatu = xxnazwa;
		ListaPU[xxid - 1].NazwiskoAutora = xxnazwisko;
		ListaPU[xxid - 1].ImieAutora = xximie;
		ListaPU[xxid - 1].DataPowstania = xxdata;
		ListaPU[xxid - 1].GdzieZnaleziono = xxgdzie;
		ListaPU[xxid - 1].KiedyZnaleziono = xxkiedy;


	}
	void ZapiszDoPliku(string nazwaPliku){

		ofstream plik;
		plik.open(nazwaPliku + "db.txt", std::ios::out);

		for (int i = 0; i < ListaPU.size(); i++)
		{
			plik << ListaPU[i].NazwaEksponatu << endl;
			plik << ListaPU[i].NazwiskoAutora << endl;
			plik << ListaPU[i].ImieAutora << endl;
			plik << ListaPU[i].DataPowstania << endl;
			plik << ListaPU[i].GdzieZnaleziono << endl;
			plik << ListaPU[i].KiedyZnaleziono << endl;
			plik << "=========================================================================================================" << endl;
		}
		plik.close();
	}
	bool WczytajZPliku(string nazwaPliku){
		int i = 0;
		string nazwa, nazwisko, imie, data, gdzie, kiedy, tmp;
		fstream plik;

		plik.open((nazwaPliku + "db.txt"), std::ios::in);
		if (plik.good() == true)
		{
			while (!plik.eof())
			{

				getline(plik, nazwa);
				getline(plik, nazwisko);
				getline(plik, imie);
				getline(plik, data);
				getline(plik, gdzie);
				getline(plik, kiedy);
				getline(plik, tmp);

				ListaPU.push_back(PrzedmiotyUzytkowe(ListaPU.size()+1, nazwa, nazwisko, imie, data, gdzie, kiedy));
			}
			ListaPU.pop_back();
			return true;
		}
		else{ return false; }

		plik.close();
	}
	void CzyscVector(){
		ListaPU.clear();
	}
	~PrzedmiotyUzytkowe(){ ListaPU.clear(); }

	int PrzeslijID(int xxid){ return ListaPU[xxid - 1].ID; }
	string PrzeslijNazwa(int xxid){ return ListaPU[xxid - 1].NazwaEksponatu; }
	string PrzeslijNazwisko(int xxid){ return ListaPU[xxid - 1].NazwiskoAutora; }
	string PrzeslijImie(int xxid){ return ListaPU[xxid - 1].ImieAutora; }
	string PrzeslijData(int xxid){ return ListaPU[xxid - 1].DataPowstania; }
	string PrzeslijGdzie(int xxid){ return ListaPU[xxid - 1].GdzieZnaleziono; }
	string PrzeslijKiedy(int xxid){ return ListaPU[xxid - 1].KiedyZnaleziono; }
	
};

class Rzezby : public Eksponat{
private:

	string StylWykonania;
	string Material;
	vector <Rzezby>ListaRzezby;

public:

	Rzezby(int id, string xnazwa, string xnazwisko, string ximie, string xdata, string xstyl, string xmaterial){
		this->ID = id;
		this->NazwaEksponatu = xnazwa;
		this->NazwiskoAutora = xnazwisko;
		this->ImieAutora = ximie;
		this->DataPowstania = xdata;
		this->StylWykonania = xstyl;
		this->Material = xmaterial;

	}
	void DodajEksponat(string xxnazwa, string xxnazwisko, string xximie, string xxdata, string xxgdzie, string xxkiedy, string xxstyl, string xxmaterial){

		ListaRzezby.push_back(Rzezby(ListaRzezby.size()+1, xxnazwa, xxnazwisko, xximie, xxdata, xxstyl, xxmaterial));

	}
	void UsunEksponat(int xxid){
		ListaRzezby.erase(ListaRzezby.begin() + xxid-1);
		for (int i = (xxid - 1); i <= ListaRzezby.size(); i++){
			ListaRzezby[i - 1].ID = i;
		}
	}
	int PobierzID(){
		return ListaRzezby.size()+1;

	}
	void AktualizujEksponat(int xxid, string xxnazwa, string xxnazwisko, string xximie, string xxdata, string xxgdzie, string xxkiedy, string xxstyl, string xxmaterial){

		ListaRzezby[xxid - 1].NazwaEksponatu = xxnazwa;
		ListaRzezby[xxid - 1].NazwiskoAutora = xxnazwisko;
		ListaRzezby[xxid - 1].ImieAutora = xximie;
		ListaRzezby[xxid - 1].DataPowstania = xxdata;
		ListaRzezby[xxid - 1].StylWykonania = xxstyl;
		ListaRzezby[xxid - 1].Material = xxmaterial;

	}
	void ZapiszDoPliku(string nazwaPliku){

		ofstream plik;
		plik.open(nazwaPliku + "db.txt", std::ios::out);

		for (int i = 0; i < ListaRzezby.size(); i++)
		{
			plik << ListaRzezby[i].NazwaEksponatu << endl;
			plik << ListaRzezby[i].NazwiskoAutora << endl;
			plik << ListaRzezby[i].ImieAutora << endl;
			plik << ListaRzezby[i].DataPowstania << endl;
			plik << ListaRzezby[i].StylWykonania << endl;
			plik << ListaRzezby[i].Material << endl;
			plik << "=========================================================================================================" << endl;
		}
		plik.close();
	}
	bool WczytajZPliku(string nazwaPliku){
		int i = 0;
		string nazwa, nazwisko, imie, data, styl, material, tmp;
		fstream plik;

		plik.open((nazwaPliku + "db.txt"), std::ios::in);
		if (plik.good() == true)
		{
			while (!plik.eof())
			{

				getline(plik, nazwa);
				getline(plik, nazwisko);
				getline(plik, imie);
				getline(plik, data);
				getline(plik, styl);
				getline(plik, material);
				getline(plik, tmp);

				ListaRzezby.push_back(Rzezby(ListaRzezby.size()+1, nazwa, nazwisko, imie, data, styl, material));
			}
			ListaRzezby.pop_back();
			return true;
		}
		else{ return false; }

		plik.close();
	}
	void CzyscVector(){
		ListaRzezby.clear();
	}
	~Rzezby(){ ListaRzezby.clear(); }

	int PrzeslijID(int xxid){ return ListaRzezby[xxid - 1].ID; }
	string PrzeslijNazwa(int xxid){ return ListaRzezby[xxid - 1].NazwaEksponatu; }
	string PrzeslijNazwisko(int xxid){ return ListaRzezby[xxid - 1].NazwiskoAutora; }
	string PrzeslijImie(int xxid){ return ListaRzezby[xxid - 1].ImieAutora; }
	string PrzeslijData(int xxid){ return ListaRzezby[xxid - 1].DataPowstania; }
	string PrzeslijStyl(int xxid){ return ListaRzezby[xxid - 1].StylWykonania; }
	string PrzeslijMaterial(int xxid){ return ListaRzezby[xxid - 1].Material; }


};

class RekopisyIStarodruki : public Eksponat{
private:

	vector <RekopisyIStarodruki>ListaRIS;
public:

	RekopisyIStarodruki(int id, string xnazwa, string xnazwisko, string ximie, string xdata){
		this->ID = id;
		this->NazwaEksponatu = xnazwa;
		this->NazwiskoAutora = xnazwisko;
		this->ImieAutora = ximie;
		this->DataPowstania = xdata;
	}
	void DodajEksponat(string xxnazwa, string xxnazwisko, string xximie, string xxdata, string xxgdzie, string xxkiedy, string xxstyl, string xxmaterial){

		ListaRIS.push_back(RekopisyIStarodruki(ListaRIS.size()+1, xxnazwa, xxnazwisko, xximie, xxdata));

	}
	void UsunEksponat(int xxid){
		ListaRIS.erase(ListaRIS.begin() + xxid-1);
		for (int i = (xxid - 1); i <= ListaRIS.size(); i++){
			ListaRIS[i - 1].ID = i;
		}
	}
	int PobierzID(){
		return ListaRIS.size()+1;

	}
	void AktualizujEksponat(int xxid, string xxnazwa, string xxnazwisko, string xximie, string xxdata, string xxgdzie, string xxkiedy, string xxstyl, string xxmaterial){

		ListaRIS[xxid - 1].NazwaEksponatu = xxnazwa;
		ListaRIS[xxid - 1].NazwiskoAutora = xxnazwisko;
		ListaRIS[xxid - 1].ImieAutora = xximie;
		ListaRIS[xxid - 1].DataPowstania = xxdata;

	}
	void ZapiszDoPliku(string nazwaPliku){

		ofstream plik;
		plik.open(nazwaPliku + "db.txt", std::ios::out);

		for (int i = 0; i < ListaRIS.size(); i++)
		{
			plik << ListaRIS[i].NazwaEksponatu << endl;
			plik << ListaRIS[i].NazwiskoAutora << endl;
			plik << ListaRIS[i].ImieAutora << endl;
			plik << ListaRIS[i].DataPowstania << endl;
			plik << "=========================================================================================================" << endl;
		}
		plik.close();
	}
	bool WczytajZPliku(string nazwaPliku){
		int i = 0;
		string nazwa, nazwisko, imie, data, tmp;
		fstream plik;

		plik.open((nazwaPliku + "db.txt"), std::ios::in);
		if (plik.good() == true)
		{
			while (!plik.eof())
			{

				getline(plik, nazwa);
				getline(plik, nazwisko);
				getline(plik, imie);
				getline(plik, data);
				getline(plik, tmp);

				ListaRIS.push_back(RekopisyIStarodruki(ListaRIS.size()+1, nazwa, nazwisko, imie, data));
			}
			ListaRIS.pop_back();
			return true;
		}
		else{ return false; }

		plik.close();
	}
	void CzyscVector(){
		ListaRIS.clear();
	}
	~RekopisyIStarodruki(){ ListaRIS.clear(); }

	int PrzeslijID(int xxid){ return ListaRIS[xxid - 1].ID; }
	string PrzeslijNazwa(int xxid){ return ListaRIS[xxid - 1].NazwaEksponatu; }
	string PrzeslijNazwisko(int xxid){ return ListaRIS[xxid - 1].NazwiskoAutora; }
	string PrzeslijImie(int xxid){ return ListaRIS[xxid - 1].ImieAutora; }
	string PrzeslijData(int xxid){ return ListaRIS[xxid - 1].DataPowstania; }
	
};

#endif