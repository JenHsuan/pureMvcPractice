#include "MainProxy.h"
#include "../Facade/ApplicationFacade.h"
#include "../Model/GenericFunction.h"
#include "../Model/ValueContainer.h"
const std::string MainProxy::NAME = "MainProxy";

//int MainProxy::currentValue = 0;
//ValueContainer::currentValue
boost::shared_ptr<ValueContainer> valueContainer = boost::shared_ptr<ValueContainer>(new ValueContainer());

MainProxy::MainProxy()
    : Proxy(NAME)
{
	MainProxy::valueContainer = boost::shared_ptr<ValueContainer>(new ValueContainer());
	//this->valueContainer.reset(new ValueContainer());
	//valueContainer
	//this->currentValue = 0;
}

MainProxy::MainProxy(const std::string& aName)
    : Proxy(aName)
{
	MainProxy::valueContainer = boost::shared_ptr<ValueContainer>(new ValueContainer());
	
	//this->currentValue = 0;
}

//void MainProxy::handleNotification(INotification const& aNotification)
//{
//    std::string noteName = aNotification.getName();
//	if (noteName == ApplicationFacade::VALUE_CHANGE)
//    {
//		int value = *GenericFunction::ConvertToNonConstType<int>(aNotification.getBody());
//		this->currentValue += 1; 
//		ApplicationFacade::SendNotification(ApplicationFacade::REFRESH_WINDOW, this);
//    }
//}

