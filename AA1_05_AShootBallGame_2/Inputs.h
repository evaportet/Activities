#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>

enum class Keys {LEFT, RIGHT, ESC, FIRE, COUNT};

struct Input {

	bool Keyboard[static_cast<int>(Keys::COUNT)] = {false};

	void Update() {
		Keyboard[(int)Keys::ESC] = GetAsyncKeyState(VK_ESCAPE);
		Keyboard[(int)Keys::LEFT] = GetAsyncKeyState(VK_LEFT);
		Keyboard[(int)Keys::RIGHT] = GetAsyncKeyState(VK_RIGHT);
		Keyboard[(int)Keys::FIRE] = GetAsyncKeyState(VK_SPACE);
	}

};
