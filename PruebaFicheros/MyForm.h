#pragma once

namespace PruebaFicheros {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
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
		}
	private: System::Windows::Forms::Label^ Titulo;
	private: System::Windows::Forms::TextBox^ nombres1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ apellidopaterno;

	private: System::Windows::Forms::Label^ apepaterno;
	private: System::Windows::Forms::TextBox^ apellidomaterno;

	private: System::Windows::Forms::Label^ apematerno;
	private: System::Windows::Forms::Label^ fecha;
	private: System::Windows::Forms::DateTimePicker^ fechass;
	private: System::Windows::Forms::TextBox^ curpdata;

	private: System::Windows::Forms::Label^ curp;
	private: System::Windows::Forms::TextBox^ domicilio;
	private: System::Windows::Forms::Label^ dom;
	private: System::Windows::Forms::Button^ bbtterminado;


	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->Titulo = (gcnew System::Windows::Forms::Label());
			this->nombres1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->apellidopaterno = (gcnew System::Windows::Forms::TextBox());
			this->apepaterno = (gcnew System::Windows::Forms::Label());
			this->apellidomaterno = (gcnew System::Windows::Forms::TextBox());
			this->apematerno = (gcnew System::Windows::Forms::Label());
			this->fecha = (gcnew System::Windows::Forms::Label());
			this->fechass = (gcnew System::Windows::Forms::DateTimePicker());
			this->curpdata = (gcnew System::Windows::Forms::TextBox());
			this->curp = (gcnew System::Windows::Forms::Label());
			this->domicilio = (gcnew System::Windows::Forms::TextBox());
			this->dom = (gcnew System::Windows::Forms::Label());
			this->bbtterminado = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Titulo pricipal del diseño 
			// 
			this->Titulo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Titulo->ForeColor = System::Drawing::SystemColors::Control;
			this->Titulo->Location = System::Drawing::Point(23, 39);
			this->Titulo->Name = L"Titulo";
			this->Titulo->Size = System::Drawing::Size(444, 40);
			this->Titulo->TabIndex = 0;
			this->Titulo->Text = L"Registro de datos ciudadanos";
			this->Titulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Etiqueta de los mombres 
			// 
			this->nombres1->Location = System::Drawing::Point(166, 125);
			this->nombres1->Name = L"nombres1";
			this->nombres1->Size = System::Drawing::Size(283, 22);
			this->nombres1->TabIndex = 6;
			// 
			// ComboBox la que nos permitira ingresar texto por parte del usuario este se usara en los nombres en este caso
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::Control;
			this->label1->Location = System::Drawing::Point(33, 113);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(137, 40);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Nombres: ";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Etiqueta del apellido paterno
			// 
			this->apellidopaterno->Location = System::Drawing::Point(222, 165);
			this->apellidopaterno->Name = L"apellidopaterno";
			this->apellidopaterno->Size = System::Drawing::Size(227, 22);
			this->apellidopaterno->TabIndex = 8;
			// 
			// apepaterno ingreso de los datos por el usuario
			// 
			this->apepaterno->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->apepaterno->ForeColor = System::Drawing::SystemColors::Control;
			this->apepaterno->Location = System::Drawing::Point(33, 153);
			this->apepaterno->Name = L"apepaterno";
			this->apepaterno->Size = System::Drawing::Size(189, 40);
			this->apepaterno->TabIndex = 7;
			this->apepaterno->Text = L"Apellido paterno:";
			this->apepaterno->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Etiqueta del apellido materno
			// 
			this->apellidomaterno->Location = System::Drawing::Point(222, 207);
			this->apellidomaterno->Name = L"apellidomaterno";
			this->apellidomaterno->Size = System::Drawing::Size(227, 22);
			this->apellidomaterno->TabIndex = 10;
			// 
			// apematerno datos ingresados por el usuario
			// 
			this->apematerno->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->apematerno->ForeColor = System::Drawing::SystemColors::Control;
			this->apematerno->Location = System::Drawing::Point(33, 195);
			this->apematerno->Name = L"apematerno";
			this->apematerno->Size = System::Drawing::Size(189, 40);
			this->apematerno->TabIndex = 9;
			this->apematerno->Text = L"Apellido materno:";
			this->apematerno->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Etiqueta de fecha
			// 
			this->fecha->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fecha->ForeColor = System::Drawing::SystemColors::Control;
			this->fecha->Location = System::Drawing::Point(24, 244);
			this->fecha->Name = L"fecha";
			this->fecha->Size = System::Drawing::Size(237, 31);
			this->fecha->TabIndex = 11;
			this->fecha->Text = L"Fecha de nacimiento:";
			this->fecha->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// DataTime el encargado de la lectura de la fecha introduccida por el usuario
			// 
			this->fechass->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->fechass->Location = System::Drawing::Point(263, 249);
			this->fechass->Name = L"fechass";
			this->fechass->Size = System::Drawing::Size(186, 22);
			this->fechass->TabIndex = 12;
			this->fechass->TabStop = false;
			this->fechass->Value = System::DateTime(2026, 3, 5, 0, 0, 0, 0);
			// 
			// curpdata este es el encargado de la lectura de los datos en este caso la curp entera 
			// 
			this->curpdata->Location = System::Drawing::Point(113, 297);
			this->curpdata->Name = L"curpdata";
			this->curpdata->Size = System::Drawing::Size(336, 22);
			this->curpdata->TabIndex = 14;
			// 
			// Etiqueta de la curp
			// 
			this->curp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->curp->ForeColor = System::Drawing::SystemColors::Control;
			this->curp->Location = System::Drawing::Point(33, 285);
			this->curp->Name = L"curp";
			this->curp->Size = System::Drawing::Size(74, 40);
			this->curp->TabIndex = 13;
			this->curp->Text = L"Curp:";
			this->curp->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// domicilio este es el encargado igaumente de la lectura de los datos colocados por nuestro usuario
			// 
			this->domicilio->Location = System::Drawing::Point(150, 337);
			this->domicilio->Name = L"domicilio";
			this->domicilio->Size = System::Drawing::Size(299, 22);
			this->domicilio->TabIndex = 16;
			// 
			// Etiqueta del domicilio
			// 
			this->dom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dom->ForeColor = System::Drawing::SystemColors::Control;
			this->dom->Location = System::Drawing::Point(24, 325);
			this->dom->Name = L"dom";
			this->dom->Size = System::Drawing::Size(126, 40);
			this->dom->TabIndex = 15;
			this->dom->Text = L"Domicilio:";
			this->dom->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// bbtterminado este es el boton el  encargado de cargar los datos a nuestro archivo .txt 
			// 
			this->bbtterminado->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bbtterminado->Location = System::Drawing::Point(166, 417);
			this->bbtterminado->Name = L"bbtterminado";
			this->bbtterminado->Size = System::Drawing::Size(177, 54);
			this->bbtterminado->TabIndex = 17;
			this->bbtterminado->Text = L"FINALIZAR";
			this->bbtterminado->UseVisualStyleBackColor = true;
			this->bbtterminado->Click += gcnew System::EventHandler(this, &MyForm::bbtterminado_Click);
			// 
			// MyForm
			// Totalidad de etiquetas que se agregaron en todo el codigo para el funcionamiento correcto de este
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::CadetBlue;
			this->ClientSize = System::Drawing::Size(513, 688);
			this->Controls->Add(this->bbtterminado);
			this->Controls->Add(this->domicilio);
			this->Controls->Add(this->dom);
			this->Controls->Add(this->curpdata);
			this->Controls->Add(this->curp);
			this->Controls->Add(this->fechass);
			this->Controls->Add(this->fecha);
			this->Controls->Add(this->apellidomaterno);
			this->Controls->Add(this->apematerno);
			this->Controls->Add(this->apellidopaterno);
			this->Controls->Add(this->apepaterno);
			this->Controls->Add(this->nombres1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Titulo);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Registro Ciudadano";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bbtterminado_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		//validamos que todos nuestros campos de texto no estén vacíos y si lo estan mandamos un error diciendo que se tienen que llenar
		if (String::IsNullOrWhiteSpace(this->nombres1->Text) ||
			String::IsNullOrWhiteSpace(this->apellidomaterno->Text) ||
			String::IsNullOrWhiteSpace(this->apellidomaterno->Text) ||
			String::IsNullOrWhiteSpace(this->curpdata->Text) ||
			String::IsNullOrWhiteSpace(this->domicilio->Text))
		{
			MessageBox::Show("Por favor, llena todos los campos antes de registrar.",
				"Datos incompletos", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return; //detenemos el programa de guardado para que este no guarde nada
		}

		//recolectamos toda la información de nuestro formulario y verificamos que todos las etiquetas de nommbre, apellidopaterno, etc. coincidan con los nombres de los controles
		String^ nombres = this->nombres1->Text;
		String^ apePaterno = this->apellidopaterno->Text;
		String^ apeMaterno = this->apellidomaterno->Text;
		String^ fechaNac = this->fechass->Text;
		String^ curp = this->curpdata->Text;
		String^ domicilio = this->domicilio->Text;

		//crearmos o abrirmos un archivo .txt
		//el true significa que los datos nuevos se pondrán al final sin borrar nuestros registros anteriores
		StreamWriter^ archivo = gcnew StreamWriter("datos_ciudadanos.txt", true);

		//escribimos todos los datos en nuestro documento
		archivo->WriteLine("--- Nuevo Registro ---");			//titulo
		archivo->WriteLine("Nombres: " + nombres);				//nombres
		archivo->WriteLine("Apellido Paterno: " + apePaterno);	//apellido paterno
		archivo->WriteLine("Apellido Materno: " + apeMaterno);  //apellido materno
		archivo->WriteLine("Fecha de Nacimiento: " + fechaNac); //la fecha de nacimiento
		archivo->WriteLine("CURP: " + curp);					//curp
		archivo->WriteLine("Domicilio: " + domicilio);			//domicilio
		archivo->WriteLine(""); //colocamos un espacio en blanco para separar registros los registros unos de otros

		//madamos a cerrar el archivo para que se guarde en nuestro disco duro
		archivo->Close();

		//mostrarmos un mensaje que nos diga que todo salio bien y correcto sin errores
		MessageBox::Show("¡Datos registrados correctamente!");

		//limpiar los cuadros de texto para el siguiente registro
		this->nombres1->Text = "";
		this->apellidopaterno->Text = "";
		this->apellidomaterno->Text = "";
		this->curpdata->Text = "";
		this->domicilio->Text = "";
	}
};
}
