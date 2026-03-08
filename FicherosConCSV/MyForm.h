#pragma once

namespace FicherosConCSV {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::IO;
    using namespace System::Collections::Generic;

    public ref class MyForm : public System::Windows::Forms::Form
    {
        //clase interna que representa a un alumno con sus datos personales
        ref class Alumno {
        public:
            String^ Nombre;
            String^ ApellidoPaterno;
            String^ ApellidoMaterno;
            String^ Matricula;
            String^ Curp;
        };
    private:
        // declaración de nuestra lista dinámica para el almacenamiento de nustros datos
        List<Alumno^>^ listaAlumnos;
    private: System::Windows::Forms::DataGridView^ Alumnos; //tabla visual para mostrar los alumnos

        // Declaración de los controles visuales

    private: System::Windows::Forms::ComboBox^ Filtros; //lista desplegable para poder seleccionar el campo de ordenamiento

        System::Windows::Forms::Button^ btnOrdenar; //botón que dispara el ordenamiento
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ colNombre;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ colApePat;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ colApeMat;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ colMatricula;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCurp;
    private: System::DirectoryServices::DirectorySearcher^ directorySearcher1;


    public:
        // inicializamos los componentes, la lista de alumnos, y configuramos el ComboBox y la carga de los datos desde el archivo CSV
        MyForm(void)
        {
            InitializeComponent();
            listaAlumnos = gcnew List<Alumno^>();
            ConfigurarComboBox();
            LeerCSV("alumnos.csv");
        }

    protected:
        //destructor
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        //método generado automáticamente por el diseñador visual de Visual Studio
        //aquí se configuran las propiedades visuales de todos los controles del formulario
        void InitializeComponent(void)
        {
            //estilos visuales para cada columna de la tabla
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle9 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle10 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            
            this->Alumnos = (gcnew System::Windows::Forms::DataGridView());
            this->Filtros = (gcnew System::Windows::Forms::ComboBox());
            this->btnOrdenar = (gcnew System::Windows::Forms::Button());
            this->directorySearcher1 = (gcnew System::DirectoryServices::DirectorySearcher());
            this->colNombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->colApePat = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->colApeMat = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->colMatricula = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->colCurp = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Alumnos))->BeginInit();
            this->SuspendLayout();
            // 
            // Alumnos
            // 
            this->Alumnos->BackgroundColor = System::Drawing::SystemColors::ControlDarkDark;
            this->Alumnos->ColumnHeadersHeight = 29;
            this->Alumnos->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
                this->colNombre, this->colApePat,
                    this->colApeMat, this->colMatricula, this->colCurp
            });
            this->Alumnos->Location = System::Drawing::Point(40, 67);
            this->Alumnos->Name = L"Alumnos";
            this->Alumnos->RowHeadersWidth = 51;
            this->Alumnos->Size = System::Drawing::Size(938, 390);
            this->Alumnos->TabIndex = 2;
            // 
            // Filtros
            // 
            this->Filtros->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->Filtros->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->Filtros->Location = System::Drawing::Point(40, 27);
            this->Filtros->Name = L"Filtros";
            this->Filtros->Size = System::Drawing::Size(252, 25);
            this->Filtros->TabIndex = 1;
            // 
            // btnOrdenar
            // 
            this->btnOrdenar->BackColor = System::Drawing::SystemColors::ControlLight;
            this->btnOrdenar->Font = (gcnew System::Drawing::Font(L"Arial Black", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnOrdenar->Location = System::Drawing::Point(310, 22);
            this->btnOrdenar->Name = L"btnOrdenar";
            this->btnOrdenar->Size = System::Drawing::Size(146, 34);
            this->btnOrdenar->TabIndex = 0;
            this->btnOrdenar->Text = L"ORDENAR";
            this->btnOrdenar->UseVisualStyleBackColor = false;
            this->btnOrdenar->Click += gcnew System::EventHandler(this, &MyForm::btnOrdenar_Click);
            // 
            // directorySearcher1
            // 
            this->directorySearcher1->ClientTimeout = System::TimeSpan::Parse(L"-00:00:01");
            this->directorySearcher1->ServerPageTimeLimit = System::TimeSpan::Parse(L"-00:00:01");
            this->directorySearcher1->ServerTimeLimit = System::TimeSpan::Parse(L"-00:00:01");
            // 
            //             --- Configuración de estilos de cada columna ---
            // Columna Nombre
            // 
            dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            dataGridViewCellStyle6->SelectionBackColor = System::Drawing::Color::Crimson;
            dataGridViewCellStyle6->SelectionForeColor = System::Drawing::Color::Black;
            this->colNombre->DefaultCellStyle = dataGridViewCellStyle6;
            this->colNombre->HeaderText = L"Nombre";
            this->colNombre->MinimumWidth = 6;
            this->colNombre->Name = L"colNombre";
            this->colNombre->Width = 125;
            // 
            // Columna Apellido Paterno
            // 
            dataGridViewCellStyle7->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            dataGridViewCellStyle7->SelectionBackColor = System::Drawing::Color::Crimson;
            dataGridViewCellStyle7->SelectionForeColor = System::Drawing::Color::Black;
            this->colApePat->DefaultCellStyle = dataGridViewCellStyle7;
            this->colApePat->HeaderText = L"Apellido Paterno";
            this->colApePat->MinimumWidth = 6;
            this->colApePat->Name = L"colApePat";
            this->colApePat->Width = 125;
            // 
            // Columna Apellido Materno
            // 
            dataGridViewCellStyle8->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            dataGridViewCellStyle8->SelectionBackColor = System::Drawing::Color::Crimson;
            dataGridViewCellStyle8->SelectionForeColor = System::Drawing::Color::Black;
            this->colApeMat->DefaultCellStyle = dataGridViewCellStyle8;
            this->colApeMat->HeaderText = L"Apellido Materno";
            this->colApeMat->MinimumWidth = 6;
            this->colApeMat->Name = L"colApeMat";
            this->colApeMat->Width = 125;
            // 
            // Columna Matricula
            // 
            dataGridViewCellStyle9->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            dataGridViewCellStyle9->SelectionBackColor = System::Drawing::Color::Crimson;
            dataGridViewCellStyle9->SelectionForeColor = System::Drawing::Color::Black;
            this->colMatricula->DefaultCellStyle = dataGridViewCellStyle9;
            this->colMatricula->HeaderText = L"Matrícula";
            this->colMatricula->MinimumWidth = 6;
            this->colMatricula->Name = L"colMatricula";
            this->colMatricula->Width = 125;
            // 
            // Columna Curp
            // 
            dataGridViewCellStyle10->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            dataGridViewCellStyle10->SelectionBackColor = System::Drawing::Color::Crimson;
            dataGridViewCellStyle10->SelectionForeColor = System::Drawing::Color::Black;
            this->colCurp->DefaultCellStyle = dataGridViewCellStyle10;
            this->colCurp->HeaderText = L"Curp";
            this->colCurp->MinimumWidth = 6;
            this->colCurp->Name = L"colCurp";
            this->colCurp->Width = 150;
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::Info;
            this->ClientSize = System::Drawing::Size(1148, 603);
            this->Controls->Add(this->btnOrdenar);
            this->Controls->Add(this->Filtros);
            this->Controls->Add(this->Alumnos);
            this->Name = L"MyForm";
            this->Text = L"Ficheros con CSV";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Alumnos))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion

    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
    }

    private:
        // agregamos las opciones del ordenamiento al ComboBox y selecciona la primera opción por defecto
        void ConfigurarComboBox() 
        {
            Filtros->Items->Add("Nombre");
            Filtros->Items->Add("Apellido Paterno");
            Filtros->Items->Add("Apellido Materno");
            Filtros->Items->Add("Matricula");
            Filtros->Items->Add("Curp");
            if (Filtros->Items->Count > 0) 
            {
                Filtros->SelectedIndex = 0; // selecciona la columna de Nombre como opción predeterminada
            }
        }

        void LeerCSV(String^ ruta) 
        {
            //verificamos que el archivo este correctamente creado antes de leerlo
            if (!File::Exists(ruta)) 
            {
                MessageBox::Show("Error: No se encontró el archivo");
                return;
            }

            //leemos todas las lineas del archivo de una sola vez
            array<String^>^ lineas = File::ReadAllLines(ruta);

            //recoremos las lineas desde la segunda para irnos al encabezado
            for (int i = 1; i < lineas->Length; i++) 
            {
                array<String^>^ datos = lineas[i]->Split(',');

                //mandamos a procesar la linea si solo esta tiene al menos los 5 campos validos que se piden 
                if (datos->Length >= 5) 
                {
                    Alumno^ nuevo = gcnew Alumno();
                    nuevo->Nombre = datos[0];
                    nuevo->ApellidoPaterno = datos[1];
                    nuevo->ApellidoMaterno = datos[2];
                    nuevo->Matricula = datos[3];
                    nuevo->Curp = datos[4];
                    listaAlumnos->Add(nuevo);
                }
            }
            MostrarTabla(); //mostramos la tabla ya actualizada 
        }

        void MostrarTabla() //limpiamos y rellenamos con los datos actuales
        {
            Alumnos->Rows->Clear(); //borramos las ffilas existentes

            //agregamos una fila por alumno que este en la lista
            for (int i = 0; i < listaAlumnos->Count; i++) {
                Alumnos->Rows->Add(
                    listaAlumnos[i]->Nombre,
                    listaAlumnos[i]->ApellidoPaterno,
                    listaAlumnos[i]->ApellidoMaterno,
                    listaAlumnos[i]->Matricula,
                    listaAlumnos[i]->Curp
                );
            }
        }

        // ordenamos la lista de los alumnos alfabéticamente según el campo indicado y utilizaremos el algoritmo de ordenamiento de burbuja
        void OrdenarDatosPorCampo(String^ campo)
        {
            // ordenamiento burbuja
            for (int i = 0; i < listaAlumnos->Count - 1; i++)
            {
                for (int j = 0; j < listaAlumnos->Count - i - 1; j++) 
                {
                    bool intercambiar = false;

                    if (campo == "Nombre") {
                        if (String::Compare(listaAlumnos[j]->Nombre, listaAlumnos[j + 1]->Nombre) > 0) intercambiar = true;
                    }
                    else if (campo == "Apellido Paterno") {
                        if (String::Compare(listaAlumnos[j]->ApellidoPaterno, listaAlumnos[j + 1]->ApellidoPaterno) > 0) intercambiar = true;
                    }
                    else if (campo == "Apellido Materno") {
                        if (String::Compare(listaAlumnos[j]->ApellidoMaterno, listaAlumnos[j + 1]->ApellidoMaterno) > 0) intercambiar = true;
                    }
                    else if (campo == "Matricula") {
                        if (String::Compare(listaAlumnos[j]->Matricula, listaAlumnos[j + 1]->Matricula) > 0) intercambiar = true;
                    }
                    else if (campo == "Curp") {
                        if (String::Compare(listaAlumnos[j]->Curp, listaAlumnos[j + 1]->Curp) > 0) intercambiar = true;
                    }

                    // si los elementos están en un orden incorrecto se intercambiaran usando uno temporal
                    if (intercambiar) 
                    {
                        Alumno^ temp = listaAlumnos[j];
                        listaAlumnos[j] = listaAlumnos[j + 1];
                        listaAlumnos[j + 1] = temp;
                    }
                }
            }
            MostrarTabla(); // mostramos la tabla ya con nuestro ordedn seleccionado
        }

        // funcion del botón Ordenar obtiene el campo seleccionado en el ComboBox y llama al método de ordenamiento correspondiente
        System::Void btnOrdenar_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (Filtros->SelectedItem != nullptr) 
            {
                String^ campoSeleccionado = Filtros->SelectedItem->ToString();
                OrdenarDatosPorCampo(campoSeleccionado);
            }
        }
    };
}