#ifndef REFRESHWINDOWCOMMAND_H
#define REFRESHWINDOWCOMMAND_H

#include "BasicCommand.h"

//class MainWindow;

class RefreshWindowCommand : public BasicCommand
{
public:
    void execute(const INotification& aNotification) override;
    static std::string GetCommandName(void);

private:
    /*void registerPropertyWindowMediator(MainWindow* aMainWindow);
    void registerView2DWindowMediator(View2DWindow* aView2DWindow);
    void registerStreetViewFor2DMediator(StreetViewFor2D* aStreetViewFor2D);
    void registerOSGCanvasMediator(OSGCanvas* aOsgCanvas);
    void registerTabCtrlMediator(TabCtrlPanel* aTabCtrl);
    void registerRemarkWindowMediator(RemarkWindow* aRemarkWindow);
    void registerEngineerTestMediator(EngineerTestDlg* aEngineerTestDlg);
    void registerStatisticsWindowMediator(MainWindow* aMainWindow);*/
};

#endif