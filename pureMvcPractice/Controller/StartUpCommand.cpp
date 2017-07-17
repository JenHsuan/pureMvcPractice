#include "StartUpCommand.h"
#include "../Facade/ApplicationFacade.h"
#include "../Proxy/MainProxy.h"
#include "../Model/GenericFunction.h"
#include "../View/MainWindowMediator.h"
#include "../View/MainWindow.h"

void StartUpCommand::execute(const INotification& aNotification)
{
    if (aNotification.getName() == ApplicationFacade::START_UP)
    {
		MainProxy* mainProxy = new MainProxy();
        ApplicationFacade::RegisterProxy(mainProxy);
		MainWindow* window = GenericFunction::ConvertToNonConstType<MainWindow>(aNotification.getBody());
        MainWindowMediator* mainWindowMediator = new MainWindowMediator(window);
        ApplicationFacade::RegisterMediator(mainWindowMediator);
        window->Show(true);
	}
}

std::string StartUpCommand::GetCommandName(void)
{
    return "StartUpCommand";
}
