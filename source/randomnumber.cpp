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

#include <QTime>
#include <qmath.h>

#include "randomnumber.h"

// Generates random numbers from both uniform and Gaussian distrubtions

RandomNumber::RandomNumber()
{
    // Seed random number generator.
    QTime time = QTime::currentTime();
    #if QT_VERSION < QT_VERSION_CHECK(6,0,0)
    qsrand((uint) time.msec());
    #else
    prng.seed((uint) time.msec());
    #endif

    // Initialize parameters for Gaussian distribution approximator.
    setGaussianAccuracy(6);
}

// Returns a random number from a uniform distribution between 0.0 and 1.0.
double RandomNumber::randomUniform()
{
    #if QT_VERSION < QT_VERSION_CHECK(6,0,0)
    return ((double)qrand() / (double)RAND_MAX);
    #else
    return ((double)prng.generate() / (double)RAND_MAX);
    #endif
}

// Returns a random number from a uniform distribution between min and max.
double RandomNumber::randomUniform(double min, double max)
{
    #if QT_VERSION < QT_VERSION_CHECK(6,0,0)
    return (((double)qrand() / (double)RAND_MAX) * (max - min) + min);
    #else
    return (((double)prng.generate() / (double)RAND_MAX) * (max - min) + min);
    #endif
}

// Returns a random number from a Gaussian distribution with variance = 1.0.
// This function relies on the central limit theorem to approximate a normal
// distribution.  Increasing gaussianN will improve accuracy at the expense of
// speed.  A value of 6 is adequate for most applications.
double RandomNumber::randomGaussian()
{
    double r = 0.0;
    for (int i = 0; i < gaussianN; ++i) {
        r += randomUniform(-1.0, 1.0);
    }
    r *= gaussianScaleFactor;
    return r;
}

// Making n larger increases accuracy of Gaussian approximation at the expense of speed.
void RandomNumber::setGaussianAccuracy(int n)
{
    gaussianN = n;
    gaussianScaleFactor = qSqrt(3.0) / qSqrt(gaussianN);  // precalculate this for speed
}
