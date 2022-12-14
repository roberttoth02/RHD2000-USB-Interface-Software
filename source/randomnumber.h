//  ------------------------------------------------------------------------
//
//  This file is part of the Intan Technologies RHD2000 Interface
//  Version 1.5.4
//  Copyright (C) 2013-2020 Intan Technologies
//
//  ------------------------------------------------------------------------
//
//  Edited for Qt6 compatibility
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

#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H

#include <QtGlobal>

#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
#include <QRandomGenerator>
#endif

class RandomNumber
{
public:
    RandomNumber();
    double randomUniform();
    double randomUniform(double min, double max);
    double randomGaussian();
    void setGaussianAccuracy(int n);

private:
    int gaussianN;
    double gaussianScaleFactor;
    #if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
    QRandomGenerator prng;
    #endif
};

#endif // RANDOMNUMBER_H
