//
// Created by tobin on 5/28/2024.
//

#ifndef FREEGLUT_PROJECT_STARTER_ANSI_ESCAPES_H
#define FREEGLUT_PROJECT_STARTER_ANSI_ESCAPES_H

#pragma once

enum Colors {
    RESET_COLOR,
    BLACK_TXT = 30,
    RED_TXT,
    GREEN_TXT,
    YELLOW_TXT,
    BLUE_TXT,
    MAGENTA_TXT,
    CYAN_TXT,
    WHITE_TXT,

    BLACK_BKG = 40,
    RED_BKG,
    GREEN_BKG,
    YELLOW_BKG,
    BLUE_BKG,
    MAGENTA_BKG,
    CYAN_BKG,
    WHITE_BKG
};

void setupConsole(void);
void restoreConsole(void);
void clearScreen(void);  // bad performance
void clearScreenToBottom(void);
void clearScreenToTop(void);
void clearLine(void);
void clearLineToRight(void);
void clearLineToLeft(void);
void moveUp(int positions);
void moveDown(int positions);
void moveRight(int positions);
void moveLeft(int positions);
void moveLeftAbsolute(void);
void moveTo(int row, int col);
void showCursor(void);
void hideCursor(void);
void moveToNoFormat(int n, int m);
void move00(void);

#endif  // FREEGLUT_PROJECT_STARTER_ANSI_ESCAPES_H
