#ifndef COLORS_H
#define COLORS_H

// Regular text
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1b[37m"

// Bold text
#define BRED    "\x1b[1;31m"
#define BGREEN  "\x1b[1;32m"
#define BYELLOW "\x1b[1;33m"
#define BBLUE   "\x1b[1;34m"
#define BMAGENTA "\x1b[1;35m"
#define BCYAN   "\x1b[1;36m"
#define BWHITE  "\x1b[1;37m"

// Reset color
#define RESET   "\x1b[0m"

// Styles
#define BOLD    "\x1b[1m"
#define DIM     "\x1b[2m"
#define ITALIC  "\x1b[3m"
#define UNDER   "\x1b[4m"

// Box drawing characters
#define BOX_TL "+"
#define BOX_TR "+"
#define BOX_BL "+"
#define BOX_BR "+"
#define BOX_H  "-"
#define BOX_V  "|"

#endif // COLORS_H
