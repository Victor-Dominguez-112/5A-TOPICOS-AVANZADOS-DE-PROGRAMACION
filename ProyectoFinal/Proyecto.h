#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>   //Procesamiento de imágenes (filtros)
#include <opencv2/videoio.hpp>   //Manejo de cámara y video
#include <msclr/marshal_cppstd.h> //Conversor de texto
#include <iostream>

namespace ProyectoFinal {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Drawing::Imaging; 

    public ref class Proyecto : public System::Windows::Forms::Form
     //Esto indica que es una clase administraday esto significa que el .NET Garbage Collector administra la memoria de la ventana
    {
    public:
        Proyecto(void)
        {
            InitializeComponent();

            imagenOriginal = new cv::Mat(); //reservara memoria manual para la matriz
            imagenProcesada = new cv::Mat();
            cap = new cv::VideoCapture();
            usandoCamara = false;

            //llenado del ComboBox nuestra lista desplegable con todos los filtros
            cmbFiltros->Items->Add("Original");
            cmbFiltros->Items->Add("Escala de Grises");
            cmbFiltros->Items->Add("Binarización (Umbral)");
            cmbFiltros->Items->Add("Invertir Binarización");
            cmbFiltros->Items->Add("Canny (Bordes)");
            cmbFiltros->Items->Add("Sobel");
            cmbFiltros->Items->Add("Canal R (Rojo)");
            cmbFiltros->Items->Add("Canal G (Verde)");
            cmbFiltros->Items->Add("Canal B (Azul)");
            cmbFiltros->Items->Add("Rotación");
            cmbFiltros->Items->Add("Zoom");

            cmbFiltros->SelectedIndex = 0; //se selecciona el primero por defecto
        }

    protected:
        ~Proyecto()
        {
            if (timerCamara->Enabled) 
            {
                timerCamara->Stop(); //detenemos el reloj si corre
            }

            if (cap->isOpened()) 
            {
                cap->release(); //quitamos la camara de nuestro equipo
            }

            delete cap; //eliminamos memoria de manera manual
            delete imagenOriginal; //si no se hace esto temos fugas de memoria
            delete imagenProcesada;

            if (components)
            {
                delete components;
            }
        }

    private:
        // Componentes de la interfaz gráfica (Botones, Imagen, Timer)
        System::Windows::Forms::PictureBox^ pictureBox1;
        System::Windows::Forms::Button^ btnCargar;
        System::Windows::Forms::Button^ btnCamara;
        System::Windows::Forms::ComboBox^ cmbFiltros;
        System::Windows::Forms::TrackBar^ trackBar1;
        System::Windows::Forms::Label^ lblValor;
        System::Windows::Forms::Timer^ timerCamara;
        System::ComponentModel::IContainer^ components;

        // Nuestras variables Nativas de OpenCV (Punteros)
        cv::Mat* imagenOriginal;    // Guarda la imagen tal cual entra
        cv::Mat* imagenProcesada;   // Guarda la imagen después del filtro
        cv::VideoCapture* cap;      // El objeto que controla la cámara web
        bool usandoCamara;          // Bandera para saber si estamos en modo video o foto

        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->btnCargar = (gcnew System::Windows::Forms::Button());
            this->btnCamara = (gcnew System::Windows::Forms::Button());
            this->cmbFiltros = (gcnew System::Windows::Forms::ComboBox());
            this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
            this->lblValor = (gcnew System::Windows::Forms::Label());
            this->timerCamara = (gcnew System::Windows::Forms::Timer(this->components));
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
            this->SuspendLayout();
            // 
            // PICTUREBOX
            // 
            this->pictureBox1->BackColor = System::Drawing::Color::DimGray;
            this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->pictureBox1->Location = System::Drawing::Point(16, 15);
            this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(799, 492);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox1->TabIndex = 0;
            this->pictureBox1->TabStop = false;
            this->pictureBox1->Click += gcnew System::EventHandler(this, &Proyecto::pictureBox1_Click);
            // 
            // BOTON DE CARGAR
            // 
            this->btnCargar->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->btnCargar->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->btnCargar->Location = System::Drawing::Point(840, 25);
            this->btnCargar->Margin = System::Windows::Forms::Padding(4);
            this->btnCargar->Name = L"btnCargar";
            this->btnCargar->Size = System::Drawing::Size(160, 49);
            this->btnCargar->TabIndex = 1;
            this->btnCargar->Text = L"Cargar Imagen";
            this->btnCargar->UseVisualStyleBackColor = false;
            this->btnCargar->Click += gcnew System::EventHandler(this, &Proyecto::btnCargar_Click);
            // 
            // BOTON DE CAMARA
            // 
            this->btnCamara->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->btnCamara->ForeColor = System::Drawing::SystemColors::Control;
            this->btnCamara->Location = System::Drawing::Point(840, 86);
            this->btnCamara->Margin = System::Windows::Forms::Padding(4);
            this->btnCamara->Name = L"btnCamara";
            this->btnCamara->Size = System::Drawing::Size(160, 49);
            this->btnCamara->TabIndex = 2;
            this->btnCamara->Text = L"Abrir Cámara";
            this->btnCamara->UseVisualStyleBackColor = false;
            this->btnCamara->Click += gcnew System::EventHandler(this, &Proyecto::btnCamara_Click);
            // 
            // CAMBIOS DE FILTROS
            // 
            this->cmbFiltros->BackColor = System::Drawing::Color::White;
            this->cmbFiltros->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbFiltros->ForeColor = System::Drawing::Color::Black;
            this->cmbFiltros->FormattingEnabled = true;
            this->cmbFiltros->Location = System::Drawing::Point(840, 160);
            this->cmbFiltros->Margin = System::Windows::Forms::Padding(4);
            this->cmbFiltros->Name = L"cmbFiltros";
            this->cmbFiltros->Size = System::Drawing::Size(159, 24);
            this->cmbFiltros->TabIndex = 3;
            this->cmbFiltros->SelectedIndexChanged += gcnew System::EventHandler(this, &Proyecto::cmbFiltros_SelectedIndexChanged);
            // 
            // TRACKBAR
            // 
            this->trackBar1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->trackBar1->Location = System::Drawing::Point(840, 209);
            this->trackBar1->Margin = System::Windows::Forms::Padding(4);
            this->trackBar1->Maximum = 255;
            this->trackBar1->Name = L"trackBar1";
            this->trackBar1->Size = System::Drawing::Size(160, 56);
            this->trackBar1->TabIndex = 4;
            this->trackBar1->Scroll += gcnew System::EventHandler(this, &Proyecto::trackBar1_Scroll);
            // 
            // LABEL DEL VALOR
            // 
            this->lblValor->AutoSize = true;
            this->lblValor->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->lblValor->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->lblValor->Location = System::Drawing::Point(837, 269);
            this->lblValor->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblValor->Name = L"lblValor";
            this->lblValor->Size = System::Drawing::Size(52, 16);
            this->lblValor->TabIndex = 0;
            this->lblValor->Text = L"Valor: 0";
            // 
            // TIEMPO DE CAMARA
            // 
            this->timerCamara->Interval = 30;
            this->timerCamara->Tick += gcnew System::EventHandler(this, &Proyecto::timerCamara_Tick);
            // 
            // PROYECTO
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::SteelBlue;
            this->ClientSize = System::Drawing::Size(1010, 532);
            this->Controls->Add(this->lblValor);
            this->Controls->Add(this->trackBar1);
            this->Controls->Add(this->cmbFiltros);
            this->Controls->Add(this->btnCamara);
            this->Controls->Add(this->btnCargar);
            this->Controls->Add(this->pictureBox1);
            this->Margin = System::Windows::Forms::Padding(4);
            this->Name = L"Proyecto";
            this->Text = L"Proyecto OpenCV - Equipo";
            this->Load += gcnew System::EventHandler(this, &Proyecto::Proyecto_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }


        void Proyecto_Load(System::Object^ sender, System::EventArgs^ e) 
        {
        }

        System::Drawing::Bitmap^ MatToBitmap(cv::Mat img) 
        {
            if (img.empty()) return nullptr; //si no hay imagen no hacemos nada

            //corregimos los canales
            cv::Mat temp;
            if (img.channels() == 1) 
            {
                //si la imagen es gris (canal 1) se convertira a color (canal 3)
                //windows Forms prefiere formatos RGB estándar para poder mostrar
                cv::cvtColor(img, temp, cv::COLOR_GRAY2BGR);
            }
            else 
            {
                temp = img.clone();
            }

            //creamos un Bitmap vacío de .NET
            System::Drawing::Bitmap^ bmp = gcnew System::Drawing::Bitmap(temp.cols, temp.rows, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
            
            //bloqueamos los bits al acceso directo de la memoria
            System::Drawing::Imaging::BitmapData^ bmpData = bmp->LockBits
            (
                System::Drawing::Rectangle(0, 0, temp.cols, temp.rows),
                System::Drawing::Imaging::ImageLockMode::WriteOnly,
                System::Drawing::Imaging::PixelFormat::Format24bppRgb
            );

            //copiamos los píxeles crudos 
            size_t size = temp.step * temp.rows; //calculamos el tamaño total en bytes
            memcpy((void*)bmpData->Scan0, (void*)temp.data, size); //copiamos de OpenCV ->.NET

            //desbloquemos
            bmp->UnlockBits(bmpData);
            return bmp;
        }

        //Función central deL procesamiento
        void AplicarFiltros() 
        {
            if (imagenOriginal == nullptr || imagenOriginal->empty()) return;

            int val = trackBar1->Value;

            *imagenProcesada = imagenOriginal->clone();

            int opcion = cmbFiltros->SelectedIndex;

            switch (opcion) {
            case 0: // ORIGINAL
                break;
            case 1: // ESCALA DE GRISES
                cv::cvtColor(*imagenProcesada, *imagenProcesada, cv::COLOR_BGR2GRAY);
                break;
            case 2: // BINARIZACION
                cv::cvtColor(*imagenProcesada, *imagenProcesada, cv::COLOR_BGR2GRAY);
                cv::threshold(*imagenProcesada, *imagenProcesada, val, 255, cv::THRESH_BINARY);
                break;
            case 3: // BINARIZACION INVERTIDA
                cv::cvtColor(*imagenProcesada, *imagenProcesada, cv::COLOR_BGR2GRAY);
                cv::threshold(*imagenProcesada, *imagenProcesada, val, 255, cv::THRESH_BINARY_INV);
                break;
            case 4: // CANNY
                cv::cvtColor(*imagenProcesada, *imagenProcesada, cv::COLOR_BGR2GRAY);
                cv::Canny(*imagenProcesada, *imagenProcesada, val, val * 2);
                break;
            case 5: // SOBEL
            {
                cv::cvtColor(*imagenProcesada, *imagenProcesada, cv::COLOR_BGR2GRAY);
                cv::Mat grad_x, grad_y;
                cv::Mat abs_grad_x, abs_grad_y;
                cv::Sobel(*imagenProcesada, grad_x, CV_16S, 1, 0, 3);
                cv::Sobel(*imagenProcesada, grad_y, CV_16S, 0, 1, 3);
                cv::convertScaleAbs(grad_x, abs_grad_x);
                cv::convertScaleAbs(grad_y, abs_grad_y);
                cv::addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, *imagenProcesada);
            }
            break;
            case 6: // CANAL R
            case 7: // CANAL G
            case 8: // CANAL B
            {
                std::vector<cv::Mat> canales;
                cv::split(*imagenProcesada, canales);
                //RGB -> 0 de azul 1 de verde y 2 de rojo
                int canalIdx = (opcion == 6) ? 2 : (opcion == 7) ? 1 : 0;

                //mostraremos solo el canal en la escala de grises o crearemos una imagen coloreada
                //aquí mostraremos la escala de grises del canal para poder simplificar
                *imagenProcesada = canales[canalIdx];
            }
            break;
            case 9: // ROTACION
            {
                cv::Point2f center(imagenProcesada->cols / 2.0, imagenProcesada->rows / 2.0);
                //usaremos el trackbar para un ángulo de 0 a 360 grados
                double angle = (double)val * (360.0 / 255.0);
                cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1.0);
                cv::warpAffine(*imagenOriginal, *imagenProcesada, rot, imagenOriginal->size());
            }
            break;
            case 10: // ZOOM
            {
                float scale = 1.0 + (val / 50.0); //zoom desde x a 7x
                cv::Mat resized;
                cv::resize(*imagenOriginal, resized, cv::Size(), scale, scale);
                //recortaremos el centro para poder mantener el tamaño
                int cx = resized.cols / 2;
                int cy = resized.rows / 2;
                int w = imagenOriginal->cols;
                int h = imagenOriginal->rows;

                //verificaremos los limites 
                if (cx - w / 2 >= 0 && cy - h / 2 >= 0 && cx + w / 2 < resized.cols && cy + h / 2 < resized.rows)
                    *imagenProcesada = resized(cv::Rect(cx - w / 2, cy - h / 2, w, h));
                else
                    *imagenProcesada = resized; //si es muy grande mostraremos todo resizeado
            }
            break;
            }

            //mostraremos los resultados en el PictureBox
            pictureBox1->Image = MatToBitmap(*imagenProcesada);
        }

