
#pragma once

struct ZcGsRenderStatistics
{
public:
    float fRenderTime;
    size_t iMemory;
    size_t iMaterialCount;
    size_t iLightCount;
    size_t iTriangleCount;
};

class ZcGsRenderProgressMonitor
{
public:
    enum Phase
    {
        kTranslation,
        kPhotonEmission,
        kFinalGather,
        kRender
    };
	enum RenderingStatus
	{
		kRendering,
		kPaused,
		kFinished,
		kAborted,
		kWillNotRender,
		kSoftOutOfMemory,
		kHardOutOfMemory,
		kError,
	};
	virtual ~ZcGsRenderProgressMonitor() { }
    virtual bool OnProgress(Phase ePhase, float fProgress,
		int iRenderTimeSpent,
		int iCurrentRenderLevel,
		float fCurrentLevelProgress,
		int iTileIndex = 0) = 0;
    virtual void OnTile(int x, int y, int w, int h, const BYTE* pPixels) = 0;
	virtual void OnStatusChanged(RenderingStatus status) = 0;
    virtual void SetStatistics(const ZcGsRenderStatistics* pStats) = 0;
    virtual bool ShouldReuseDatabase() { return false; }
	virtual bool IsValid() { return true; }
	virtual bool IsAsync() { return false; }
	virtual bool IsOutputImageFlipped() { return false; }
};
