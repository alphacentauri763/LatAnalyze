/*
 * Histogram.hpp, part of LatAnalyze 3
 *
 * Copyright (C) 2013 - 2015 Antonin Portelli
 *
 * LatAnalyze 3 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * LatAnalyze 3 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LatAnalyze 3.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef Latan_Histogram_hpp_
#define Latan_Histogram_hpp_

#include <LatAnalyze/Global.hpp>
#include <gsl/gsl_histogram.h>
#include <gsl/gsl_cdf.h>

BEGIN_LATAN_NAMESPACE

/******************************************************************************
 *                          Histogram class                                   *
 ******************************************************************************/
class Histogram
{
public:
    // constructor
    Histogram(void) = default;
    Histogram(const DVec &data, const double xMin, const double xMax,
              const Index nBin);
    Histogram(const DVec &data, const DVec &w, const double xMin,
              const double xMax, const Index nBin);
    // destructor
    virtual ~Histogram(void) = default;
    // generate from data
    void setFromData(const DVec &data, const double xMin, const double xMax,
                     const Index nBin);
    void setFromData(const DVec &data, const DVec &w, const double xMin,
                     const double xMax, const Index nBin);
    // normalize as a probablility
    void normalize(const bool n = true);
    bool isNormalized(void) const;
    // access
    Index  size(void) const;
    double getX(const Index i) const;
    double operator[](const Index i) const;
    double operator()(const double x) const;
private:
    // resize
    void resize(const Index nBin);
    // compute normalization factor
    void computeNorm(void);
private:
    DVec          x_, bin_;
    double        total_, norm_, xMax_, xMin_;
    bool          normalize_{false};
};

END_LATAN_NAMESPACE

#endif // Latan_Histogram_hpp_
