#pragma once
class Point
{

public:

Point(int x, char y);
Point& operator=(const Point& p);
bool operator==(const Point& p) const;


public:
	int m_x;
	int m_y;




};

