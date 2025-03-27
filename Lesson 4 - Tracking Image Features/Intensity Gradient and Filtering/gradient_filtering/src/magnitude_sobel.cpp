#include <iostream>
#include <numeric>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;
#include "helper.hpp"
using namespace std;

void magnitudeSobel()
{
    // load image from file
    cv::Mat img;
    img = cv::imread("../images/img1gray.png");

    // convert image to grayscale
    cv::Mat imgGray;
    cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);

    // apply smoothing using the GaussianBlur() function from the OpenCV
    // Define the kernel size (it must be odd and positive)
    Size kernel_size(5, 5);

    // Define the standard deviation in X and Y direction 
    //(if sigmaY is zero, it is set to be equal to sigmaX, if both are zeros, they are computed from kernel size)
    double sigmaX = 0;
    double sigmaY = 0;

    // Apply Gaussian blur
    Mat blurred_image;
    GaussianBlur(imgGray, blurred_image, kernel_size, sigmaX, sigmaY);

    // create filter kernels using the cv::Mat datatype both for x and y
    cv::Mat sobel_image = applySobel(blurred_image);

    // apply filter using the OpenCv function filter2D()
    // ToDo : Add your code here
    

    // compute magnitude image based on the equation presented in the lesson 
    // ToDo : Add your code here
    

    // show result
    string windowName = "Gaussian Blurring";
    cv::namedWindow(windowName, 1); // create window
    cv::imshow(windowName, sobel_image);
    cv::waitKey(0); // wait for keyboard input before continuing
}

int main()
{
    magnitudeSobel();
}