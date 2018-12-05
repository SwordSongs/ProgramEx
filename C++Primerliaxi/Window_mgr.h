#ifndef __WINDOW_MGR_H__
#define __WINDOW_MGR_H__
#include"Screen.h"
#include<vector>


class Window_mgr {
	public:
		typedef double Money;
		using ScreenIndex = std::vector<Screen>::size_type;
		Window_mgr(int count,Screen::pos ht, Screen::pos wd,char c) {
			Screen s(ht, wd, c);
			std::vector<Screen> tmp(count, s);
			screens = tmp;
		}

		void display(){
			for (std::vector<Screen>::iterator it = screens.begin();
				it != screens.end();
				++it) {
					it->display(std::cout);
					std::cout << std::endl;
			}

		}
		ScreenIndex addScreen(Screen& s) {
			screens.push_back(s);
			return screens.size() - 1;
		}
	private:
		std::vector<Screen> screens;
};
#endif

