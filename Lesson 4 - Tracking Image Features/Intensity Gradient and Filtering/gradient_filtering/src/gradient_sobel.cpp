#include <iostream>
#include <numeric>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "helper.hpp"
using namespace std;

void gradientSobel()
{
    // Based on the image gradients in both x and y, compute an image 
    // which contains the gradient magnitude according to the equation at the 
    // beginning of this leesson (refer to the equations for gradient direction and magnitude) 
    // for every pixel position. Also, apply different 
    // levels of Gaussian blurring before applying the Sobel operator and compare the results.
  
  	// Step 1 - load image from file
    cv::Mat img;
    img = cv::imread("../images/img1.png");

    //  Step 2 - convert image to grayscale
    cv::Mat imgGray;
    cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);

    //  Step 3 - apply Gaussin filter
    cv::Mat imgBlur = applyGaussian(imgGray,5,1.0);
    // Step 4- apply Sobel filter
    cv::Mat result = applySobel(imgBlur);

    //  Step 5 - show result
    string windowName = "Sobel operator (x and y directions with Gaussian Blurring)";
    cv::namedWindow( windowName, 1 ); // create window 
    cv::imshow(windowName, result);
    cv::waitKey(0); // wait for keyboard input before continuing
  
}

int main()
{
    gradientSobel();
}