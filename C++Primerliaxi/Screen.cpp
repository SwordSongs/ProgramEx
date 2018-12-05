#include"Screen.h"

Screen& Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}

Screen& Screen::set(pos r, pos col, char c) {
	contents[r*width + col] = c;
	return *this;
}
Screen& Screen::display(std::ostream& os) {
	do_display(os);
	return *this;
}

const Screen& Screen::display(std::ostream& os) const {
	do_display(os);
	return *this;
}