#pragma once

#include "opencv2/core/types.hpp"

namespace Objects{
    enum Color { Blue, Red, Green, Yellow, Purple};
    
    class Ball{

        Color m_color;
        cv::Point m_position;
        cv::Rect m_bounds;

    public:

        Ball(Color color, cv::Rect bounds, cv::Point position);

        [[nodiscard]] Color getColor() const noexcept {return m_color;}
        [[nodiscard]] cv::Point getPosition() const noexcept {return m_position;}
        [[nodiscard]] cv::Rect getBounds() const noexcept {return m_bounds;}

    };
}
