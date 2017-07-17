#include "OnValueCommand.h"
#include "../Facade/ApplicationFacade.h"
#include "../Proxy/MainProxy.h"
#include "../Model/GenericFunction.h"
#include "../View/MainWindowMediator.h"
#include "../View/MainWindow.h"

void OnValueCommand::execute(const INotification& aNotification)
{
    if (aNotification.getName() == ApplicationFacade::VALUE_CHANGE)
    {
		MainProxy& mainProxy = *ApplicationFacade::GetMainProxy();
		int value = *GenericFunction::ConvertToNonConstType<int>(aNotification.getBody());
		mainProxy.valueContainer->SetValue(mainProxy.valueContainer->GetValue() + value); 
		ApplicationFacade::SendNotification(ApplicationFacade::REFRESH_WINDOW, &mainProxy);
	}
}

std::string OnValueCommand::GetCommandName(void)
{
    return "OnValueCommand";
}
