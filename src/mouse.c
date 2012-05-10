#include "mouse.h"

#include <string.h>

void mouseMove(uint32_t x, uint32_t y)
{
#ifdef LINUX
	XWarpPointer(display, None, DefaultRootWindow(display), 0, 0, 0, 0, x, y);
	XFlush(display);
#endif
}

void mousePos(uint32_t *x, uint32_t *y)
{
#ifdef LINUX
	XEvent event;
	memset(&event, 0, sizeof(event));
	
	XQueryPointer(display, DefaultRootWindow(display),
			&event.xbutton.root, &event.xbutton.window,
	     		&event.xbutton.x_root, &event.xbutton.y_root,
	     		&event.xbutton.x, &event.xbutton.y,
	     		&event.xbutton.state);
	
	*x = event.xbutton.x;
	*y = event.xbutton.y;
#endif
}

void mouseClick(mouseButton button)
{
#ifdef LINUX
	XEvent event;
	memset(&event, 0, sizeof(event));
	
	event.xbutton.button = button;
	event.xbutton.same_screen = True;
	event.xbutton.subwindow = DefaultRootWindow(display);
	
	while (event.xbutton.subwindow) {
		event.xbutton.window = event.xbutton.subwindow;
		
		XQueryPointer(display, event.xbutton.window,
		     &event.xbutton.root, &event.xbutton.subwindow,
		     &event.xbutton.x_root, &event.xbutton.y_root,
		     &event.xbutton.x, &event.xbutton.y,
		     &event.xbutton.state);
	}
	
	event.type = ButtonPress;
	XSendEvent(display, PointerWindow, True, ButtonPressMask, &event);
	XFlush(display);
	
	event.type = ButtonRelease;
	XSendEvent(display, PointerWindow, True, ButtonReleaseMask, &event);
	XFlush(display);
#endif
}

