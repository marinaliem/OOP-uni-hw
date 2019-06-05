#include "pch.h"
#include <iostream>

class LauncherItem {
protected:
	char* title;
public:
	virtual char* getTitle() = 0;
	virtual bool canMove() = 0;
};

template<typename T>
class Launcher : virtual public LauncherItem {
	T** screen;
	int width, height;
public:
	Launcher() {
		screen = new LauncherItem*[1];
		screen[0] = new LauncherItem[1];
		width = 1, height = 1;
	}
	~Launcher() {
		clear();
	}
	Launcher(int _width, int _height) {
		screen = new LauncherItem*[_width];
		screen[0] = new LauncherItem[_height];
		width = _width, height = _height;
	}
	Launcher(const Launcher& l) {
		screen = new LauncherItem*[l.width];
		screen[0] = new LauncherItem[l.height];
		width = l.width, height = l.height;
	}
	/*ostream& operator<<(ostream& o, const Launcher& l) {
		for (int i = 0; i < l.width; i++) {
			for (int j = 0; j < l.height; j++) {
				o << l.screen[i].title << " on pos " << i << std::endl;
			}
		}
		return o;
	}*/
	void addElem(const T& _l, int i, int j) {
		if (screen[i][j] == nullptr) {
			screen[i][j] = _l;
		}
		else {
			for (int ind1 = 0; ind1 < width; ind1++) {
				for (int ind2 = 0; ind2 < height; ind2++) {
					if (screen[ind1][ind2] == nullptr) {
						screen[ind1][ind2] = _l;
						break;
					}
				}
			}
			std::cout << "Error: not enough space on screen" << std::endl;
		}
	}
	void removeElem(int i, int j) {
		if (screen[i][j] != nullptr && canMove())
			delete[] screen[i][j];
		else
			std::cout << "Error" << std::endl;
	}
	void moveElem(int i, int j, int k, int l) {
		if (screen[i][j]->canMove()) {
			if (screen[k][l] == nullptr)
				screen[k][l] = screen[i][j];
			else
				swap(screen[i][j], screen[k][l]);
		}
	}
	void clear() {
		for (int i = 0; i < width; i++)
			delete[] screen[i];
		delete[] screen;
	}
};

class MobileApp : public LauncherItem {
public:
	MobileApp(const char* name) {
		title = new char[strlen(getTitle())+1];
		strcpy_s(getTitle(),strlen(getTitle())+1,name);
	}
	char* getTitle() {
		return title;
	}
	bool canMove() {
		return true;
	}
};

class SystemWidget : public LauncherItem {
	SystemWidget() {
		title = new char[strlen(getTitle()) + 1];
		strcpy_s(getTitle(), strlen(getTitle()) + 1, "System Widget");
	}
	char* getTitle() {
		return title;
	}
	bool canMove() {
		return false;
	}
};

int main()
{

}
