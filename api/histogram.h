#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED

#include "paraverkerneltypes.h"

class KernelConnection;
class KHistogramTotals;
class HistogramStatistic;
class Window;

class Histogram
{
  public:
    static Histogram *create( KernelConnection *whichKernel );

    Histogram() {}
    Histogram( KernelConnection *whichKernel );
    virtual ~Histogram() {}

    virtual bool getThreeDimensions() const = 0;

    virtual TRecordTime getBeginTime() const = 0;
    virtual TRecordTime getEndTime() const = 0;

    virtual Window *getControlWindow() const = 0;
    virtual Window *getDataWindow() const = 0;
    virtual Window *getExtraControlWindow() const = 0;
    virtual void setControlWindow( Window *whichWindow ) = 0;
    virtual void setDataWindow( Window *whichWindow ) = 0;
    virtual void setExtraControlWindow( Window *whichWindow ) = 0;
    virtual void clearControlWindow() = 0;
    virtual void clearDataWindow() = 0;
    virtual void clearExtraControlWindow() = 0;

    virtual void setControlMin( THistogramLimit whichMin ) = 0;
    virtual void setControlMax( THistogramLimit whichMax ) = 0;
    virtual void setControlDelta( THistogramLimit whichDelta ) = 0;
    virtual void setExtraControlMin( THistogramLimit whichMin ) = 0;
    virtual void setExtraControlMax( THistogramLimit whichMax ) = 0;
    virtual void setExtraControlDelta( THistogramLimit whichDelta ) = 0;
    virtual void setDataMin( THistogramLimit whichMin ) = 0;
    virtual void setDataMax( THistogramLimit whichMax ) = 0;

    virtual THistogramLimit getControlMin() const = 0;
    virtual THistogramLimit getControlMax() const = 0;
    virtual THistogramLimit getControlDelta() const = 0;
    virtual THistogramLimit getExtraControlMin() const = 0;
    virtual THistogramLimit getExtraControlMax() const = 0;
    virtual THistogramLimit getExtraControlDelta() const = 0;
    virtual THistogramLimit getDataMin() const = 0;
    virtual THistogramLimit getDataMax() const = 0;

    virtual void setInclusive( bool newValue ) = 0;

    virtual THistogramColumn getNumPlanes() const = 0;
    virtual THistogramColumn getNumColumns() const = 0;
    virtual TObjectOrder getNumRows() const = 0;

    virtual TSemanticValue getCurrentValue( UINT32 col,
                                            UINT16 idStat,
                                            UINT32 plane = 0 ) const = 0;
    virtual UINT32 getCurrentRow( UINT32 col, UINT32 plane = 0 ) const = 0;
    virtual void setNextCell( UINT32 col, UINT32 plane = 0 ) = 0;
    virtual void setFirstCell( UINT32 col, UINT32 plane = 0 ) = 0;
    virtual bool endCell( UINT32 col, UINT32 plane = 0 ) = 0;
    virtual bool planeWithValues( UINT32 plane = 0 ) const = 0;

    virtual TSemanticValue getCommCurrentValue( UINT32 col,
        UINT16 idStat,
        UINT32 plane = 0 ) const = 0;
    virtual UINT32 getCommCurrentRow( UINT32 col, UINT32 plane = 0 ) const = 0;
    virtual void setCommNextCell( UINT32 col, UINT32 plane = 0 ) = 0;
    virtual void setCommFirstCell( UINT32 col, UINT32 plane = 0 ) = 0;
    virtual bool endCommCell( UINT32 col, UINT32 plane = 0 ) = 0;
    virtual bool planeCommWithValues( UINT32 plane = 0 ) const = 0;

    virtual KHistogramTotals *getColumnTotals() const = 0;
    virtual KHistogramTotals *getCommColumnTotals() const = 0;
    virtual KHistogramTotals *getRowTotals() const = 0;
    virtual KHistogramTotals *getCommRowTotals() const = 0;

    virtual void clearStatistics() = 0;
    virtual void pushbackStatistic( HistogramStatistic *whichStatistic ) = 0;

    virtual void execute( TRecordTime whichBeginTime, TRecordTime whichEndTime ) = 0;

