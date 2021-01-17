

#ifndef ZCPLPLOTLOGGER_H
#define ZCPLPLOTLOGGER_H

class ZSOFT_NO_VTABLE ZcPlPlotLogger
{
public:

    ZcPlPlotLogger(){};
    virtual ~ZcPlPlotLogger(){};

    virtual Zcad::ErrorStatus startJob(void) = 0;

    virtual Zcad::ErrorStatus startSheet(void) = 0;

    virtual Zcad::ErrorStatus logTerminalError(const ZTCHAR *pErrorString) = 0;

    virtual Zcad::ErrorStatus logARIError(const ZTCHAR *pErrorString) = 0;

    virtual Zcad::ErrorStatus logSevereError(const ZTCHAR *pErrorString) = 0;

    virtual Zcad::ErrorStatus logError(const ZTCHAR *pErrorString) = 0;

    virtual Zcad::ErrorStatus logWarning(const ZTCHAR *pWarningString) = 0;

    virtual Zcad::ErrorStatus logMessage(const ZTCHAR *pMessageString) = 0;

    virtual Zcad::ErrorStatus logInformation(const ZTCHAR *pMessageString) = 0;

    virtual Zcad::ErrorStatus endSheet(void) = 0;

    virtual bool errorHasHappenedInSheet(void) const = 0;

    virtual bool warningHasHappenedInSheet(void) const = 0;

    virtual Zcad::ErrorStatus endJob(void) = 0;

    virtual bool errorHasHappenedInJob(void) const = 0;

    virtual bool warningHasHappenedInJob(void) const = 0;
};

#endif 
