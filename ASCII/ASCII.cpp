#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int getBrightness(int Gvalue); //function prototype. Defined below.

//next two functions will be used in our algorithm to convert to grayscale. These simply find the max and min of 3 numbers.
float largest(int x, int y, int z) {

    int largest = 0;

    if (x > largest)
        largest = x;
    if (y > largest)
        largest = y;
    if (z > largest)
        largest = z;

    return largest;
}

float smallest(int x, int y, int z) {

    int smallest = 0;

    if (x < smallest)
        smallest = x;
    if (y < smallest)
        smallest = y;
    if (z < smallest)
        smallest = z;

    return smallest;
}

//function to read every pixel of image, convert to grayscale, find correspoding brightness value
//and then map that pixel to an ascii character of matching brightness. The function has 2 parameters.
//One parameter is the image file we are processing, the second is the alogorithm desired to convert to grayscale.

void imageProcessor(Mat img2, String algo) {


    unsigned char grayScale;
    int maximum, minimum;

    //scan through every pixel 
    for (int row = 0; row < img2.rows; row++) {
        for (int col = 0; col < img2.cols; col++) {

            Vec3b bgrpixel = img2.at<Vec3b>(row, col); //holds bgr value for that specific row/col pixel

            //3 different algorithms to convert to grayscale
            if (algo == "luminosity")
                grayScale = (bgrpixel[2] * .21) + (bgrpixel[1] * .72) + (bgrpixel[0] * .07);
            else if (algo == "average")
                grayScale = ((bgrpixel[2] + bgrpixel[1] + bgrpixel[0]) / 3);
            else if (algo == "min_max") {
                maximum = (largest(bgrpixel[2], bgrpixel[1], bgrpixel[0]));
                minimum = (smallest(bgrpixel[2], bgrpixel[1], bgrpixel[0]));
                grayScale = (maximum + minimum) / 2;

            }
      
            img2.at<Vec3b>(row, col) = { grayScale, grayScale, grayScale }; //conversion of bgr to grayscale

            Vec3b graypixel = img2.at<Vec3b>(row, col);

            int gValue = graypixel[0];

            if (getBrightness(gValue) == 13)
                cout << "$";
            else if (getBrightness(gValue) == 12)
                cout << "@";
            else if (getBrightness(gValue) == 11)
                cout << "B";
            else if (getBrightness(gValue) == 10)
                cout << "%";
            else if (getBrightness(gValue) == 9)
                cout << "8";
            else if (getBrightness(gValue) == 8)
                cout << "o";
            else if (getBrightness(gValue) == 7)
                cout << "p";
            else if (getBrightness(gValue) == 6)
                cout << "L";
            else if (getBrightness(gValue) == 5)
                cout << "{";
            else if (getBrightness(gValue) == 4)
                cout << "!";
            else if (getBrightness(gValue) == 3)
                cout << "^";
            else if (getBrightness(gValue) == 2)
                cout << ".";
            else if (getBrightness(gValue) == 1)
                cout << " ";

        }

        cout << endl;
    }

}

//function gets the brightness of given pixel and returns the corresponding ascii code. 1 being the lightest, 
int getBrightness(int gValue)
{
    int asciival;

    if (gValue >= 240)
    {
        asciival = 1;
    }
    else if (gValue >= 220)
    {
        asciival = 2;
    }
    else if (gValue >= 200)
    {
        asciival = 3;
    }
    else if (gValue >= 175)
    {
        asciival = 4;
    }
    else if (gValue >= 150)
    {
        asciival = 5;
    }
    else if (gValue >= 125)
    {
        asciival = 6;
    }
    else if (gValue >= 100)
    {
        asciival = 7;
    }
    else if (gValue >= 80)
    {
        asciival = 8;
    }
    else if (gValue >= 55)
    {
        asciival = 9;
    }
    else if (gValue >= 40)
    {
        asciival = 10;
    }
    else if (gValue >= 25)
    {
        asciival = 11;
    }
    else if (gValue >= 10)
    {
        asciival = 12;
    }
    else
    {
        asciival = 13;
    }

    return asciival;
}


int main() {
    String path, algo = "min_max";  //choose the algorithm - average, luminosity or min_max

    //the following is to take an existing photo and convert to ascii

    path = "C:/Users/justi/Pictures/Edited.png";
    Mat img1 = imread(path), img2;
    resize(img1, img2, Size(900, 355));
    imageProcessor(img2, algo);
    

    ////the following code is used to capture still shots from an external device/webcam and convert to ascii art in real time

    //while (true) {

    //    VideoCapture cap(0);
    //    Mat vid, vid2;
    //    
    //    cap.read(vid);
    //    resize(vid, vid2, Size(500, 250));
    //    imshow("video", vid);
    //    imageProcessor(vid2, algo);
    //    waitKey(1);

    //}
    return 0; 
}
