#include "pch.h"
#include "Player.h"
#include "utils.h"
#include <iostream>

Player::Player(const Point2f& pos) :
	m_Pos{ pos },
	m_Speed{ 7.f },
	startPointLeft{},
	endPointLeft{},
	startPointRight{},
	endPointRight{},
	m_Won{ false },
	m_WinCounter{ 0 },
	m_Timer{ 0 }

	
{
	m_pSVG = new SVGParser();
	m_pSVG2 = new SVGParser();
	m_pSVG3 = new SVGParser();
}

void Player::Draw() const
{
	Rectf playerRect{ m_Pos.x, m_Pos.y, 60, 60 };
	utils::FillRect(playerRect);
	
	if (m_WinCounter == 0)
	{
		for (int i = 0; i < m_Vertices.size(); ++i) {
			utils::SetColor(Color4f{ 0.f,1.f,0.f,1.f });
			utils::DrawPolygon(m_Vertices[i], 3.f);
			
			utils::FillEllipse(1300, 2800, 30, 30);
			utils::FillEllipse(2350, 2800, 30, 30);
			
		}
	}
	if (m_WinCounter == 1)
	{
		for (int i = 0; i < m_Vertices2.size(); ++i) {
			utils::SetColor(Color4f{ 0.f,0.f,1.f,1.f });
			utils::DrawPolygon(m_Vertices2[i], 3.f);

		}
	}
	if (m_WinCounter == 2)
	{
		for (int i = 0; i < m_Vertices3.size(); ++i) {
			utils::SetColor(Color4f{ 1.f,0.f,0.f,1.f });
			utils::DrawPolygon(m_Vertices3[i], 3.f);

		}
	}
}

void Player::Move(float elapsedSec, const Uint8* pStates)
{
	if(pStates[SDL_SCANCODE_A])
	{
		m_Pos.x -= m_Speed;
	}
	if (pStates[SDL_SCANCODE_D])
	{
		m_Pos.x += m_Speed;
	}
	if (pStates[SDL_SCANCODE_S])
	{
		m_Pos.y -= m_Speed;
	}
	if (pStates[SDL_SCANCODE_W])
	{
		m_Pos.y += m_Speed;
	}
}

Point2f Player::GetPosition()
{
	return Point2f(m_Pos);
}

void Player::Raycast()
{
	utils::HitInfo hitinfo;
	startPointLeft = Point2f{ m_Pos.x, m_Pos.y + 30 };
	endPointLeft = Point2f{ m_Pos.x, m_Pos.y };

	startPointRight = Point2f{ m_Pos.x + 30, m_Pos.y + 30 };
	endPointRight = Point2f{ m_Pos.x + 30, m_Pos.y };

	if (m_WinCounter == 0)
	{
		for (int idx{}; idx < m_Vertices.size(); ++idx)
		{
			if (utils::Raycast(m_Vertices[idx], startPointLeft, endPointLeft, hitinfo))
			{
				m_Pos = Point2f{ 100,100 };
			}
			if (utils::Raycast(m_Vertices[idx], startPointLeft, startPointRight, hitinfo))
			{
				m_Pos = Point2f{ 100,100 };
			}
		}
	}
	if (m_WinCounter == 1)
	{
		for (int idx{}; idx < m_Vertices2.size(); ++idx)
		{
			if (utils::Raycast(m_Vertices2[idx] , startPointLeft, endPointLeft, hitinfo))
			{
				m_Pos = Point2f{ 100,100 };
			}
			if (utils::Raycast(m_Vertices2[idx], startPointLeft, startPointRight, hitinfo))
			{
				m_Pos = Point2f{ 100,100 };
			}
		}
	}
	if (m_WinCounter == 2)
	{
		for (int idx{}; idx < m_Vertices3.size(); ++idx)
		{
			if (utils::Raycast(m_Vertices3[idx], startPointLeft, endPointLeft, hitinfo))
			{
				m_Pos = Point2f{ 100,100 };
			}
			if (utils::Raycast(m_Vertices3[idx], startPointLeft, startPointRight, hitinfo))
			{
				m_Pos = Point2f{ 100,100 };
			}
		}
	}
	
	
}
void Player::Win()
{
	if (m_Pos.y >= 3050)
	{
		m_Won = true;
	}
	else m_Won = false;

	if (m_Won == true)
	{
		
		++m_WinCounter;
		if (m_WinCounter == 1)
		{
			std::cout << "You made it through the first maze, keep going!!" << std::endl;
		}
		if (m_WinCounter == 2)
		{
			std::cout << "One more maze and you are free!!" << std::endl;
		}
		if (m_WinCounter == 3)
		{
			std::cout << "You thought you could escape, NEVER, you will be stuck here FOREVER!!" << std::endl;
		}
		m_Pos = Point2f{ 100,100 };
	}
	if (m_WinCounter == 3) m_WinCounter = 0;
}



void Player::ProcessSVGFile(const std::string& filePath)
{


	if (m_pSVG->GetVerticesFromSvgFile(filePath, m_Vertices)) {
		
	}
	else {
		std::cout << "error";
	}

	
}

void Player::ProcessSVGFile2(const std::string& filePath)
{
	if (m_pSVG2->GetVerticesFromSvgFile(filePath, m_Vertices2)) {

	}
	else {
		std::cout << "error";
	}
}

void Player::ProcessSVGFile3(const std::string& filePath)
{
	if (m_pSVG3->GetVerticesFromSvgFile(filePath, m_Vertices3)) {

	}
	else {
		std::cout << "error";
	}
}

