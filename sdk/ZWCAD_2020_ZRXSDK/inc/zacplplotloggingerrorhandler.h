

#ifndef ZCPLPLOTLOGGINGERRORHANDLER_H
#define ZCPLPLOTLOGGINGERRORHANDLER_H

class ZcPlPlotLogger;
class ZcPlSystenInternals;

class ZcPlPlotLoggingErrorHandler : public ZcPlPlotErrorHandler
{
public:
    ZCPL_PORT ZcPlPlotLoggingErrorHandler();
    ZCPL_PORT ZcPlPlotLoggingErrorHandler(ZcPlPlotLogger *);
    ZCPL_PORT virtual ~ZcPlPlotLoggingErrorHandler();

    ZCPL_DECLARE_MEMBERS(ZcPlPlotLoggingErrorHandler);

public:

    ZCPL_PORT virtual void infoMessage(const ZTCHAR *pMessage);

    ZCPL_PORT virtual int messageBox(const ZTCHAR *pText,
                                     const ZTCHAR *pCaption,
                                     unsigned int uType, 
                                     int defaultReturn);

    ZCPL_PORT virtual void info(ULONG_PTR category,
                                const unsigned int specific,
                                const ZTCHAR *pLocation,
                                const ZTCHAR *pContextData,
                                const ZTCHAR *pRevision);

    ZCPL_PORT virtual ErrorResult warning(ULONG_PTR category,
                                          const unsigned int specific,
                                          const ZTCHAR *pLocation,
                                          const ZTCHAR *pContextData,
                                          const ZTCHAR *pRevision);

    ZCPL_PORT virtual void severeError(ULONG_PTR category,
                                       const unsigned int specific, 
                                       const ZTCHAR *pLocation,
                                       const ZTCHAR *pContextData,
                                       const ZTCHAR *pRevision);

    ZCPL_PORT virtual ErrorResult error(ULONG_PTR category,
                                        const unsigned int specific, 
                                        const ZTCHAR *pLocation,
                                        const ZTCHAR *pContextData,
                                        const ZTCHAR *pRevision);

    ZCPL_PORT virtual ErrorResult ariError(ULONG_PTR category,
                                           const unsigned int specific,
                                           const ZTCHAR *pLocation,
                                           const ZTCHAR *pContextData,
                                           const ZTCHAR *pRevision);

    ZCPL_PORT virtual void terminalError(ULONG_PTR category,
                                         const unsigned int specific,
                                         const ZTCHAR *pLocation,
                                         const ZTCHAR *pContextData,
                                         const ZTCHAR *pRevision);

    ZCPL_PORT virtual void logMessage(const ZTCHAR *pTitle, const ZTCHAR *pMsg);

};

#endif 