    // Specific methods of HistogramProxy
    virtual void setHorizontal( bool horiz ) {};
    virtual bool getHorizontal() const { return true; };
    virtual void setHideColumns( bool hide ) {};
    virtual bool getHideColumns() const { return true; };

  protected:
    KernelConnection *myKernel;
};


class HistogramProxy : public Histogram
{
  public:
    HistogramProxy() {}
    HistogramProxy( KernelConnection *whichKernel );
    virtual ~HistogramProxy();

    virtual bool getThreeDimensions() const;
    virtual TRecordTime getBeginTime() const;
    virtual TRecordTime getEndTime() const;
    virtual Window *getControlWindow() const;
    virtual Window *getDataWindow() const;
    virtual Window *getExtraControlWindow() const;
    virtual void setControlWindow( Window *whichWindow );
    virtual void setDataWindow( Window *whichWindow );
    virtual void setExtraControlWindow( Window *whichWindow );
    virtual void clearControlWindow();
    virtual void clearDataWindow();
    virtual void clearExtraControlWindow();
    virtual void setControlMin( THistogramLimit whichMin );
    virtual void setControlMax( THistogramLimit whichMax );
    virtual void setControlDelta( THistogramLimit whichDelta );
    virtual void setExtraControlMin( THistogramLimit whichMin );
    virtual void setExtraControlMax( THistogramLimit whichMax );
    virtual void setExtraControlDelta( THistogramLimit whichDelta );
    virtual void setDataMin( THistogramLimit whichMin );
    virtual void setDataMax( THistogramLimit whichMax );
    virtual THistogramLimit getControlMin() const;
    virtual THistogramLimit getControlMax() const;
    virtual THistogramLimit getControlDelta() const;
    virtual THistogramLimit getExtraControlMin() const;
    virtual THistogramLimit getExtraControlMax() const;
    virtual THistogramLimit getExtraControlDelta() const;
    virtual THistogramLimit getDataMin() const;
    virtual THistogramLimit getDataMax() const;
    virtual void setInclusive( bool newValue );
    virtual THistogramColumn getNumPlanes() const;
    virtual THistogramColumn getNumColumns() const;
    virtual TObjectOrder getNumRows() const;
    virtual TSemanticValue getCurrentValue( UINT32 col,
                                            UINT16 idStat,
                                            UINT32 plane = 0 ) const;
    virtual UINT32 getCurrentRow( UINT32 col, UINT32 plane = 0 ) const;
    virtual void setNextCell( UINT32 col, UINT32 plane = 0 );
    virtual void setFirstCell( UINT32 col, UINT32 plane = 0 );
    virtual bool endCell( UINT32 col, UINT32 plane = 0 );
    virtual bool planeWithValues( UINT32 plane = 0 ) const;
    virtual TSemanticValue getCommCurrentValue( UINT32 col,
        UINT16 idStat,
        UINT32 plane = 0 ) const;
    virtual UINT32 getCommCurrentRow( UINT32 col, UINT32 plane = 0 ) const;
    virtual void setCommNextCell( UINT32 col, UINT32 plane = 0 );
    virtual void setCommFirstCell( UINT32 col, UINT32 plane = 0 );
    virtual bool endCommCell( UINT32 col, UINT32 plane = 0 );
    virtual bool planeCommWithValues( UINT32 plane = 0 ) const;
    virtual KHistogramTotals *getColumnTotals() const;
    virtual KHistogramTotals *getCommColumnTotals() const;
    virtual KHistogramTotals *getRowTotals() const;
    virtual KHistogramTotals *getCommRowTotals() const;
    virtual void clearStatistics();
    virtual void pushbackStatistic( HistogramStatistic *whichStatistic );
    virtual void execute( TRecordTime whichBeginTime, TRecordTime whichEndTime );

    virtual void setHorizontal( bool horiz );
    virtual bool getHorizontal() const;
    virtual void setHideColumns( bool hide );
    virtual bool getHideColumns() const;

  private:
    bool horizontal;
    bool hideColumns;
};


#endif // HISTOGRAM_H_INCLUDED
