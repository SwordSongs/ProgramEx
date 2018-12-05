#ifndef __SCREEN_H__
#define __SCREEN_H__
#include<string>

class Screen {
	public:
		using pos = std::string::size_type;
		Screen() = default;
		Screen(pos ht, pos wd, char c) : height(ht), width(wd),
		contents(ht*wd, c) {}
		char get() const {
			return contents[cursor];
		}

		char get(pos r, pos c) const {
			return contents[r*width + c];
		}

		Screen& move(pos r, pos c) {
			cursor = r * width + c;
			return *this;
		}

		Screen& set(char c);
		Screen& set(pos r, pos c0l, char c);
		Screen& display(std::ostream& os);
		const Screen& display(std::ostream& os) const;

		private:
		pos height = 0;
		pos width = 0;
		pos cursor = 0;
		std::string contents;
		void do_display(std::ostream& os )const {
			for (pos i = 0; i < height*width; ++i) {
				os << contents[i];
				if (i%width == width - 1)
					os<< std::endl;
			}
		}
		//using pos = std::string::size_type;
};
#endif
