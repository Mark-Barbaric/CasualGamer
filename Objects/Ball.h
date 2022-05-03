#pragma once
#include "opencv2/core/types.hpp"
#include "ObjectColor.h"

namespace Objects{
    
    class Ball{

        Color m_color;
        cv::Rect m_bounds;
        cv::Point m_position;
        ColorScalar m_scalar;

    public:

        explicit Ball(Color color)
        :m_color(color)
        {
            m_scalar = ObjectColorFactory::getColor(color);
        }

        void setBounds(cv::Rect bounds){
            m_bounds = bounds;
            m_position = m_bounds.tl();
        }

        [[nodiscard]] Color getColor() const noexcept {return m_color;}
        [[nodiscard]] cv::Point getPosition() const noexcept {return m_position;}
        [[nodiscard]] cv::Rect getBounds() const noexcept {return m_bounds;}
        [[nodiscard]] cv::Scalar getLowMaskScalar() const noexcept {return m_scalar.m_low;}
        [[nodiscard]] cv::Scalar getHighMaskScalar() const noexcept {return m_scalar.m_high;}

    };

    class BallFactory {

    };
}
