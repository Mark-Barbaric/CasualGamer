#include <Windows.h>
#include <iostream>
#include <vector>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "Objects/Ball.h"

std::vector<Objects::Ball> balls;

void getBalls(cv::Mat& img, Objects::Color color){

    Objects::Ball ball (color);
    cv::Mat mask;
    cv::inRange(img, ball.getLowMaskScalar(), ball.getHighMaskScalar(), mask);
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(mask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    std::vector<std::vector<cv::Point>> contoursPoly(contours.size());
    std::vector<cv::Rect> boundRect(contours.size());

    for(const auto& contour : contours){
        ball.setBounds(cv::boundingRect(contour));
        balls.push_back(ball);
    }
}

void drawBalls(cv::Mat background){

    for(const auto& ball : balls){

        switch(ball.getColor()){
            case Objects::Color::Red:
                cv::rectangle(background, ball.getBounds().tl(), ball.getBounds().br(), CV_RGB(255, 0, 0), 2);
                break;
            case Objects::Color::Blue:
                cv::rectangle(background, ball.getBounds().tl(), ball.getBounds().br(), CV_RGB(0, 0, 255), 2);
                break;
            case Objects::Color::Green:
                cv::rectangle(background, ball.getBounds().tl(), ball.getBounds().br(), CV_RGB(0, 255, 0), 2);
                break;
            case Objects::Color::Yellow:
                cv::rectangle(background, ball.getBounds().tl(), ball.getBounds().br(), CV_RGB(255, 255, 0), 2);
                break;
            case Objects::Color::Purple:
                cv::rectangle(background, ball.getBounds().tl(), ball.getBounds().br(), CV_RGB(128, 0, 128), 2);
                break;
        }
    }
}

int main() {

    LPCWSTR windowTitle = L"Zuma Deluxe 1.1.0.0";
    HWND hwnd = FindWindowW(nullptr, windowTitle);
    cv::Mat source = cv::imread("C:\\Users\\mark.barbaric\\Documents\\Developer\\CPP\\CasualGamer\\OpenCV\\image1.jpeg", cv::IMREAD_COLOR);

    if(source.empty() || !source.data){
        std::cout << "Couldn't find example image.\n";
        return 1;
    }

    std::cout << "image1.jpeg loaded.\n";
    cv::Mat sourceGray;

    cv::cvtColor(source, sourceGray, cv::IMREAD_GRAYSCALE);
    cv::blur(sourceGray, sourceGray, cv::Size(3,3));
    cv::Mat background;
    source.copyTo(background);

    while(cv::waitKey(100) != 27){

        balls.clear();

        for(auto color = Objects::Color::Yellow; color != Objects::Color::Purple; ++color){
            getBalls(source, Objects::Color::Yellow);
        }

        drawBalls(background);
        cv::imshow("output", background);

    }

    return 0;
}
