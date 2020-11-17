#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED


class Screen
{
public:
	Screen();
	virtual void processEvents();
	virtual void update();
	virtual void render();

private:
	const bool blockEvents;
	const bool blockUpdate;
	const bool blockRender;
};

#endif // SCREEN_H_INCLUDED
