

#ifndef ZCPLPLOTERRORHANDLER_H
#define ZCPLPLOTERRORHANDLER_H

#include "zacplobject.h"

class ZcPlSystemInternals;

class ZcPlPlotErrorHandler : public ZcPlObject
{
public:
    enum ErrorResult {
        kAbort,
        kRetry,
        kIgnore
    };
    enum Handler {
        kInfo,
        kWarning,
        kError,
        kARI,
        kSevere,
        kTerminal,
        kNone 
    };

    ZCPL_PORT ZcPlPlotErrorHandler();
    ZCPL_PORT ~ZcPlPlotErrorHandler();

    ZCPL_DECLARE_MEMBERS(ZcPlPlotErrorHandler);

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

    ZCPL_PORT virtual bool takeResponsibility(Handler kind) ;

    ZCPL_PORT virtual bool setLogHandle(const ZTCHAR *pFilePathName) ;

    ZCPL_PORT virtual void setQuietMode(bool bQuiet);

    ZCPL_PORT virtual void setLogMode(bool bLog);

    ZCPL_PORT virtual bool quietMode() const;

    ZCPL_PORT virtual bool logMode() const;

    ZCPL_PORT void getProductString(ZTCHAR*& pProductString) const;
    ZCPL_PORT void getProgramString(ZTCHAR*& pProgramString) const;
    ZCPL_PORT void getCompanyString(ZTCHAR*& pCompanyString) const;

    ZCPL_PORT virtual const ZTCHAR* warningTitle() const;
    ZCPL_PORT virtual const ZTCHAR* severeTitle() const;
    ZCPL_PORT virtual const ZTCHAR* errorTitle() const;
    ZCPL_PORT virtual const ZTCHAR* ariTitle() const;
    ZCPL_PORT virtual const ZTCHAR* terminalTitle() const;
    ZCPL_PORT virtual const ZTCHAR* infoTitle() const;

protected:

    ZCPL_PORT void appInfoMessage(const ZTCHAR *pMessage);

    ZCPL_PORT int appMessageBox(const ZTCHAR *pText,
                                const ZTCHAR *pCaption,
                                unsigned int uType, 
                                int defaultReturn);

    ZCPL_PORT void appInfo(ULONG_PTR category,
                           const unsigned int specific,
                           const ZTCHAR *pLocation,
                           const ZTCHAR *pContextData,
                           const ZTCHAR *pRevision);

    ZCPL_PORT ErrorResult appWarning(ULONG_PTR category,
                                     const unsigned int specific,
                                     const ZTCHAR *pLocation,
                                     const ZTCHAR *pContextData,
                                     const ZTCHAR *pRevision);

    ZCPL_PORT void appSevereError(ULONG_PTR category,
                                  const unsigned int specific,
                                  const ZTCHAR *pLocation,
                                  const ZTCHAR *pContextData,
                                  const ZTCHAR *pRevision);

    ZCPL_PORT ErrorResult appError(ULONG_PTR category,
                                   const unsigned int specific,
                                   const ZTCHAR *pLocation,
                                   const ZTCHAR *pContextData,
                                   const ZTCHAR *pRevision);

    ZCPL_PORT ErrorResult appARIError(ULONG_PTR category,
                                      const unsigned int specific,
                                      const ZTCHAR *pLocation,
                                      const ZTCHAR *pContextData,
                                      const ZTCHAR *pRevision);

    ZCPL_PORT void appTerminalError(ULONG_PTR category,
                                    const unsigned int specific,
                                    const ZTCHAR *pLocation,
                                    const ZTCHAR *pContextData,
                                    const ZTCHAR *pRevision);

    ZCPL_PORT void appLogMessage(const ZTCHAR *pTitle, const ZTCHAR *pMsg);

    ZCPL_PORT bool appSetLogHandle(const ZTCHAR *pFilePathName);
};

#endif 
