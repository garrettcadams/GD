/**
 *  Game Develop
 *  2008-2010 Florian Rival (Florian.Rival@gmail.com)
 */

#ifdef DEBUG
#define _MEMORY_TRACKER
#include "debugMem.h" //suivi m�moire
#endif

#include "CppUnitLite/TestHarness.h"
#include "EditorEvents.h"

//(*InternalHeaders(EditorEvents)
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)
#include <wx/config.h>
#include <wx/gdicmn.h>
#include <wx/image.h>
#include <wx/bitmap.h>
#include <wx/statbmp.h>
#include <wx/settings.h>
#include <wx/log.h>
#include <wx/config.h>
#include <wx/help.h>
#include <wx/dc.h>
#include <wx/dcbuffer.h>

#include "Game_Develop_EditorMain.h"
#include "GDL/Game.h"
#include "EditConditions.h"
#include "EditActions.h"
#include "TranslateCondition.h"
#include "TranslateAction.h"
#ifdef __WXMSW__
#include <wx/msw/winundef.h>
#endif
#include "MemTrace.h"
#include "ChoixTemplateEvent.h"
#include "EditCommentaire.h"
#include "EditDossier.h"
#include "DossierRenderer.h"
#include "LinkRenderer.h"
#include "EditLink.h"
#include "CreateTemplate.h"
#include "CommentaireRenderer.h"
#include "EventRenderer.h"
#include "Clipboard.h"
#include "GDL/StdAlgo.h"
#include "GDL/HelpFileAccess.h"
#include <time.h>

#ifdef __WXGTK__
#include <gtk/gtk.h>
#endif

extern MemTrace MemTracer;

//(*IdInit(EditorEvents)
const long EditorEvents::ID_PANEL1 = wxNewId();
const long EditorEvents::ID_PANEL2 = wxNewId();
const long EditorEvents::ID_SCROLLBAR1 = wxNewId();
const long EditorEvents::ID_SCROLLBAR2 = wxNewId();
const long EditorEvents::idEventInsert = wxNewId();
const long EditorEvents::idMenuCom = wxNewId();
const long EditorEvents::idMenuSubEvent = wxNewId();
const long EditorEvents::idMenuLien = wxNewId();
const long EditorEvents::ID_MENUITEM1 = wxNewId();
const long EditorEvents::idMenuEventDel = wxNewId();
const long EditorEvents::idMenuDelConditions = wxNewId();
const long EditorEvents::idMenuDelActions = wxNewId();
const long EditorEvents::idMenuDelSubEvents = wxNewId();
const long EditorEvents::ID_MENUITEM2 = wxNewId();
const long EditorEvents::idMenuUndo = wxNewId();
const long EditorEvents::idMenuRedo = wxNewId();
const long EditorEvents::idMenuClearHistory = wxNewId();
const long EditorEvents::idMenuCopy = wxNewId();
const long EditorEvents::idMenuCut = wxNewId();
const long EditorEvents::idMenuPastAvant = wxNewId();
const long EditorEvents::idMenuPasteApres = wxNewId();
const long EditorEvents::idMenuPasteSubEvent = wxNewId();
const long EditorEvents::idMenuPaste = wxNewId();
const long EditorEvents::idMenuEdit = wxNewId();
const long EditorEvents::idMenuAdd = wxNewId();
const long EditorEvents::idMenuDel = wxNewId();
const long EditorEvents::ID_MENUITEM3 = wxNewId();
const long EditorEvents::idMenuCouper = wxNewId();
const long EditorEvents::ID_MENUITEM4 = wxNewId();
const long EditorEvents::ID_MENUITEM5 = wxNewId();
const long EditorEvents::ID_MENUITEM6 = wxNewId();
const long EditorEvents::ID_MENUITEM7 = wxNewId();
const long EditorEvents::ID_MENUITEM8 = wxNewId();
const long EditorEvents::ID_MENUITEM9 = wxNewId();
const long EditorEvents::ID_MENUITEM10 = wxNewId();
//*)
const long EditorEvents::ID_TEMPLATEBUTTON = wxNewId();
const long EditorEvents::ID_CREATETEMPLATEBUTTON = wxNewId();
const long EditorEvents::ID_HELPBUTTON = wxNewId();
const long EditorEvents::ID_SEARCHBUTTON = wxNewId();

const long EditorEvents::idRibbonEvent = wxNewId();
const long EditorEvents::idRibbonCom = wxNewId();
const long EditorEvents::idRibbonSubEvent = wxNewId();
const long EditorEvents::idRibbonLink = wxNewId();
const long EditorEvents::idRibbonDelEvent = wxNewId();
const long EditorEvents::idRibbonUndo = wxNewId();
const long EditorEvents::idRibbonRedo = wxNewId();
const long EditorEvents::idRibbonCopy = wxNewId();
const long EditorEvents::idRibbonCut = wxNewId();
const long EditorEvents::idRibbonPaste = wxNewId();
const long EditorEvents::idRibbonTemplate = wxNewId();
const long EditorEvents::idRibbonCreateTemplate = wxNewId();
const long EditorEvents::idRibbonHelp = wxNewId();

BEGIN_EVENT_TABLE( EditorEvents, wxPanel )
    //(*EventTable(EditorEvents)
    //*)
END_EVENT_TABLE()

