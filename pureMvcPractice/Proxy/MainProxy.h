#pragma once
#include <PureMVC.hpp>
#include <Patterns/Proxy/Proxy.hpp>
#include <boost/shared_ptr.hpp>
#include "../Model/ValueContainer.h"

using namespace PureMVC::Patterns;

class ValueContainer;

class MainProxy : public Proxy
{
public:
    static const std::string NAME;
	
	int currentValue;

	MainProxy();

    MainProxy(const std::string& aName);

	void MainProxy::handleNotification(INotification const& aNotification);

	
	boost::shared_ptr<ValueContainer> valueContainer;
	//ValueContainer *valueContainer;

};