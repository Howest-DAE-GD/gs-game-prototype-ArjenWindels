#include "pch.h"
#include "Camera.h"
#include "utils.h"




Camera::Camera(float screenWidth, float screenHeight) :
    m_ScreenWidth{ screenWidth },
    m_ScreenHeight{ screenHeight},
    m_CameraPosition{ Point2f(0,0) },
    camX{ m_CameraPosition.x },
    camY{ m_CameraPosition.y }
{
}


void Camera::Aim(float levelW, float levelH, const Point2f& trackCenter)
{


    float threshold = m_ScreenWidth / 4;
    float thresholdback{ 150.f };
    

    camX = m_CameraPosition.x >= levelW;
    if (trackCenter.x > (m_ScreenWidth + m_CameraPosition.x) - thresholdback - 150) {
        camX = m_CameraPosition.x += 7.f;
    }
    else if (trackCenter.x < m_CameraPosition.x + thresholdback) {
        camX = m_CameraPosition.x -= 7.f;
    }
    if (trackCenter.y > (m_ScreenHeight + m_CameraPosition.y) - thresholdback - 60) {
        camY = m_CameraPosition.y += 7.f;
    }
    else if (trackCenter.y < m_CameraPosition.y + thresholdback) {
        camY = m_CameraPosition.y -= 7.f;
    }
    else camY = m_CameraPosition.y += 0;

    
    glPushMatrix();
    {
        glTranslatef(-m_CameraPosition.x, -m_CameraPosition.y, 0.f);
    }

}

Point2f Camera::Reset()
{

    {
        return m_CameraPosition;
    }
    glPopMatrix();
}

Point2f Camera::Getposition()
{
    return Point2f(camX, camY);
}
