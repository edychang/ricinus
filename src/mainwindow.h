﻿//Ricinus, platform independent Digital Signage Player
//Copyright (C) 2014 Edward Zhang

//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef __RICINUS_MAINWINDOW_H__
#define __RICINUS_MAINWINDOW_H__

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

/**
 * @brief Ricinus播放器主窗口类.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0); ///< 构造函数
    ~MainWindow(); ///< 析构函数

private:
    Ui::MainWindow *ui;
};

#endif // __RICINUS_MAINWINDOW_H__
