namespace Objects{

    enum class Color: char{
        Yellow=0, Blue, Red, Green, Purple
    };

    struct ColorScalar {

        cv::Scalar m_low;
        cv::Scalar m_high;
    };

    class ObjectColorFactory {

    public:

        static ColorScalar getColor(Color type){
            switch(type){
                case Color::Yellow:
                    return {cv::Scalar(25, 130, 180), cv::Scalar(45, 255, 255)};
                case Color::Blue:
                    return {cv::Scalar(100, 150, 150), cv::Scalar(140, 255, 255)};
                case Color::Red:
                    return {cv::Scalar(170, 140, 160), cv::Scalar(180, 255, 255)};
                case Color::Green:
                    return {cv::Scalar(46, 40, 40), cv::Scalar(70, 255, 255)};
                case Color::Purple:
                    return {cv::Scalar(148, 117, 89), cv::Scalar(152, 255, 255)};

            }
        }
    };

}