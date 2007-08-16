#include "kwindow.h"

KSingleWindow::KSingleWindow( Trace *whichTrace ): KWindow( whichTrace )
{
  if ( myTrace->totalThreads() > myTrace->totalCPUs() )
  {
    recordsByTime.reserve( myTrace->totalThreads() );
    for ( TThreadOrder i = 0; i < myTrace->totalThreads(); i++ )
      recordsByTime.push_back( NULL );
  }
  else
  {
    recordsByTime.reserve( myTrace->totalCPUs() );
    for ( TCPUOrder i = 0; i < myTrace->totalCPUs(); i++ )
      recordsByTime.push_back( NULL );
  }

  intervalThread.reserve( myTrace->totalThreads() );
  for ( TThreadOrder i = 0; i < myTrace->totalThreads(); i++ )
    intervalThread.push_back( IntervalThread( this, i ) );
}


RecordList *KSingleWindow::init( TRecordTime initialTime, TCreateList create )
{
  if ( level >= SYSTEM )
  {
    if ( initialTime > 0 )
      myTrace->getRecordByTimeCPU( recordsByTime, initialTime );
    else
    {
      for ( TCPUOrder i = 0; i < myTrace->totalCPUs(); i++ )
      {
        if ( recordsByTime[ i ] != NULL )
          delete recordsByTime[ i ];
        recordsByTime[ i ] = myTrace->CPUBegin( i );
      }
    }
  }
  else
  {
    if ( initialTime > 0 )
      myTrace->getRecordByTimeThread( recordsByTime, initialTime );
    else
    {
      for ( TThreadOrder i = 0; i < myTrace->totalThreads(); i++ )
      {
        if ( recordsByTime[ i ] != NULL )
          delete recordsByTime[ i ];
        recordsByTime[ i ] = myTrace->threadBegin( i );
      }
    }
  }

  // Se debe sustituir intervalThread por el top compose
  for ( TThreadOrder i = 0; i < intervalThread.size(); i++ )
    intervalThread[ i ].init( initialTime, create );

  return NULL;
}


void KSingleWindow::setLevelFunction( TWindowLevel whichLevel,
                                      SemanticFunction *whichFunction )
{
  if( whichLevel == THREAD )
  {
    for( TThreadOrder i = 0; i < intervalThread.size(); i++ )
      intervalThread[ i ].setSemanticFunction( (SemanticThread *)whichFunction );
  }
}


RecordList *KSingleWindow::calcNext( TObjectOrder whichObject )
{
  // Se debe sustituir intervalThread por el top compose
  return intervalThread[ whichObject ].calcNext();
}


RecordList *KSingleWindow::calcPrev( TObjectOrder whichObject )
{
  // Se debe sustituir intervalThread por el top compose
  return intervalThread[ whichObject ].calcPrev();
}


TRecordTime KSingleWindow::getBeginTime( TObjectOrder whichObject ) const
{
  // Se debe sustituir intervalThread por el top compose
  return intervalThread[ whichObject ].getBeginTime();
}


TRecordTime KSingleWindow::getEndTime( TObjectOrder whichObject ) const
{
  // Se debe sustituir intervalThread por el top compose
  return intervalThread[ whichObject ].getEndTime();
}


TSemanticValue KSingleWindow::getValue( TObjectOrder whichObject ) const
{
  // Se debe sustituir intervalThread por el top compose
  return intervalThread[ whichObject ].getValue();
}