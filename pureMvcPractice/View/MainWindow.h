#include "MainWindowPanel.h"
#include <wx/wxprec.h>
#include "Delegate.h"
 
 
class MainWindow : public wxFrame
{
public:
    MainWindow(const wxString& title);
 
    LeftPanel *m_lp;
    RightPanel *m_rp;
    wxPanel *m_parent;
    ~MainWindow();

    typedef Event<void, int> onPlusArgEvent;
    onPlusArgEvent onPlusSender;
	
    typedef Event<void, int> onMinusArgEvent;
    onMinusArgEvent onMinusSender;
 
};