#include <X11/X.h>
#include <X11/Xutil.h>
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  Display *d;
  Window w;
  XEvent e;
  const char *msg = "This is my first window write in C";
  int s;

  d = XOpenDisplay(NULL);
  if (d == NULL) {
    fprintf(stderr, "Cannot open the display\n");
    exit(EXIT_FAILURE);
  }

  s = XDefaultScreen(d);
  w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, 1280, 720, 1, BlackPixel(d, s), WhitePixel(d, s));

  XSelectInput(d, w, ExposureMask | KeyPressMask);
  XMapWindow(d, w);

  while (1) {
    XNextEvent(d, &e);
    if (e.type == Expose) {
      XFillRectangle(d, w, DefaultGC(d, s), 25, 25, 60, 10);
      XDrawString(d, w, DefaultGC(d, s), 20, 20, msg, strlen(msg));
    }
    if (e.xkey.keycode == XK_h) {
      break;
    }
  }

  XCloseDisplay(d);

  return 0;
}
