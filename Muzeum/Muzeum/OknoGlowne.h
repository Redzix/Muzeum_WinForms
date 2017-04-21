#pragma once
#include "Classes.h"
namespace Muzeum {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for OknoGlowne
	/// </summary>
	public ref class OknoGlowne : public System::Windows::Forms::Form
	{
	public:
		//
		//Obiekty
		//
		Meble *mebel;
		Obrazy *obraz;
		PrzedmiotyUzytkowe *puzytk;
		Rzezby *rzezba;
		RekopisyIStarodruki *rekistar;
	


	public:
		//Zmienne logiczne s³u¿¹ce do obs³ugi plików
		bool Zapisany = true;
		bool ZapisanyMebel = true;
		bool ZapisanyObraz = true;
		bool ZapisanyPU = true;
		bool ZapisanyR = true;

	public:
		bool ZapisanyRIS = true;
	
		
		//Funkcja String^ to string
		inline string Sts(String^ temp){
			return marshal_as<std::string>(temp);
		}
		//Funkcja string to String^
		inline String^ stS(string temp){
			return marshal_as<System::String^>(temp);
		}
		//Funkcja int to string
		string inttostring(int x){

			ostringstream ss;
			ss << x;
			return  ss.str();

		}
		//Funkcja string to int
		int stringtoint(string napis){
			
			int i;
			istringstream iss(napis);
			iss >> i;
			return i;
		}
		
		OknoGlowne(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~OknoGlowne()
		{
			if (components)
			{
				delete components;
			}
		}
		//Funkcja usuwa widocznoœc niepotrzebnych labeli i textboxow
		void DeleteNotUsedControls()
		{

			if (StyleLabel){
				this->RightPanel->Controls->Remove(StyleLabel);
			}
			if (StyleTB)
			{
				this->RightPanel->Controls->Remove(StyleTB);
			}

			if (WhenFoundLabel){
				this->RightPanel->Controls->Remove(WhenFoundLabel);
			}
			if (WhenFoundTB)
			{
				this->RightPanel->Controls->Remove(WhenFoundTB);
			}

			if (WhereFoundLabel){
				this->RightPanel->Controls->Remove(WhereFoundLabel);
			}
			if (WhereFoundTB)
			{
				this->RightPanel->Controls->Remove(WhereFoundTB);
			}

			if (StuffLabel){
				this->RightPanel->Controls->Remove(StuffLabel);
			}
			if (StuffTB)
			{
				this->RightPanel->Controls->Remove(StuffTB);
			}



		}
	private: System::Windows::Forms::TableLayoutPanel^  LeftPanel;
	protected:


	private: System::Windows::Forms::ComboBox^  CollectionCB;

	private: System::Windows::Forms::ListView^  ObjectList;
	private: System::Windows::Forms::ListViewItem^ ObjectListItems;

	private: System::Windows::Forms::TableLayoutPanel^  RightPanel;

	private: System::Windows::Forms::Button^  EditButton;
	private: System::Windows::Forms::Button^  DeleteButton;
	private: System::Windows::Forms::Label^  AuthorILabel;
	private: System::Windows::Forms::Label^  ExhibitNameLabel;
	private: System::Windows::Forms::Label^  AuthorNLabel;
	private: System::Windows::Forms::Label^  CreatDateLabel;


	private: System::Windows::Forms::Label^  StyleLabel;
	private: System::Windows::Forms::Label^  WhenFoundLabel;
	private: System::Windows::Forms::Label^  WhereFoundLabel;
	private: System::Windows::Forms::Label^  StuffLabel;


	private: System::Windows::Forms::TextBox^  ExhibitNameTB;
	private: System::Windows::Forms::TextBox^  CreatDateTB;
	private: System::Windows::Forms::TextBox^  AuthorITB;
	private: System::Windows::Forms::TextBox^  AuthorNTB;
	private: System::Windows::Forms::TextBox^  StyleTB;
	private: System::Windows::Forms::TextBox^  WhenFoundTB;
	private: System::Windows::Forms::TextBox^  WhereFoundTB;
	private: System::Windows::Forms::TextBox^  StuffTB;
	private: System::Windows::Forms::Button^  UpdateButton;
	private: System::Windows::Forms::Button^  ClearButton;
	private: System::Windows::Forms::Button^  AddButton;
	private: System::Windows::Forms::ColumnHeader^  columnHeader8;
	private: System::Windows::Forms::Button^  ReadFromFileButtonAll;
	private: System::Windows::Forms::Button^  SaveToFileButonAll;
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;
	private: System::Windows::Forms::ColumnHeader^  columnHeader4;
	private: System::Windows::Forms::Button^  SaveToFiletButtonCurrent;
	private: System::Windows::Forms::Button^  ChangeV;
	private: System::Windows::Forms::Button^  ReadFromFileButtonCurrent;


	private: System::Windows::Forms::ColumnHeader^  columnHeader5;
	private: System::Windows::Forms::ColumnHeader^  columnHeader6;
	private: System::Windows::Forms::ColumnHeader^  columnHeader7;







	private:
		//Funkcje odpowiadaj¹ce za wyœwietlanie poszczególnych kolekcji
		void WyswietlWszystkie(){

			this->WyswietlMeble(true);
			this->WyswietlObrazy(true);
			this->WyswietlPU(true);
			this->WyswietlRzezby(true);
			this->WyswietlRIS(true);

		}
		void WyswietlMeble(bool CzyWszystkie){
			if (this->mebel->PobierzID() > 0){

				for (int i = 1; i < this->mebel->PobierzID(); i++)
				{
					ObjectListItems = gcnew Windows::Forms::ListViewItem(stS(this->mebel->PrzeslijNazwa(i)));
					ObjectListItems->SubItems->Add(stS(this->mebel->PrzeslijNazwisko(i)));
					ObjectListItems->SubItems->Add(stS(this->mebel->PrzeslijImie(i)));
					ObjectListItems->SubItems->Add(stS(this->mebel->PrzeslijData(i)));
					if (!CzyWszystkie){
					
					ObjectListItems->SubItems->Add(stS(this->mebel->PrzeslijGdzie(i)));
					ObjectListItems->SubItems->Add(stS(this->mebel->PrzeslijKiedy(i)));
					ObjectListItems->SubItems->Add(stS(this->mebel->PrzeslijMaterial(i)));
					ObjectListItems->SubItems->Add(stS(inttostring(this->mebel->PrzeslijID(i))));

					}
					this->ObjectList->Items->Add(this->ObjectListItems);
				}
			}
			else if (this->mebel->PobierzID() == 0){
				ObjectListItems = gcnew Windows::Forms::ListViewItem("Brak eksponatów");
				this->ObjectList->Items->Add(this->ObjectListItems);
			}
		}
		void WyswietlObrazy(bool CzyWszystkie){
			if (this->obraz->PobierzID() > 0){

				for (int i = 1; i < this->obraz->PobierzID(); i++)
				{
					ObjectListItems = gcnew Windows::Forms::ListViewItem(stS(this->obraz->PrzeslijNazwa(i)));
					ObjectListItems->SubItems->Add(stS(this->obraz->PrzeslijNazwisko(i)));
					ObjectListItems->SubItems->Add(stS(this->obraz->PrzeslijImie(i)));
					ObjectListItems->SubItems->Add(stS(this->obraz->PrzeslijData(i)));
					if (!CzyWszystkie){
					
					ObjectListItems->SubItems->Add(stS(this->obraz->PrzeslijStyl(i)));
					ObjectListItems->SubItems->Add(" ");
					ObjectListItems->SubItems->Add(" ");
					ObjectListItems->SubItems->Add(stS(inttostring(this->obraz->PrzeslijID(i))));

					}
					this->ObjectList->Items->Add(this->ObjectListItems);
				}
			}else if (this->obraz->PobierzID() == 0){
				ObjectListItems = gcnew Windows::Forms::ListViewItem("Brak eksponatów");
				this->ObjectList->Items->Add(this->ObjectListItems);
			}
		}
		void WyswietlPU(bool CzyWszystkie){
			if (this->puzytk->PobierzID() > 0){

				for (int i = 1; i < this->puzytk->PobierzID(); i++)
				{
					ObjectListItems = gcnew Windows::Forms::ListViewItem(stS(this->puzytk->PrzeslijNazwa(i)));
					ObjectListItems->SubItems->Add(stS(this->puzytk->PrzeslijNazwisko(i)));
					ObjectListItems->SubItems->Add(stS(this->puzytk->PrzeslijImie(i)));
					ObjectListItems->SubItems->Add(stS(this->puzytk->PrzeslijData(i)));
					if (!CzyWszystkie){
					
					ObjectListItems->SubItems->Add(stS(this->puzytk->PrzeslijGdzie(i)));
					ObjectListItems->SubItems->Add(stS(this->puzytk->PrzeslijKiedy(i)));
					ObjectListItems->SubItems->Add(" ");
					ObjectListItems->SubItems->Add(stS(inttostring(this->puzytk->PrzeslijID(i))));

					}
					this->ObjectList->Items->Add(this->ObjectListItems);
				}
			}else if (this->puzytk->PobierzID() == 0){
					
				ObjectListItems = gcnew Windows::Forms::ListViewItem("Brak eksponatów");
				this->ObjectList->Items->Add(this->ObjectListItems);
			}
		}
		void WyswietlRzezby(bool CzyWszystkie){

			if (this->rzezba->PobierzID() > 0){

				for (int i = 1; i < this->rzezba->PobierzID(); i++)
				{
					ObjectListItems = gcnew Windows::Forms::ListViewItem(stS(this->rzezba->PrzeslijNazwa(i)));
					ObjectListItems->SubItems->Add(stS(this->rzezba->PrzeslijNazwisko(i)));
					ObjectListItems->SubItems->Add(stS(this->rzezba->PrzeslijImie(i)));
					ObjectListItems->SubItems->Add(stS(this->rzezba->PrzeslijData(i)));
					if (!CzyWszystkie){

					ObjectListItems->SubItems->Add(stS(this->rzezba->PrzeslijStyl(i)));
					ObjectListItems->SubItems->Add(stS(this->rzezba->PrzeslijMaterial(i)));
					ObjectListItems->SubItems->Add(" ");
					ObjectListItems->SubItems->Add(stS(inttostring(this->rzezba->PrzeslijID(i))));

					}
					this->ObjectList->Items->Add(this->ObjectListItems);
				}
			}else if (this->rzezba->PobierzID() == 0){
			
				ObjectListItems = gcnew Windows::Forms::ListViewItem("Brak eksponatów");
				this->ObjectList->Items->Add(this->ObjectListItems);
			}
		}
		void WyswietlRIS(bool CzyWszystkie){

			if (this->rekistar->PobierzID() > 0){

				for (int i = 1; i < this->rekistar->PobierzID(); i++)
				{
					ObjectListItems = gcnew Windows::Forms::ListViewItem(stS(this->rekistar->PrzeslijNazwa(i)));
					ObjectListItems->SubItems->Add(stS(this->rekistar->PrzeslijNazwisko(i)));
					ObjectListItems->SubItems->Add(stS(this->rekistar->PrzeslijImie(i)));
					ObjectListItems->SubItems->Add(stS(this->rekistar->PrzeslijData(i)));
					if (!CzyWszystkie){

					ObjectListItems->SubItems->Add(" ");
					ObjectListItems->SubItems->Add(" ");
					ObjectListItems->SubItems->Add(" ");
					ObjectListItems->SubItems->Add(stS(inttostring(this->rekistar->PrzeslijID(i))));

					}
					this->ObjectList->Items->Add(this->ObjectListItems);
				}
			}else if (this->rekistar->PobierzID() == 0){
				ObjectListItems = gcnew Windows::Forms::ListViewItem("Brak eksponatów");
				this->ObjectList->Items->Add(this->ObjectListItems);
			}
		}
		//Funkcje odpowiadaj¹ce za w³¹czenie odpowiednich przycisków
		void WlaczPrzyciskiEdycji(bool CzyWszystkie){

			//this->EditButton->Enabled = CzyWszystkie;
			//this->UpdateButton->Enabled = CzyWszystkie;
			this->DeleteButton->Enabled = CzyWszystkie;
		}
		void WlaczPrzyciskiZapisuITworzenia(bool CzyWszystkie){
			this->AddButton->Enabled = CzyWszystkie;
			this->ClearButton->Enabled = CzyWszystkie;
			this->ReadFromFileButtonCurrent->Enabled = CzyWszystkie;
			this->SaveToFiletButtonCurrent->Enabled = CzyWszystkie;
		}
		//Funkcja odpowiadaj¹ca za ustawienie zmiennych logicznych zapisu
		void ZapisaneWszystkie(bool CzyWszystkie){
			
			bool ZapisanyMebel = CzyWszystkie;
			bool ZapisanyObraz = CzyWszystkie;
			bool ZapisanyPU = CzyWszystkie;
			bool ZapisanyR = CzyWszystkie;
			bool ZapisanyRIS = CzyWszystkie;
		}

	internal:





	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->LeftPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CollectionCB = (gcnew System::Windows::Forms::ComboBox());
			this->ObjectList = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader7 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader8 = (gcnew System::Windows::Forms::ColumnHeader());
			this->RightPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CreatDateTB = (gcnew System::Windows::Forms::TextBox());
			this->AuthorITB = (gcnew System::Windows::Forms::TextBox());
			this->AuthorNTB = (gcnew System::Windows::Forms::TextBox());
			this->ExhibitNameLabel = (gcnew System::Windows::Forms::Label());
			this->EditButton = (gcnew System::Windows::Forms::Button());
			this->AuthorNLabel = (gcnew System::Windows::Forms::Label());
			this->CreatDateLabel = (gcnew System::Windows::Forms::Label());
			this->AuthorILabel = (gcnew System::Windows::Forms::Label());
			this->UpdateButton = (gcnew System::Windows::Forms::Button());
			this->ExhibitNameTB = (gcnew System::Windows::Forms::TextBox());
			this->DeleteButton = (gcnew System::Windows::Forms::Button());
			this->ClearButton = (gcnew System::Windows::Forms::Button());
			this->AddButton = (gcnew System::Windows::Forms::Button());
			this->SaveToFiletButtonCurrent = (gcnew System::Windows::Forms::Button());
			this->ReadFromFileButtonCurrent = (gcnew System::Windows::Forms::Button());
			this->ReadFromFileButtonAll = (gcnew System::Windows::Forms::Button());
			this->SaveToFileButonAll = (gcnew System::Windows::Forms::Button());
			this->ChangeV = (gcnew System::Windows::Forms::Button());
			this->StyleLabel = (gcnew System::Windows::Forms::Label());
			this->StyleTB = (gcnew System::Windows::Forms::TextBox());
			this->WhereFoundLabel = (gcnew System::Windows::Forms::Label());
			this->WhereFoundTB = (gcnew System::Windows::Forms::TextBox());
			this->WhenFoundLabel = (gcnew System::Windows::Forms::Label());
			this->WhenFoundTB = (gcnew System::Windows::Forms::TextBox());
			this->StuffLabel = (gcnew System::Windows::Forms::Label());
			this->StuffTB = (gcnew System::Windows::Forms::TextBox());
			this->LeftPanel->SuspendLayout();
			this->RightPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// LeftPanel
			// 
			this->LeftPanel->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->LeftPanel->ColumnCount = 2;
			this->LeftPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 67.34198F)));
			this->LeftPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 32.65802F)));
			this->LeftPanel->Controls->Add(this->CollectionCB, 0, 0);
			this->LeftPanel->Controls->Add(this->ObjectList, 0, 1);
			this->LeftPanel->Controls->Add(this->RightPanel, 1, 1);
			this->LeftPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LeftPanel->Location = System::Drawing::Point(0, 0);
			this->LeftPanel->Name = L"LeftPanel";
			this->LeftPanel->RowCount = 2;
			this->LeftPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->LeftPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->LeftPanel->Size = System::Drawing::Size(1543, 518);
			this->LeftPanel->TabIndex = 0;
			// 
			// CollectionCB
			// 
			this->CollectionCB->AccessibleRole = System::Windows::Forms::AccessibleRole::MenuBar;
			this->CollectionCB->DisplayMember = L"Wyœwietl wszystkie";
			this->CollectionCB->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CollectionCB->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->CollectionCB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->CollectionCB->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Wyœwietl wszystkie", L"Meble", L"Obrazy",
					L"Przedmioty u¿ytkowe", L"RzeŸby", L"Zabytkowe rêkopisy i starodruki"
			});
			this->CollectionCB->Location = System::Drawing::Point(3, 3);
			this->CollectionCB->Name = L"CollectionCB";
			this->CollectionCB->Size = System::Drawing::Size(1033, 28);
			this->CollectionCB->TabIndex = 0;
			this->CollectionCB->SelectedIndexChanged += gcnew System::EventHandler(this, &OknoGlowne::CollectionCB_SelectedIndexChanged);
			// 
			// ObjectList
			// 
			this->ObjectList->Alignment = System::Windows::Forms::ListViewAlignment::Default;
			this->ObjectList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(8) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader3, this->columnHeader4, this->columnHeader5, this->columnHeader6, this->columnHeader7, this->columnHeader8
			});
			this->ObjectList->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ObjectList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->ObjectList->GridLines = true;
			this->ObjectList->Location = System::Drawing::Point(3, 33);
			this->ObjectList->MultiSelect = false;
			this->ObjectList->Name = L"ObjectList";
			this->ObjectList->Size = System::Drawing::Size(1033, 484);
			this->ObjectList->Sorting = System::Windows::Forms::SortOrder::Ascending;
			this->ObjectList->TabIndex = 1;
			this->ObjectList->UseCompatibleStateImageBehavior = false;
			this->ObjectList->View = System::Windows::Forms::View::Details;
			this->ObjectList->SelectedIndexChanged += gcnew System::EventHandler(this, &OknoGlowne::ObjectList_SelectedIndexChanged);
			// 
			// columnHeader1
			// 
			this->columnHeader1->DisplayIndex = 1;
			this->columnHeader1->Text = L"Nazwa eksponatu";
			this->columnHeader1->Width = 221;
			// 
			// columnHeader2
			// 
			this->columnHeader2->DisplayIndex = 2;
			this->columnHeader2->Text = L"Nazwisko autora";
			this->columnHeader2->Width = 161;
			// 
			// columnHeader3
			// 
			this->columnHeader3->DisplayIndex = 3;
			this->columnHeader3->Text = L"Imiê autora";
			this->columnHeader3->Width = 102;
			// 
			// columnHeader4
			// 
			this->columnHeader4->DisplayIndex = 4;
			this->columnHeader4->Text = L"Data powstania";
			this->columnHeader4->Width = 125;
			// 
			// columnHeader5
			// 
			this->columnHeader5->DisplayIndex = 5;
			this->columnHeader5->Text = L"Gdzie znaleziono";
			this->columnHeader5->Width = 140;
			// 
			// columnHeader6
			// 
			this->columnHeader6->DisplayIndex = 6;
			this->columnHeader6->Text = L"Kiedy znaleziono";
			this->columnHeader6->Width = 136;
			// 
			// columnHeader7
			// 
			this->columnHeader7->DisplayIndex = 7;
			this->columnHeader7->Text = L"Materia³";
			this->columnHeader7->Width = 145;
			// 
			// columnHeader8
			// 
			this->columnHeader8->DisplayIndex = 0;
			this->columnHeader8->Text = L"ID";
			this->columnHeader8->Width = 35;
			// 
			// RightPanel
			// 
			this->RightPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->RightPanel->ColumnCount = 2;
			this->RightPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 39.79849F)));
			this->RightPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 60.20151F)));
			this->RightPanel->Controls->Add(this->CreatDateTB, 1, 4);
			this->RightPanel->Controls->Add(this->AuthorITB, 1, 3);
			this->RightPanel->Controls->Add(this->AuthorNTB, 1, 2);
			this->RightPanel->Controls->Add(this->ExhibitNameLabel, 0, 1);
			this->RightPanel->Controls->Add(this->EditButton, 0, 0);
			this->RightPanel->Controls->Add(this->AuthorNLabel, 0, 2);
			this->RightPanel->Controls->Add(this->CreatDateLabel, 0, 4);
			this->RightPanel->Controls->Add(this->AuthorILabel, 0, 3);
			this->RightPanel->Controls->Add(this->UpdateButton, 0, 9);
			this->RightPanel->Controls->Add(this->ExhibitNameTB, 1, 1);
			this->RightPanel->Controls->Add(this->DeleteButton, 1, 0);
			this->RightPanel->Controls->Add(this->ClearButton, 1, 8);
			this->RightPanel->Controls->Add(this->AddButton, 0, 8);
			this->RightPanel->Controls->Add(this->SaveToFiletButtonCurrent, 1, 10);
			this->RightPanel->Controls->Add(this->ReadFromFileButtonCurrent, 0, 10);
			this->RightPanel->Controls->Add(this->ReadFromFileButtonAll, 0, 11);
			this->RightPanel->Controls->Add(this->SaveToFileButonAll, 1, 11);
			this->RightPanel->Controls->Add(this->ChangeV, 0, 12);
			this->RightPanel->Location = System::Drawing::Point(1042, 33);
			this->RightPanel->Name = L"RightPanel";
			this->RightPanel->RowCount = 14;
			this->RightPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 35)));
			this->RightPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->RightPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->RightPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->RightPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->RightPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->RightPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->RightPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->RightPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 35)));
			this->RightPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 35)));
			this->RightPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 37)));
			this->RightPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 38)));
			this->RightPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 36)));
			this->RightPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->RightPanel->Size = System::Drawing::Size(498, 484);
			this->RightPanel->TabIndex = 2;
			// 
			// CreatDateTB
			// 
			this->CreatDateTB->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CreatDateTB->Location = System::Drawing::Point(201, 128);
			this->CreatDateTB->Name = L"CreatDateTB";
			this->CreatDateTB->Size = System::Drawing::Size(294, 22);
			this->CreatDateTB->TabIndex = 9;
			// 
			// AuthorITB
			// 
			this->AuthorITB->Dock = System::Windows::Forms::DockStyle::Fill;
			this->AuthorITB->Location = System::Drawing::Point(201, 98);
			this->AuthorITB->Name = L"AuthorITB";
			this->AuthorITB->Size = System::Drawing::Size(294, 22);
			this->AuthorITB->TabIndex = 8;
			// 
			// AuthorNTB
			// 
			this->AuthorNTB->Dock = System::Windows::Forms::DockStyle::Fill;
			this->AuthorNTB->Location = System::Drawing::Point(201, 68);
			this->AuthorNTB->Name = L"AuthorNTB";
			this->AuthorNTB->Size = System::Drawing::Size(294, 22);
			this->AuthorNTB->TabIndex = 7;
			// 
			// ExhibitNameLabel
			// 
			this->ExhibitNameLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ExhibitNameLabel->AutoSize = true;
			this->ExhibitNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->ExhibitNameLabel->Location = System::Drawing::Point(3, 40);
			this->ExhibitNameLabel->Name = L"ExhibitNameLabel";
			this->ExhibitNameLabel->Size = System::Drawing::Size(141, 20);
			this->ExhibitNameLabel->TabIndex = 4;
			this->ExhibitNameLabel->Text = L"Nazwa eksponatu";
			this->ExhibitNameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// EditButton
			// 
			this->EditButton->Dock = System::Windows::Forms::DockStyle::Left;
			this->EditButton->Enabled = false;
			this->EditButton->Location = System::Drawing::Point(3, 3);
			this->EditButton->Name = L"EditButton";
			this->EditButton->Size = System::Drawing::Size(85, 29);
			this->EditButton->TabIndex = 0;
			this->EditButton->Text = L"Edytuj";
			this->EditButton->UseVisualStyleBackColor = true;
			this->EditButton->Click += gcnew System::EventHandler(this, &OknoGlowne::EditButton_Click);
			// 
			// AuthorNLabel
			// 
			this->AuthorNLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->AuthorNLabel->AutoSize = true;
			this->AuthorNLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->AuthorNLabel->Location = System::Drawing::Point(3, 70);
			this->AuthorNLabel->Name = L"AuthorNLabel";
			this->AuthorNLabel->Size = System::Drawing::Size(133, 20);
			this->AuthorNLabel->TabIndex = 3;
			this->AuthorNLabel->Text = L"Nazwisko autora";
			this->AuthorNLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// CreatDateLabel
			// 
			this->CreatDateLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CreatDateLabel->AutoSize = true;
			this->CreatDateLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->CreatDateLabel->Location = System::Drawing::Point(3, 130);
			this->CreatDateLabel->Name = L"CreatDateLabel";
			this->CreatDateLabel->Size = System::Drawing::Size(125, 20);
			this->CreatDateLabel->TabIndex = 5;
			this->CreatDateLabel->Text = L"Data powstania";
			this->CreatDateLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// AuthorILabel
			// 
			this->AuthorILabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->AuthorILabel->AutoSize = true;
			this->AuthorILabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->AuthorILabel->Location = System::Drawing::Point(3, 100);
			this->AuthorILabel->Name = L"AuthorILabel";
			this->AuthorILabel->Size = System::Drawing::Size(92, 20);
			this->AuthorILabel->TabIndex = 2;
			this->AuthorILabel->Text = L"Imiê autora";
			this->AuthorILabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// UpdateButton
			// 
			this->UpdateButton->Enabled = false;
			this->UpdateButton->Location = System::Drawing::Point(3, 283);
			this->UpdateButton->Name = L"UpdateButton";
			this->UpdateButton->Size = System::Drawing::Size(85, 29);
			this->UpdateButton->TabIndex = 10;
			this->UpdateButton->Text = L"Aktualizuj";
			this->UpdateButton->UseVisualStyleBackColor = true;
			this->UpdateButton->Click += gcnew System::EventHandler(this, &OknoGlowne::UpdateButton_Click);
			// 
			// ExhibitNameTB
			// 
			this->ExhibitNameTB->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ExhibitNameTB->Location = System::Drawing::Point(201, 38);
			this->ExhibitNameTB->Name = L"ExhibitNameTB";
			this->ExhibitNameTB->Size = System::Drawing::Size(294, 22);
			this->ExhibitNameTB->TabIndex = 6;
			// 
			// DeleteButton
			// 
			this->DeleteButton->Dock = System::Windows::Forms::DockStyle::Left;
			this->DeleteButton->Enabled = false;
			this->DeleteButton->Location = System::Drawing::Point(201, 3);
			this->DeleteButton->Name = L"DeleteButton";
			this->DeleteButton->Size = System::Drawing::Size(85, 29);
			this->DeleteButton->TabIndex = 1;
			this->DeleteButton->Text = L"Usuñ";
			this->DeleteButton->UseVisualStyleBackColor = true;
			this->DeleteButton->Click += gcnew System::EventHandler(this, &OknoGlowne::DeleteButton_Click);
			// 
			// ClearButton
			// 
			this->ClearButton->Dock = System::Windows::Forms::DockStyle::Left;
			this->ClearButton->Enabled = false;
			this->ClearButton->Location = System::Drawing::Point(201, 248);
			this->ClearButton->Name = L"ClearButton";
			this->ClearButton->Size = System::Drawing::Size(102, 29);
			this->ClearButton->TabIndex = 11;
			this->ClearButton->Text = L"Wyczyœæ pola";
			this->ClearButton->UseVisualStyleBackColor = true;
			this->ClearButton->Click += gcnew System::EventHandler(this, &OknoGlowne::ClearButton_Click);
			// 
			// AddButton
			// 
			this->AddButton->Dock = System::Windows::Forms::DockStyle::Left;
			this->AddButton->Enabled = false;
			this->AddButton->Location = System::Drawing::Point(3, 248);
			this->AddButton->Name = L"AddButton";
			this->AddButton->Size = System::Drawing::Size(85, 29);
			this->AddButton->TabIndex = 12;
			this->AddButton->Text = L"Dodaj";
			this->AddButton->UseVisualStyleBackColor = true;
			this->AddButton->Click += gcnew System::EventHandler(this, &OknoGlowne::AddButton_Click);
			// 
			// SaveToFiletButtonCurrent
			// 
			this->SaveToFiletButtonCurrent->Location = System::Drawing::Point(201, 318);
			this->SaveToFiletButtonCurrent->Name = L"SaveToFiletButtonCurrent";
			this->SaveToFiletButtonCurrent->Size = System::Drawing::Size(133, 29);
			this->SaveToFiletButtonCurrent->TabIndex = 13;
			this->SaveToFiletButtonCurrent->Text = L"Zapisz obecny";
			this->SaveToFiletButtonCurrent->UseVisualStyleBackColor = true;
			this->SaveToFiletButtonCurrent->Click += gcnew System::EventHandler(this, &OknoGlowne::SaveToFiletButtonCurrent_Click);
			// 
			// ReadFromFileButtonCurrent
			// 
			this->ReadFromFileButtonCurrent->Location = System::Drawing::Point(3, 318);
			this->ReadFromFileButtonCurrent->Name = L"ReadFromFileButtonCurrent";
			this->ReadFromFileButtonCurrent->Size = System::Drawing::Size(133, 29);
			this->ReadFromFileButtonCurrent->TabIndex = 14;
			this->ReadFromFileButtonCurrent->Text = L"Wczytaj obecny";
			this->ReadFromFileButtonCurrent->UseVisualStyleBackColor = true;
			this->ReadFromFileButtonCurrent->Click += gcnew System::EventHandler(this, &OknoGlowne::ReadFromFileButtonCurrent_Click);
			// 
			// ReadFromFileButtonAll
			// 
			this->ReadFromFileButtonAll->Location = System::Drawing::Point(3, 355);
			this->ReadFromFileButtonAll->Name = L"ReadFromFileButtonAll";
			this->ReadFromFileButtonAll->Size = System::Drawing::Size(133, 29);
			this->ReadFromFileButtonAll->TabIndex = 16;
			this->ReadFromFileButtonAll->Text = L"Wczytaj wszystkie";
			this->ReadFromFileButtonAll->UseVisualStyleBackColor = true;
			this->ReadFromFileButtonAll->Click += gcnew System::EventHandler(this, &OknoGlowne::ReadFromFileButtonAll_Click);
			// 
			// SaveToFileButonAll
			// 
			this->SaveToFileButonAll->Location = System::Drawing::Point(201, 355);
			this->SaveToFileButonAll->Name = L"SaveToFileButonAll";
			this->SaveToFileButonAll->Size = System::Drawing::Size(133, 29);
			this->SaveToFileButonAll->TabIndex = 17;
			this->SaveToFileButonAll->Text = L"Zapisz wszystkie";
			this->SaveToFileButonAll->UseVisualStyleBackColor = true;
			this->SaveToFileButonAll->Click += gcnew System::EventHandler(this, &OknoGlowne::SaveToFileButonAll_Click);
			// 
			// ChangeV
			// 
			this->ChangeV->Location = System::Drawing::Point(3, 393);
			this->ChangeV->Name = L"ChangeV";
			this->ChangeV->Size = System::Drawing::Size(106, 29);
			this->ChangeV->TabIndex = 15;
			this->ChangeV->Text = L"Zmien widok";
			this->ChangeV->UseVisualStyleBackColor = true;
			this->ChangeV->Click += gcnew System::EventHandler(this, &OknoGlowne::ChangeV_Click);
			// 
			// StyleLabel
			// 
			this->StyleLabel->Location = System::Drawing::Point(0, 0);
			this->StyleLabel->Name = L"StyleLabel";
			this->StyleLabel->Size = System::Drawing::Size(0, 20);
			this->StyleLabel->TabIndex = 0;
			// 
			// StyleTB
			// 
			this->StyleTB->Location = System::Drawing::Point(0, 0);
			this->StyleTB->Name = L"StyleTB";
			this->StyleTB->Size = System::Drawing::Size(234, 22);
			this->StyleTB->TabIndex = 0;
			// 
			// WhereFoundLabel
			// 
			this->WhereFoundLabel->Location = System::Drawing::Point(0, 0);
			this->WhereFoundLabel->Name = L"WhereFoundLabel";
			this->WhereFoundLabel->Size = System::Drawing::Size(0, 20);
			this->WhereFoundLabel->TabIndex = 0;
			// 
			// WhereFoundTB
			// 
			this->WhereFoundTB->Location = System::Drawing::Point(0, 0);
			this->WhereFoundTB->Name = L"WhereFoundTB";
			this->WhereFoundTB->Size = System::Drawing::Size(234, 22);
			this->WhereFoundTB->TabIndex = 0;
			// 
			// WhenFoundLabel
			// 
			this->WhenFoundLabel->Location = System::Drawing::Point(0, 0);
			this->WhenFoundLabel->Name = L"WhenFoundLabel";
			this->WhenFoundLabel->Size = System::Drawing::Size(0, 20);
			this->WhenFoundLabel->TabIndex = 0;
			// 
			// WhenFoundTB
			// 
			this->WhenFoundTB->Location = System::Drawing::Point(0, 0);
			this->WhenFoundTB->Name = L"WhenFoundTB";
			this->WhenFoundTB->Size = System::Drawing::Size(234, 22);
			this->WhenFoundTB->TabIndex = 0;
			// 
			// StuffLabel
			// 
			this->StuffLabel->Location = System::Drawing::Point(0, 0);
			this->StuffLabel->Name = L"StuffLabel";
			this->StuffLabel->Size = System::Drawing::Size(0, 20);
			this->StuffLabel->TabIndex = 0;
			// 
			// StuffTB
			// 
			this->StuffTB->Location = System::Drawing::Point(0, 0);
			this->StuffTB->Name = L"StuffTB";
			this->StuffTB->Size = System::Drawing::Size(234, 22);
			this->StuffTB->TabIndex = 0;
			// 
			// OknoGlowne
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1543, 518);
			this->Controls->Add(this->LeftPanel);
			this->Location = System::Drawing::Point(3, 283);
			this->Name = L"OknoGlowne";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Muzeum";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &OknoGlowne::OknoGlowne_FormClosing);
			this->Load += gcnew System::EventHandler(this, &OknoGlowne::OknoGlowne_Load);
			this->LeftPanel->ResumeLayout(false);
			this->RightPanel->ResumeLayout(false);
			this->RightPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void OknoGlowne_Load(System::Object^  sender, System::EventArgs^  e) {

	mebel = new Meble(0,"default", "default", "default", "default", "default", "default", "default");
	obraz = new Obrazy(0,"default", "default", "default", "default", "default");
	puzytk = new PrzedmiotyUzytkowe(0,"default", "default", "default", "default", "default", "default");
	rzezba = new Rzezby(0,"default", "default", "default", "default", "default", "default");
	rekistar = new RekopisyIStarodruki(0,"default", "default", "default", "default");

}
private: System::Void CollectionCB_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	//
	//Usuñ wszystkie dodatkowe kontrolki
	//
	DeleteNotUsedControls();
	this->ObjectList->Items->Clear();
	//	
	//wyœwietl wszystkie
	//
	if (CollectionCB->SelectedIndex == 0){
		//Program najpierw 'usuwa' niepotrzebne kolumny z listview, nastêpnie w³¹cza i wy³¹cza dostepnoœc odpowiednich przycisków
		this->columnHeader5->Text = L" ";
		this->columnHeader6->Text = L" ";
		this->columnHeader7->Text = L" ";
		
		this->UpdateButton->Enabled = false;
		this->WlaczPrzyciskiEdycji(false);
		this->WlaczPrzyciskiZapisuITworzenia(false);
		this->WyswietlWszystkie();
		
	}
	//
	//Meble
	//
	else if(CollectionCB->SelectedIndex == 1){
		//W ka¿dym wrunku analogicznie jak w tym: utworzenie doatkowych pol na dane
		this->WhereFoundLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
		this->WhereFoundLabel->AutoSize = true;
		this->WhereFoundLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->WhereFoundLabel->Location = System::Drawing::Point(3, 160);
		this->WhereFoundLabel->TabIndex = 13;
		this->WhereFoundLabel->Text = L"Gdzie znaleziono";
		this->WhereFoundLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		this->RightPanel->Controls->Add(this->WhereFoundLabel, 0, 5);

		this->WhereFoundTB->Dock = System::Windows::Forms::DockStyle::Fill;
		this->WhereFoundTB->Location = System::Drawing::Point(160, 158);
		this->WhereFoundTB->TabIndex = 14;
		this->RightPanel->Controls->Add(this->WhereFoundTB, 1, 5);
		

		this->WhenFoundLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
		this->WhenFoundLabel->AutoSize = true;
		this->WhenFoundLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->WhenFoundLabel->Location = System::Drawing::Point(3, 190);
		this->WhenFoundLabel->TabIndex = 15;
		this->WhenFoundLabel->Text = L"Kiedy znaleziono";
		this->WhenFoundLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		this->RightPanel->Controls->Add(this->WhenFoundLabel, 0, 6);

		this->WhenFoundTB->Dock = System::Windows::Forms::DockStyle::Fill;
		this->WhenFoundTB->Location = System::Drawing::Point(160, 188);
		this->WhenFoundTB->TabIndex = 16;
		this->RightPanel->Controls->Add(this->WhenFoundTB, 1, 6);


		this->StuffLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
		this->StuffLabel->AutoSize = true;
		this->StuffLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->StuffLabel->Location = System::Drawing::Point(3, 220);
		this->StuffLabel->TabIndex = 17;
		this->StuffLabel->Text = L"Materia³";
		this->StuffLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		this->RightPanel->Controls->Add(this->StuffLabel, 0, 7);

		this->StuffTB->Dock = System::Windows::Forms::DockStyle::Fill;
		this->StuffTB->Location = System::Drawing::Point(160, 218);
		this->StuffTB->TabIndex = 18;
		this->RightPanel->Controls->Add(this->StuffTB, 1, 7);
		//Nastêpnie dodanie odpowiednich kolumn w listviewiw
		this->columnHeader5->Text = L"Gdzie znaleziono";
		this->columnHeader6->Text = L"Kiedy znaleziono";
		this->columnHeader7->Text = L"Materia³";
		//I kolejno w³¹cza odpowiendie przyciski, gdy brak obiektów w pamiêci, program pozostawia przyciski edycji wy³¹czone
		this->UpdateButton->Enabled = false;
		this->WlaczPrzyciskiZapisuITworzenia(true);
		this->WyswietlMeble(false);
		if (this->ObjectList->Items->Count > 0){
			this->WlaczPrzyciskiEdycji(true);
		}
		else
		{
			this->WlaczPrzyciskiEdycji(false);
		}

	}
	//
	//Obrazy
	//
	else if (CollectionCB->SelectedIndex == 2){

		this->StyleLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
		this->StyleLabel->AutoSize = true;
		this->StyleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->StyleLabel->Location = System::Drawing::Point(3, 160);
		this->StyleLabel->TabIndex = 13;
		this->StyleLabel->Text = L"Styl wykonania";
		this->StyleLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		this->RightPanel->Controls->Add(this->StyleLabel, 0, 5);
		
		this->StyleTB->Dock = System::Windows::Forms::DockStyle::Fill;
		this->StyleTB->Location = System::Drawing::Point(160, 158);
		this->StyleTB->TabIndex = 14;
		this->RightPanel->Controls->Add(this->StyleTB, 1, 5);

		this->columnHeader5->Text = L"Styl wykonania";
		this->columnHeader6->Text = L" ";
		this->columnHeader7->Text = L" ";
		
		this->UpdateButton->Enabled = false;
		this->WlaczPrzyciskiZapisuITworzenia(true);
		this->WyswietlObrazy(false);
		if (this->ObjectList->Items->Count > 0){
			this->WlaczPrzyciskiEdycji(true);
		}
		else
		{
			this->WlaczPrzyciskiEdycji(false);
		}

	}
	//
	//Przedmioty u¿ytkowe
	//
	else if(CollectionCB->SelectedIndex == 3){

		this->WhereFoundLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
		this->WhereFoundLabel->AutoSize = true;
		this->WhereFoundLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->WhereFoundLabel->Location = System::Drawing::Point(3, 160);
		this->WhereFoundLabel->TabIndex = 13;
		this->WhereFoundLabel->Text = L"Gdzie znaleziono";
		this->WhereFoundLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		this->RightPanel->Controls->Add(this->WhereFoundLabel, 0, 5);

		this->WhereFoundTB->Dock = System::Windows::Forms::DockStyle::Fill;
		this->WhereFoundTB->Location = System::Drawing::Point(160, 158);
		this->WhereFoundTB->TabIndex = 14;
		this->RightPanel->Controls->Add(this->WhereFoundTB, 1, 5);


		this->WhenFoundLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
		this->WhenFoundLabel->AutoSize = true;
		this->WhenFoundLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->WhenFoundLabel->Location = System::Drawing::Point(3, 190);
		this->WhenFoundLabel->TabIndex = 15;
		this->WhenFoundLabel->Text = L"Kiedy znaleziono";
		this->WhenFoundLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		this->RightPanel->Controls->Add(this->WhenFoundLabel, 0, 6);

		this->WhenFoundTB->Dock = System::Windows::Forms::DockStyle::Fill;
		this->WhenFoundTB->Location = System::Drawing::Point(160, 188);
		this->WhenFoundTB->TabIndex = 16;
		this->RightPanel->Controls->Add(this->WhenFoundTB, 1, 6);

		this->columnHeader5->Text = L"Gdzie znaleziono";
		this->columnHeader6->Text = L"Kiedy znaleziono";
		this->columnHeader7->Text = L" ";

		this->UpdateButton->Enabled = false;
		this->WlaczPrzyciskiZapisuITworzenia(true);
		this->WyswietlPU(false);
		if (this->ObjectList->Items->Count > 0){
			this->WlaczPrzyciskiEdycji(true);
		}
		else
		{
			this->WlaczPrzyciskiEdycji(false);
		}

	}
	//
	//RzeŸby
	//
	else if(CollectionCB->SelectedIndex == 4){

		this->UpdateButton->Enabled = false;
		this->StyleLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
		this->StyleLabel->AutoSize = true;
		this->StyleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->StyleLabel->Location = System::Drawing::Point(3, 160);
		this->StyleLabel->TabIndex = 13;
		this->StyleLabel->Text = L"Styl wykonania";
		this->StyleLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		this->RightPanel->Controls->Add(this->StyleLabel, 0, 5);

		this->StyleTB->Dock = System::Windows::Forms::DockStyle::Fill;
		this->StyleTB->Location = System::Drawing::Point(160, 158);
		this->StyleTB->TabIndex = 14;
		this->RightPanel->Controls->Add(this->StyleTB, 1, 5);
		

		this->StuffLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
		this->StuffLabel->AutoSize = true;
		this->StuffLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->StuffLabel->Location = System::Drawing::Point(3, 190);
		this->StuffLabel->TabIndex = 15;
		this->StuffLabel->Text = L"Materia³";
		this->StuffLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		this->RightPanel->Controls->Add(this->StuffLabel, 0, 6);

		this->StuffTB->Dock = System::Windows::Forms::DockStyle::Fill;
		this->StuffTB->Location = System::Drawing::Point(160, 188);
		this->StuffTB->TabIndex = 16;
		this->RightPanel->Controls->Add(this->StuffTB, 1, 6);

		this->columnHeader5->Text = L"Styl wykonania";
		this->columnHeader6->Text = L"Materia³";
		this->columnHeader7->Text = L" ";
		
		this->UpdateButton->Enabled = false;
		this->WlaczPrzyciskiZapisuITworzenia(true);
		this->WyswietlRzezby(false);
		if (this->ObjectList->Items->Count > 0){
			this->WlaczPrzyciskiEdycji(true);
		}
		else
		{
			this->WlaczPrzyciskiEdycji(false);
		}
	}
	//
	//Zabytkowe rêkopisy i starodruki
	//
	else if(CollectionCB->SelectedIndex == 5){

		this->columnHeader5->Text = L" ";
		this->columnHeader6->Text = L" ";
		this->columnHeader7->Text = L" ";
		
		this->UpdateButton->Enabled = false;
		this->WlaczPrzyciskiZapisuITworzenia(true);
		this->WyswietlRIS(false);
		if (this->ObjectList->Items->Count > 0){
			this->WlaczPrzyciskiEdycji(true);
		}
		else
		{
			this->WlaczPrzyciskiEdycji(false);
		}
	}
}
private: System::Void ClearButton_Click(System::Object^  sender, System::EventArgs^  e) {
	//Funkcja odpowiadaj¹ca za wyczyszczenie wszystkich textboxów
	if (StyleTB) this->StyleTB->Text = "";
	if (ExhibitNameTB) this->ExhibitNameTB->Text = "";
	if (AuthorITB) this->AuthorITB->Text = "";
	if (AuthorNTB) this->AuthorNTB->Text = "";
	if (CreatDateTB) this->CreatDateTB->Text = "";
	if (WhenFoundTB) this->WhenFoundTB->Text = "";
	if (WhereFoundTB) this->WhereFoundTB->Text = "";
	if (StuffTB) this->StuffTB->Text = "";
}
private: System::Void AddButton_Click(System::Object^  sender, System::EventArgs^  e) {
	//Funkcja odpowiadaj¹ca za dodanie eksponatu do kolekcji, wszystko w niej jest robione analogicznie do "Meble"
	 if (this->CollectionCB->SelectedIndex > 0){
		 this->Zapisany = false;
		//
		//Meble
		//
		if (this->CollectionCB->SelectedIndex == 1){
			//Nastepuje edycja kolekcji, wiêc odpowiednia zmienna logiczna zostaje ustawiona na false
			this->ZapisanyMebel = false;
			//Dodanie obiektu do listview
			ObjectListItems = gcnew Windows::Forms::ListViewItem(this->ExhibitNameTB->Text);
			ObjectListItems->SubItems->Add(this->AuthorNTB->Text);
			ObjectListItems->SubItems->Add(this->AuthorITB->Text);
			ObjectListItems->SubItems->Add(this->CreatDateTB->Text);
			ObjectListItems->SubItems->Add(this->WhereFoundTB->Text);
			ObjectListItems->SubItems->Add(this->WhenFoundTB->Text);
			ObjectListItems->SubItems->Add(this->StuffTB->Text);
			ObjectListItems->SubItems->Add(stS(inttostring(mebel->PobierzID())));
			this->ObjectList->Items->Add(this->ObjectListItems);
			//Dodanie eksponatu do struktury dynamicznej->vectora
			mebel->DodajEksponat(Sts(this->ExhibitNameTB->Text), Sts(this->AuthorNTB->Text),
				Sts(this->AuthorITB->Text), Sts(this->CreatDateTB->Text),
				Sts(this->WhereFoundTB->Text), Sts(this->WhenFoundTB->Text), " ", Sts(this->StuffTB->Text));
		}
		//
		//Obrazy
		//
		else if (this->CollectionCB->SelectedIndex == 2){

			this->ZapisanyObraz = false;

			ObjectListItems = gcnew Windows::Forms::ListViewItem(this->ExhibitNameTB->Text);
			ObjectListItems->SubItems->Add(this->AuthorNTB->Text);
			ObjectListItems->SubItems->Add(this->AuthorITB->Text);
			ObjectListItems->SubItems->Add(this->CreatDateTB->Text);
			ObjectListItems->SubItems->Add(this->StyleTB->Text);
			ObjectListItems->SubItems->Add("");
			ObjectListItems->SubItems->Add("");
			ObjectListItems->SubItems->Add(stS(inttostring(obraz->PobierzID())));
			this->ObjectList->Items->Add(this->ObjectListItems);
			
			obraz->DodajEksponat(Sts(this->ExhibitNameTB->Text), Sts(this->AuthorNTB->Text),
				Sts(this->AuthorITB->Text), Sts(this->CreatDateTB->Text),
				" ", " ", Sts(this->StyleTB->Text), " ");
		}
		//
		//Przedmioty u¿ytkowe
		//
		else if (this->CollectionCB->SelectedIndex == 3){

			this->ZapisanyPU = false;

			ObjectListItems = gcnew Windows::Forms::ListViewItem(this->ExhibitNameTB->Text);
			ObjectListItems->SubItems->Add(this->AuthorNTB->Text);
			ObjectListItems->SubItems->Add(this->AuthorITB->Text);
			ObjectListItems->SubItems->Add(this->CreatDateTB->Text);
			ObjectListItems->SubItems->Add(this->WhereFoundTB->Text);
			ObjectListItems->SubItems->Add(this->WhenFoundTB->Text);
			ObjectListItems->SubItems->Add("");
			ObjectListItems->SubItems->Add(stS(inttostring(puzytk->PobierzID())));
			this->ObjectList->Items->Add(this->ObjectListItems);

			puzytk->DodajEksponat(Sts(this->ExhibitNameTB->Text), Sts(this->AuthorNTB->Text),
				Sts(this->AuthorITB->Text), Sts(this->CreatDateTB->Text),
				Sts(this->WhereFoundTB->Text), Sts(this->WhenFoundTB->Text), " ", " ");
		}
		//
		//RzeŸby
		//
		else if (this->CollectionCB->SelectedIndex == 4){

			this->ZapisanyR = false;

			ObjectListItems = gcnew Windows::Forms::ListViewItem(this->ExhibitNameTB->Text);
			ObjectListItems->SubItems->Add(this->AuthorNTB->Text);
			ObjectListItems->SubItems->Add(this->AuthorITB->Text);
			ObjectListItems->SubItems->Add(this->CreatDateTB->Text);
			ObjectListItems->SubItems->Add(this->StyleTB->Text);
			ObjectListItems->SubItems->Add(this->StuffTB->Text);
			ObjectListItems->SubItems->Add("");
			ObjectListItems->SubItems->Add(stS(inttostring(rzezba->PobierzID())));
			this->ObjectList->Items->Add(this->ObjectListItems);

			rzezba->DodajEksponat(Sts(this->ExhibitNameTB->Text), Sts(this->AuthorNTB->Text),
				Sts(this->AuthorITB->Text), Sts(this->CreatDateTB->Text),
				" ", " ", Sts(this->StyleTB->Text), Sts(this->StuffTB->Text));
		}
		//
		//Zabytkowe rêkopisy i starodruki
		//
		else if (this->CollectionCB->SelectedIndex == 5){

			this->ZapisanyRIS = false;

			ObjectListItems = gcnew Windows::Forms::ListViewItem(this->ExhibitNameTB->Text);
			ObjectListItems->SubItems->Add(this->AuthorNTB->Text);
			ObjectListItems->SubItems->Add(this->AuthorITB->Text);
			ObjectListItems->SubItems->Add(this->CreatDateTB->Text);
			ObjectListItems->SubItems->Add("");
			ObjectListItems->SubItems->Add("");
			ObjectListItems->SubItems->Add("");
			ObjectListItems->SubItems->Add(stS(inttostring(rekistar->PobierzID())));
			this->ObjectList->Items->Add(this->ObjectListItems);

			rekistar->DodajEksponat(Sts(this->ExhibitNameTB->Text), Sts(this->AuthorNTB->Text),
				Sts(this->AuthorITB->Text), Sts(this->CreatDateTB->Text),
				" ", " ", " ", " ");
		}
		//W³aczenie odpowiednich przycisków edycji	
		this->WlaczPrzyciskiEdycji(true);
	}
}
private: System::Void DeleteButton_Click(System::Object^  sender, System::EventArgs^  e) {
	//Funkcja odpowiadaj¹ca za usuwanie eksponatów

	if (MessageBox::Show("Czy na pewno chcesz usun¹c wybrany element?", "Usuñ",
		MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes){

		//Zmienia wartoœæ odpowiedniej zmiennej logicznej dotycz¹cej zapisu, analogicznie
		this->Zapisany = false;
		if (this->CollectionCB->SelectedIndex == 1){
			//Wywo³uje odpowiedni¹ mrtode z klasy "Meble", która usuwa element z vectora
			mebel->UsunEksponat(stringtoint(Sts(ObjectList->SelectedItems[0]->SubItems[7]->Text)));
			this->ZapisanyMebel = false;
			this->ObjectList->Items->Clear();
			this->WyswietlMeble(false);

		}else if (this->CollectionCB->SelectedIndex == 2){

			obraz->UsunEksponat(stringtoint(Sts(ObjectList->SelectedItems[0]->SubItems[7]->Text)));
			this->ZapisanyObraz = false;
			this->ObjectList->Items->Clear();
			this->WyswietlObrazy(false);

		}else if(this->CollectionCB->SelectedIndex == 3){

			puzytk->UsunEksponat(stringtoint(Sts(ObjectList->SelectedItems[0]->SubItems[7]->Text)));
			this->ZapisanyPU = false;
			this->ObjectList->Items->Clear();
			this->WyswietlPU(false);

		}else if(this->CollectionCB->SelectedIndex == 4){

			rzezba->UsunEksponat(stringtoint(Sts(ObjectList->SelectedItems[0]->SubItems[7]->Text)));
			this->ZapisanyR = false;
			this->ObjectList->Items->Clear();
			this->WyswietlRzezby(false);

		}else if(this->CollectionCB->SelectedIndex == 5){

			rekistar->UsunEksponat(stringtoint(Sts(ObjectList->SelectedItems[0]->SubItems[7]->Text)));
			this->ZapisanyRIS = false;
			this->ObjectList->Items->Clear();
			this->WyswietlRIS(false);

		}
		
	}
	else {
		return;
	}
	//Kiedy listview nie zawiera ¿adnych itemów, czyt. eksponatów, przyciski edycji zostaj¹ wy³¹czone
	if (ObjectList->Items->Count == 0){
		this->WlaczPrzyciskiEdycji(false);
	}
	
}
private: System::Void EditButton_Click(System::Object^  sender, System::EventArgs^  e) {
	//Funkcja przekazuje atrybuty wybranego do odpowiednich pó³-textboxów
	
	
	if (this->CollectionCB->SelectedIndex == 1){

		if (ExhibitNameTB){
			this->ExhibitNameTB->Text = "";
			this->ExhibitNameTB->Text = ObjectList->SelectedItems[0]->SubItems[0]->Text;
		}
		if (AuthorNTB){
			this->AuthorNTB->Text = "";
			this->AuthorNTB->Text = ObjectList->SelectedItems[0]->SubItems[1]->Text;
		}
		if (AuthorITB){
			this->AuthorITB->Text = "";
			this->AuthorITB->Text = ObjectList->SelectedItems[0]->SubItems[2]->Text;
		}
		if (CreatDateTB){
			this->CreatDateTB->Text = "";
			this->CreatDateTB->Text = ObjectList->SelectedItems[0]->SubItems[3]->Text;
		}
		if (WhereFoundTB){
			this->WhereFoundTB->Text = "";
			this->WhereFoundTB->Text = ObjectList->SelectedItems[0]->SubItems[4]->Text;
		}
		if (WhenFoundTB){
			this->WhenFoundTB->Text = "";
			this->WhenFoundTB->Text = ObjectList->SelectedItems[0]->SubItems[5]->Text;
		}
		if (StuffTB){
			this->StuffTB->Text = "";
			this->StuffTB->Text = ObjectList->SelectedItems[0]->SubItems[6]->Text;
		}
	}
	else if (this->CollectionCB->SelectedIndex == 2){

		if (ExhibitNameTB){
			this->ExhibitNameTB->Text = "";
			this->ExhibitNameTB->Text = ObjectList->SelectedItems[0]->SubItems[0]->Text;
		}
		if (AuthorNTB){
			this->AuthorNTB->Text = "";
			this->AuthorNTB->Text = ObjectList->SelectedItems[0]->SubItems[1]->Text;
		}
		if (AuthorITB){
			this->AuthorITB->Text = "";
			this->AuthorITB->Text = ObjectList->SelectedItems[0]->SubItems[2]->Text;
		}
		if (CreatDateTB){
			this->CreatDateTB->Text = "";
			this->CreatDateTB->Text = ObjectList->SelectedItems[0]->SubItems[3]->Text;
		}
		if (StyleTB){
			this->StyleTB->Text = "";
			this->StyleTB->Text = ObjectList->SelectedItems[0]->SubItems[4]->Text;
		}

	}
	else if (this->CollectionCB->SelectedIndex == 3){

		if (ExhibitNameTB){
			this->ExhibitNameTB->Text = "";
			this->ExhibitNameTB->Text = ObjectList->SelectedItems[0]->SubItems[0]->Text;
		}
		if (AuthorNTB){
			this->AuthorNTB->Text = "";
			this->AuthorNTB->Text = ObjectList->SelectedItems[0]->SubItems[1]->Text;
		}
		if (AuthorITB){
			this->AuthorITB->Text = "";
			this->AuthorITB->Text = ObjectList->SelectedItems[0]->SubItems[2]->Text;
		}
		if (CreatDateTB){
			this->CreatDateTB->Text = "";
			this->CreatDateTB->Text = ObjectList->SelectedItems[0]->SubItems[3]->Text;
		}
		if (WhereFoundTB){
			this->WhereFoundTB->Text = "";
			this->WhereFoundTB->Text = ObjectList->SelectedItems[0]->SubItems[4]->Text;
		}
		if (WhenFoundTB){
			this->WhenFoundTB->Text = "";
			this->WhenFoundTB->Text = ObjectList->SelectedItems[0]->SubItems[5]->Text;
		}

	}
	else if (this->CollectionCB->SelectedIndex == 4){

		if (ExhibitNameTB){
			this->ExhibitNameTB->Text = "";
			this->ExhibitNameTB->Text = ObjectList->SelectedItems[0]->SubItems[0]->Text;
		}
		if (AuthorNTB){
			this->AuthorNTB->Text = "";
			this->AuthorNTB->Text = ObjectList->SelectedItems[0]->SubItems[1]->Text;
		}
		if (AuthorITB){
			this->AuthorITB->Text = "";
			this->AuthorITB->Text = ObjectList->SelectedItems[0]->SubItems[2]->Text;
		}
		if (CreatDateTB){
			this->CreatDateTB->Text = "";
			this->CreatDateTB->Text = ObjectList->SelectedItems[0]->SubItems[3]->Text;
		}
		if (StyleTB){
			this->StyleTB->Text = "";
			this->StyleTB->Text = ObjectList->SelectedItems[0]->SubItems[4]->Text;
		}
		if (StuffTB){
			this->StuffTB->Text = "";
			this->StuffTB->Text = ObjectList->SelectedItems[0]->SubItems[5]->Text;
		}

	}
	else if (this->CollectionCB->SelectedIndex == 5){

		if (ExhibitNameTB){
			this->ExhibitNameTB->Text = "";
			this->ExhibitNameTB->Text = ObjectList->SelectedItems[0]->SubItems[0]->Text;
		}
		if (AuthorNTB){
			this->AuthorNTB->Text = "";
			this->AuthorNTB->Text = ObjectList->SelectedItems[0]->SubItems[1]->Text;
		}
		if (AuthorITB){
			this->AuthorITB->Text = "";
			this->AuthorITB->Text = ObjectList->SelectedItems[0]->SubItems[2]->Text;
		}
		if (CreatDateTB){
			this->CreatDateTB->Text = "";
			this->CreatDateTB->Text = ObjectList->SelectedItems[0]->SubItems[3]->Text;
		}
	}
	this->UpdateButton->Enabled = true;
	

}
private: System::Void UpdateButton_Click(System::Object^  sender, System::EventArgs^  e) {
	//funkcja odpowiada za aktualizacjê eksponatu, analogicznie
	this->Zapisany = false;

	if (this->CollectionCB->SelectedIndex == 1){

		this->ZapisanyMebel = false;
		//Zamiana odpowiednich wartoœci w listviewie na nowe
		ObjectList->SelectedItems[0]->SubItems[0]->Text = this->ExhibitNameTB->Text;
		ObjectList->SelectedItems[0]->SubItems[1]->Text = this->AuthorNTB->Text;
		ObjectList->SelectedItems[0]->SubItems[2]->Text = this->AuthorITB->Text;
		ObjectList->SelectedItems[0]->SubItems[3]->Text = this->CreatDateTB->Text;
		ObjectList->SelectedItems[0]->SubItems[4]->Text = this->WhereFoundTB->Text;
		ObjectList->SelectedItems[0]->SubItems[5]->Text = this->WhenFoundTB->Text;
		ObjectList->SelectedItems[0]->SubItems[6]->Text = this->StuffTB->Text;
		ObjectList->Update();
	
		//Aktualizacja odpowiedniej pozycji w vectorze
		mebel->AktualizujEksponat(stringtoint(Sts(ObjectList->SelectedItems[0]->SubItems[7]->Text)), Sts(this->ExhibitNameTB->Text), Sts(this->AuthorNTB->Text),
			Sts(this->AuthorITB->Text), Sts(this->CreatDateTB->Text),
			Sts(this->WhereFoundTB->Text), Sts(this->WhenFoundTB->Text), " ", Sts(this->StuffTB->Text));


	}
	else if (this->CollectionCB->SelectedIndex == 2){

		this->ZapisanyObraz = false;

		ObjectList->SelectedItems[0]->SubItems[0]->Text = this->ExhibitNameTB->Text;
		ObjectList->SelectedItems[0]->SubItems[1]->Text = this->AuthorNTB->Text;
		ObjectList->SelectedItems[0]->SubItems[2]->Text = this->AuthorITB->Text;
		ObjectList->SelectedItems[0]->SubItems[3]->Text = this->CreatDateTB->Text;
		ObjectList->SelectedItems[0]->SubItems[4]->Text = this->StyleTB->Text;
		ObjectList->Update();

		obraz->AktualizujEksponat(stringtoint(Sts(ObjectList->SelectedItems[0]->SubItems[7]->Text)), Sts(this->ExhibitNameTB->Text), Sts(this->AuthorNTB->Text),
			Sts(this->AuthorITB->Text), Sts(this->CreatDateTB->Text),
			" ", " ", Sts(this->StyleTB->Text), " ");


	}if (this->CollectionCB->SelectedIndex == 3){

		this->ZapisanyPU = false;

		ObjectList->SelectedItems[0]->SubItems[0]->Text = this->ExhibitNameTB->Text;
		ObjectList->SelectedItems[0]->SubItems[1]->Text = this->AuthorNTB->Text;
		ObjectList->SelectedItems[0]->SubItems[2]->Text = this->AuthorITB->Text;
		ObjectList->SelectedItems[0]->SubItems[3]->Text = this->CreatDateTB->Text;
		ObjectList->SelectedItems[0]->SubItems[4]->Text = this->WhereFoundTB->Text;
		ObjectList->SelectedItems[0]->SubItems[5]->Text = this->WhenFoundTB->Text;

		ObjectList->Update();

		puzytk->AktualizujEksponat(stringtoint(Sts(ObjectList->SelectedItems[0]->SubItems[7]->Text)), Sts(this->ExhibitNameTB->Text), Sts(this->AuthorNTB->Text),
			Sts(this->AuthorITB->Text), Sts(this->CreatDateTB->Text),
			Sts(this->WhereFoundTB->Text), Sts(this->WhenFoundTB->Text), " ", " ");


	}if (this->CollectionCB->SelectedIndex == 4){

		this->ZapisanyR = false;

		ObjectList->SelectedItems[0]->SubItems[0]->Text = this->ExhibitNameTB->Text;
		ObjectList->SelectedItems[0]->SubItems[1]->Text = this->AuthorNTB->Text;
		ObjectList->SelectedItems[0]->SubItems[2]->Text = this->AuthorITB->Text;
		ObjectList->SelectedItems[0]->SubItems[3]->Text = this->CreatDateTB->Text;
		ObjectList->SelectedItems[0]->SubItems[4]->Text = this->StyleTB->Text;
		ObjectList->SelectedItems[0]->SubItems[5]->Text = this->StuffTB->Text;

		ObjectList->Update();

		rzezba->AktualizujEksponat(stringtoint(Sts(ObjectList->SelectedItems[0]->SubItems[7]->Text)), Sts(this->ExhibitNameTB->Text), Sts(this->AuthorNTB->Text),
			Sts(this->AuthorITB->Text), Sts(this->CreatDateTB->Text),
			" ", " ", Sts(this->StyleTB->Text), Sts(this->StuffTB->Text));


	}if (this->CollectionCB->SelectedIndex == 5){

		this->ZapisanyRIS = false;

		ObjectList->SelectedItems[0]->SubItems[0]->Text = this->ExhibitNameTB->Text;
		ObjectList->SelectedItems[0]->SubItems[1]->Text = this->AuthorNTB->Text;
		ObjectList->SelectedItems[0]->SubItems[2]->Text = this->AuthorITB->Text;
		ObjectList->SelectedItems[0]->SubItems[3]->Text = this->CreatDateTB->Text;

		ObjectList->Update();

		rekistar->AktualizujEksponat(stringtoint(Sts(ObjectList->SelectedItems[0]->SubItems[7]->Text)), Sts(this->ExhibitNameTB->Text), Sts(this->AuthorNTB->Text),
			Sts(this->AuthorITB->Text), Sts(this->CreatDateTB->Text),
			" ", " ", " ", " ");
	}
	this->EditButton->Enabled = false;
}
private: System::Void OknoGlowne_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	//Funkcja obs³uguj¹ca zdarzenie wyjœcia z programu, nie pozwala na utracenie nowych, b¹dŸ edytownych danych
	 if ((Zapisany) || (MessageBox::Show("Czy na pewno wyjœæ z programu? Pamietaj, ¿e wszystkie niezapisane dane zostan¹ utracone. ", "Wyjœcie",
		 MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)){
		//Wyjœcie z programu
		 
		 mebel->~Meble();
		 delete mebel;
		 obraz->~Obrazy();
		 delete obraz;
		 puzytk->~PrzedmiotyUzytkowe();
		 delete puzytk;
		 rzezba->~Rzezby();
		 delete rzezba;
		 rekistar->~RekopisyIStarodruki();
		 delete rekistar;

		 e->Cancel = false;

	} else {

		 e->Cancel = true;
		 //Jeœli coœ jest niezapisane, program prze³¹cza automatycznie okna listviewu 
		 if (!this->ZapisanyMebel){
			 this->CollectionCB->SelectedIndex = 1;
		 } else if (!this->ZapisanyObraz){
			 this->CollectionCB->SelectedIndex = 2;
		 } else if(!this->ZapisanyPU){
			 this->CollectionCB->SelectedIndex = 3;
		 }else if(!this->ZapisanyR){
			 this->CollectionCB->SelectedIndex = 4;
		 } else if(!this->ZapisanyRIS){
			 this->CollectionCB->SelectedIndex = 5;
		 }
		

	}
}
private: System::Void ChangeV_Click(System::Object^  sender, System::EventArgs^  e) {
	//Funkcja zmienia rodzaj widoku w listviewie
	if (this->ObjectList->View == Windows::Forms::View::Tile)
	{
		this->ObjectList->View = Windows::Forms::View::Details;
	}
	else if (this->ObjectList->View == Windows::Forms::View::Details)
	{
		this->ObjectList->View = Windows::Forms::View::Tile;
	}
}
private: System::Void ReadFromFileButtonCurrent_Click(System::Object^  sender, System::EventArgs^  e) {
	//Funkcja odpowiadaj¹ca za wczytanie danych danej grupy eksponatów z pliku , analogicznie
	if (this->CollectionCB->SelectedIndex <= 0){
		return;
	}else if (MessageBox::Show("Czy na pewno wczytaæ  dane? Wszystkie niezapisane dane zostan¹ zresetowane.", "Wczytaj wszystkie",
		MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes){
		//Wyczyszczenie aktualnych pozycji listview
		this->ObjectList->Items->Clear();
						
		if (this->CollectionCB->SelectedIndex == 1){
			//Wyczyszczenie vectora
			mebel->CzyscVector();
			//Wczytanie danych z odpowiedniego pliku
			if (!mebel->WczytajZPliku("Meble")){

				MessageBox::Show("Plik nie 'Meble.txt' nie istnieje.", "Wczytaj meble", MessageBoxButtons::OK, MessageBoxIcon::Warning);

			}
			else{
			//Wyswietlenie wczytanych danych w listviewie
				this->WyswietlMeble(false);
			}

		}
		else if (this->CollectionCB->SelectedIndex == 2){
			
			obraz->CzyscVector();
			if (!obraz->WczytajZPliku("Obrazy")){

				MessageBox::Show("Plik nie 'Obrazy.txt' nie istnieje.", "Wczytaj obrazy", MessageBoxButtons::OK, MessageBoxIcon::Warning);

			}
			else{
				this->WyswietlObrazy(false);
			}
			
		}
		else if (this->CollectionCB->SelectedIndex == 3){
			
			puzytk->CzyscVector();
			if (!puzytk->WczytajZPliku("Przedmioty_uzytkowe")){

				MessageBox::Show("Plik nie 'Przedmioty_uzytkowe.txt' nie istnieje.", "Wczytaj przedmioty u¿ytkowe", MessageBoxButtons::OK, MessageBoxIcon::Warning);

			}
			else {
				this->WyswietlPU(false);
			}

		}
		else if (this->CollectionCB->SelectedIndex == 4){
			
			rzezba->CzyscVector();
			if (!rzezba->WczytajZPliku("Rzezby")){

				MessageBox::Show("Plik nie 'Rzezby.txt' nie istnieje.", "Wczytaj rzeŸby", MessageBoxButtons::OK, MessageBoxIcon::Warning);

			}
			else{
				this->WyswietlRzezby(false);
			}

		}
		else if (this->CollectionCB->SelectedIndex == 5){

			rekistar->CzyscVector();

			if (!rekistar->WczytajZPliku("Rekopisy_i_starodruki")){

				MessageBox::Show("Plik nie 'Rekopisy_i_starodruki.txt' nie istnieje.", "Wczytaj rêkopisy i starodruki", MessageBoxButtons::OK, MessageBoxIcon::Warning);

			}
			else {
				this->WyswietlRIS(false);
			}

		}
		if (this->ObjectList->Items->Count == 0){
			this->WlaczPrzyciskiEdycji(false);
		}
		else
		{
			this->WlaczPrzyciskiEdycji(true);
		}
	}
	else
	{
		return;
	}
}
private: System::Void SaveToFiletButtonCurrent_Click(System::Object^  sender, System::EventArgs^  e) {
	//Funkcja odpowiedzialna za zapis danej grupy eksponatów do pliku, analogicznie
	if (MessageBox::Show("Czy na pewno zapisaæ  dane? Aktualny plik z danymi zostanie nadpisany.", "Zapisz obecny",
		MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes){

		if (this->CollectionCB->SelectedIndex == 1){
			//Zapis do pliku
			mebel->ZapiszDoPliku("Meble");
			//Ustawienie odpowiedniej zmiennej logicznej
			this->ZapisanyMebel = true;
			MessageBox::Show("Zapisano meble.", "Zapisz meble", MessageBoxButtons::OK, MessageBoxIcon::Information);

		}
		else if (this->CollectionCB->SelectedIndex == 2){

			obraz->ZapiszDoPliku("Obrazy");
			this->ZapisanyObraz = true;
			MessageBox::Show("Zapisano obrazy.", "Zapisz obrazy", MessageBoxButtons::OK, MessageBoxIcon::Information);
		
		}
		else if (this->CollectionCB->SelectedIndex == 3){

			puzytk->ZapiszDoPliku("Przedmioty_uzytkowe");
			this->ZapisanyPU = true;
			MessageBox::Show("Zapisano przedmioty u¿ytkowe.", "Zapisz przedmioty u¿ytkowe", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

		else if (this->CollectionCB->SelectedIndex == 4){

			rzezba->ZapiszDoPliku("Rzezby");
			this->ZapisanyR = true;
			MessageBox::Show("Zapisano rzeŸby.", "Zapisz rzeŸby", MessageBoxButtons::OK, MessageBoxIcon::Information);

		}
		else if (this->CollectionCB->SelectedIndex == 5){

			rekistar->ZapiszDoPliku("Rekopisy_i_starodruki");
			this->ZapisanyRIS = true;
			MessageBox::Show("Zapisano rêkopisy i starodruki.", "Zapisz rêkopisy i starodruki", MessageBoxButtons::OK, MessageBoxIcon::Information);

		}
	}
	else
	{
		this->ZapisaneWszystkie(false);
		return;
	}

	if ((this->ZapisanyMebel) && (this->ZapisanyObraz) && (this->ZapisanyPU) && (this->ZapisanyR) && (this->ZapisanyRIS)){
		this->Zapisany = true;
	}
	
}
private: System::Void ReadFromFileButtonAll_Click(System::Object^  sender, System::EventArgs^  e) {
	//Funkcja odpowiedzialna za wczytanie danych wszystkich grup eksponatów z plików

	Zapisany = true;
	if (MessageBox::Show("Czy na pewno wczytaæ wszystkie dane? Pamiêtaj, ¿e wszystkie niezapisane dane, równie¿ te z innych ekspozycji zostan¹ utracone.", "Wczytaj wszystkie",
		MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes){
		//Czyszczenie wwszystkich vectorów
		this->ObjectList->Items->Clear();
		mebel->CzyscVector();
		obraz->CzyscVector();
		puzytk->CzyscVector();
		rzezba->CzyscVector();
		rekistar->CzyscVector();
		//Wczytanie wszystkich danych z odpowiednich plików
		if (!mebel->WczytajZPliku("Meble")){

			MessageBox::Show("Plik nie 'Meble.txt' nie istnieje.", "Wczytaj meble", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		
		}
		if (!obraz->WczytajZPliku("Obrazy")){

			MessageBox::Show("Plik nie 'Obrazy.txt' nie istnieje.", "Wczytaj obrazy", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		}
		if (!puzytk->WczytajZPliku("Przedmioty_uzytkowe")){

			MessageBox::Show("Plik nie 'Przedmioty_uzytkowe.txt' nie istnieje.", "Wczytaj przedmioty u¿ytkowe", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		}
		if (!rzezba->WczytajZPliku("Rzezby")){

			MessageBox::Show("Plik nie 'Rzezby.txt' nie istnieje.", "Wczytaj rzeŸby", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		}
		if (!rekistar->WczytajZPliku("Rekopisy_i_starodruki")){

			MessageBox::Show("Plik nie 'Rekopisy_i_starodruki.txt' nie istnieje.", "Wczytaj rêkopisy i starodruki", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		}
		

		//Wyswietlenie danych w listviewie i w³aczenie odpowiednich przycisków edycji
		if (this->CollectionCB->SelectedIndex == 0){

			this->WyswietlWszystkie();
			this->WlaczPrzyciskiEdycji(false);


		}else if (this->CollectionCB->SelectedIndex == 1){
					
			this->WyswietlMeble(false);
			this->WlaczPrzyciskiEdycji(true);

		}
		else if (this->CollectionCB->SelectedIndex == 2){

			this->WyswietlObrazy(false);
			this->WlaczPrzyciskiEdycji(true);

		}
		else if (this->CollectionCB->SelectedIndex == 3){

			this->WyswietlPU(false);
			this->WlaczPrzyciskiEdycji(true);

		}
		else if (this->CollectionCB->SelectedIndex == 4){

			this->WyswietlRzezby(false);
			this->WlaczPrzyciskiEdycji(true);

		}
		else if (this->CollectionCB->SelectedIndex == 5){

			this->WyswietlRIS(false);
			this->WlaczPrzyciskiEdycji(true);

		}
	}
	else {
		return;
	}

}
private: System::Void SaveToFileButonAll_Click(System::Object^  sender, System::EventArgs^  e) {
	//Funkcja odpowiedzialna za zapis wszystkich danych do pliku
	
	if (MessageBox::Show("Czy na pewno zapisaæ wszystkie dane? Pamiêtaj, ¿e wszystkie pliki z danym, równie¿e te z innych ekspozycji zostan¹ utracone.", "Zapisz wszystkie",
		MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes){
		
		
		obraz->ZapiszDoPliku("Obrazy");
		mebel->ZapiszDoPliku("Meble");
		puzytk->ZapiszDoPliku("Przedmioty_uzytkowe");
		rzezba->ZapiszDoPliku("Rzezby");
		rekistar->ZapiszDoPliku("Rekopisy_i_starodruki");
		this->Zapisany = true;
		this->ZapisaneWszystkie(true);

		MessageBox::Show("Zapisano wszystkie dane.", "Zapisz wszystkie",MessageBoxButtons::OK, MessageBoxIcon::Information);

	}
	else {
		
		this->Zapisany = false;
		this->ZapisaneWszystkie(false);
		return;
	}
}
private: System::Void ObjectList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	this->EditButton->Enabled = true;
}
};
}
