#include "ApplicationFacade.h"
#include <boost/foreach.hpp>

const std::string ApplicationFacade::NAME = "ApplicationFacade";

boost::shared_ptr<IFacade> ApplicationFacade::_facade(&Facade::getInstance(NAME));

ApplicationFacade* ApplicationFacade::_instance = NULL;

const std::string ApplicationFacade::START_UP = "StartUp";
bool ApplicationFacade::StartUp(MainWindow* aWindow)
{
    _facade->sendNotification(START_UP, aWindow);
    return true;
}

ApplicationFacade::ApplicationFacade()
{
    //initializeCommands();
    //initializeMessageMap();
    //registerCommand();
}
ApplicationFacade::~ApplicationFacade()
{
}

ApplicationFacade* ApplicationFacade::GetInstance()
{
    if (_instance == NULL)
    {
        _instance = new ApplicationFacade;
        /*if (_facade.get() == NULL)
        {
            _facade = boost::shared_ptr<IFacade>(&Facade::getInstance(NAME));
        }*/
    }
    return _instance;
}