#include "Ball.h"

namespace Objects{
    
    Ball::Ball(Color color, cv::Rect bounds, cv::Point position):m_color(color),
        m_bounds(std::move(bounds)),
        m_position(std::move(m_position))
        {

        }
}