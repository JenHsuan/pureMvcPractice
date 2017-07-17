#include "MainWindowPanel.h"
#include <wx/wxprec.h>
 
 
class MainWindow : public wxFrame
{
public:
    MainWindow(const wxString& title);
 
    LeftPanel *m_lp;
    RightPanel *m_rp;
    wxPanel *m_parent;
 
};