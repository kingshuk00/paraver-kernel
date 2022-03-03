/*****************************************************************************\
 *                        ANALYSIS PERFORMANCE TOOLS                         *
 *                               libparaver-api                              *
 *                      API Library for libparaver-kernel                    *
 *****************************************************************************
 *     ___     This library is free software; you can redistribute it and/or *
 *    /  __         modify it under the terms of the GNU LGPL as published   *
 *   /  /  _____    by the Free Software Foundation; either version 2.1      *
 *  /  /  /     \   of the License, or (at your option) any later version.   *
 * (  (  ( B S C )                                                           *
 *  \  \  \_____/   This library is distributed in hope that it will be      *
 *   \  \__         useful but WITHOUT ANY WARRANTY; without even the        *
 *    \___          implied warranty of MERCHANTABILITY or FITNESS FOR A     *
 *                  PARTICULAR PURPOSE. See the GNU LGPL for more details.   *
 *                                                                           *
 * You should have received a copy of the GNU Lesser General Public License  *
 * along with this library; if not, write to the Free Software Foundation,   *
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA          *
 * The GNU LEsser General Public License is contained in the file COPYING.   *
 *                                 ---------                                 *
 *   Barcelona Supercomputing Center - Centro Nacional de Supercomputacion   *
\*****************************************************************************/


#pragma once


#include <string>
#include <vector>
#include <map>
#include "paraverkerneltypes.h"

template< typename dummy = nullptr_t >
class RowLabels
{
  public:
    RowLabels() = default;
    RowLabels( const std::string& filename );
    ~RowLabels() = default;

    void dumpToFile( const std::string& filename ) const;

    std::string getRowLabel( TWindowLevel whichLevel, TObjectOrder whichRow ) const;
    void pushBack( TWindowLevel whichLevel, const std::string& rowLabel );

    // whichLevel == NONE (by default) ==> all levels MaxLength
    size_t getMaxLength( TWindowLevel whichLevel = NONE ) const;

  protected:

  private:
    // tuple elements are: level name, max length, level objects labels
    std::map<TWindowLevel, std::tuple< std::string, size_t, std::vector<std::string> > > levelLabels;

    size_t globalMaxLength;

    void dumpLevel( const std::tuple< std::string, size_t, std::vector<std::string> >& whichLevel, std::ofstream& whichFile ) const;
};

#include "rowlabels.cpp"
