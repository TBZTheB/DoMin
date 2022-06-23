#ifndef _MAP_H

#define _MAP_H

class Map
{
public:
	Map();
	Map(const int& defaultValue = 0);
	~Map();

	void random();
	int getValue(const int& x, const int& y) const;
	void change(const int& x, const int& y, const int& value);

private:
	int** mmap;

	void increaseAround(const int& _x, const int& _y);
};

#endif // _MAP_H
