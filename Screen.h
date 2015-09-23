#ifndef SCREEN
#define SCREEN
#include <string>
class Screen
{
	friend class Window_mgr;

public:
	typedef std::string::size_type pos;
	//等价
	//using pos = std::string::size_type;
	Screen() = default;
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
	char get() const { return contents[cursor]; }
	char get(pos r, pos col) const;
	Screen &move(pos r, pos col);

	void some_member() const;

	Screen &set(char);
	Screen &set(pos, pos, char);

	Screen &display(std::ostream &os) { do_display(os); return *this; }
	const Screen &display(std::ostream &os) const { do_display(os); return *this; }
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;

	mutable size_t access_ctr;	//即使在一个const对象内也能被修改

	void do_display(std::ostream &os) const { os << contents; }
};

inline Screen &Screen::move(pos r, pos col)
{	//移动光标到指定位置
	pos row = r * width;
	cursor = row + col;
	return *this;
}

inline char Screen::get(pos r, pos col) const
{	//取得光标处字符
	pos row = r * width;
	return contents[row + col];
}

inline Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen &Screen::set(pos r, pos col, char c)
{
	contents[r * width + col] = c;
	return *this;
}

void Screen::some_member() const
{
	++access_ctr;
}
#endif