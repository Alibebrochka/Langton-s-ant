#pragma once
#include <Windows.h>
#include <conio.h>
enum eDirection { LEFT = 0, RIGHT, UP, DOWN };

class AAnt
{
	bool next{};
	int scale{};
	int left{}, top{}, right{}, bot{};
	int cntr_rect{};
	HBRUSH red{}, black{}, white{};
	eDirection dir;
public:
	AAnt();
	void Go(HDC hdc);
private:
	void direction(eDirection dir);
};

