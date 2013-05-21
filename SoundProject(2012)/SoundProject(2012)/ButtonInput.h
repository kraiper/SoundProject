#pragma once


class ButtonInput
{
private:
	bool mPressed, nPressed,ismPressed,isnPressed;

public:
	//ButtonInput();

	void SetMPressed(bool pressed){if(pressed){if(ismPressed == false){mPressed = !mPressed;}ismPressed = true;}else{ismPressed = false;}}//{mPressed = pressed;}
	void SetNPressed(bool pressed){if(pressed){if(isnPressed == false){nPressed = !nPressed;}isnPressed = true;}else{isnPressed = false;}}
	bool GetMPressed() {return mPressed;}
	bool GetNPressed() {return nPressed;}

};

