#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include "paraverkerneltypes.h"

class KernelConnection;
class RecordList;
class SemanticFunction;
class Trace;
class Filter;

class Window
{
  public:
    // Create Single Window
    static Window *create( KernelConnection *whichKernel, Trace *whichTrace );
    //Create Derived Window
    static Window *create( KernelConnection *whichKernel );
    static Window *create( KernelConnection *whichKernel, Window *parent1, Window *parent2 );

    Window() {}
    Window( KernelConnection *whichKernel );
    virtual ~Window() {}

    // Specefic for WindowProxy because Single and Derived window
    // SingleWindow
    virtual Filter *getFilter() const = 0;

    //DerivedWindow
    virtual void setFactor( UINT16 whichFactor, TSemanticValue newValue ) = 0;
    virtual void setParent( UINT16 whichParent, Window *whichWindow ) = 0;

    //------------------------------------------------------------
    virtual Trace *getTrace() const = 0;
    virtual TWindowLevel getLevel() const = 0;
    virtual void setLevel( TWindowLevel whichLevel ) = 0;
    virtual void setTimeUnit( TTimeUnit whichUnit ) = 0;
    virtual TTimeUnit getTimeUnit() = 0;
    virtual TWindowLevel getComposeLevel( TWindowLevel whichLevel ) const = 0;
    virtual bool setLevelFunction( TWindowLevel whichLevel,
                                   SemanticFunction *whichFunction ) = 0;
    virtual SemanticFunction *getLevelFunction( TWindowLevel whichLevel ) = 0;
    virtual SemanticFunction *getFirstUsefulFunction( ) = 0;
    virtual void setFunctionParam( TWindowLevel whichLevel,
                                   TParamIndex whichParam,
                                   const TParamValue& newValue ) = 0;
    virtual RecordList *getRecordList( TObjectOrder whichObject ) = 0;
    virtual RecordList *init( TRecordTime initialTime, TCreateList create ) = 0;
    virtual RecordList *calcNext( TObjectOrder whichObject ) = 0;
    virtual RecordList *calcPrev( TObjectOrder whichObject ) = 0;
    virtual TRecordTime getBeginTime( TObjectOrder whichObject ) const = 0;
    virtual TRecordTime getEndTime( TObjectOrder whichObject ) const = 0;
    virtual TSemanticValue getValue( TObjectOrder whichObject ) const = 0;
    virtual bool isDerivedWindow() const = 0;
    virtual TObjectOrder cpuObjectToWindowObject( TCPUOrder whichCPU ) = 0;
    virtual TObjectOrder threadObjectToWindowObject( TThreadOrder whichThread ) = 0;
    virtual TObjectOrder getWindowLevelObjects() = 0;
    virtual TRecordTime traceUnitsToWindowUnits( TRecordTime whichTime ) = 0;

    virtual Window *getConcrete() const
    {
      return NULL;
    }

  protected:
    KernelConnection *myKernel;

};


class WindowProxy: public Window
{
  public:
    virtual ~WindowProxy();

    // Specefic for WindowProxy because Single and Derived window
    // SingleWindow
    virtual Filter *getFilter() const;

    //DerivedWindow
    virtual void setFactor( UINT16 whichFactor, TSemanticValue newValue );
    virtual void setParent( UINT16 whichParent, Window *whichWindow );

    //------------------------------------------------------------
    virtual Trace *getTrace() const;
    virtual TWindowLevel getLevel() const;
    virtual void setLevel( TWindowLevel whichLevel );
    virtual void setTimeUnit( TTimeUnit whichUnit );
    virtual TTimeUnit getTimeUnit();
    virtual TWindowLevel getComposeLevel( TWindowLevel whichLevel ) const;
    virtual bool setLevelFunction( TWindowLevel whichLevel,
                                   SemanticFunction *whichFunction );
    virtual SemanticFunction *getLevelFunction( TWindowLevel whichLevel );
    virtual SemanticFunction *getFirstUsefulFunction( );
    virtual void setFunctionParam( TWindowLevel whichLevel,
                                   TParamIndex whichParam,
                                   const TParamValue& newValue );
    virtual RecordList *getRecordList( TObjectOrder whichObject );
    virtual RecordList *init( TRecordTime initialTime, TCreateList create );
    virtual RecordList *calcNext( TObjectOrder whichObject );
    virtual RecordList *calcPrev( TObjectOrder whichObject );
    virtual TRecordTime getBeginTime( TObjectOrder whichObject ) const;
    virtual TRecordTime getEndTime( TObjectOrder whichObject ) const;
    virtual TSemanticValue getValue( TObjectOrder whichObject ) const;
    virtual bool isDerivedWindow() const;
    virtual TObjectOrder cpuObjectToWindowObject( TCPUOrder whichCPU );
    virtual TObjectOrder threadObjectToWindowObject( TThreadOrder whichThread );
    virtual TObjectOrder getWindowLevelObjects();
    virtual TRecordTime traceUnitsToWindowUnits( TRecordTime whichTime );

    virtual Window *getConcrete() const;

  private:
    Window *myWindow;

    // For Single Window
    WindowProxy( KernelConnection *whichKernel, Trace *whichTrace );
    // For Derived Window
    WindowProxy( KernelConnection *whichKernel );
    WindowProxy( KernelConnection *whichKernel, Window *parent1, Window *parent2 );

    friend Window *Window::create( KernelConnection *, Trace * );
    friend Window *Window::create( KernelConnection * );
    friend Window *Window::create( KernelConnection *, Window *, Window * );
};

#endif // WINDOW_H_INCLUDED
