#pragma once
#include <string>
#include <map>

#include <boost/shared_ptr.hpp>
#include <PureMVC.hpp>

class MainProxy;
class MainWindow;

using namespace PureMVC::Patterns;

class ApplicationFacade : public Facade
{
public:
    static const std::string NAME;

	#pragma region MessageNames
    static const std::string START_UP;
	static const std::string VALUE_CHANGE;
	static const std::string REFRESH_WINDOW;
	#pragma endregion MessageNames;

	bool StartUp(MainWindow* aWindow);

    static ApplicationFacade* GetInstance();

	static void SendNotification(
        const std::string& aNoteName,
        const void* aBody = NULL,
        const std::string& aType = "");
	static void RegisterProxy(IProxy* aProxy);
    static IProxy& RetrieveProxy(const std::string& aProxyName);
    static void RegisterMediator(IMediator* aMediator);
    static IMediator& RetrieveMediator(const std::string& aMediatorName);
    static bool HasMediator(const std::string& aMediatorName);
    //static void ReplaceCommand(const std::string& aCommandName, const boost::shared_ptr<ICommand>& aCommand);

    //static boost::shared_ptr<ICommand> GetCommand(const std::string& aCommandName);

    static MainProxy* GetMainProxy();

    ~ApplicationFacade();

protected:
    ApplicationFacade();

    void initializeCommands();
    void initializeMessageMap();

private:
    typedef std::map<std::string, boost::shared_ptr<ICommand>> CommandList;
    typedef std::map<std::string, std::string> MessageList;
    typedef std::map<std::string, IMediator*> MediatorList;
    typedef std::map<std::string, IProxy*> ProxyList;

    static boost::shared_ptr<IFacade> _facade;
    static CommandList _commandList;
    static MessageList _messageList;
    static MediatorList _mediatorList;
    static ProxyList _proxyList;
    static ApplicationFacade* _instance;

    void registerCommand();
    //static void replaceCommand(const std::string& aCommandName, const boost::shared_ptr<ICommand>& aCommand);

};