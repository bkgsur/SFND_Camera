#include <iostream>
#include <numeric>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

cv::Mat getGaussianKernel(int n, double sigma)
{
    // create a 1D kernel
    cv::Mat kernel = cv::Mat(1, n*n, CV_32F);
    double sum = 0.0;
    for (int i = 0; i < n*n; i++)
    {
        kernel.at<float>(0, i) = exp(-0.5 * pow(i / sigma, 2));
        sum += kernel.at<float>(0, i);
    }
    // normalize the kernel
    kernel = kernel / sum;
    return kernel;
}
cv::Mat applyGaussian(cv::Mat img,int n, double sigma)
{
    // create a 5x5 Gaussian kernel
    cv::Mat kernel = getGaussianKernel (n, sigma);
    // apply filter
    cv::Mat result;
    cv::filter2D(img, result, -1, kernel, cv::Point(-1, -1), 0, cv::BORDER_DEFAULT);
    return result;

}

cv::Mat applySobel(cv::Mat img)
{
    // create filter kernels using the cv::Mat datatype both for x and y
    float sobel_x[9] = {-1, 0, +1,
                        -2, 0, +2, 
                        -1, 0, +1};
    cv::Mat kernel_x = cv::Mat(3, 3, CV_32F, sobel_x);

    float sobel_y[9] = {-1, -2, -1,
                        0, 0, 0, 
                        +1, +2, +1};
    cv::Mat kernel_y = cv::Mat(3, 3, CV_32F, sobel_y);

    // apply filter using the OpenCv function filter2D()
    cv::Mat result_x;
    cv::filter2D(img, result_x, -1, kernel_x, cv::Point(-1, -1), 0, cv::BORDER_DEFAULT);
    cv::Mat result_y;
    cv::filter2D(img, result_y, -1, kernel_y, cv::Point(-1, -1), 0, cv::BORDER_DEFAULT);

    // compute magnitude image based on the equation presented in the lesson 
    cv::Mat magnitude = img.clone();
    for (int r = 0; r < magnitude.rows; r++)
    {
        for (int c = 0; c < magnitude.cols; c++)
        {
            float sum = pow(result_x.at<unsigned char>(r, c), 2) + pow(result_y.at<unsigned char>(r, c), 2);
            magnitude.at<unsigned char>(r, c) = sqrt(sum);
        }
    }
    return magnitude;
}