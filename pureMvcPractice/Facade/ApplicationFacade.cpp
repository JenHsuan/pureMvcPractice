#include "ApplicationFacade.h"
#include <boost/foreach.hpp>
#include "../Proxy/MainProxy.h"
#include "../View/Mainwindow.h"
#include "../Controller/StartUpCommand.h"
#include "../Controller/OnValueCommand.h"
#include "../Controller/RefreshWindowCommand.h"

const std::string ApplicationFacade::NAME = "ApplicationFacade";

ApplicationFacade::ProxyList ApplicationFacade::_proxyList;

ApplicationFacade::MediatorList ApplicationFacade::_mediatorList;

ApplicationFacade::CommandList ApplicationFacade::_commandList;

ApplicationFacade::MessageList ApplicationFacade::_messageList;

boost::shared_ptr<IFacade> ApplicationFacade::_facade(&Facade::getInstance(NAME));

ApplicationFacade* ApplicationFacade::_instance = NULL;

const std::string ApplicationFacade::START_UP = "StartUp";
const std::string ApplicationFacade::VALUE_CHANGE = "ValueChange";
const std::string ApplicationFacade::REFRESH_WINDOW = "RefreshWindow";

bool ApplicationFacade::StartUp(MainWindow* aWindow)
{
    _facade->sendNotification(START_UP, aWindow);
    return true;
}

ApplicationFacade::ApplicationFacade()
{
    initializeCommands();
    initializeMessageMap();
    registerCommand();
}
ApplicationFacade::~ApplicationFacade()
{
	BOOST_FOREACH(MediatorList::value_type meditor, _mediatorList)
    {
        delete meditor.second;
    }
    BOOST_FOREACH(ProxyList::value_type proxy, _proxyList)
    {
        delete proxy.second;
    }
}

ApplicationFacade* ApplicationFacade::GetInstance()
{
    if (_instance == NULL)
    {
        _instance = new ApplicationFacade;
        if (_facade.get() == NULL)
        {
            _facade = boost::shared_ptr<IFacade>(&Facade::getInstance(NAME));
        }
    }
    return _instance;
}
void ApplicationFacade::initializeMessageMap()
{
    _messageList[START_UP] = StartUpCommand::GetCommandName();
    _messageList[VALUE_CHANGE] = OnValueCommand::GetCommandName();
    _messageList[REFRESH_WINDOW] = RefreshWindowCommand::GetCommandName();
}
void ApplicationFacade::initializeCommands()
{
    //start up main window,register window mediator
    _commandList[StartUpCommand::GetCommandName()] = boost::shared_ptr<StartUpCommand>(new StartUpCommand);
    _commandList[OnValueCommand::GetCommandName()] = boost::shared_ptr<OnValueCommand>(new OnValueCommand);
    _commandList[RefreshWindowCommand::GetCommandName()] = boost::shared_ptr<RefreshWindowCommand>(new RefreshWindowCommand);
}
void ApplicationFacade::registerCommand()
{
    BOOST_FOREACH(MessageList::value_type message, _messageList)
    {
        _facade->registerCommand(message.first, _commandList[message.second].get());
    }
}


void ApplicationFacade::RegisterProxy(IProxy* aProxy)
{
    std::string proxyName = aProxy->getProxyName();
    _proxyList[proxyName] = aProxy;
    _facade->registerProxy(aProxy);
}

void ApplicationFacade::RegisterMediator(IMediator* aMediator)
{
    std::string meditorName = aMediator->getMediatorName();
    _mediatorList[meditorName] = aMediator;
    _facade->registerMediator(aMediator);
}

void ApplicationFacade::SendNotification(
    const std::string& aNoteName,
    const void* aBody /*= NULL*/,
    const std::string& aType /*= ""*/)
{
    _facade->sendNotification(aNoteName, aBody, aType);
}

IProxy& ApplicationFacade::RetrieveProxy(const std::string& aProxyName)
{
    return _facade->retrieveProxy(aProxyName);
}

IMediator& ApplicationFacade::RetrieveMediator(const std::string& aMediatorName)
{
    return _facade->retrieveMediator(aMediatorName);
}
MainProxy* ApplicationFacade::GetMainProxy()
{
    MainProxy& mainProxy = dynamic_cast<MainProxy&>(RetrieveProxy(MainProxy::NAME));
    return &mainProxy;
}