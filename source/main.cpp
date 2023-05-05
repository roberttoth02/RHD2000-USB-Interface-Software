//  ------------------------------------------------------------------------
//
//  This file is part of the Intan Technologies RHD2000 Interface
//  Version 1.5.4
//  Copyright (C) 2013-2020 Intan Technologies
//
//  ------------------------------------------------------------------------
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published
//  by the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <QApplication>
#include <QMessageBox>
#include <QStyleFactory>

#include "mainwindow.h"

// Starts application main window.

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    #if defined(__APPLE__)
    app.setStyle(QStyleFactory::create("Fusion"));
    #elif QT_VERSION >= QT_VERSION_CHECK(6,5,0)
    #if defined(Q_OS_WIN)
    if (QSysInfo::productVersion().toInt() > 10) {
        app.setStyle(QStyleFactory::create("Fusion"));
    }
    #endif
    #endif

    MainWindow mainWin;
    mainWin.show();

    return app.exec();
}
