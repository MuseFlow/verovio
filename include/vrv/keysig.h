
/////////////////////////////////////////////////////////////////////////////
// Name:        keysig.h
// Author:      Rodolfo Zitellini
// Created:     10/07/2012
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////


#ifndef __VRV_KEYSIG_H__
#define __VRV_KEYSIG_H__

#include "atts_shared.h"
#include "layerelement.h"
#include "vrvdef.h"

namespace vrv {
    
class KeySigAttr;

//----------------------------------------------------------------------------
// KeySig
//----------------------------------------------------------------------------

/**
 * This class models the MEI <keySig> element.
 */
class KeySig: public LayerElement
{
public:
    /**
     * @name Constructors, destructors, and other standard methods
     * Reset method reset all attribute classes.
     */
    ///@{
    KeySig();
    KeySig(int num_alter, char alter);
    KeySig( KeySigAttr *keySigAttr );
    virtual ~KeySig();
    virtual void Reset();
    virtual Object* Clone() { return new KeySig(*this); };
    virtual std::string GetClassName( ) { return "KeySig"; };
    
    /**
     * Return the default horizontal spacing after a keysig.
     */
    virtual int GetHorizontalSpacing( ) { return 20; };
    
    unsigned char GetAlterationAt(int pos);
    int GetOctave(unsigned char pitch, int clefId);
    
    /* Alteration number getter/setter */
    int GetAlterationNumber() { return m_num_alter; };
    void SetAlterationNumber(int n) { m_num_alter = n; };
    
    /* Alteration number getter/setter */
    unsigned char GetAlteration() { return m_alteration; };
    void SetAlteration(int n) { m_alteration = n; };
    
private:
    
public:
    
private:
    static unsigned char flats[];
    static unsigned char sharps[];
    static int octave_map[2][9][7];
    
    // This is temporary - it needs to be changed to libMEI atts
    int m_num_alter;
    unsigned char m_alteration;
    
};
    
//----------------------------------------------------------------------------
// KeySigAttr
//----------------------------------------------------------------------------

/**
 * This class models the MEI @key attributes in scoreDef or staffDef elements.
 */
class KeySigAttr: public Object, public AttKeySigDefaultLog
{
public:
    /**
     * @name Constructors, destructors, reset and class name methods
     * Reset method reset all attribute classes
     */
    ///@{
    KeySigAttr();
    virtual ~KeySigAttr();
    virtual void Reset();
    virtual std::string GetClassName( ) { return "KeySigAttr"; };
    virtual Object* Clone() { return new KeySigAttr(*this); };
    ///@}
    
    /**
     * Comparison operator.
     * Check if the LayerElement if a ClefAttr and compare attributes
     */
    virtual bool operator==(Object& other);
    
private:
    
public:
    
private:
    
};

} // namespace vrv    

#endif
