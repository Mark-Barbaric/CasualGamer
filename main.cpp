#include <Windows.h>
#include <iostream>
#include <vector>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "Ball.h"

std::vector<Objects::Ball> balls;

cv::Scalar yellowLow = cv::Scalar(25, 130, 180);
cv::Scalar yellowHigh = cv::Scalar(45, 255, 255);
cv::Mat background;

void getBalls(cv::Mat img, cv::Scalar low, cv::Scalar high, Objects::Color color){
    cv::Mat mask;
    cv::inRange(img, low, high, mask);
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(mask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);


    std::vector<std::vector<cv::Point>> contoursPoly(contours.size());
    std::vector<cv::Rect> boundRect(contours.size());


    for(int i = 0; i < contours.size(); ++i){
        boundRect[i] = cv::boundingRect(contours[i]);
    }
}

void drawBalls(cv::Mat background){

}

int main() {

    LPCWSTR windowTitle = L"Zuma Deluxe 1.1.0.0";
    HWND hwnd = FindWindowW(nullptr, windowTitle);


    cv::Mat target = cv::imread("target.jpg");
  //  cv::Mat background;
   // target.copyTo(background);

    while(cv::waitKey(100) != 27){

        balls.clear();
        getBalls(target, yellowLow, yellowHigh, Objects::Color::Yellow);
        //drawBalls


        cv::imshow("output", background);

    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