        //BOTON PARA CARGAR LA IMAGEN
        void btnCargar_Click(System::Object^ sender, System::EventArgs^ e) 
        {
            //detenemos la camara en caso de que esta este activada
            if (usandoCamara) 
            {
                timerCamara->Stop();
                cap->release();
                usandoCamara = false;
                btnCamara->Text = "Abrir Cámara";
            }

            OpenFileDialog^ ofd = gcnew OpenFileDialog();
            ofd->Filter = "Archivos de imagen|*.jpg;*.png;*.bmp";
            if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) 
            {
                std::string filename = msclr::interop::marshal_as<std::string>(ofd->FileName);
                *imagenOriginal = cv::imread(filename);

                if (imagenOriginal->empty()) 
                {
                    MessageBox::Show("Error al cargar la imagen");
                    return;
                }
                //redimensionaremos la imagen si es muy grande para que quede bien en memoria visual
                if (imagenOriginal->cols > 1920) 
                {
                    cv::resize(*imagenOriginal, *imagenOriginal, cv::Size(1280, 720));
                }

                AplicarFiltros();
            }
        }

        //BOTON DE LA CAMARA
        void btnCamara_Click(System::Object^ sender, System::EventArgs^ e) 
        {
            if (!usandoCamara) 
            {
                //prendemos nuestra camara
                cap->open(0); //esta es nuestra camara por defecto 
                if (cap->isOpened()) {
                    usandoCamara = true;
                    timerCamara->Start(); //iniciamos nuestra camara
                    btnCamara->Text = "Detener Cámara";
                }
                else 
                {
                    MessageBox::Show("No se pudo abrir la cámara");
                }
            }
            else 
            {
                //detenemos la camara para que se deje de pedir fotos
                timerCamara->Stop();
                usandoCamara = false;

                //liberamos la camara de OpenCV
                if (cap->isOpened()) 
                {
                    cap->release();
                }
                //limpiamos la imagen de la pantalla
                pictureBox1->Image = nullptr;

                btnCamara->Text = "Abrir Cámara";
            }
        }

        void timerCamara_Tick(System::Object^ sender, System::EventArgs^ e) 
        {
            //SEGURIDAD solo intentamos leer si la cámara está abierta
            if (cap->isOpened() && usandoCamara) 
            {
                cv::Mat frame;
                *cap >> frame; //capturamos el frame

                if (!frame.empty()) 
                {
                    //clonamos para no afectar el buffer interno del OpenCV
                    *imagenOriginal = frame.clone();
                    AplicarFiltros();
                }
            }
        }

        //este es el cambio en el Slider 
        void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) 
        {
            if (!usandoCamara) //si es la camara el timer lo actualiza por si solo
            { 
                AplicarFiltros();
            }
        }

        //cambio en el ComboBox
        void cmbFiltros_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
        {
            //reseteamos la slider a un valor medio y seguro al cambiar por cada uno de los filtros
            trackBar1->Value = 100;
            if (!usandoCamara) 
            {
                AplicarFiltros();
            }
        }
    private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) 
    {
    }
};
}