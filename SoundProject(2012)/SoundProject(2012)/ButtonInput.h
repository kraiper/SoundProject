#pragma once


class ButtonInput
{
private:
	bool mPressed, nPressed;

public:
	//ButtonInput();

	void SetMPressed(bool pressed) {mPressed = pressed;}
	void SetNPressed(bool pressed) {nPressed = pressed;}
	bool GetMPressed() {return mPressed;}
	bool GetNPressed() {return nPressed;}

};

