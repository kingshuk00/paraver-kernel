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

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- *\
 | @file: $HeadURL$
 | @last_commit: $Date$
 | @version:     $Revision$
\* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

#ifndef KTRACESHIFTER_H_INCLUDED
#define KTRACESHIFTER_H_INCLUDED

#include <string>
#include <vector>

#include "traceshifter.h"
#include "traceeditsequence.h"
#include "paraverkerneltypes.h"
#include "progresscontroller.h"


class KTraceShifter : public TraceShifter
{
  public:
    KTraceShifter( const KernelConnection *myKernel,
                   std::string traceIn,
                   std::string traceOut,
                   std::string whichShiftTimes,
                   TWindowLevel shiftLevel,
                   ProgressController *progress = NULL );
    ~KTraceShifter();

    virtual void execute( std::string traceIn,
                          std::string traceOut,
                          ProgressController *progress = NULL );

    virtual const std::vector< TTime > getShiftTimes() { return shiftTimes; }

  private:
    std::vector< TTime > shiftTimes;
    TraceEditSequence *mySequence;

    std::vector<std::string> traces;

    std::vector< TTime > readShiftTimes( std::string shiftTimesFile );

};

#endif // KTRACESHIFTER_H_INCLUDED
