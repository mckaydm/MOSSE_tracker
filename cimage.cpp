#include "cimage.h"

CImage::CImage(const cv::Mat& mat)
{
    image_ = cv::Mat(mat);
}

CImage::CImage()
{
    image_ = cv::Mat();
}

CImage::~CImage()
{
}

QImage CImage::getQImage() const
{
    if (image_.empty()) 
        return QImage();

    // Convert BGR to RGB format
    cv::Mat rgb;
    if (image_.channels() == 3) {
        cv::cvtColor(image_, rgb, cv::COLOR_BGR2RGB);
    } else {
        cv::cvtColor(image_, rgb, cv::COLOR_GRAY2RGB);
    }

    // Create QImage with the same dimensions as input
    QImage img(rgb.data, 
              rgb.cols, 
              rgb.rows, 
              static_cast<int>(rgb.step),
              QImage::Format_RGB888);
    
    // Return a deep copy of the image data
    return img.copy();
}

QImage CImage::getQImage(const cv::Mat &mat)
{
    return CImage(mat).getQImage();
}
