/*****************************************************************************\
 *                        ANALYSIS PERFORMANCE TOOLS                         *
 *                               libparaver-api                              *
 *                       Paraver Main Computing Library                      *
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

#include <unordered_set>
#include <fstream>

template< class    TraceStreamT,
          class    RecordContainerT,
          class    ProcessModelT,
          class    ResourceModelT,
          typename StateT,
          typename EventTypeT,
          class    MetadataManagerT,
          typename RecordTimeT,
          class    RecordT>
class TraceBodyIO
{
  public:
    TraceBodyIO() = default;
    virtual ~TraceBodyIO() = default;

    virtual bool ordered() const = 0;
    virtual void read( TraceStreamT& file,
                       RecordContainerT& records,
                       const ProcessModelT& whichProcessModel,
                       const ResourceModelT& whichResourceModel,
                       std::unordered_set<StateT>& states,
                       std::unordered_set<EventTypeT>& events,
                       MetadataManagerT& traceInfo,
                       RecordTimeT& endTime ) const = 0;
    virtual void write( std::fstream& whichStream,
                        const ProcessModelT& whichProcessModel,
                        const ResourceModelT& whichResourceModel,
                        RecordT *record ) const = 0;

  protected:

};


