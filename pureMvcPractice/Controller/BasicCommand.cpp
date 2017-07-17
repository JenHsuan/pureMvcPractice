#include "BasicCommand.h"
#include "../Facade/ApplicationFacade.h"
#include "../View/MainWindow.h"
#include "../View/MainWindowMediator.h"
//#include "MainProxy.h"

MainProxy* BasicCommand::getMainProxy()
{
    return ApplicationFacade::GetMainProxy();
}

MainWindow* BasicCommand::getMainWindow()
{
    return MainWindowMediator::GetMainWindow();
}
