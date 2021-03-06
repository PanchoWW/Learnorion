// -*- C++ -*-
#ifndef _AccordionPanel_h_
#define _AccordionPanel_h_

#include <GG/GGFwd.h>
#include <GG/Wnd.h>
#include <GG/GLClientAndServerBuffer.h>

class AccordionPanel : public GG::Wnd {
public:
    /** \name Structors */ //@{
    AccordionPanel(GG::X w);
    virtual ~AccordionPanel();
    //@}

    /** \name Mutators */ //@{
    virtual void Render();
    virtual void MouseWheel(const GG::Pt& pt, int move, GG::Flags<GG::ModKey> mod_keys);
    virtual void SizeMove(const GG::Pt& ul, const GG::Pt& lr);
    //@}

    mutable boost::signals2::signal<void ()> ExpandCollapseSignal;

protected:
    GG::GL2DVertexBuffer    m_border_buffer;

    void            SetCollapsed(bool collapsed);
    virtual void    DoLayout();
    virtual void    InitBuffer();

    GG::Button*             m_expand_button;    ///< at top right of panel, toggles the panel open/closed to show details or minimal summary
};

#endif
