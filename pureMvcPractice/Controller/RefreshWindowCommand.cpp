#include "RefreshWindowCommand.h"
#include "../Facade/ApplicationFacade.h"
#include "../Proxy/MainProxy.h"
#include "../Model/GenericFunction.h"
#include "../View/MainWindowMediator.h"
#include "../View/MainWindow.h"

void RefreshWindowCommand::execute(const INotification& aNotification)
{
    if (aNotification.getName() == ApplicationFacade::REFRESH_WINDOW)
    {
		MainWindowMediator& mainWindowMediator = dynamic_cast<MainWindowMediator&>(ApplicationFacade::RetrieveMediator(MainWindowMediator::NAME));
		MainWindow* window = mainWindowMediator.GetMainWindow();
		MainProxy* mainProxy = GenericFunction::ConvertToNonConstType<MainProxy>(aNotification.getBody());
		int count = mainProxy->valueContainer->GetValue();
		window->m_rp->m_text->SetLabel(wxString::Format(wxT("%d"), count));
	}
}

std::string RefreshWindowCommand::GetCommandName(void)
{
    return "RefreshWindowCommand";
}
