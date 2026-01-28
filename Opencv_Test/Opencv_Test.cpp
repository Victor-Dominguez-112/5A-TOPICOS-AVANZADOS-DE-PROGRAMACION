#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/*
 * Código de prueba para verificar la instalación y configuración de OpenCV
 */

int main()
{
    Mat img = imread("C:/Users/domin/Desktop/QUINTO CUATRIMESTRE/PROGRAMACION AVANZADA/PAR 1/Opencv_Test/img/peakpx.jpg");

    if (img.empty())
    {
        cout << "No se pudo cargar la imagen" << endl;
        return -1;
    }

    Mat img_resized;
    resize(img, img_resized, Size(636, 316));

    Mat img_gray_big, img_gray_small;

    // Blanco y negro grande
    cvtColor(img, img_gray_big, COLOR_BGR2GRAY);

    // Blanco y negro pequeña
    cvtColor(img_resized, img_gray_small, COLOR_BGR2GRAY);

    imshow("Color - Grande", img);
    imshow("Color - Pequena", img_resized);

    imshow("BN - Grande", img_gray_big);
    imshow("BN - Pequena", img_gray_small);

    waitKey(0);
    return 0;
}