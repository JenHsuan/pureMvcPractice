#include "MainWindowMediator.h"
#include "MainWindow.h"
#include "../Proxy/MainProxy.h"
#include "../Facade/ApplicationFacade.h"
#include "../Model/GenericFunction.h"

const std::string MainWindowMediator::NAME = "MainWindowMediator";


MainWindowMediator::MainWindowMediator(const void* aViewComponent)
    : Mediator(NAME, aViewComponent)
{
    MainWindow* window = getMainWindow();
	window->onPlusSender += new MainWindow::onPlusArgEvent::T<MainWindowMediator>(this, &MainWindowMediator::OnValueChange);
    
}

void MainWindowMediator::handleNotification(INotification const& aNotification)
{
    std::string noteName = aNotification.getName();
}

MainWindow* MainWindowMediator::getMainWindow()
{
    MainWindow* frame = GenericFunction::ConvertToNonConstType<MainWindow>(getViewComponent());
    return frame;
}

MainProxy* MainWindowMediator::getMainProxy()
{
    MainProxy& mainProxy = dynamic_cast<MainProxy&>(ApplicationFacade::RetrieveProxy(MainProxy::NAME));
    return &mainProxy;
}
MainWindow* MainWindowMediator::GetMainWindow()
{
    IMediator& mediator = ApplicationFacade::RetrieveMediator(MainWindowMediator::NAME);
    MainWindowMediator& mainWindowMediator = dynamic_cast<MainWindowMediator&>(mediator);

    const void* viewComponent = mainWindowMediator.getViewComponent();
    MainWindow* mainWindow = static_cast<MainWindow*>(const_cast<void*>(viewComponent));
    return mainWindow;
}
void MainWindowMediator::OnValueChange(int value){
	ApplicationFacade::SendNotification(ApplicationFacade::VALUE_CHANGE, &value);
}