EditorEvents::EditorEvents( wxWindow* parent, Game & game_, Scene & scene_, vector < Event > * events_, MainEditorCommand & mainEditorCommand_ ) :
game(game_),
scene(scene_),
events(events_),
mainEditorCommand(mainEditorCommand_),
conditionsColumnWidth(350),
ctrlPressed(false),
isResizingColumns(false)
{
    MemTracer.AddObj( "Editeur d'evenements", ( long )this );
    //(*Initialize(EditorEvents)
    wxMenuItem* MenuItem26;
    wxFlexGridSizer* FlexGridSizer3;
    wxMenuItem* MenuItem11;
    wxMenuItem* MenuItem29;
    wxFlexGridSizer* FlexGridSizer2;
    wxMenuItem* MenuItem27;
    wxMenuItem* MenuItem20;
    wxMenuItem* MenuItem28;
    wxMenuItem* MenuItem23;
    wxMenuItem* editMenuItem;
    wxMenu* MenuItem5;
    wxFlexGridSizer* FlexGridSizer1;
    wxMenuItem* MenuItem19;

    Create(parent, wxID_ANY, wxDefaultPosition, wxSize(536,252), 0, _T("wxID_ANY"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer1->AddGrowableCol(0);
    FlexGridSizer1->AddGrowableRow(1);
    FlexGridSizer2 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer2->AddGrowableCol(0);
    FlexGridSizer2->AddGrowableRow(0);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(-1,0), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetBackgroundColour(wxColour(255,255,255));
    FlexGridSizer2->Add(Panel1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer3 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer3->AddGrowableCol(0);
    FlexGridSizer3->AddGrowableRow(0);
    EventsPanel = new wxPanel(this, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    FlexGridSizer3->Add(EventsPanel, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    ScrollBar1 = new wxScrollBar(this, ID_SCROLLBAR1, wxDefaultPosition, wxSize(18,130), wxSB_VERTICAL, wxDefaultValidator, _T("ID_SCROLLBAR1"));
    ScrollBar1->SetScrollbar(0, 1, 1000, 1);
    FlexGridSizer3->Add(ScrollBar1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    horizontalScrollbar = new wxScrollBar(this, ID_SCROLLBAR2, wxDefaultPosition, wxDefaultSize, wxSB_HORIZONTAL, wxDefaultValidator, _T("ID_SCROLLBAR2"));
    horizontalScrollbar->SetScrollbar(0, 1, 10, 1);
    horizontalScrollbar->Hide();
    FlexGridSizer3->Add(horizontalScrollbar, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    SetSizer(FlexGridSizer1);
    MenuItem8 = new wxMenuItem((&ContextMenu), idEventInsert, _("Ins�rer un �v�nement\tINSERT"), wxEmptyString, wxITEM_NORMAL);
    MenuItem8->SetBitmap(wxBitmap(wxImage(_T("res/eventaddicon.png"))));
    ContextMenu.Append(MenuItem8);
    MenuItem7 = new wxMenuItem((&ContextMenu), idMenuCom, _("Ins�rer un commentaire"), wxEmptyString, wxITEM_NORMAL);
    MenuItem7->SetBitmap(wxBitmap(wxImage(_T("res/commentaireaddicon.png"))));
    ContextMenu.Append(MenuItem7);
    MenuItem9 = new wxMenu();
    SubEventMenuItem = new wxMenuItem(MenuItem9, idMenuSubEvent, _("Un sous �v�nement"), wxEmptyString, wxITEM_NORMAL);
    SubEventMenuItem->SetBitmap(wxBitmap(wxImage(_T("res/subeventaddicon.png"))));
    MenuItem9->Append(SubEventMenuItem);
    MenuItem12 = new wxMenuItem(MenuItem9, idMenuLien, _("Un lien"), wxEmptyString, wxITEM_NORMAL);
    MenuItem12->SetBitmap(wxBitmap(wxImage(_T("res/lienaddicon.png"))));
    MenuItem9->Append(MenuItem12);
    ContextMenu.Append(ID_MENUITEM1, _("Ins�rer..."), MenuItem9, wxEmptyString);
    ContextMenu.AppendSeparator();
    MenuItem1 = new wxMenuItem((&ContextMenu), idMenuEventDel, _("Supprimer cet �v�nement\tDEL"), _("Supprimer l\'�v�nement complet ( Action et Condition ) de la sc�ne"), wxITEM_NORMAL);
    MenuItem1->SetBitmap(wxBitmap(wxImage(_T("res/deleteicon.png"))));
    ContextMenu.Append(MenuItem1);
    MenuItem14 = new wxMenu();
    MenuItem2 = new wxMenuItem(MenuItem14, idMenuDelConditions, _("uniquement les conditions de l\'�v�nement"), wxEmptyString, wxITEM_NORMAL);
    MenuItem2->SetBitmap(wxBitmap(wxImage(_T("res/deletecondition.png"))));
    MenuItem14->Append(MenuItem2);
    MenuItem3 = new wxMenuItem(MenuItem14, idMenuDelActions, _("uniquement les actions de l\'�v�nement"), wxEmptyString, wxITEM_NORMAL);
    MenuItem3->SetBitmap(wxBitmap(wxImage(_T("res/deleteaction.png"))));
    MenuItem14->Append(MenuItem3);
    MenuItem15 = new wxMenuItem(MenuItem14, idMenuDelSubEvents, _("les sous �v�nements"), wxEmptyString, wxITEM_NORMAL);
    MenuItem14->Append(MenuItem15);
    ContextMenu.Append(ID_MENUITEM2, _("Supprimer..."), MenuItem14, wxEmptyString);
    ContextMenu.AppendSeparator();
    MenuItem16 = new wxMenuItem((&ContextMenu), idMenuUndo, _("Annuler\tCtrl-Z"), _("Annuler les modifications pr�c�dentes"), wxITEM_NORMAL);
    MenuItem16->SetBitmap(wxBitmap(wxImage(_T("res/undo.png"))));
    ContextMenu.Append(MenuItem16);
    MenuItem17 = new wxMenuItem((&ContextMenu), idMenuRedo, _("Refaire\tCtrl-Y"), _("R�tablir les modifications annul�es"), wxITEM_NORMAL);
    MenuItem17->SetBitmap(wxBitmap(wxImage(_T("res/redo.png"))));
    ContextMenu.Append(MenuItem17);
    MenuItem18 = new wxMenuItem((&ContextMenu), idMenuClearHistory, _("Supprimer l\'historique"), wxEmptyString, wxITEM_NORMAL);
    ContextMenu.Append(MenuItem18);
    ContextMenu.AppendSeparator();
    MenuItem4 = new wxMenuItem((&ContextMenu), idMenuCopy, _("Copier cet �v�nement\tCtrl-C"), wxEmptyString, wxITEM_NORMAL);
    MenuItem4->SetBitmap(wxBitmap(wxImage(_T("res/copyicon.png"))));
    ContextMenu.Append(MenuItem4);
    MenuItem6 = new wxMenuItem((&ContextMenu), idMenuCut, _("Couper cet �v�nement\tCtrl-X"), wxEmptyString, wxITEM_NORMAL);
    MenuItem6->SetBitmap(wxBitmap(wxImage(_T("res/cuticon.png"))));
    ContextMenu.Append(MenuItem6);
    MenuItem5 = new wxMenu();
    MenuItem10 = new wxMenuItem(MenuItem5, idMenuPastAvant, _("Avant"), wxEmptyString, wxITEM_NORMAL);
    MenuItem5->Append(MenuItem10);
    MenuItem11 = new wxMenuItem(MenuItem5, idMenuPasteApres, _("Apr�s\tCtrl-V"), wxEmptyString, wxITEM_NORMAL);
    MenuItem5->Append(MenuItem11);
    MenuItem13 = new wxMenuItem(MenuItem5, idMenuPasteSubEvent, _("En tant que sous �v�nement\tCtrl-Shift-V"), wxEmptyString, wxITEM_NORMAL);
    MenuItem5->Append(MenuItem13);
    ContextMenu.Append(idMenuPaste, _("Coller"), MenuItem5, wxEmptyString);
    editMenuItem = new wxMenuItem((&conditionsMenu), idMenuEdit, _("Editer cette condition"), wxEmptyString, wxITEM_NORMAL);
    editMenuItem->SetBitmap(wxBitmap(wxImage(_T("res/editicon.png"))));
    conditionsMenu.Append(editMenuItem);
    conditionsMenu.AppendSeparator();
    MenuItem19 = new wxMenuItem((&conditionsMenu), idMenuAdd, _("Ajouter une condition"), wxEmptyString, wxITEM_NORMAL);
    MenuItem19->SetBitmap(wxBitmap(wxImage(_T("res/addicon.png"))));
    conditionsMenu.Append(MenuItem19);
    MenuItem20 = new wxMenuItem((&conditionsMenu), idMenuDel, _("Supprimer la condition"), wxEmptyString, wxITEM_NORMAL);
    MenuItem20->SetBitmap(wxBitmap(wxImage(_T("res/remove.png"))));
    conditionsMenu.Append(MenuItem20);
    conditionsMenu.AppendSeparator();
    MenuItem21 = new wxMenuItem((&conditionsMenu), ID_MENUITEM3, _("Copier"), wxEmptyString, wxITEM_NORMAL);
    MenuItem21->SetBitmap(wxBitmap(wxImage(_T("res/copyicon.png"))));
    conditionsMenu.Append(MenuItem21);
    MenuItem22 = new wxMenuItem((&conditionsMenu), idMenuCouper, _("Couper"), wxEmptyString, wxITEM_NORMAL);
    MenuItem22->SetBitmap(wxBitmap(wxImage(_T("res/cuticon.png"))));
    conditionsMenu.Append(MenuItem22);
    MenuItem23 = new wxMenuItem((&conditionsMenu), ID_MENUITEM4, _("Coller"), wxEmptyString, wxITEM_NORMAL);
    MenuItem23->SetBitmap(wxBitmap(wxImage(_T("res/pasteicon.png"))));
    conditionsMenu.Append(MenuItem23);
    MenuItem24 = new wxMenuItem((&actionsMenu), ID_MENUITEM5, _("Editer cette action"), wxEmptyString, wxITEM_NORMAL);
    MenuItem24->SetBitmap(wxBitmap(wxImage(_T("res/editicon.png"))));
    actionsMenu.Append(MenuItem24);
    actionsMenu.AppendSeparator();
    MenuItem25 = new wxMenuItem((&actionsMenu), ID_MENUITEM6, _("Ajouter une action"), wxEmptyString, wxITEM_NORMAL);
    MenuItem25->SetBitmap(wxBitmap(wxImage(_T("res/addicon.png"))));
    actionsMenu.Append(MenuItem25);
    MenuItem26 = new wxMenuItem((&actionsMenu), ID_MENUITEM7, _("Supprimer cette action"), wxEmptyString, wxITEM_NORMAL);
    MenuItem26->SetBitmap(wxBitmap(wxImage(_T("res/remove.png"))));
    actionsMenu.Append(MenuItem26);
    actionsMenu.AppendSeparator();
    MenuItem27 = new wxMenuItem((&actionsMenu), ID_MENUITEM8, _("Copier"), wxEmptyString, wxITEM_NORMAL);
    MenuItem27->SetBitmap(wxBitmap(wxImage(_T("res/copyicon.png"))));
    actionsMenu.Append(MenuItem27);
    MenuItem28 = new wxMenuItem((&actionsMenu), ID_MENUITEM9, _("Couper"), wxEmptyString, wxITEM_NORMAL);
    MenuItem28->SetBitmap(wxBitmap(wxImage(_T("res/cuticon.png"))));
    actionsMenu.Append(MenuItem28);
    MenuItem29 = new wxMenuItem((&actionsMenu), ID_MENUITEM10, _("Coller"), wxEmptyString, wxITEM_NORMAL);
    MenuItem29->SetBitmap(wxBitmap(wxImage(_T("res/pasteicon.png"))));
    actionsMenu.Append(MenuItem29);
    FlexGridSizer1->SetSizeHints(this);

    Panel1->Connect(wxEVT_KEY_UP,(wxObjectEventFunction)&EditorEvents::OnEventsPanelKeyUp,0,this);
    Panel1->Connect(wxEVT_SIZE,(wxObjectEventFunction)&EditorEvents::OnPanel1Resize,0,this);
    EventsPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&EditorEvents::OnEventsPanelPaint,0,this);
    EventsPanel->Connect(wxEVT_KEY_UP,(wxObjectEventFunction)&EditorEvents::OnEventsPanelKeyUp,0,this);
    EventsPanel->Connect(wxEVT_SET_FOCUS,(wxObjectEventFunction)&EditorEvents::OnEventsPanelSetFocus,0,this);
    EventsPanel->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&EditorEvents::OnEventsPanelLeftDown,0,this);
    EventsPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&EditorEvents::OnEventsPanelLeftUp,0,this);
    EventsPanel->Connect(wxEVT_LEFT_DCLICK,(wxObjectEventFunction)&EditorEvents::OnEventsPanelLeftDClick,0,this);
    EventsPanel->Connect(wxEVT_RIGHT_UP,(wxObjectEventFunction)&EditorEvents::OnEventsPanelRightUp,0,this);
    EventsPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&EditorEvents::OnEventsPanelMouseMove,0,this);
    EventsPanel->Connect(wxEVT_MOUSEWHEEL,(wxObjectEventFunction)&EditorEvents::OnEventsPanelMouseWheel,0,this);
    EventsPanel->Connect(wxEVT_SIZE,(wxObjectEventFunction)&EditorEvents::OnEventsPanelResize,0,this);
    Connect(ID_SCROLLBAR1,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&EditorEvents::OnScrollBar1ScrollChanged);
    Connect(ID_SCROLLBAR1,wxEVT_SCROLL_LINEUP,(wxObjectEventFunction)&EditorEvents::OnScrollBar1ScrollChanged);
    Connect(ID_SCROLLBAR1,wxEVT_SCROLL_LINEDOWN,(wxObjectEventFunction)&EditorEvents::OnScrollBar1ScrollChanged);
    Connect(ID_SCROLLBAR1,wxEVT_SCROLL_THUMBTRACK,(wxObjectEventFunction)&EditorEvents::OnScrollBar1ScrollChanged);
    Connect(ID_SCROLLBAR1,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&EditorEvents::OnScrollBar1ScrollChanged);
    Connect(ID_SCROLLBAR2,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&EditorEvents::OnhorizontalScrollbarScroll);
    Connect(ID_SCROLLBAR2,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&EditorEvents::OnhorizontalScrollbarScroll);
    Connect(idEventInsert,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnInsertEventSelected);
    Connect(idMenuCom,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnMenuItem7Selected);
    Connect(idMenuSubEvent,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnSubEventMenuItemSelected);
    Connect(idMenuLien,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnAddLienSelected);
    Connect(idMenuEventDel,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnDelEventSelected);
    Connect(idMenuDelConditions,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnDelConditionsSelected);
    Connect(idMenuDelActions,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnDelActionsSelected);
    Connect(idMenuDelSubEvents,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnDelSubEventsSelected);
    Connect(idMenuUndo,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnUndoSelected);
    Connect(idMenuRedo,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnRedoSelected);
    Connect(idMenuClearHistory,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnClearHistorySelected);
    Connect(idMenuCopy,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnMenuCopySelected);
    Connect(idMenuCut,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnCutSelected);
    Connect(idMenuPastAvant,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnMenuPasteSelected);
    Connect(idMenuPasteApres,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnMenuPasteAfterSelected);
    Connect(idMenuPasteSubEvent,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnPasteAsASubEventSelected);
    Connect(idMenuEdit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OneEditConditionMenuSelected);
    Connect(idMenuAdd,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnAddConditionMenuSelected);
    Connect(idMenuDel,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnDelConditionMenuSelected);
    Connect(ID_MENUITEM3,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnCopyConditionMenuSelected);
    Connect(idMenuCouper,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnCutConditionMenuSelected);
    Connect(ID_MENUITEM4,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnPasteConditionMenuSelected);
    Connect(ID_MENUITEM5,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnEditActionMenuSelected);
    Connect(ID_MENUITEM6,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnAddActionMenuSelected);
    Connect(ID_MENUITEM7,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnDelActionMenuSelected);
    Connect(ID_MENUITEM8,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnCopyActionMenuSelected);
    Connect(ID_MENUITEM9,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnCutActionMenuSelected);
    Connect(ID_MENUITEM10,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorEvents::OnPasteActionMenuSelected);
    Connect(wxEVT_KEY_UP,(wxObjectEventFunction)&EditorEvents::OnEventsPanelKeyUp);
    Connect(wxEVT_MOUSEWHEEL,(wxObjectEventFunction)&EditorEvents::OnEventsPanelMouseWheel);
    //*)
    Connect( ID_TEMPLATEBUTTON, wxEVT_COMMAND_TOOL_CLICKED, ( wxObjectEventFunction )&EditorEvents::OnTemplateBtClick );
    Connect( ID_CREATETEMPLATEBUTTON, wxEVT_COMMAND_TOOL_CLICKED, ( wxObjectEventFunction )&EditorEvents::OnCreateTemplateBtClick );
    Connect( ID_SEARCHBUTTON, wxEVT_COMMAND_TOOL_CLICKED, ( wxObjectEventFunction )&EditorEvents::OnSearchBtClick );
    Connect( ID_HELPBUTTON, wxEVT_COMMAND_TOOL_CLICKED, ( wxObjectEventFunction )&EditorEvents::OnAideBtClick );

    toolbar = new wxToolBar( Panel1, -1, wxDefaultPosition, wxDefaultSize,
                             wxTB_FLAT | wxTB_NODIVIDER | wxTB_HORIZONTAL );

    toolbar->ClearTools();
    toolbar->SetToolBitmapSize( wxSize( 16, 16 ) );
    toolbar->AddTool( idEventInsert, wxT( "Ins�rer un �v�nement" ), wxBitmap( wxImage( "res/eventaddicon.png" ) ), _( "Ins�rer un �v�nement" ) );
    toolbar->AddTool( idMenuSubEvent, wxT( "Ins�rer un sous-�v�nement" ), wxBitmap( wxImage( "res/subeventaddicon.png" ) ), _( "Ins�rer un sous-�v�nement" ) );
    toolbar->AddTool( idMenuCom, wxT( "Ins�rer un commentaire" ), wxBitmap( wxImage( "res/commentaireaddicon.png" ) ), _( "Ins�rer un commentaire" ) );
    toolbar->AddTool( idMenuLien, wxT( "Ins�rer un lien vers des �v�nements" ), wxBitmap( wxImage( "res/lienaddicon.png" ) ), _( "Ins�rer un lien vers des �v�nements" ) );
    toolbar->AddSeparator();
    toolbar->AddTool( idMenuEventDel, wxT( "Supprimer l'�v�nement selectionn�" ), wxBitmap( wxImage( "res/deleteicon.png" ) ), _( "Supprimer l'�v�nement selectionn�" ) );
    toolbar->AddSeparator();
    toolbar->AddTool( ID_TEMPLATEBUTTON, wxT( "Mod�le d'�v�nements" ), wxBitmap( wxImage( "res/templateicon.png" ) ), _( "Ajouter des �v�nements depuis un mod�le" ) );
    toolbar->AddTool( ID_CREATETEMPLATEBUTTON, wxT( "Cr�ation de mod�le d'�v�nements" ), wxBitmap( wxImage( "res/addtemplateicon.png" ) ), _( "Cr�er un mod�le d'�v�nements depuis la sc�ne" ) );
    toolbar->AddSeparator();
    toolbar->AddTool( idMenuUndo, wxT( "Annuler les modifications pr�c�dentes" ), wxBitmap( wxImage( "res/undo.png" ) ), _( "Annuler les modifications pr�c�dentes" ) );
    toolbar->AddTool( idMenuRedo, wxT( "R�tablir les modifications annul�es" ), wxBitmap( wxImage( "res/redo.png" ) ), _( "R�tablir les modifications annul�es" ) );
    toolbar->AddSeparator();
    toolbar->AddTool( idMenuCopy, wxT( "Copier l'�v�nement selectionn�" ), wxBitmap( wxImage( "res/copyicon.png" ) ), _( "Copier l'�v�nement selectionn�" ) );
    toolbar->AddTool( idMenuCut, wxT( "Couper l'�v�nement selectionn�" ), wxBitmap( wxImage( "res/cuticon.png" ) ), _( "Couper l'�v�nement selectionn�" ) );
    toolbar->AddTool( idMenuPasteApres, wxT( "Coller apr�s l'�v�nement selectionn�" ), wxBitmap( wxImage( "res/pasteicon.png" ) ), _( "Coller apr�s l'�v�nement selectionn�" ) );

    toolbar->AddSeparator();
    toolbar->AddTool( ID_SEARCHBUTTON, wxT( "Rechercher dans les �v�nements" ), wxBitmap( wxImage( "res/searchicon.png" ) ), _( "Rechercher dans les �v�nements" ) );
    toolbar->AddSeparator();
    toolbar->AddTool( ID_HELPBUTTON, wxT( "Aide" ), wxBitmap( wxImage( "res/helpicon.png" ) ), _( "Aide de l'�diteur d'�v�nements" ) );
    toolbar->AddSeparator();
    toolbar->Realize();

    //On v�rifie si on est pas en mode simple.
    wxConfigBase * pConfig = wxConfigBase::Get();

    bool result = false;
    pConfig->Read("/ModeSimple", &result);

    //TODO : Desactiver ceci quand implement�
    toolbar->EnableTool(ID_SEARCHBUTTON, false);

    //D�sactivation d'options du menu en mode simple
    if ( result )
    {
        toolbar->EnableTool(idMenuSubEvent, false);
        toolbar->EnableTool(idMenuLien, false);
        toolbar->EnableTool(ID_CREATETEMPLATEBUTTON, false);
        SubEventMenuItem->Enable(false);
        MenuItem12->Enable(false);
        MenuItem2->Enable(false);
        MenuItem3->Enable(false);
        MenuItem15->Enable(false);
        MenuItem13->Enable(false);
    }

    //Obligatoire avec wxGTK, sinon la toolbar ne s'affiche pas
#ifdef __WXGTK__
    wxSize tbSize = toolbar->GetSize();
    gtk_widget_set_usize( toolbar->m_widget, tbSize.GetWidth(), tbSize.GetHeight() );
#endif

    searchDialog = new SearchEvents(this, unusedEventList);
}

/**
 * Static method for creating ribbon for events editors.
 */
void EditorEvents::CreateRibbonPage(wxRibbonPage * page)
{
    wxConfigBase *pConfig = wxConfigBase::Get();
    bool hideLabels = false;
    pConfig->Read( _T( "/Skin/HideLabels" ), &hideLabels );

    {
        wxRibbonPanel *ribbonPanel = new wxRibbonPanel(page, wxID_ANY, _("Insertion"), wxBitmap("res/add24.png", wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, wxRIBBON_PANEL_DEFAULT_STYLE);
        wxRibbonButtonBar *ribbonBar = new wxRibbonButtonBar(ribbonPanel, wxID_ANY);
        ribbonBar->AddButton(idRibbonEvent, !hideLabels ? _("Ajouter un �v�nement") : "", wxBitmap("res/eventadd24.png", wxBITMAP_TYPE_ANY));
        ribbonBar->AddButton(idRibbonSubEvent, !hideLabels ? _("Ajouter un sous-�v�nement") : "", wxBitmap("res/subeventadd24.png", wxBITMAP_TYPE_ANY));
        ribbonBar->AddButton(idRibbonCom, !hideLabels ? _("Ajouter un commentaire") : "", wxBitmap("res/commentaireadd24.png", wxBITMAP_TYPE_ANY));
        ribbonBar->AddButton(idRibbonLink, !hideLabels ? _("Ajout. un lien") : "", wxBitmap("res/lienadd24.png", wxBITMAP_TYPE_ANY));
    }
    {
        wxRibbonPanel *ribbonPanel = new wxRibbonPanel(page, wxID_ANY, _("Suppression"), wxBitmap("res/delete24.png", wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, wxRIBBON_PANEL_DEFAULT_STYLE);
        wxRibbonButtonBar *ribbonBar = new wxRibbonButtonBar(ribbonPanel, wxID_ANY);
        ribbonBar->AddButton(idRibbonDelEvent, !hideLabels ? _("Supprimer l'�v�nement") : "", wxBitmap("res/delete24.png", wxBITMAP_TYPE_ANY));
    }
    {
        wxRibbonPanel *ribbonPanel = new wxRibbonPanel(page, wxID_ANY, _("Annulation"), wxBitmap("res/unredo24.png", wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, wxRIBBON_PANEL_DEFAULT_STYLE);
        wxRibbonButtonBar *ribbonBar = new wxRibbonButtonBar(ribbonPanel, wxID_ANY);
        ribbonBar->AddButton(idRibbonUndo, !hideLabels ? _("Annuler") : "", wxBitmap("res/undo24.png", wxBITMAP_TYPE_ANY));
        ribbonBar->AddButton(idRibbonRedo, !hideLabels ? _("Refaire") : "", wxBitmap("res/redo24.png", wxBITMAP_TYPE_ANY));
    }
    {
        wxRibbonPanel *ribbonPanel = new wxRibbonPanel(page, wxID_ANY, _("Presse papiers"), wxBitmap("res/copy24.png", wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, wxRIBBON_PANEL_DEFAULT_STYLE);
        wxRibbonButtonBar *ribbonBar = new wxRibbonButtonBar(ribbonPanel, wxID_ANY);
        ribbonBar->AddButton(idRibbonCopy, !hideLabels ? _("Copier") : "", wxBitmap("res/copy24.png", wxBITMAP_TYPE_ANY));
        ribbonBar->AddButton(idRibbonCut, !hideLabels ? _("Couper") : "", wxBitmap("res/cut24.png", wxBITMAP_TYPE_ANY));
        ribbonBar->AddButton(idRibbonPaste, !hideLabels ? _("Coller") : "", wxBitmap("res/paste24.png", wxBITMAP_TYPE_ANY));
    }
    {
        wxRibbonPanel *ribbonPanel = new wxRibbonPanel(page, wxID_ANY, _("Mod�les"), wxBitmap("res/template24.png", wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, wxRIBBON_PANEL_DEFAULT_STYLE);
        wxRibbonButtonBar *ribbonBar = new wxRibbonButtonBar(ribbonPanel, wxID_ANY);
        ribbonBar->AddButton(idRibbonTemplate, !hideLabels ? _("Ins�rer") : "", wxBitmap("res/template24.png", wxBITMAP_TYPE_ANY));
        ribbonBar->AddButton(idRibbonCreateTemplate, !hideLabels ? _("Cr�er") : "", wxBitmap("res/addtemplate24.png", wxBITMAP_TYPE_ANY));
    }
    {
        wxRibbonPanel *ribbonPanel = new wxRibbonPanel(page, wxID_ANY, _("Aide"), wxBitmap("res/helpicon24.png", wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, wxRIBBON_PANEL_DEFAULT_STYLE);
        wxRibbonButtonBar *ribbonBar = new wxRibbonButtonBar(ribbonPanel, wxID_ANY);
        ribbonBar->AddButton(idRibbonHelp, !hideLabels ? _("Aide") : "", wxBitmap("res/helpicon24.png", wxBITMAP_TYPE_ANY));
    }
}

void EditorEvents::ConnectEvents()
{
    mainEditorCommand.GetMainEditor()->Connect(idRibbonEvent, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorEvents::OnInsertEventSelected, NULL, this);
    mainEditorCommand.GetMainEditor()->Connect(idRibbonCom, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorEvents::OnMenuItem7Selected, NULL, this);
    mainEditorCommand.GetMainEditor()->Connect(idRibbonLink, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorEvents::OnAddLienSelected, NULL, this);
    mainEditorCommand.GetMainEditor()->Connect(idRibbonSubEvent, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorEvents::OnSubEventMenuItemSelected, NULL, this);
    mainEditorCommand.GetMainEditor()->Connect(idRibbonDelEvent, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorEvents::OnDelEventSelected, NULL, this);
    mainEditorCommand.GetMainEditor()->Connect(idRibbonUndo, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorEvents::OnUndoSelected, NULL, this);
    mainEditorCommand.GetMainEditor()->Connect(idRibbonRedo, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorEvents::OnRedoSelected, NULL, this);
    mainEditorCommand.GetMainEditor()->Connect(idRibbonCopy, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorEvents::OnMenuCopySelected, NULL, this);
    mainEditorCommand.GetMainEditor()->Connect(idRibbonCut, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorEvents::OnCutSelected, NULL, this);
    mainEditorCommand.GetMainEditor()->Connect(idRibbonPaste, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorEvents::OnMenuPasteSelected, NULL, this);
    mainEditorCommand.GetMainEditor()->Connect(idRibbonTemplate, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorEvents::OnTemplateBtClick, NULL, this);
    mainEditorCommand.GetMainEditor()->Connect(idRibbonCreateTemplate, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorEvents::OnCreateTemplateBtClick, NULL, this);
    mainEditorCommand.GetMainEditor()->Connect(idRibbonHelp, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorEvents::OnAideBtClick, NULL, this);
}

EditorEvents::~EditorEvents()
{
    MemTracer.DelObj(( long )this );
    //(*Destroy(EditorEvents)
    //*)
}

////////////////////////////////////////////////////////////
/// Mise � jour de la taille de la toolbar
/// quand on redimensionne le panel
////////////////////////////////////////////////////////////
void EditorEvents::OnPanel1Resize( wxSizeEvent& event )
{
    toolbar->SetSize(Panel1->GetSize().x, -1);
}

////////////////////////////////////////////////////////////
/// Rafraichissement � chaque changement de la scrollbar
////////////////////////////////////////////////////////////
void EditorEvents::OnScrollBar1ScrollChanged( wxScrollEvent& event )
{
    EventsPanel->Refresh();
    EventsPanel->Update();
}
void EditorEvents::OnhorizontalScrollbarScroll(wxScrollEvent& event)
{
    EventsPanel->Refresh();
    EventsPanel->Update();
}

////////////////////////////////////////////////////////////
/// Rafraichissement en cas de changement de taille
////////////////////////////////////////////////////////////
void EditorEvents::OnEventsPanelResize( wxSizeEvent& event )
{
    ResetEventsSizeCache(*events);

    EventsPanel->Refresh();
    EventsPanel->Update();
}

////////////////////////////////////////////////////////////
/// Remise � z�ro des variables contenant les tailles des �v�nements
////////////////////////////////////////////////////////////
void EditorEvents::ResetEventsSizeCache(vector < Event > & eventsToReset)
{
    vector<Event>::iterator e = eventsToReset.begin();
    vector<Event>::const_iterator end = eventsToReset.end();

    for(;e != end;++e)
    {
        e->conditionsHeightNeedUpdate = true;
        e->actionsHeightNeedUpdate = true;

        if ( !e->events.empty() )
            ResetEventsSizeCache(e->events);
    }
}

////////////////////////////////////////////////////////////
/// Appel� � chaque changements dans les �v�nements
////////////////////////////////////////////////////////////
void EditorEvents::ChangesMadeOnEvents()
{
    //Mise � jour de l'historique d'annulation
    history.push_back(*events);
    redoHistory.clear();

    scene.wasModified = true;

    //Rafraichissement
    EventsPanel->Refresh();
    EventsPanel->Update();
}

////////////////////////////////////////////////////////////
/// Affichage des �v�nements de la sc�ne
////////////////////////////////////////////////////////////
void EditorEvents::OnEventsPanelPaint( wxPaintEvent& event )
{
    wxBufferedPaintDC dc( EventsPanel ); //Cr�ation obligatoire du wxBufferedPaintDC
    EventsPanel->SetBackgroundStyle( wxBG_STYLE_PAINT );

    //Pr�paration de la zone de dessin
    dc.SetBackgroundMode( wxTRANSPARENT );
    wxColour backgroundColor( wxColour( 250, 250, 250 ) );
    dc.SetBackground( backgroundColor );
    dc.SetBrush( wxBrush( backgroundColor ) );
    dc.SetFont( wxFont( 8, wxDEFAULT, wxNORMAL, wxNORMAL ) );
    dc.SetTextForeground( wxColour( 0, 0, 0 ) );

    //Effacement de l'arri�re plan
    dc.SetPen( wxPen( backgroundColor ) );
    dc.DrawRectangle( 0, 0, EventsPanel->GetSize().x, EventsPanel->GetSize().y );

    dc.SetPen( wxPen( wxColour( 120, 120, 120 ), 1, wxSOLID ) );

    //On r�cup�re la position de dessin initiale
    int Yposition = -( ScrollBar1->GetThumbPosition() );
    int positionScrollbar = ScrollBar1->GetThumbPosition();
    int initialXposition = 2 + dc.GetTextExtent(st(events->size())).GetWidth() + 2 - horizontalScrollbar->GetThumbPosition();
    int maximalWidth = 0;

    //Setup renderings datas which are constants.
    eventsRenderersDatas.SetRenderZoneWidth(EventsPanel->GetSize().x);
    eventsRenderersDatas.SetConditionsColumnWidth(conditionsColumnWidth);

    //Phase de dessin des �v�nements
    DrawEvents(*events, dc, Yposition, initialXposition, maximalWidth, true);

    //Phase de dessin du texte final
    dc.SetFont(eventsRenderersDatas.GetFont());
    wxString text = _("Utilisez le clic droit pour ajouter des �v�nements.\nVous pouvez ensuite double cliquer sur les �v�nements pour les �diter.");
    dc.DrawLabel(text,
                wxRect( (EventsPanel->GetSize().x-dc.GetMultiLineTextExtent(text).GetWidth())/2,Yposition+15,
                        (EventsPanel->GetSize().x+dc.GetMultiLineTextExtent(text).GetWidth())/2-(EventsPanel->GetSize().x-dc.GetMultiLineTextExtent(text).GetWidth())/2,0)
                , wxALIGN_CENTER);

    //Mise � jour des scrollbars
    ScrollBar1->SetScrollbar( positionScrollbar, EventsPanel->GetSize().y, Yposition + positionScrollbar + 5 + dc.GetMultiLineTextExtent(text).GetHeight(), EventsPanel->GetSize().y );
    horizontalScrollbar->SetScrollbar( horizontalScrollbar->GetThumbPosition(), EventsPanel->GetSize().x, maximalWidth, EventsPanel->GetSize().x );
}

////////////////////////////////////////////////////////////
/// Permet d'afficher une liste d'�v�nement.
/// Cette fonction est r�cursive en cas de sous �v�nements.
/// Met aussi � jour eventTreeSelected avec l'�v�nement selectionn�.
////////////////////////////////////////////////////////////
void EditorEvents::DrawEvents(vector < Event > & list, wxBufferedPaintDC & dc, int & Yposition, int initialXposition, int & parentMaximalWidth, bool draw)
{
    int positionScrollbar = ScrollBar1->GetThumbPosition();
    const int separation = 3;

    int maximalWidth = 0;
    for ( unsigned int i = 0;i < list.size();++i )
    {
        //Num�rotation
        //i+1 permet de commencer la num�rotation � 1
        if ( draw )
        {
            dc.SetFont( eventsRenderersDatas.GetFont() );
            dc.DrawText(st(i+1), initialXposition-(dc.GetTextExtent(st(i+1)).GetWidth()+2), Yposition);
        }

        //Get a renderer for the event
        bool normalEvent = false;
        Renderer * renderer = NULL;
        if ( list[i].type == "Commentaire" )
            renderer = new CommentaireRenderer(dc, list.at( i ), eventsRenderersDatas);
        else if ( list[i].type == "Link" )
            renderer = new LinkRenderer(dc, list.at( i ), eventsRenderersDatas);
        else
        {
            normalEvent = true;
            renderer = new EventRenderer(dc, list.at( i ), eventsRenderersDatas);
        }

        //Hit test
        if ( MouseY >= Yposition+positionScrollbar &&
             MouseY <= Yposition+positionScrollbar+renderer->GetHeight() )
        {
            eventsSelected.push_back(std::make_pair(&list, i));
            list[i].selected = true;

            if ( MouseX <= conditionsColumnWidth)
            {
                if ( !ConditionsSelected )
                {
                    ConditionsSelected = true;
                    instructionsSelected.clear();
                }

                unsigned int conditionsY = 1;
                for (unsigned int c = 0;c<list[i].conditions.size();++c)
                {
                    conditionsY += 1;
                    if ( MouseY >= Yposition+positionScrollbar+conditionsY &&
                         MouseY <= Yposition+positionScrollbar+conditionsY+list[i].conditions[c].renderedHeight)
                     {
                         list[i].conditions[c].selected = true;
                         instructionsSelected.push_back(std::make_pair(&list[i].conditions, c));
                     }
                    conditionsY += list[i].conditions[c].renderedHeight+2;
                }
            }
            else
            {
                cout << "here";
                if ( ConditionsSelected )
                {
                    ConditionsSelected = false;
                    instructionsSelected.clear();
                }

                unsigned int actionsY = 1;
                for (unsigned int a = 0;a<list[i].actions.size();++a)
                {
                    actionsY += 1;
                    if ( MouseY >= Yposition+positionScrollbar+actionsY &&
                         MouseY <= Yposition+positionScrollbar+actionsY+list[i].actions[a].renderedHeight)
                     {
                cout << "selected";
                         list[i].actions[a].selected = true;
                         instructionsSelected.push_back(std::make_pair(&list[i].actions, a));
                     }
                    actionsY += list[i].actions[a].renderedHeight+2;
                }
            }

            list[i].selected = true;
        }

        //Render
        eventsRenderersDatas.SetOrigineX(initialXposition);
        eventsRenderersDatas.SetOrigineY(Yposition);
        if ( Yposition + renderer->GetHeight() + positionScrollbar >= positionScrollbar &&
             Yposition + positionScrollbar < ( positionScrollbar + EventsPanel->GetSize().y ) &&
             draw)
        {
            renderer->Render();
        }

        Yposition += renderer->GetHeight();
        delete renderer;

        //Sub events
        if ( !list[i].events.empty() )
        {
            Yposition += separation;
            DrawEvents(list[i].events, dc, Yposition, initialXposition+32, maximalWidth, draw);
        }

        Yposition += separation;
    }

    if ( initialXposition + maximalWidth > parentMaximalWidth )
        parentMaximalWidth = initialXposition + maximalWidth;
}

////////////////////////////////////////////////////////////
/// Suppression de l'�v�nement entier
////////////////////////////////////////////////////////////
void EditorEvents::OnDelEventSelected( wxCommandEvent& event )
{
    for (unsigned int i = 0;i<eventsSelected.size();++i)
    	eventsSelected[i].first->erase(eventsSelected[i].first->begin() + eventsSelected[i].second);

    eventsSelected.clear();

    ChangesMadeOnEvents();
}

////////////////////////////////////////////////////////////
/// Suppression des conditions
////////////////////////////////////////////////////////////
void EditorEvents::OnDelConditionsSelected( wxCommandEvent& event )
{
    for (unsigned int i = 0;i<eventsSelected.size();++i)
    	eventsSelected[i].first->at(eventsSelected[i].second).conditions.clear();

    ChangesMadeOnEvents();
}

////////////////////////////////////////////////////////////
/// Suppression des actions
////////////////////////////////////////////////////////////
void EditorEvents::OnDelActionsSelected( wxCommandEvent& event )
{
    for (unsigned int i = 0;i<eventsSelected.size();++i)
    	eventsSelected[i].first->at(eventsSelected[i].second).actions.clear();

    ChangesMadeOnEvents();
}

////////////////////////////////////////////////////////////
/// Ouvrir la fen�tre des mod�les d'�v�nements
////////////////////////////////////////////////////////////
void EditorEvents::OnTemplateBtClick( wxCommandEvent& event )
{
    if ( eventsSelected.empty() )
    {
        wxLogStatus(_("Aucun endroit o� ins�rer le mod�le d'�v�nement."));
        return;
    }

    ChoixTemplateEvent Dialog( this );
    if ( Dialog.ShowModal() == 1 )
    {
        //Insertion des �v�nements ( d�j� personnalis�s )
        for ( unsigned int i = 0;i < Dialog.TemplateFinal.events.size();i++ )
            eventsSelected[0].first->push_back( Dialog.TemplateFinal.events.at( i ) );

    }

    ChangesMadeOnEvents();
}


////////////////////////////////////////////////////////////
/// Insertion d'un commentaire
////////////////////////////////////////////////////////////
void EditorEvents::OnMenuItem7Selected( wxCommandEvent& event )
{
    if ( eventsSelected.empty() )
    {
        wxLogStatus(_("Aucun endroit o� ins�rer le mod�le d'�v�nement."));
        return;
    }

    Event eventToAdd;
    eventToAdd.type = "Commentaire";
    EditCommentaire Dialog( this, &eventToAdd );
    if ( Dialog.ShowModal() == 1 )
    {
        if ( eventsSelected[0].second < eventsSelected[0].first->size() )
        {
            eventsSelected[0].first->insert( eventsSelected[0].first->begin() + eventsSelected[0].second, eventToAdd );
        }
        else { eventsSelected[0].first->push_back( eventToAdd ); }

        ChangesMadeOnEvents();
    }
}


////////////////////////////////////////////////////////////
/// Insertion d'un �v�nement
////////////////////////////////////////////////////////////
void EditorEvents::OnInsertEventSelected( wxCommandEvent& event )
{
    if ( eventsSelected.empty() )
    {
        wxLogStatus(_("Aucun endroit o� ins�rer le mod�le d'�v�nement."));
        return;
    }

    Event eventToAdd;

    if ( eventsSelected[0].second < eventsSelected[0].first->size() )
        eventsSelected[0].first->insert( eventsSelected[0].first->begin() + eventsSelected[0].second, eventToAdd );
    else
        eventsSelected[0].first->push_back( eventToAdd );

    ChangesMadeOnEvents();
}


////////////////////////////////////////////////////////////
/// Insertion d'un sous �v�nement
////////////////////////////////////////////////////////////
void EditorEvents::OnSubEventMenuItemSelected(wxCommandEvent& event)
{
    if ( eventsSelected.empty() )
    {
        wxLogStatus(_("Aucun endroit o� ins�rer le sous �v�nement"));
        return;
    }

    Event eventToAdd;
    eventsSelected[0].first->at(eventsSelected[0].second).events.push_back(eventToAdd);

    ChangesMadeOnEvents();
}


////////////////////////////////////////////////////////////
/// Insertion d'un lien
////////////////////////////////////////////////////////////
void EditorEvents::OnAddLienSelected( wxCommandEvent& event )
{
    if ( eventsSelected.empty() )
    {
        wxLogStatus(_("Aucun endroit o� ins�rer le lien."));
        return;
    }

    Event eventToAdd;
    eventToAdd.type = "Link";
    EditLink dialog( this, eventToAdd );
    if ( dialog.ShowModal() == 1 )
    {
        if ( eventsSelected[0].second < eventsSelected[0].first->size() )
            eventsSelected[0].first->insert( eventsSelected[0].first->begin() + eventsSelected[0].second, eventToAdd );
        else
            eventsSelected[0].first->push_back( eventToAdd );

        ChangesMadeOnEvents();
    }
}


////////////////////////////////////////////////////////////
/// Copier un �v�nement
////////////////////////////////////////////////////////////
void EditorEvents::OnMenuCopySelected( wxCommandEvent& event )
{
    if ( eventsSelected.empty() ) return;

    Clipboard * clipboard = Clipboard::getInstance();
    clipboard->SetEvent( eventsSelected[0].first->at(eventsSelected[0].second) );
}

////////////////////////////////////////////////////////////
/// Couper un �v�nement
////////////////////////////////////////////////////////////
void EditorEvents::OnCutSelected( wxCommandEvent& event )
{
    if ( eventsSelected.empty() ) return;

    Clipboard * clipboard = Clipboard::getInstance();
    clipboard->SetEvent( eventsSelected[0].first->at(eventsSelected[0].second) );

    eventsSelected[0].first->erase( eventsSelected[0].first->begin() + eventsSelected[0].second );
    eventsSelected.clear();

    ChangesMadeOnEvents();
}

////////////////////////////////////////////////////////////
/// Coller un �v�nement avant l'�v�nement choisi
////////////////////////////////////////////////////////////
void EditorEvents::OnMenuPasteSelected( wxCommandEvent& event )
{
    if ( eventsSelected.empty() ) return;

    Clipboard * clipboard = Clipboard::getInstance();

    if ( eventsSelected[0].second < eventsSelected[0].first->size() )
        eventsSelected[0].first->insert( eventsSelected[0].first->begin() + eventsSelected[0].second, clipboard->GetEvent() );
    else
        eventsSelected[0].first->push_back( clipboard->GetEvent() );

    ChangesMadeOnEvents();
}

////////////////////////////////////////////////////////////
/// Coller apr�s l'�v�nement choisi
////////////////////////////////////////////////////////////
void EditorEvents::OnMenuPasteAfterSelected( wxCommandEvent& event )
{
    if ( eventsSelected.empty() ) return;

    Clipboard * clipboard = Clipboard::getInstance();

    if ( eventsSelected[0].second+1 < eventsSelected[0].first->size() )
        eventsSelected[0].first->insert( eventsSelected[0].first->begin() + eventsSelected[0].second+1, clipboard->GetEvent() );
    else
        eventsSelected[0].first->push_back( clipboard->GetEvent() );

    ChangesMadeOnEvents();
}

////////////////////////////////////////////////////////////
/// Coller en tant que sous �v�nement
////////////////////////////////////////////////////////////
void EditorEvents::OnPasteAsASubEventSelected(wxCommandEvent& event)
{
    if ( eventsSelected.empty() ) return;

    Clipboard * clipboard = Clipboard::getInstance();
    eventsSelected[0].first->at(eventsSelected[0].second).events.push_back( clipboard->GetEvent() );

    ChangesMadeOnEvents();
}

////////////////////////////////////////////////////////////
/// Supprimer les sous �v�nements de l'�v�nement
////////////////////////////////////////////////////////////
void EditorEvents::OnDelSubEventsSelected(wxCommandEvent& event)
{
    if ( eventsSelected.empty() ) return;

    eventsSelected[0].first->at(eventsSelected[0].second).events.clear();

    ChangesMadeOnEvents();
}


void EditorEvents::OnAideBtClick( wxCommandEvent& event )
{
    HelpFileAccess * helpFileAccess = HelpFileAccess::getInstance();
    helpFileAccess->DisplaySection(11);
}

////////////////////////////////////////////////////////////
/// Cr�ation d'un mod�le d'�v�nement
/// � partir des �v�nements du jeu
////////////////////////////////////////////////////////////
void EditorEvents::OnCreateTemplateBtClick( wxCommandEvent& event )
{
    if ( eventsSelected.empty() );

    CreateTemplate dialog( this, *eventsSelected[0].first );
    dialog.ShowModal();
}

////////////////////////////////////////////////////////////
/// Double clic gauche : Edition d'un �v�nement
////////////////////////////////////////////////////////////
void EditorEvents::OnEventsPanelLeftDClick( wxMouseEvent& event )
{
    if ( eventsSelected.empty() ) return;

    MouseX = event.GetX();
    MouseY = event.GetY()+ScrollBar1->GetThumbPosition();

    //Rafraichissement n�cessaire pour s'assurer que l'�v�nement selectionn� soit le bon
    EventsPanel->Refresh();
    EventsPanel->Update();

    Event & eventSelected = eventsSelected[0].first->at(eventsSelected[0].second);

    if ( eventSelected.type == "Commentaire" )
    {
        EditCommentaire dialog( this, &eventSelected );
        if ( dialog.ShowModal() == 1 )
            ChangesMadeOnEvents();
    }
    else if ( eventSelected.type == "Link" )
    {
        EditLink dialog( this, eventSelected );
        if ( dialog.ShowModal() == 1 )
            ChangesMadeOnEvents();
    }
    else
    {
        if ( ConditionsSelected )
        {
            EditConditions EditDialog( this, game, scene, eventSelected );
            if ( EditDialog.ShowModal() == 1 )
            {
                eventSelected = EditDialog.eventEdited;
                eventSelected.conditionsHeightNeedUpdate = true;
                ChangesMadeOnEvents();
            }
        }
        else
        {
            EditActions EditDialog( this, game, scene, eventSelected );
            if ( EditDialog.ShowModal() == 1 )
            {
                eventSelected = EditDialog.eventEdited;
                eventSelected.actionsHeightNeedUpdate = true;
                ChangesMadeOnEvents();
            }
        }
    }

}

////////////////////////////////////////////////////////////
/// Clic gauche : selection
////////////////////////////////////////////////////////////
void EditorEvents::OnEventsPanelLeftUp(wxMouseEvent& event)
{
    wxFocusEvent unusedEvent;
    OnEventsPanelSetFocus(unusedEvent);

    instructionsSelected.clear();
    eventsSelected.clear();
    DeselectAllEvents(*events);
    DeselectAllActions(*events);
    DeselectAllConditions(*events);

    MouseX = event.GetX();
    MouseY = event.GetY()+ScrollBar1->GetThumbPosition();

    //Si on relache la souris apr�s avoir redimensionn� une colonne
    if ( isResizingColumns )
    {
        conditionsColumnWidth = event.GetX();
        ResetEventsSizeCache(*events);
        isResizingColumns = false;
    }

    EventsPanel->Refresh();
    EventsPanel->Update();
}

////////////////////////////////////////////////////////////
/// Clic droit : menu contextuel
////////////////////////////////////////////////////////////
void EditorEvents::OnEventsPanelRightUp( wxMouseEvent& event )
{
    wxFocusEvent unusedEvent;
    OnEventsPanelSetFocus(unusedEvent);

    instructionsSelected.clear();
    eventsSelected.clear();
    DeselectAllEvents(*events);
    DeselectAllActions(*events);
    DeselectAllConditions(*events);

    MouseX = event.GetX();
    MouseY = event.GetY()+ScrollBar1->GetThumbPosition();

    EventsPanel->Refresh();
    EventsPanel->Update();

    if ( !instructionsSelected.empty() && ConditionsSelected )
        PopupMenu( &conditionsMenu );
    else if ( !instructionsSelected.empty() && !ConditionsSelected )
        PopupMenu( &actionsMenu );
    else if ( !eventsSelected.empty())
        PopupMenu( &ContextMenu );
}

////////////////////////////////////////////////////////////
/// Scroll avec la molette
////////////////////////////////////////////////////////////
void EditorEvents::OnEventsPanelMouseWheel(wxMouseEvent& event)
{
    ScrollBar1->SetScrollbar(ScrollBar1->GetThumbPosition()-event.GetWheelRotation(), ScrollBar1->GetThumbSize(), ScrollBar1->GetRange(), ScrollBar1->GetPageSize());
    EventsPanel->Refresh();
    EventsPanel->Update();
}

////////////////////////////////////////////////////////////
/// Afficher la fen�tre de recherche
////////////////////////////////////////////////////////////
void EditorEvents::OnSearchBtClick(wxCommandEvent& event)
{
    if ( searchDialog )
        searchDialog->ShowModal();
}

////////////////////////////////////////////////////////////
/// Suppression de l'historique des changements
////////////////////////////////////////////////////////////
void EditorEvents::OnClearHistorySelected(wxCommandEvent& event)
{
    history.clear();
    redoHistory.clear();
}

////////////////////////////////////////////////////////////
/// Annuler le dernier changement
////////////////////////////////////////////////////////////
void EditorEvents::OnUndoSelected(wxCommandEvent& event)
{
    if ( history.size() < 2 )
        return;

    redoHistory.push_back(*events); //On pourra revenir � l'�tat actuel avec "Refaire"
    *events = history.at( history.size() - 2 ); //-2 car le dernier �l�ment est la liste d'�v�nement actuelle
    history.pop_back();

    EventsPanel->Refresh();
    EventsPanel->Update();

    scene.wasModified = true;
}

////////////////////////////////////////////////////////////
/// R�tablir le dernier changement
////////////////////////////////////////////////////////////
void EditorEvents::OnRedoSelected(wxCommandEvent& event)
{
    if ( redoHistory.empty() )
        return;

    history.push_back(redoHistory.back()); //Le dernier �l�ment est la liste d'�v�nement actuellement �dit�e
    *events = redoHistory.back();
    redoHistory.pop_back();

    EventsPanel->Refresh();
    EventsPanel->Update();

    scene.wasModified = true;
}

////////////////////////////////////////////////////////////
/// D�placement de la souris : Changement de curseur si besoin
////////////////////////////////////////////////////////////
void EditorEvents::OnEventsPanelMouseMove(wxMouseEvent& event)
{
    if (    (event.GetX() >= conditionsColumnWidth-2 && event.GetX() <= conditionsColumnWidth+2)
        ||  isResizingColumns)
        SetCursor(wxCURSOR_SIZEWE);
    else
        SetCursor(wxNullCursor);
}

void EditorEvents::OnEventsPanelLeftDown(wxMouseEvent& event)
{
    if ( event.GetX() >= conditionsColumnWidth-2 && event.GetX() <= conditionsColumnWidth+2  )
        isResizingColumns = true;
}

void EditorEvents::DeselectAllEvents(vector < Event > & eventsToUnselected)
{
    for (unsigned int i = 0;i<eventsToUnselected.size();++i)
    {
    	eventsToUnselected[i].selected = false;
    	if ( !eventsToUnselected[i].events.empty() )
            DeselectAllEvents(eventsToUnselected[i].events);
    }
}

void EditorEvents::DeselectAllActions(vector < Event > & eventsToUnselected)
{
    for (unsigned int i = 0;i<eventsToUnselected.size();++i)
    {
        for (unsigned int a = 0;a<eventsToUnselected[i].actions.size();++a)
            eventsToUnselected[i].actions[a].selected = false;

    	if ( !eventsToUnselected[i].events.empty() )
            DeselectAllActions(eventsToUnselected[i].events);
    }
}

void EditorEvents::DeselectAllConditions(vector < Event > & eventsToUnselected)
{
    for (unsigned int i = 0;i<eventsToUnselected.size();++i)
    {
        for (unsigned int c = 0;c<eventsToUnselected[i].conditions.size();++c)
            eventsToUnselected[i].conditions[c].selected = false;

    	if ( !eventsToUnselected[i].events.empty() )
            DeselectAllConditions(eventsToUnselected[i].events);
    }
}


////////////////////////////////////////////////////////////
/// Tests unitaires
////////////////////////////////////////////////////////////
TEST( Dialogues, EditorEvents )
{
    Game game;
    MainEditorCommand nrC;
    Scene scene;

    wxLogNull noLog;

    //On v�rifie que rien ne plante
    EditorEvents editor(NULL, game, scene, &scene.events, nrC);

    wxCommandEvent unusedEvent;
    editor.OnDelEventSelected(unusedEvent);
    editor.OnDelConditionsSelected(unusedEvent);
    editor.OnDelActionsSelected(unusedEvent);

    editor.OnCutSelected(unusedEvent);
    editor.OnMenuCopySelected(unusedEvent);
    editor.OnMenuItem7Selected(unusedEvent);
    //editor.OnAddLienSelected(unusedEvent);
    editor.OnInsertEventSelected(unusedEvent);
    editor.OnSubEventMenuItemSelected(unusedEvent);
    //editor.OnAddLienSelected(unusedEvent);
    editor.OnMenuPasteAfterSelected(unusedEvent);
    editor.OnMenuPasteSelected(unusedEvent);
    editor.OnPasteAsASubEventSelected(unusedEvent);
    editor.OnDelSubEventsSelected(unusedEvent);

}

////////////////////////////////////////////////////////////
/// Raccourcis clavier, renvoyant aux fonctions d�j� existantes
////////////////////////////////////////////////////////////
void EditorEvents::OnEventsPanelKeyUp(wxKeyEvent& event)
{
    if ( event.GetKeyCode() == WXK_DELETE )
    {
        wxCommandEvent unusedEvent;
        OnDelEventSelected( unusedEvent );
    }
    if ( event.GetKeyCode() == WXK_INSERT )
    {
        wxCommandEvent unusedEvent;
        OnInsertEventSelected( unusedEvent );
    }
    else if ( event.GetModifiers() == wxMOD_CMD ) //Ctrl-xxx
    {
        switch ( event.GetKeyCode() )
        {
            case 67: //Ctrl C
            {
                wxCommandEvent unusedEvent;
                OnMenuCopySelected( unusedEvent );
                break;
            }
            case 86: //Ctrl-V
            {
                wxCommandEvent unusedEvent;
                OnMenuPasteAfterSelected( unusedEvent );
                break;
            }
            case 88: //Ctrl-X
            {
                wxCommandEvent unusedEvent;
                OnCutSelected( unusedEvent );
                break;
            }
            case 89: //Ctrl-Y
            {
                wxCommandEvent unusedEvent;
                OnRedoSelected( unusedEvent );
                break;
            }
            case 90: //Ctrl-Z
            {
                wxCommandEvent unusedEvent;
                OnUndoSelected( unusedEvent );
                break;
            }
            default:
                break;
        }
    }
    else if ( event.GetModifiers() == (wxMOD_CMD|wxMOD_SHIFT) )
    {

        switch ( event.GetKeyCode() )
        {
            case 86: //Ctrl-V
            {
                wxCommandEvent unusedEvent;
                OnPasteAsASubEventSelected( unusedEvent );
                break;
            }
            default:
                break;
        }
    }
}

/**
 * Display ribbon and connect events when get focus
 */
void EditorEvents::OnEventsPanelSetFocus(wxFocusEvent& event)
{
    mainEditorCommand.GetRibbon()->SetActivePage(4);
    ConnectEvents();
}

