#ifndef HDR_INFO_VIEWER_H_
#define HDR_INFO_VIEWER_H_


#include <QListWidget>
#include <QShowEvent>

#include <HevcParser.h>

class HDRInfoViewer:
  public QListWidget,
  public HEVC::Parser::Consumer
{
  public:
    HDRInfoViewer(QWidget *pwgt = NULL);

    void clear();

    virtual void onNALUnit(std::shared_ptr<HEVC::NALUnit> pNALUnit, const HEVC::Parser::Info *pInfo);
    virtual void onWarning(const std::string &warning, const HEVC::Parser::Info *pInfo, HEVC::Parser::WarningType);

  protected:
    virtual void showEvent(QShowEvent* pevent);
  private:
    void update();

    void readCustomData();
    void saveCustomData();

    virtual void closeEvent(QCloseEvent* pevent);

    std::shared_ptr<HEVC::SPS>                      m_psps;
    std::shared_ptr<HEVC::MasteringDisplayInfo>     m_pMasteringDisplayInfo;
    std::shared_ptr<HEVC::ContentLightLevelInfo>    m_pCLLInfo;
};


#endif
