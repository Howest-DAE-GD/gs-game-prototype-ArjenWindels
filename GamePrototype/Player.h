#pragma once
#include "utils.h"
#include <vector>
#include "SVGParser.h"
class Player
{
public:
	Player(const Point2f& pos);
	void Draw() const;
	void Move(float elapsedSec, const Uint8* pStates);
	Point2f GetPosition();
	void ProcessSVGFile(const std::string& filePath);
	void ProcessSVGFile2(const std::string& filePath);
	void ProcessSVGFile3(const std::string& filePath);
	void Raycast();
	void Win();
	
private:
	Point2f m_Pos;
	float m_Speed;
	
	Point2f startPointLeft;
	Point2f endPointLeft;
	Point2f startPointRight;
	Point2f endPointRight;
	SVGParser* m_pSVG;
	SVGParser* m_pSVG2;
	SVGParser* m_pSVG3;
	std::vector<std::vector<Point2f>> m_Vertices;
	std::vector<std::vector<Point2f>> m_Vertices2;
	std::vector<std::vector<Point2f>> m_Vertices3;
	bool m_Won;
	int m_WinCounter;
	float m_Timer;
};

