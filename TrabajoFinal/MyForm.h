#pragma once
#include "Juego.h"
#include "MyForm3.h"
#include "Ganaste.h"
namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form

	{private:
		Juego^ juego;
		Graphics^ g;
		BufferedGraphicsContext^ bfc;
		BufferedGraphics^ bf;
		MyForm3^ perdiste;
		Ganaste^ ganaste;
		SoundPlayer^ music;
	private: System::Windows::Forms::Label^ lbl_vidas;

	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;


		   Bitmap^ fondo;
		   
	public:
		MyForm(int vidas, int velocidad, Bitmap^ background)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//

			juego = gcnew Juego(vidas, velocidad);
			//fondo = gcnew Bitmap("Images/fondo.png");
			fondo = gcnew Bitmap(background);
			g = this->CreateGraphics();
			bfc = BufferedGraphicsManager::Current;
			bf = bfc->Allocate(g, this->ClientRectangle);
			perdiste = gcnew MyForm3();
			ganaste = gcnew  Ganaste();
			music = gcnew SoundPlayer("music.wav");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete juego;
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lbl_vidas = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// lbl_vidas
			// 
			this->lbl_vidas->AutoSize = true;
			this->lbl_vidas->Location = System::Drawing::Point(209, 620);
			this->lbl_vidas->Name = L"lbl_vidas";
			this->lbl_vidas->Size = System::Drawing::Size(33, 13);
			this->lbl_vidas->TabIndex = 0;
			this->lbl_vidas->Text = L"Vidas";
			this->lbl_vidas->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(655, 642);
			this->Controls->Add(this->lbl_vidas);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		bf->Graphics->Clear(Color::Gray);
		bf->Graphics->DrawImage(fondo, 10,10, Rectangle(0,0, 630, 655), GraphicsUnit::Pixel);
		
		juego->DrawEverything(bf->Graphics);
		this->lbl_vidas->Text = "Vidas: " + juego->getVidas();
		
		
	
		if (juego->MoveEverything(g) == false) {
			timer1->Enabled = false;
			if (juego->getPapel() == 15 && juego->getPlastico() == 15 && juego->getVidrio() == 15) {
				Hide();
				ganaste->Show();
			}
			else {
				Hide();
				perdiste->Show();
			}
		}
		bf->Render(g);

	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		juego->AccionJugador(true, e->KeyCode);
	}
	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		juego->AccionJugador(false, e->KeyCode);
	}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	music->PlayLooping();
}
};
}
