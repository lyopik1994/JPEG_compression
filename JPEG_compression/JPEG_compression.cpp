// JPEG_compression.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main()
{

    
    cv::Mat img = cv::imread("D:/source/OpenCV/cat.jpg");

    std::vector<int> compression_params;
    compression_params.push_back(cv::IMWRITE_JPEG_QUALITY);
    compression_params.push_back(40);

    std::string output_filename = "output.jpg";
    cv::imwrite(output_filename, img, compression_params);

    //cv::imshow("Window", img);
    
    //cv::waitKey(0);
    /*
    cv::Mat img = cv::imread("D:/source/OpenCV/1.ARW");

    cv::Mat img_Ycbcr;
    cv::cvtColor(img, img_Ycbcr, cv::COLOR_BGR2YCrCb);

    cv::imshow("Window", img);
    cv::imshow("Window2", img_Ycbcr);
    cv::waitKey(0);
    */
   


}

/*

Кодирование JPEG включает в себя следующие шаги:

Преобразование изображения из RGB цветового пространства в цветовое пространство YCbCr. Это позволяет представить изображение с использованием яркости (Y) и двух цветностей (Cb и Cr), основанных на цветовых различиях между пикселями.
Разделение изображения на блоки 8x8 пикселей.
Применение к каждому блоку дискретного косинусного преобразования (DCT). DCT преобразует блок пикселей в частотную область, что позволяет концентрировать энергию сигнала в низкочастотных коэффициентах.
Квантование коэффициентов DCT. Этот шаг позволяет удалить информацию, которая воспринимается человеческим глазом менее чувствительно, путем округления значений коэффициентов.
Процессом кодирования Хаффмана осуществляется кодирование и сжатие коэффициентов DCT. Часто встречающиеся значения кодируются короткими битовыми последовательностями, а редкие значения - длинными последовательностями.

*/


//https://bigdevops.ru/article/szhatie-jpeg-s-ispolzovaniem-opencv