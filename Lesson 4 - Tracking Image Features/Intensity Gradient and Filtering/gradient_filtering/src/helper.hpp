#ifndef helper_hpp
#define helper_hpp
#include <opencv2/core.hpp>

cv::Mat getGaussianKernel(int n, double sigma);
cv::Mat applyGaussian(cv::Mat img,int n, double sigma);
cv::Mat applySobel(cv::Mat img);
#endif 